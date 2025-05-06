#pragma once
#include "Commonlnclude.h"
#include "LeePlayerObject.h"

namespace lee {

	class Application
	{
	public:
		Application();
		~Application();
		void Initialize(HWND);//�̴ϼȶ�����
		void Run(int);

		void Updata(int);
		void LateUpdata();
		void Render(int);//�������� �׸��� ���

	private:
		HWND mHwnd;
		HDC mHdc;
		
		Player_Object player;
		
	};

}