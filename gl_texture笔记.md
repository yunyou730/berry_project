
# OpenGL Texture2D 使用笔记 

## 生成 texture 

    glGenTextures(1,&m_textureID)
    glBindTexture(GL_TEXTURE_2D,m_textureID)    // 开始操作 当前 texture 


## 读取 图片格式 到 内存  stbi 库  

    stbi_set_flip_vertically_on_load(1);
    m_localBuffer = stbi_load(path.c_str(), &m_width, &m_height, &m_bpp, 4);// 4 means RGBA  
    
读取时需要注意 ，必须 设置  flip vertical    
因为 图片原点 在 左上角 ， OpenGL 原点在左下角   
不设置会导致 图片是上下 颠倒 的  


## 设置 texture 必要参数 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE)
    
经测试，至少要设置 GL_TEXTURE_MIN_FILTER , GL_TEXTURE_MAG_FILTER 这两个属性， 否则 最终 texture 无法绘制  


## 将 内存中的 texture RGBA 数据，传送到显存 
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,m_width,m_height,0,GL_RGBA,GL_UNSIGNED_BYTE,m_localBuffer)
    glBindTexture(GL_TEXTURE_2D, 0);    // 结束操作当前 texture ,解除绑定 
    
之后，内存中的 rgba 数据可以删除掉  

    if (m_localBuffer)
    {
        stbi_image_free(m_localBuffer);
        m_localBuffer = nullptr;
    }


## 使用 texture  

    GLCALL(glActiveTexture(GL_TEXTURE0 + slot));
    GLCALL(glBindTexture(GL_TEXTURE_2D, m_textureID));  
    
其中 slot 参数 ，需要跟 shader 的 sampler2D 参数相对应  



## Shader  

    #shader vertex
    #version 330 core
    layout(location = 0) in vec4 position;
    layout(location = 1) in vec2 uv;
    out vec2 v_uv;

    void main()
    {
        gl_Position = position;
        v_uv = uv;
    }

    #shader fragment
    #version 330 core

    layout(location = 0) out vec4 color;
    uniform sampler2D u_Texture;
    in vec2 v_uv;

    void main()
    {
        vec4 texColor = texture(u_Texture,v_uv);
        color = texColor;
    }


注意点 : 
- 传递顶点位置到 position ,uv 坐标到 uv  
- 需要一个 varying 参数 v_uv ，从  vs 传递到 fs 
- 需要一个 uniform 的 sampler2D 参数 u_Texture 来标记 使用 绑定到  OpenGL 哪个 slot 上的 texture .对应 GL_TEXTURE0 - GL_TEXTURE(N)  
- fragment shader 接受 varying 参数 v_uv 
- 使用 texture(纹理 slot , vec2 uv坐标 ) 采样纹理上的颜色  



## 绘制之前的准备工作  

开启 VAO,EBO  
绑定 texture :  glActiveTexture,glBindTexture  
shader 开启，并设置 u_Texture 的 uniform 值，用于标记 shader 中使用哪个 OpenGL 纹理  
开始绘制  


## Blend  

如果不开启 Blend ，则绘制的图片 会很 "trash" 没有透明通道  
因此 ，需要让 OpenGL 开启 Blend ，并给  Blend 设置一套  BlendFunc 参数

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

