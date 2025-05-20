#include "Lee_Application.h"
#include "LeeInPut.h"


namespace lee {
	Application::Application() : mHwnd{ nullptr }
		,mHdc{ nullptr }
		,mWidth(0)
		,mHeight(0)
		,mBackHdc(nullptr)
		,mBackBitmap(nullptr)
	{
	}
	Application::~Application() {}

	void Application::Initialize(HWND hwnd, UINT width, UINT height) 
		//HWND는 포인터 자료형이기에 복사되어 넘어간것이 아닌 주소가 넘어감
		//창 가로 세로 크기 받음
	{
		mHwnd = hwnd; //핸들 초기화
		mHdc = GetDC(hwnd);//GetDC에 핸들넣으면 HDC형으로 반환


		RECT rect = {0, 0, width, height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		//윈도우 해상도에 맞는 백버퍼 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, mWidth, mHeight);

		//백버퍼를 가르킬 Dc 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldTitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);

		DeleteObject(oldTitmap);


		InPut::Initailize(); //최초 1번만 하면 되기때문
		Time::Initialize();
	}

	void Application::Run() 
	{
		Updata();
		LateUpdata();
		Render();
		

	}

	void Application::Updata() 
	{
		InPut::Updata();
		Time::Updata();
		player.Updata();
	}

	void Application::LateUpdata()
	{

	}

	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, 1600, 900);

		player.Render(mBackHdc);
		Time::Render(mBackHdc);

		//
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}