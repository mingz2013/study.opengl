////
////  The first triangle The first triangle the_first_triangle.cpp
////  opengl_02
////
////  Created by zhaojm on 14/12/30.
////  Copyright (c) 2014年 zhaojm. All rights reserved.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <fstream>
//#include <stdlib.h>
//#include <string.h>
//
//////// 下面的GLM是个很有用的三维数学库，我们暂时没用到，但很快就会用上。GLM库很好用，但没有什么神奇的，你自己也可以写一个。添加“using namespace”是为了不用写“glm::vec3”，直接写“vec3”。
//////// Include GLM
//////#include <glm/glm.hpp>
//////using namespace glm;
//
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//
//#include "shader.hpp"
//
//int main(){
//    // 初始化
//    if( !glfwInit() )
//    {
//        fprintf( stderr, "Failed to initialize GLFW\n" );
//        return -1;
//    }
//    
//    //    可以创建我们的第一个OpenGL窗口啦！
//    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL
//    
//    // Open a window and create its OpenGL context
//    GLFWwindow* window; // (In the accompanying source code, this variable is global)
//    window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);
//    if( window == NULL ){
//        fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window); // Initialize GLEW
//    glewExperimental=true; // Needed in core profile
//    if (glewInit() != GLEW_OK) {
//        fprintf(stderr, "Failed to initialize GLEW\n");
//        return -1;
//    }
//    
//    // Ensure we can capture the escape key being pressed below
//    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
//    
//    // Dark blue background
//    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
//    
//    
//    //创建一个顶点数组对象
//    // Do this once your window is created (= after the OpenGL Context creation) and before any other OpenGL call.
//    GLuint VertexArrayID;
//    glGenVertexArrays(1, &VertexArrayID);
//    glBindVertexArray(VertexArrayID);
//    
//
//    // Create and compile our GLSL program from the shaders
//    // 顶点着色器 和 片断着色器
//    GLuint programID = LoadShaders( "res/shaders/05/SimpleVertexShader.vertexshader", "res/shaders/05/SimpleFragmentShader.fragmentshader" );
//    
//
//    
//    // So we need three 3D points in order to make a triangle ; let’s go :
//    // 我们需要三个三维点来组成一个三角形
//    // An array of 3 vectors which represents 3 vertices
//    static const GLfloat g_vertex_buffer_data[] = {
//        -1.0f, -1.0f, 0.0f,
//        1.0f, -1.0f, 0.0f,
//        0.0f,  1.0f, 0.0f,
//    };
//    
//    //下一步把这个三角形传给OpenGL。我们通过创建一个缓冲区完成
//    // This will identify our vertex buffer
//    GLuint vertexbuffer;
//    
//    // Generate 1 buffer, put the resulting identifier in vertexbuffer
//    glGenBuffers(1, &vertexbuffer);
//    
//    // The following commands will talk about our 'vertexbuffer' buffer
//    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//    
//    // Give our vertices to OpenGL.
//    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
//
//    
//    
//    do{
//        // 首先清屏
//        glClear( GL_COLOR_BUFFER_BIT );
//        
//        // Use our shader 然后告诉OpenGL你想用你的着色器
//        glUseProgram(programID);
//        
//     
//        // 1rst attribute buffer : vertices
//        glEnableVertexAttribArray(0);
//        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//        glVertexAttribPointer(
//                              0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
//                              3,                  // size
//                              GL_FLOAT,           // type
//                              GL_FALSE,           // normalized?
//                              0,                  // stride
//                              (void*)0            // array buffer offset
//                              );
//        
//        
//
//        
//        // Draw the triangle !
//        glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
//        
//        glDisableVertexAttribArray(0);
//
//        
//        // Swap buffers
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//        
//    } // Check if the ESC key was pressed or the window was closed
//    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
//          glfwWindowShouldClose(window) == 0 );
//    
//    
//    
//    glDeleteBuffers(1, &vertexbuffer);
//    glDeleteVertexArrays(1, &VertexArrayID);
//    glDeleteProgram(programID);
//    
//    // Close OpenGL window and terminate GLFW
//    glfwTerminate();
//    
//    return 0;
//}
