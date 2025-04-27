#include "Lee_Application.h"

namespace lee {
	Application::Application() : mHwnd{ nullptr }, 
		mHdc{ nullptr }
	{
	}
	Application::~Application() {}

	void Application::Initialize(HWND hwnd) //HWND는 포인터 자료형이기에
											//복자되어 넘어간것이 아닌 주소가 넘어감
	{
		mHwnd = hwnd; //핸들 초기화
		mHdc = GetDC(hwnd);//GetDC에 핸들넣으면 HDC형으로 반환
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