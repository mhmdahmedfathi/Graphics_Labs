#version 330 //essiantial at the beganing of the file

out vec4 vertex_color;
uniform float time; //7aga sabta bs httb3t mn elc++
//in vec3 positions; //to make it dynamic 
//in vec4 colors; //to make it dynamic 

layout(location=0) in vec3 positions;
layout(location=1) in vec4 colors;


//elfar2 ben vert and frag we ben elc++ en hna byrun 3la 7sb kam vertices
void main(){

    // const vec3 positions[3] = vec3[3](
    //     vec3(-0.5,-0.5,0.0),//(x,y,z)
    //     vec3(0.5,-0.5,0.0),
    //     vec3(0.0,0.5,0.0)
    // );
    // commented as we will get it from outside so we don't need it anymore ---> in lab 2


    // const vec4 colors[3] = vec4[3](
    //     vec4(1,0,0,1),
    //     vec4(0,1,0,1),
    //     vec4(0,0,1,1)
    // );
    // commented as we will get it from outside so we don't need it anymore ---> in lab 2

    // commented as we will get it from outside so we don't need it anymore ---> in lab 2
    //gl_Position = vec4(positions[gl_VertexID] * sin(time),1.0); // gl_position takes 4 args not only 3 
    
    gl_Position = vec4(positions,1.0);
    vertex_color = colors;    
    //vertex_color = colors[gl_VertexID]; // make every vertix with color 
    // commented as we will get it from outside so we don't need it anymore ---> in lab 2
}