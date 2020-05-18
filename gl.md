  


- berry lua  接入 lua 库 ,提供 lua 支持
- berry testcase 测试 berry_lua 库 
- berry gl client  写 opengl 逻辑  


#### berry gl client  

glfw  

下载, 配置 include 目录  ,配置 link 目录  和 lib 
按照官网 找到 最简单的代码,拷贝到 main.cpp  即可  


glew

下载,配置 include 目录, 配置 link 目录和 lib, dll  

	#define GLEW_STATIC
	
	#include <GL/glew.h>
	#include <GLFW/glfw3.h>
	#include <cstdio>

注意 include 顺序, glew.h 必须在 glfw3.h  之前  

GLEW_STATIC 根据是否是 glew32s.lib 来决定是否 define  
在本地 win32 上发现 只能 link 动态库 ,原因待查  
   

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


glewInit() 必须在 OpenGL 创建 context 之后调用,否则会报错  


opengl32.lib   

最后必须 link opengl32.lib 才能正确调用 opengl 函数 ,比如glClear(GL_COLOR_BUFFER_BIT);  

否则 会报 opengl 相关的函数 有 链接 错误  


