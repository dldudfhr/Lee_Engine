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
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));//����
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush);//���� ������ oldBrush�� ���� �� ���� ����

		Rectangle(mHdc, 100 + mx, 100 + my, 200 + mx, 200 + my); //�簢��

		(HBRUSH)SelectObject(mHdc, oldBrush); // oldBrush�� �ҷ��� �ٽ� �ػ� ����
		DeleteObject(brush);//API���� �����Ǵ� delete ��� �Ķ� ����
	}
}