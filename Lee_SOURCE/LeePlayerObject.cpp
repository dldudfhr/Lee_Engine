#include "LeePlayerObject.h"
#include "LeeInPut.h"

namespace lee {
	Player_Object::Player_Object() : mx{ 0 }, my{ 0 }, mSpeed{ 0.00f }
	{
	}

	Player_Object::~Player_Object()
	{
	}
	


	void Player_Object::Updata(int a)
	{
		if (a == 0) {
			mSpeed = 0.01f;
			if (InPut::GetKey(eKeyCode::Left)) {
				mx -= mSpeed;
			}
			if (InPut::GetKey(eKeyCode::Right)) {
				mx += mSpeed;
			}
			if (InPut::GetKey(eKeyCode::Up)) {
				my -= mSpeed;
			}
			if (InPut::GetKey(eKeyCode::Down)) {
				my += mSpeed;
			}
			
		}
		if (a == 1) {
			mSpeed = 0.01f;
			if (InPut::GetKey(eKeyCode::A)) {
				mx -= mSpeed;
			}
			if (InPut::GetKey(eKeyCode::D)) {
				mx += mSpeed;
			}
			if (InPut::GetKey(eKeyCode::W)) {
				my -= mSpeed;
			}
			if (InPut::GetKey(eKeyCode::S)) {
				my += mSpeed;
			}
			
		}


		//my += mSpeed;
	}

	void Player_Object::LateUdata()
	{
	}

	void Player_Object::Render(HDC mHdc, int a)
	{
		if (a == 0) {
			HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));//����
			HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush);//���� ������ oldBrush�� ���� �� ���� ����

			Rectangle(mHdc, 1200 + mx, 600 + my, 1300 + mx, 700 + my); //�簢��

			(HBRUSH)SelectObject(mHdc, oldBrush); // oldBrush�� �ҷ��� �ٽ� �ػ� ����
			DeleteObject(brush);//API���� �����Ǵ� delete ��� �Ķ� ����
		}
		if (a == 1) {
			HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));//����
			HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush);//���� ������ oldBrush�� ���� �� ���� ����

			Rectangle(mHdc, 100 + mx, 100 + my, 200 + mx, 200 + my); //�簢��

			(HBRUSH)SelectObject(mHdc, oldBrush); // oldBrush�� �ҷ��� �ٽ� �ػ� ����
			DeleteObject(brush);//API���� �����Ǵ� delete ��� �Ķ� ����
		}
	}
}
