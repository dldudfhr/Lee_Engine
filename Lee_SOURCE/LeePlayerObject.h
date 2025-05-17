#pragma once
#include "Commonlnclude.h" // 이거 필수
#include "Lee_Time.h"

namespace lee {
	class Player_Object
	{
	public:
		Player_Object();
		~Player_Object();

		void Updata();
		void LateUdata();
		void Render(HDC mHdc);
	private:
		float mSpeed;
		float mx;
		float my;
	};
}

