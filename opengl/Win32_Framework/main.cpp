/**包含链接的库文件**/
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glaux.lib")
#pragma comment(lib, "vfw32.lib")
/**包含头文件**/
#include <windows.h>	/**windows的头文件**/
#include "glew.h"		/**包含最新的gl.h、glu.h库**/
#include "glut.h"		/**包含OpenGL实用库**/
/**全局变量**/
HDC			hDC = NULL;	// 窗口的设备环境句柄
HGLRC		hRC = NULL;	// OpenGL渲染设备句柄
HWND		hWnd = NULL;	// 保存我们的窗口句柄
HINSTANCE	hInstance;	// 保存程序的实例

bool keys[256];			// 保存键盘按键的数组
bool active = TRUE;		// 窗口的活动标志，默认为TRUE
bool fullscreen = TRUE;	// 全屏标志默认，默认设定成全屏模式

/**消息处理回调函数**/
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

/**重置OpenGL窗口大小**/
GLvoid ReSizeGLScene(GLsizei width, GLsizei height)
{
	if(height == 0)	// 防止被零除
	{
		height = 1;	// 将Height设为1
	}

	glViewport(0, 0, width, height);	// 重置当前的视口

	glMatrixMode(GL_PROJECTION);		/**选择投影矩阵**/
	glLoadIdentity();					// 重置投影矩阵

	// 设置视口的大小
	gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);		// 选择模型观察矩阵
	glLoadIdentity();				// 重置模型观察矩阵

}

// 此处开始对OpenGL进行所有设置
int InitGL(GLvoid)
{
	glShadeModel(GL_SMOOTH);		// 启用阴影平滑
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);	// 黑色背景
	glClearDepth(1.0f);				// 设置深度缓存
	glEnable(GL_DEPTH_TEST);		// 启用深度测试
	glDepthFunc(GL_LEQUAL);			// 所作深度测试的类型

	// 告诉系统对透视进行修正
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	return TRUE;
}

// 从这里开始进行所有的绘制
int DrawGLScene(GLvoid)
{
	// 清除屏幕和深度缓存
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();		// 充值当前的模型观察矩阵
	return TRUE;
}

/**正常销毁窗口**/
GLvoid KillGLWindow(GLvoid)
{
	if(fullscreen)
	{	// 我们处于全屏模式吗
		ChangeDisplaySettings(NULL, 0);	// 切换回桌面
		ShowCursor(TRUE);				// 显示鼠标指针
	}
	if(hRC)	// 拥有OpenGL渲染环境句柄吗
	{
		if(!wglMakeCurrent(NULL, NULL))	
		{
			MessageBox(NULL, LPCWSTR("释放DC或RC失败。"), LPCWSTR("关闭错误"), MB_OK | MB_ICONINFORMATION);
		}

		if(!wglDeleteContext(hRC))	// 我们能否删除RC
		{
			MessageBox(NULL, LPCWSTR("释放RC失败。"), LPCWSTR("关闭错误"), MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;		// 将RC设为NULL
	}
	if(hDC && ReleaseDC(hWnd, hDC))	// 我们能否释放DC
	{
		MessageBox(NULL, LPCWSTR("释放DC失败。"), LPCWSTR("关闭错误"), MB_OK | MB_ICONINFORMATION);
		hDC = NULL;			// 将DC设为NULL
	}
	if(hWnd && ! DestroyWindow(hWnd))	// 能否销毁窗口
	{
		MessageBox(NULL, LPCWSTR("释放窗口句柄失败。"), LPCWSTR("关闭错误"), MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;			// 将hWnd设为NULL
	}
	if(!UnregisterClass(LPCWSTR("OpenG"), hInstance))	// 能否注销类
	{
		MessageBox(NULL, LPCWSTR("不能注销窗口类。"), LPCWSTR("关闭错误"), MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;			// 将hInstance设为NULL
	}
}


