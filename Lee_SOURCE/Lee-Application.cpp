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
	}

	void Application::Run(int a) 
	{
		Updata(a);
		LateUpdata();
		Render(a);

	}

	void Application::Updata(int a) 
	{
		InPut::Updata();
		player.Updata(a);
	}

	void Application::LateUpdata()
	{

	}

	void Application::Render(int a)
	{
		player.Render(mHdc, a);
	}
}