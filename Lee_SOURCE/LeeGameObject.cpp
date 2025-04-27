#include "Commonlnclude.h" // 이거 필수임
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
		
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));//색상
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush);//원레 색상을 oldBrush에 저장 후 색상 적용

		Rectangle(mHdc, 100 + mx, 100 + my, 200 + mx, 200 + my); //사각형

		(HBRUSH)SelectObject(mHdc, oldBrush); // oldBrush를 불러와 다시 휜색 적용
		DeleteObject(brush);//API에서 제공되는 delete 사용 파랑 삭제
	}
}
