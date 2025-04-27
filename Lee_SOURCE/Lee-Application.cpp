#include "Lee_Application.h"

namespace lee {
	Application::Application() : mHwnd{ nullptr }, 
		mHdc{ nullptr }, 
		mSpeed{0.0f}
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
		float x = player.GetPositionX();
		float y = player.GetPositionY();
		mSpeed = 0.01f;
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			x -= mSpeed;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			x += mSpeed;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			y -= mSpeed;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			y += mSpeed;
		}
		player.setPosition(x, y);
		
		//my += mSpeed;
	}

	void Application::LateUpdata()
	{

	}

	void Application::Render()
	{
		float x = player.GetPositionX();
		float y = player.GetPositionY();
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));//����
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush);//���� ������ oldBrush�� ���� �� ���� ����

		Rectangle(mHdc, 100 + x, 100 + y, 200 + x, 200 + y); //�簢��

		(HBRUSH)SelectObject(mHdc, oldBrush); // oldBrush�� �ҷ��� �ٽ� �ػ� ����
		DeleteObject(brush);//API���� �����Ǵ� delete ��� �Ķ� ����
	}
}