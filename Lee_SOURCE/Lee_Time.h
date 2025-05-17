#pragma once
#include "Commonlnclude.h"
// (���������� - ����������) / ���������� = 1���� ���� �ð�
// 1 / 1���� ���½ð� = ������
namespace lee 
{
	class Time
	{
	public:
		static void Initialize();
		static void Updata();
		static void Render(HDC hdc);
		static float Fps;
		
	private:
		static LARGE_INTEGER CpuFrequency; // ���� ������
		static LARGE_INTEGER PrevFrequency; // ����������
		static LARGE_INTEGER CurrentFrequency; // ����������
		
		static float DeltaTime;
	};
}

