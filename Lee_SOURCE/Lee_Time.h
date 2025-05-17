#pragma once
#include "Commonlnclude.h"
// (현제진동수 - 이전진동수) / 고유진동수 = 1바퀴 도는 시간
// 1 / 1바퀴 도는시간 = 프레임
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
		static LARGE_INTEGER CpuFrequency; // 고유 진동수
		static LARGE_INTEGER PrevFrequency; // 이전진동수
		static LARGE_INTEGER CurrentFrequency; // 현재진동수
		
		static float DeltaTime;
	};
}

