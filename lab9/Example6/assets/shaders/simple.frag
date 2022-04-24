#version 330

uniform sampler2D tex_sampler; //sampler2d to sample object color

in vec4 vertex_color;
in vec2 vertex_tex_coord;

out vec4 frag_color;

void main(){
    frag_color = texture(tex_sampler, vertex_tex_coord); //related to the box 
    /* texelFetch(
        tex_sampler, 
        ivec2(vec2(gl_FragCoord.xy) / 100  //to make the point واضحة we divided it by 100 //100 to make it much more bigger to make it bigger increase this number ),
        1
    ); //related to the coord of the point regardless to the object
    */ 
}