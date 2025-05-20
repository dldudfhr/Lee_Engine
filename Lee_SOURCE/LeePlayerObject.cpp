#include "LeePlayerObject.h"
#include "LeeInPut.h"

namespace lee {
	Player_Object::Player_Object() : mx{ 0 }, my{ 0 }, mSpeed{ 0.00f }
	{
	}

	Player_Object::~Player_Object()
	{
	}
	


	void Player_Object::Updata()
	{
		mSpeed = 200.0f;
		if (InPut::GetKey(eKeyCode::A)) {
			mx -= mSpeed * Time::GetFps();
		}
		if (InPut::GetKey(eKeyCode::D)) {
			mx += mSpeed * Time::GetFps();
		}
		if (InPut::GetKey(eKeyCode::W)) {
			my -= mSpeed * Time::GetFps();
		}
		if (InPut::GetKey(eKeyCode::S)) {
			my += mSpeed * Time::GetFps();
		}
		//my += mSpeed;
	}

	void Player_Object::LateUdata()
	{
	}

	void Player_Object::Render(HDC mHdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));//����
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush);//���� ������ oldBrush�� ���� �� ���� ����

		Rectangle(mHdc, 100 + mx, 100 + my, 200 + mx, 200 + my); //�簢��

		(HBRUSH)SelectObject(mHdc, oldBrush); // oldBrush�� �ҷ��� �ٽ� �ػ� ����
		DeleteObject(brush);//API���� �����Ǵ� delete ��� �Ķ� ����
		
	}
}
