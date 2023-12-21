#include "pch.h"
#include "Game.h"

#include "InputManager.h"
#include "TimeManager.h"
#include "Graphics.h"

WPARAM Game::Run(GameDesc& _desc)
{
	m_Desc = _desc;
	assert(m_Desc.app != nullptr);

	//1) 윈도우 창 정보 등록
	MyRegisterClass();

	//2) 윈도우 창 생성
	if (!InitInstance(SW_SHOWNORMAL))
		return FALSE;

	InputManager::GetInstance()->Init(m_Desc.hwnd);
	TimeManager::GetInstance()->Initialize();
	Graphics::GetInstance()->Init(m_Desc.hwnd);

	m_Desc.app->Init();

	MSG msg = { 0 };

	while (msg.message != WM_QUIT)
	{
		if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}
		else
		{
			Update();
		}
	}

	return msg.wParam;
}

ATOM Game::MyRegisterClass()
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_Desc.hInstance;
	wcex.hIcon = ::LoadIcon(NULL, IDI_WINLOGO);
	wcex.hCursor = ::LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = m_Desc.appName.c_str();
	wcex.hIconSm = wcex.hIcon;

	return RegisterClassExW(&wcex);
}

BOOL Game::InitInstance(int _cmdShow)
{
	RECT windowRect = { 0, 0, m_Desc.width, m_Desc.height };
	::AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, false);

	m_Desc.hwnd = CreateWindowW(m_Desc.appName.c_str(), m_Desc.appName.c_str(), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, nullptr, nullptr, m_Desc.hInstance, nullptr);

	if (!m_Desc.hwnd)
		return FALSE;

	::ShowWindow(m_Desc.hwnd, _cmdShow);
	::UpdateWindow(m_Desc.hwnd);

	return TRUE;
}

LRESULT CALLBACK Game::WndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_SIZE:
		break;
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return ::DefWindowProc(handle, message, wParam, lParam);
	}
}

void Game::Update()
{
	TimeManager::GetInstance()->Update();
	InputManager::GetInstance()->Update();

	Graphics::GetInstance()->RenderBegin();

	m_Desc.app->Update();
	m_Desc.app->FixedUpdate();
	m_Desc.app->LateUpdate();
	m_Desc.app->Render();

	Graphics::GetInstance()->RenderEnd();
}