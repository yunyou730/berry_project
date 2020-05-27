#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include <string>
#include <iostream>
//#include "source/ShaderManager.h"
#include <fstream>
#include <sstream>
#include "Renderer.h"

#include "DrawWithOnlyVBO.h"
#include "DrawWithVAO.h"
#include "DrawWithEBO.h"
#include "DrawPosColor.h"
#include "DrawPosColorMixVBO.h"

struct ShaderSource
{
	std::string vertex;
	std::string fragment;
};

static void CreateShaderWithFile(const std::string& path,ShaderSource& shaderSource)
{
	enum class ShaderSourceType
	{
		None = -1,
		Vertex = 0,
		Fragment = 1,
		Max,
	};
	std::string source[(int)ShaderSourceType::Max];

	std::fstream fs;
	fs.open(path);
    if(!fs.is_open())
    {
        printf("open shader file %s failed\n",path.c_str());
    }

	ShaderSourceType sourceType = ShaderSourceType::None;
	std::string str;
	while (getline(fs,str))
	{
		std::cout << str << std::endl;
		if (str.find("#shader") != std::string::npos)
		{
			if (str.find("vertex") != std::string::npos)
			{
				sourceType = ShaderSourceType::Vertex;
			}
			else if (str.find("fragment") != std::string::npos)
			{
				sourceType = ShaderSourceType::Fragment;
			}
		}
		else if(sourceType > ShaderSourceType::None && sourceType <= ShaderSourceType::Max)
		{
			source[(int)sourceType] += str + "\n";
		}
	}
	fs.close();
	shaderSource.vertex = source[(int)ShaderSourceType::Vertex];
	shaderSource.fragment = source[(int)ShaderSourceType::Fragment];
}

static GLuint CompileShader(GLuint type,const std::string& source)
{
	GLuint id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		int length = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = new char[length];
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Shader " << (type == GL_VERTEX_SHADER ? "vertex shader":"fragment shader") << " compile error" << std::endl;
		std::cout << message << std::endl;
		delete[] message;

		glDeleteShader(id);
		return 0;
	}
	return id;
}


static GLuint CreateShader(const std::string& vertexShader,const std::string& fragmentShader)
{
	GLuint program = glCreateProgram();
	GLuint vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	GLuint fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}


int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
#endif

	//bool isFullScreen = true;
	//GLFWmonitor* pMonitor = isFullScreen ? glfwGetPrimaryMonitor() : NULL;
	//const GLFWvidmode * mode = glfwGetVideoMode(pMonitor);


	/* Create a windowed mode window and its OpenGL context */
	//window = glfwCreateWindow(mode->width, mode->height, "Hello World", pMonitor, NULL);
	window = glfwCreateWindow(640,480, "Hello World", nullptr, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Init glew */
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		glfwTerminate();
		return -1;
	}

	// Version info
	const GLubyte* vendor = glGetString(GL_VENDOR);
	const GLubyte* version = glGetString(GL_VERSION);
	std::cout << "GL info\n" << "[vendor]" << vendor << std::endl << "[version]" << version << std::endl;
	

	ShaderSource source;
	CreateShaderWithFile("res/test.shader",source);
	GLuint shader = CreateShader(source.vertex,source.fragment);

	ShaderSource source2;
	CreateShaderWithFile("res/test2.shader", source2);
	GLuint shader2 = CreateShader(source2.vertex, source2.fragment);

	//DrawWithOnlyVBO test1;
	//test1.Prepare();
	//test1.SetShader(shader);

	berry::DrawWithVAO test2;
	test2.Prepare();
	test2.SetShader(shader);
    
	DrawWithEBO test3;
	test3.Prepare();
	test3.SetShader(shader);
    
    /*
	DrawPosColor test4;
	test4.Prepare();
	test4.SetShader(shader2);

	DrawPosColorMixVBO test5;
	test5.Prepare();
	test5.SetShader(shader2);
    */

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
//        glClearColor(0.5,0.8,0.5,1.0);
		glClear(GL_COLOR_BUFFER_BIT);

		//test1.Renderer();
		test2.Renderer();
		test3.Renderer();
		//test4.Renderer();
//		test5.Renderer();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glDeleteShader(shader);
	glDeleteShader(shader2);

	glfwTerminate();
	return 0;
}
