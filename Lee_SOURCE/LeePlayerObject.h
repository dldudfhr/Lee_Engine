#pragma once
#include "Commonlnclude.h" // �̰� �ʼ�

namespace lee {
	class Player_Object
	{
	public:
		Player_Object();
		~Player_Object();

		void Updata(int);
		void LateUdata();
		void Render(HDC mHdc, int);
	private:
		float mSpeed;
		float mx;
		float my;
	};
}

