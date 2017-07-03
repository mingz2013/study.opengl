////
////  new_window.cpp
////  opengl_02
////
////  Created by zhaojm on 14/12/30.
////  Copyright (c) 2014年 zhaojm. All rights reserved.
////
//
//// 从处理依赖库开始：我们要用一些基本库，在控制台显示消息
//// Include standard headers
//#include <stdio.h>
//#include <stdlib.h>
//
//// 然后是GLEW库。这东西的原理，我们以后再说。
//// Include GLEW. Always include it before gl.h and glfw.h, since it's a bit magic.
//#include <GL/glew.h>
//
//// 我们使用GLFW库处理窗口和键盘消息，把它也包含进来
//// Include GLFW
////#include <GL/glfw.h>
//#include <GLFW/glfw3.h>
//
//
////// 下面的GLM是个很有用的三维数学库，我们暂时没用到，但很快就会用上。GLM库很好用，但没有什么神奇的，你自己也可以写一个。添加“using namespace”是为了不用写“glm::vec3”，直接写“vec3”。
////// Include GLM
////#include <glm/glm.hpp>
////using namespace glm;
//
//int main(){
//
////    首先初始化GLFW ：
//    
//    // Initialise GLFW
//    if( !glfwInit() )
//    {
//        fprintf( stderr, "Failed to initialize GLFW\n" );
//        return -1;
//    }
//
////    可以创建我们的第一个OpenGL窗口啦！
//
//    
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
//
////    编译并运行。一个窗口弹出后立即关闭了。可不是嘛！还没设置等待用户Esc按键再关闭呢：
//    
//    // Ensure we can capture the escape key being pressed below
//    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
//    
//    do{
//        // Draw nothing, see you in tutorial 2 !
//        
//        // Swap buffers
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//        
//    } // Check if the ESC key was pressed or the window was closed
//    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
//          glfwWindowShouldClose(window) == 0 );
//}
//
//
//
