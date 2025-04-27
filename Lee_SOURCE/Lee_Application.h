#pragma once
#include "Commonlnclude.h"
#include "LeeGameObject.h"

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
		
		float mSpeed;

		//float mx;
		//float my;
		GameObject player;
		
	};

}