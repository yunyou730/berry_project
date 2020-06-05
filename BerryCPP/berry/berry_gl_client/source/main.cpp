#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Renderer.h"
#include "Shader.h"

#include "DrawWithOnlyVBO.h"
#include "DrawWithVAO.h"
#include "DrawWithEBO.h"
#include "DrawPosColor.h"
#include "DrawPosColorMixVBO.h"
#include "DrawSimpleTexture.h"

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
	
	// shader
	berry::Shader shader1("res/test.shader");
	berry::Shader shader2("res/test2.shader");
	berry::Shader shader3("res/test3.shader");


	//DrawWithOnlyVBO test1;
	//test1.Prepare();
	//test1.SetShader(shader);

	//berry::DrawWithVAO test2;
	//test2.Prepare();
	//test2.SetShader(&shader1);
 //   
	//DrawWithEBO test3;
	//test3.Prepare();
	//test3.SetShader(&shader1);
 //   
 //   
	//DrawPosColor test4;
	//test4.Prepare();
	//test4.SetShader(&shader2);

	//DrawPosColorMixVBO test5;
	//test5.Prepare();
	//test5.SetShader(&shader2);

	DrawSimpleTexture test6;
	test6.Prepare();
	test6.SetShader(&shader1);

	berry::Renderer renderer;
	//renderer.SetClearColor(0.5, 0.8, 0.5, 1.0);
    
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		renderer.Clear();

		//test1.Renderer();
		//test2.Renderer(&renderer);
		//test3.Renderer(&renderer);
		//test4.Renderer(&renderer);
		//test5.Renderer(&renderer);
		test6.Renderer(&renderer);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
