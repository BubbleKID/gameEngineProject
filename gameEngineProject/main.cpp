#include <windows.h>  
#include <stdlib.h>  
#include <string.h>  
#include <tchar.h> 
HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow)
{
	//MessageBox(NULL, L"欢迎来到马克大人的世界", L"消息窗口", 0);

	WNDCLASSEX wndClass = { 0 };
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc; //设置指向窗口过程函数的指针
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInstance; //指定包含窗口过程的程序实例句柄

	//wndClass.hIcon = (HICON)::LoadImage(NULL, _T("icon.ico"), IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = _T("ForTheDreamOfGameDevelop");

	if (!RegisterClassEx(&wndClass))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	hInst = hInstance;
	//HWND hWnd = CreateWindow(_T("ForTheDreamOfGameDevelop"),
		//L"至我们用不熄灭的游戏开发梦想!",
		//WS_OVERLAPPEDWINDOW, CW_USERDEFAULT, CW_USEDEFAULT, 800,
		//600, NULL, NULL, hInstance, NULL);

	HWND hWnd = CreateWindow(
		_T("ForTheDreamOfGameDevelop"),
		_T("Window"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		500, 100,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	// The parameters to ShowWindow explained:  
	// hWnd: the value returned from CreateWindow  
	// nCmdShow: the fourth parameter from WinMain  
	ShowWindow(hWnd,
		nCmdShow);
	UpdateWindow(hWnd);

	// Main message loop:  
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("First c++ window");

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		// Here your application is laid out.  
		// For this introduction, we just print out "Hello, World!"  
		// in the top left corner.  
		TextOut(hdc,
			5, 5,
			greeting, _tcslen(greeting));
		// End application-specific layout section.  

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}


