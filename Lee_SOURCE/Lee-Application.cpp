#include "Lee_Application.h"

namespace lee {
	Application::Application() : mHwnd{ nullptr }, 
		mHdc{ nullptr }
	{
	}
	Application::~Application() {}

	void Application::Initialize(HWND hwnd) //HWND�� ������ �ڷ����̱⿡
											//���ڵǾ� �Ѿ���� �ƴ� �ּҰ� �Ѿ
	{
		mHwnd = hwnd; //�ڵ� �ʱ�ȭ
		mHdc = GetDC(hwnd);//GetDC�� �ڵ������ HDC������ ��ȯ
	}

	void Application::Run() 
	{
		Updata();
		LateUpdata();
		Render();

	}

	void Application::Updata() 
	{
		player.Updata();
	}

	void Application::LateUpdata()
	{

	}

	void Application::Render()
	{
		player.Render(mHdc);
	}
}