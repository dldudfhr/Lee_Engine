#include "Lee_Application.h"
#include "LeeInPut.h"


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
		InPut::Initailize(); //최초 1번만 하면 되기때문
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