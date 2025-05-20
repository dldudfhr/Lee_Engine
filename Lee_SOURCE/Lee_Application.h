#pragma once
#include "Commonlnclude.h"
#include "LeePlayerObject.h"
#include "Lee_Time.h"

namespace lee {

	class Application
	{
	public:
		Application();
		~Application();
		void Initialize(HWND, UINT, UINT);//이니셜라이즈
		void Run();

		void Updata();
		void LateUpdata();
		void Render();//랜더에서 그리기 사용

	private:
		HWND mHwnd;
		HDC mHdc;
		
		HDC mBackHdc;
		HBITMAP mBackBitmap;//핸들의 자료형

		UINT mWidth;
		UINT mHeight;

		Player_Object player;
		
	};

}