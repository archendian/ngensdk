


// VERTEX SHADER
// Position3Rgb3



struct Vertex {
	vec3 POSITION0;
	vec3 COLOR0;
}

in Vertex* Vertex;

void main(void)
{
   vec4 a = gl_Vertex;
   a.x = a.x * 0.5;
   a.y = a.y * 0.5;


   gl_Position = gl_ModelViewProjectionMatrix * a;

}    