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
			HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));//색상
			HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush);//원레 색상을 oldBrush에 저장 후 색상 적용

			Rectangle(mHdc, 1200 + mx, 600 + my, 1300 + mx, 700 + my); //사각형

			(HBRUSH)SelectObject(mHdc, oldBrush); // oldBrush를 불러와 다시 휜색 적용
			DeleteObject(brush);//API에서 제공되는 delete 사용 파랑 삭제
		}
		if (a == 1) {
			HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));//색상
			HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush);//원레 색상을 oldBrush에 저장 후 색상 적용

			Rectangle(mHdc, 100 + mx, 100 + my, 200 + mx, 200 + my); //사각형

			(HBRUSH)SelectObject(mHdc, oldBrush); // oldBrush를 불러와 다시 휜색 적용
			DeleteObject(brush);//API에서 제공되는 delete 사용 파랑 삭제
		}
	}
}
