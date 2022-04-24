#version 330 //essiantial at the beginning of the file and the version is 330 as we use 3.3 in opengl

uniform float time;

in vec4 vertex_color;
out vec4 frag_color;

void main(){

    vec3 tint = vec3(sin(time),sin(2*time),sin(3*time)) +0.5*0.5;

    frag_color = vertex_color;
}