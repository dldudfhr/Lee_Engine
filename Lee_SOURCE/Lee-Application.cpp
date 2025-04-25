#include "Lee_Application.h"

namespace lee {
	Application::Application() : mHwnd{ nullptr }, 
		mHdc{ nullptr }, 
		mSpeed{0.0f},
		mx{0},
		my{0}
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
		mSpeed = 0.01f;
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			mx -= mSpeed;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			mx += mSpeed;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			my -= mSpeed;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			my += mSpeed;
		}
		
		
		//my += mSpeed;
	}

	void Application::LateUpdata()
	{

	}

	void Application::Render()
	{
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));//색상
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush);//원레 색상을 oldBrush에 저장 후 색상 적용

		Rectangle(mHdc, 100 + mx, 100 + my, 200 + mx, 200 + my); //사각형

		(HBRUSH)SelectObject(mHdc, oldBrush); // oldBrush를 불러와 다시 휜색 적용
		DeleteObject(brush);//API에서 제공되는 delete 사용 파랑 삭제
	}
}