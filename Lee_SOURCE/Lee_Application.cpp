#include "Lee_Application.h"
#include "LeeInPut.h"


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
		player.Render(mHdc);
		Time::Render(mHdc);
	}
}