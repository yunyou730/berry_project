#shader vertex
#version 330 core
layout(location = 0) in vec4 position;
layout(location = 1) in vec4 input_color;
out vec4 pass_color;
void main()
{
	pass_color = input_color;
	gl_Position = position;
}

#shader fragment
#version 330 core
in vec4 pass_color;
layout(location = 0) out vec4 color;
void main()
{
	//color = vec4(0.2,0.5,0.8,1.0);
	color = pass_color;
}
