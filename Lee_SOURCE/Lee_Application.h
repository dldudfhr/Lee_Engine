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
		void Initialize(HWND);//�̴ϼȶ�����
		void Run();

		void Updata();
		void LateUpdata();
		void Render();//�������� �׸��� ���

	private:
		HWND mHwnd;
		HDC mHdc;
		
		Player_Object player;
		
	};

}