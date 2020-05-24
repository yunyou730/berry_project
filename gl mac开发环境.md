从 windows 移植到 osx 上遇到的问题 


### 安装 glew glfw 

brew install glew  
brew install glfw  

xcode 里设置 头文件路径，链接库   

编译成功之后，运行时会 glew, glfw 的 dylib 签名错误  
需要修改  dylib 库的签名  

遇到错误百度一下可以解决  


### 拷贝 shader 资源文件  

xcode 的 build phase 里增加 Copy Files   
去掉  Copy oly when installing 的勾，保证每次运行都会复制  
把目录选对  即可  


###  设置 OpenGL 版本  

最初发现 shader 330 版本会报错， opengl 不支持此版本  
通过打印  OpenGL 版本

    const GLubyte* vendor = glGetString(GL_VENDOR);
    const GLubyte* version = glGetString(GL_VERSION);
    std::cout << "GL info\n" << "[vendor]" << vendor << std::endl << "[version]" << version << std::endl;

发现 此时提示 使用的是 OpenGL 2.1  

App Store 下载 OpenGL Extension Viewer 得知电脑支持的  OpenGL 版本是  4.1  

在 glfwInit() 之后 调用 如下代码，使得  OpenGL 支持版本到达 4.1  

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
        glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
        
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
    #endif


### 运行时错误  GL_INVALID_OPERATION

成功运行之后，会发现 无法绘制任何图形。给每一个  OpenGL 调用增加错误信息之后，发现在调用 glEnableVertexAttribArray() 时，会报告 GL_INVALID_OPERATION 异常  

GLCALL(glEnableVertexAttribArray(0));


(http://docs.gl/gl3/glEnableVertexAttribArray)[http://docs.gl/gl3/glEnableVertexAttribArray]   

通过 上面的链接得知，在没有生成  VAO 时，会报此错误   

原因是在  windows 上面 有3个基础的绘制代码 :
1.纯  VBO 
2.VAO + VBO 
3. VAO + VBO + EBO   

而 OpenGL 3以上 版本 不支持没有 VAO 的绘制  ，windows 下由于做了兼融因此能够在没有 VAO 的情况下绘制。  

因此，去掉 第一种纯  VBO 绘制的代码，程序运行成功  


