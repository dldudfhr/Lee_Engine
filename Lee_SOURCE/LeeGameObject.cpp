#include "Commonlnclude.h" // �̰� �ʼ���
#include "LeeGameObject.h"
#include "Lee_Application.h"

namespace lee {
	GameObject::GameObject() : mx{ 0 }, my{ 0 }, mSpeed{ 0.00f }
	{
	}

	GameObject::~GameObject()
	{
	}


	void GameObject::Updata()
	{
		float x = mx;
		float y = my;
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

	void GameObject::LateUdata()
	{
	}

	void GameObject::Render(HDC mHdc)
	{
		
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));//����
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush);//���� ������ oldBrush�� ���� �� ���� ����

		Rectangle(mHdc, 100 + mx, 100 + my, 200 + mx, 200 + my); //�簢��

		(HBRUSH)SelectObject(mHdc, oldBrush); // oldBrush�� �ҷ��� �ٽ� �ػ� ����
		DeleteObject(brush);//API���� �����Ǵ� delete ��� �Ķ� ����
	}
}
