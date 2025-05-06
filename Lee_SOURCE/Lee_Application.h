#pragma once
#include "Commonlnclude.h"
#include "LeePlayerObject.h"

namespace lee {

	class Application
	{
	public:
		Application();
		~Application();
		void Initialize(HWND);//이니셜라이즈
		void Run(int);

		void Updata(int);
		void LateUpdata();
		void Render(int);//랜더에서 그리기 사용

	private:
		HWND mHwnd;
		HDC mHdc;
		
		Player_Object player;
		
	};

}