#pragma once
#include "Commonlnclude.h"

namespace lee {

	class Application
	{
	public:
		Application();
		~Application();
		void Initialize(HWND);//�̴ϼȶ�����
		void Run();

		void Updata();
		void LateUpdata();
		void Render();//�������� �׸��� ���

	private:
		HWND mHwnd;
		HDC mHdc;
		float mx;
		float my;
		float mSpeed;
		
	};

}