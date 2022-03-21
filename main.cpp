#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>

GLuint loadShader(const std::string& filePath , GLenum shaderType){
        GLuint shader = glCreateShader(shaderType);
        std::ifstream file(filePath);
        std::string source = std::string(std::istreambuf_iterator<char>(file),std::istreambuf_iterator<char>()); //make itrator to the file and get all of the file
        const char* sourceCStr = source.c_str();
        glShaderSource(shader,1,&sourceCStr,nullptr);
        glCompileShader(shader); 
        return shader;

}

struct Vertex {
    float x, y, z;
    uint8_t r, g, b, a;
};


int main(int, char**) {

    if(!glfwInit()){
        std::cerr <<"Faild to init glfw" << std::endl;
        exit(-1);
    }

    GLFWwindow* window = glfwCreateWindow( 500,500,"Labs",nullptr,nullptr );

    if(!window){
        glfwTerminate();
        std::cerr << "Faild to create windows" <<std::endl;
        exit(-1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    


    glfwMakeContextCurrent(window);//point to this window as the main window that we will make any change in it
    gladLoadGL(glfwGetProcAddress); //this two commands must be used before opengl get used

    GLuint program = glCreateProgram();
    GLuint vs = loadShader("assets/shaders/simple.vert",GL_VERTEX_SHADER);
    glAttachShader(program,vs); //attach program with shader
    glDeleteShader(vs); //delete shader when finished

    GLuint fs = loadShader("assets/shaders/simple.frag",GL_FRAGMENT_SHADER);
    glAttachShader(program,fs); //attach program with shader
    glDeleteShader(fs); //delete shader when finished
    
    
    glLinkProgram(program); //link program

    GLuint VAO;//make vertix array of objext to init the vertices
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);

     Vertex vertices[] = {
        {-0.5f, -0.5f, 0.0f,   0, 255, 255, 255},
        { 0.5f, -0.5f, 0.0f, 255,   0, 255, 255},
        { 0.5f,  0.5f, 0.0f, 255, 255,   0, 255},
        {-0.5f,  0.5f, 0.0f, 255,   0, 255, 255},
    };
    // data will be divided to the first 3 element is the position of the point and the rest 4 points indecates its color

    GLuint VBO; //buffer ( container of data)
    glGenBuffers(1,&VBO); // make a object of it
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO); //we must bind anything before using it 
    
    glBufferData(GL_ARRAY_BUFFER, 3*sizeof(Vertex) , vertices , GL_STATIC_DRAW ); /* it transfer data and it is init to vbo(buffer) 
    and 3*(sizeof(Vertex)) indecates 3 vertix * size of each vertex which are (3 float points which are (x,y,z) * each one 4 bytes ), data => position (pointer) , 
    static draw => used to draw and will not change  */

    GLint positionLoc = 0; // instead of getting the location of positions which in simple.vert which i gave it location 0 there 

    //glGetAttribLocation(program,"positions"); to get it dynamic

    glEnableVertexAttribArray(positionLoc); //it is essensiol as it won't read any attribute with out this
    glVertexAttribPointer(positionLoc,3,GL_FLOAT,false, sizeof(Vertex),(void*)0); //3 indecates components x,y,z get the data from last mentioned buffer
    // stride is the time taken from the buffer to get to the given point (not sure)
    
    

    //this is the code of colors if we divided vertex in positions and colors individual

    
    // float colors[] = {
    //      0.0,  1.0, 1.0, 1.0,
    //      1.0,  0.0, 1.0, 1.0,
    //      1.0,  1.0, 0.0, 1.0,
    // }; --> TA merge the colors and positions togather in vertex struct

    
    // GLuint VB1; //buffer ( container of data)
    // glGenBuffers(1,&VB1); // make a object of it
    
    // glBindBuffer(GL_ARRAY_BUFFER, VB1); //we must bind anything before using it 
    
    // glBufferData(GL_ARRAY_BUFFER, 3*4*4 , colors , GL_STATIC_DRAW );
     /* it transfer data and it is init to vbo(buffer) 
    and 3*3*4 indecates 3 vertix * 3 points which are (x,y,z) * each one 4 bytes , data => position (pointer) , 
    static draw => used to draw and will not change  */



    GLint colorLoc = 1; //glGetAttribLocation(program,"colors");

    glEnableVertexAttribArray(colorLoc); //it is essensiol as it won't read any attribute with out this
    glVertexAttribPointer(colorLoc,4,GL_UNSIGNED_BYTE,true,sizeof(Vertex),(void*)offsetof(Vertex, r)); //3 indecates components x,y,z get the data from last mentioned buffer

    GLint timeloc = glGetUniformLocation(program,"time"); //get pointer to the time

    while(!glfwWindowShouldClose(window)){ //if not clicked x in window it won't close
        glClearColor(0.2,0.4,0.6,1);//RGB and alpha get the color that will be used
        glClear(GL_COLOR_BUFFER_BIT);//الفانكشن الي بتنفذه
        
        glBindVertexArray(VAO);
        glUseProgram(program);

        glUniform1f(timeloc,(float)glfwGetTime()); //declare time to the vert file at each cycle

        glDrawArrays(GL_TRIANGLES,0,3);//draw tringles(take three points and make a tringle with it) and start with vertix 0 to vertix 3

        glfwSwapBuffers(window);//draw everything at single buffer and then appear everything to the user
        glfwPollEvents(); //check all events of the window
    }

    glfwDestroyWindow(window);
    return 0;
}
