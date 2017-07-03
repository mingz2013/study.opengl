/**�������ӵĿ��ļ�**/
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glaux.lib")
#pragma comment(lib, "vfw32.lib")
/**����ͷ�ļ�**/
#include <windows.h>	/**windows��ͷ�ļ�**/
#include "glew.h"		/**�������µ�gl.h��glu.h��**/
#include "glut.h"		/**����OpenGLʵ�ÿ�**/
/**ȫ�ֱ���**/
HDC			hDC = NULL;	// ���ڵ��豸�������
HGLRC		hRC = NULL;	// OpenGL��Ⱦ�豸���
HWND		hWnd = NULL;	// �������ǵĴ��ھ��
HINSTANCE	hInstance;	// ��������ʵ��

bool keys[256];			// ������̰���������
bool active = TRUE;		// ���ڵĻ��־��Ĭ��ΪTRUE
bool fullscreen = TRUE;	// ȫ����־Ĭ�ϣ�Ĭ���趨��ȫ��ģʽ

/**��Ϣ����ص�����**/
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

/**����OpenGL���ڴ�С**/
GLvoid ReSizeGLScene(GLsizei width, GLsizei height)
{
	if(height == 0)	// ��ֹ�����
	{
		height = 1;	// ��Height��Ϊ1
	}

	glViewport(0, 0, width, height);	// ���õ�ǰ���ӿ�

	glMatrixMode(GL_PROJECTION);		/**ѡ��ͶӰ����**/
	glLoadIdentity();					// ����ͶӰ����

	// �����ӿڵĴ�С
	gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);		// ѡ��ģ�͹۲����
	glLoadIdentity();				// ����ģ�͹۲����

}

// �˴���ʼ��OpenGL������������
int InitGL(GLvoid)
{
	glShadeModel(GL_SMOOTH);		// ������Ӱƽ��
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);	// ��ɫ����
	glClearDepth(1.0f);				// ������Ȼ���
	glEnable(GL_DEPTH_TEST);		// ������Ȳ���
	glDepthFunc(GL_LEQUAL);			// ������Ȳ��Ե�����

	// ����ϵͳ��͸�ӽ�������
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	return TRUE;
}

// �����￪ʼ�������еĻ���
int DrawGLScene(GLvoid)
{
	// �����Ļ����Ȼ���
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();		// ��ֵ��ǰ��ģ�͹۲����
	return TRUE;
}

/**�������ٴ���**/
GLvoid KillGLWindow(GLvoid)
{
	if(fullscreen)
	{	// ���Ǵ���ȫ��ģʽ��
		ChangeDisplaySettings(NULL, 0);	// �л�������
		ShowCursor(TRUE);				// ��ʾ���ָ��
	}
	if(hRC)	// ӵ��OpenGL��Ⱦ���������
	{
		if(!wglMakeCurrent(NULL, NULL))	
		{
			MessageBox(NULL, LPCWSTR("�ͷ�DC��RCʧ�ܡ�"), LPCWSTR("�رմ���"), MB_OK | MB_ICONINFORMATION);
		}

		if(!wglDeleteContext(hRC))	// �����ܷ�ɾ��RC
		{
			MessageBox(NULL, LPCWSTR("�ͷ�RCʧ�ܡ�"), LPCWSTR("�رմ���"), MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;		// ��RC��ΪNULL
	}
	if(hDC && ReleaseDC(hWnd, hDC))	// �����ܷ��ͷ�DC
	{
		MessageBox(NULL, LPCWSTR("�ͷ�DCʧ�ܡ�"), LPCWSTR("�رմ���"), MB_OK | MB_ICONINFORMATION);
		hDC = NULL;			// ��DC��ΪNULL
	}
	if(hWnd && ! DestroyWindow(hWnd))	// �ܷ����ٴ���
	{
		MessageBox(NULL, LPCWSTR("�ͷŴ��ھ��ʧ�ܡ�"), LPCWSTR("�رմ���"), MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;			// ��hWnd��ΪNULL
	}
	if(!UnregisterClass(LPCWSTR("OpenG"), hInstance))	// �ܷ�ע����
	{
		MessageBox(NULL, LPCWSTR("����ע�������ࡣ"), LPCWSTR("�رմ���"), MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;			// ��hInstance��ΪNULL
	}
}


