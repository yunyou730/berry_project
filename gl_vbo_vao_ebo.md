

[https://learnopengl-cn.github.io/01%20Getting%20started/04%20Hello%20Triangle/](https://learnopengl-cn.github.io/01%20Getting%20started/04%20Hello%20Triangle/)


###  VBO

准备数据  

    
	float vertices[] = {
	    -0.5f, -0.5f, 0.0f,
	     0.5f, -0.5f, 0.0f,
	     0.0f,  0.5f, 0.0f
	};

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);  
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

----------



	//1 复制顶点数组到缓冲中供OpenGL使用    
	glBindBuffer(GL_ARRAY_BUFFER, VBO);  
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	//2 设置顶点属性指针  
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);  
	glEnableVertexAttribArray(0);
	
	//3 当我们渲染一个物体时要使用着色器程序  
	glUseProgram(shaderProgram);
	
	//4 绘制物体
	someOpenGLFunctionThatDrawsOurTriangle();


### VAO 

生成 VAO 
  
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);


VAO 所存储的数据  

- glEnableVertexAttribArray和glDisableVertexAttribArray的调用。
- 通过glVertexAttribPointer设置的顶点属性配置。
- 通过glVertexAttribPointer调用与顶点属性关联的VBO。

-----------
	
	// ..:: 初始化代码（只运行一次 (除非你的物体频繁改变)） :: ..
	// 1. 绑定VAO
	glBindVertexArray(VAO);
	// 2. 把顶点数组复制到缓冲中供OpenGL使用
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3. 设置顶点属性指针
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	[...]
	
	// ..:: 绘制代码（渲染循环中） :: ..
	// 4. 绘制物体
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	someOpenGLFunctionThatDrawsOurTriangle();


----------------------

### EBO  



### 总结

使用 VAO +  VBO 配合的方式,可以完成绘制  
仅使用 VBO  也可以完成绘制  
VAO 更像是 对 VBO 所有属性设置操作的一个存储


仅使用 VBO 绘制的必要步骤 

准备阶段 :   

- 生成数组 arr
- glGenBuffer() 生成一个 vbo 
- glBindBuffer() glBufferData() 用c++数组 arr 填充这个 vbo  
- glVertexAttribPointer() 定义 vbo 数据和 shader 属性的映射关系 
- 完毕,glBindbuffer() 为0 解除绑定 

绘制阶段 :  

- glBindBuffer() 到 vbo  
- glEnableVertexAttribArray() 打开各个 shader 和 vbo 映射的属性 
- glUseProgram() 指定 shader  
- 调用 绘制 api 
- 完毕,glBindbuffer() 为0 解除绑定


----------------------

VAO 配合 VBO 绘制的步骤  

经过总结,绘制时必须要有 VBO  ,
并且必须通过 glVertexAttribPointer  设置 VBO 和 shader 数据映射关系    


如果使用 VAO 的话, 则 VAO 会记录  glEnableVertexAttribArray() 开启了 shader 的哪些参数 
绘制之前只需要 glBindVertexArray(vao) 即可完成一系列 已存储的 shader 参数设置  


如果不使用 VAO ,则每次绘制 VBO 之前 ,需要手动调用 glEnableVertexAttribArray, 控制每个 shader 的参数 是否开启  

--------------

经测试 ,使用 VAO VBO EBO 的初始化顺序 这样最稳: 

生成 VAO,VBO,EBO  
绑定 VAO 
绑定 VBO, 设置 VBO 数据 
绑定 EBO, 设置 EBO 数据 
设置 shader 参数数据 
接触绑定 VAO .注意,这一步绝不可以解除绑定 VBO ,EBO  

绘制时 
绑定 VAO 
调用 OpenGL 绘制函数 

OK 

相当于 绑定 VAO 之后, 做了一系列的操作 ,这些操作被"记录"到 VAO 里, 
在绘制时, 只需要做 "绑定VAO" 这一个操作,即可完成 在初始化 VAO 时设置的所有 对 VBO, EBO,shader参数的操作  

即 VAO 初始化时,相当于把一系列复杂的操作"打包" , 在绘制时简化为 "绑定VAO" 这样一个操作,即可顺利绘制  
 
 


  




