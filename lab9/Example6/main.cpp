#include <iostream>
#include <fstream>
#include <string>
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

GLuint loadShader(const std::string& filePath, GLenum shaderType) {
    GLuint shader = glCreateShader(shaderType);

    std::ifstream file(filePath);
    std::string sourceCode = std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
    const char* sourceCodeCStr = sourceCode.c_str();

    glShaderSource(shader, 1, &sourceCodeCStr, nullptr);
    glCompileShader(shader);

    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (!status) {
        GLint length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        char *logStr = new char[length];
        glGetShaderInfoLog(shader, length, nullptr, logStr);
        std::cerr << "ERROR IN " << filePath << std::endl;
        std::cerr << logStr << std::endl;
        delete[] logStr;
        glDeleteShader(shader);
        return false;
    }

    return shader;
}

struct Color {
    uint8_t r, g, b;
};

struct Vertex {
    float x, y, z;
    uint8_t r, g, b, a;
    float s, t;
};

int main(int, char**) {
    
    if(!glfwInit()){
        std::cerr << "Failed to initialize GLFW" << std::endl;
        exit(-1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    const int W = 800, H = 600;
    GLFWwindow* window = glfwCreateWindow(W, H, "Example 1", nullptr, nullptr);
    if(!window){
        std::cerr << "Failed to create window" << std::endl;
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);

    gladLoadGL(glfwGetProcAddress);

    GLuint program = glCreateProgram();
    
    GLuint vs = loadShader("assets/shaders/simple.vert", GL_VERTEX_SHADER);
    glAttachShader(program, vs);
    glDeleteShader(vs);

    GLuint fs = loadShader("assets/shaders/simple.frag", GL_FRAGMENT_SHADER);
    glAttachShader(program, fs);
    glDeleteShader(fs);

    glLinkProgram(program);

    GLint mvpLoc = glGetUniformLocation(program, "MVP");
    GLint samplerLoc = glGetUniformLocation(program, "tex_sampler");

    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    Vertex vertices[] = {
        {-0.5f, -0.5f, 0.0f,   0, 255, 255, 255, 0, 0}, //if  one of the last 2 bit more than 1 or less than 0 by dafualt it will be repeated by the number of the deffirance
        { 0.5f, -0.5f, 0.0f, 255,   0, 255, 255, 20, 0},
        { 0.5f,  0.5f, 0.0f, 255, 255,   0, 255, 20, 20},
        {-0.5f,  0.5f, 0.0f, 255,   0,   0, 255, 0, 20}
    };

    glBufferData(GL_ARRAY_BUFFER, 4*sizeof(Vertex), vertices, GL_STATIC_DRAW);

    GLint positionLoc = 0; //glGetAttribLocation(program, "position");
    glEnableVertexAttribArray(positionLoc);
    glVertexAttribPointer(positionLoc, 3, GL_FLOAT, false, sizeof(Vertex), (void*)0);

    GLint colorLoc = 1; //glGetAttribLocation(program, "color");
    glEnableVertexAttribArray(colorLoc);
    glVertexAttribPointer(colorLoc, 4, GL_UNSIGNED_BYTE, true, sizeof(Vertex), (void*)offsetof(Vertex, r));

    GLint texCoordLoc = 2; //glGetAttribLocation(program, "tex_coord");
    glEnableVertexAttribArray(texCoordLoc);
    glVertexAttribPointer(texCoordLoc, 2, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, s));

    GLuint EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    uint16_t elements[] = {
        0, 1, 2,
        2, 3, 0
    };

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6*sizeof(uint16_t), elements, GL_STATIC_DRAW);
  //---------------------------------------------------------------------------------------------

    Color w = {255, 255, 255}; // White
    Color Y = {255, 255, 0}; // Yellow
    Color b = {0, 0, 0}; // Black

    const int TEX_W = 9;
    const int TEX_H = 8;

    Color pixels[TEX_W*TEX_H] = {
        w, w, Y, Y, Y, Y, w, w, w, //dh byb2a akher sf
        w, Y, Y, b, b, Y, Y, w, w,
        Y, Y, b, Y, Y, b, Y, Y, w,
        Y, Y, Y, Y, Y, Y, Y, Y, w,
        Y, Y, b, Y, Y, b, Y, Y, w,
        Y, Y, b, Y, Y, b, Y, Y, w,
        w, Y, Y, Y, Y, Y, Y, w, w,
        w, w, Y, Y, Y, Y, w, w, w,
    };

    GLuint texture; //array of pixels and each pixel hold a vector to represent it
    glGenTextures(1, &texture); //one texture only
    glBindTexture(GL_TEXTURE_2D, texture); //we must bind everything before use it
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); //to handle the packing and unpacking as it is by defualt each row has a position in memory in multiable of 4
                                           //which is not true in RGB and 9 width as there are 3 channels so 9*3 is not divasable by 4 


    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, TEX_W, TEX_H, 0, GL_RGB, GL_UNSIGNED_BYTE, (void*)pixels); //to send image data to the object (2d vector,level,internalformat => Red bliue green 8bit (RGB8),
                                                                                                       //width,height,border => must be zero ,format => format of the color which is red grean blue alpha RGBA)
                                                                                                       //type => unsigned byte , pointer to the pixels
    
    glGenerateMipmap(GL_TEXTURE_2D); //necessry to work as it get the 8x8 level and compete the the rest of the levels 4x4 and 2x2 and sampler needs Mipmap

    GLuint sampler;
    glGenSamplers(1, &sampler);
    glSamplerParameteri(sampler, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //as the dafult linear and it makes the image blur
    glSamplerParameteri(sampler, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    // glSamplerParameteri(sampler, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // GL_REPEAT => command to make it repeat if one of the last 2 bits of the vertices 
    // if there are much more pixels inside the object then it will get the center of the object and draaw it and the center will change every second
    // due to the change of the coordinate so we have to make GL_NEAREST_MIPMAP_LINEAR to the MIN Filter to handle this noise 
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glDepthMask(true);
    glColorMask(true, true, true, true);

    // glEnable(GL_CULL_FACE);
    // glCullFace(GL_BACK);
    // glFrontFace(GL_CCW);

    // glEnable(GL_SCISSOR_TEST);

    while(!glfwWindowShouldClose(window)){

        glClearColor(0.2f, 0.4f, 0.6f, 1.0f);
        glClearDepth(1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindVertexArray(VAO);
        glUseProgram(program);

        //there are texture units which cant be more than it and is is usually 16 bit and we will send the unit to the texture

        glActiveTexture(GL_TEXTURE0); //we send it unit 0 
        glBindTexture(GL_TEXTURE_2D, texture); //we must bind after making active texture except for unit zero as it is the dafualt value
        glBindSampler(0, sampler); //to bind it to unit 0 as the texture
        glUniform1i(samplerLoc, 0);//we send unit zero to the uniform
        
        float angle = (float)glfwGetTime();

        glm::vec3 eye = glm::vec3(2*glm::sin(angle), 1, 2*glm::cos(angle)); //glm::vec3(0, 0, 2); //

        glm::mat4 view = glm::lookAt(
            eye,
            glm::vec3(0, 0, 0),
            glm::vec3(0, 1, 0)
        );

        glm::mat4 projection = glm::perspective(
            glm::pi<float>()/2,
            W/float(H),
            0.01f,
            100.0f
        );

        for(int z = -1; z <= 1; z++){
            glm::mat4 MVP = projection * view * glm::translate(
                glm::mat4(1.0f),
                glm::vec3(0, 0, z)
            );
            glUniformMatrix4fv(mvpLoc, 1, false, (float*)&MVP);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (void*)0);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // you must destroy texture
    glDeleteTextures(1, &texture);

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
