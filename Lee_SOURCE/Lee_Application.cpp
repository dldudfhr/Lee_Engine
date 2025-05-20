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
		//HWND�� ������ �ڷ����̱⿡ ����Ǿ� �Ѿ���� �ƴ� �ּҰ� �Ѿ
		//â ���� ���� ũ�� ����
	{
		mHwnd = hwnd; //�ڵ� �ʱ�ȭ
		mHdc = GetDC(hwnd);//GetDC�� �ڵ������ HDC������ ��ȯ


		RECT rect = {0, 0, width, height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		//������ �ػ󵵿� �´� ����� ����
		mBackBitmap = CreateCompatibleBitmap(mHdc, mWidth, mHeight);

		//����۸� ����ų Dc ����
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldTitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);

		DeleteObject(oldTitmap);


		InPut::Initailize(); //���� 1���� �ϸ� �Ǳ⶧��
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