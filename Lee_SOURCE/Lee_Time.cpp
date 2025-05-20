#include "Lee_Time.h"
namespace lee
{
	LARGE_INTEGER Time::CpuFrequency = {}; // 고유 진동수
	LARGE_INTEGER Time::PrevFrequency = {}; // 이전진동수
	LARGE_INTEGER Time::CurrentFrequency = {}; // 현재진동수
	float Time::DeltaTime = 0.0f;

	void Time::Initialize()
	{
		//고유진동수
		QueryPerformanceFrequency(&CpuFrequency);
		//프로그램이 시작했을때 진동수
		QueryPerformanceCounter(&PrevFrequency);
	}
	void Time::Updata()
	{
		//현재 진동수
		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency
			= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		DeltaTime = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);

		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;

	}
	void Time::Render(HDC hdc)
	{
		float fps = 0.0f;

		fps = 1 / DeltaTime;

		wchar_t str[50] = L"";  //리터럴
		swprintf_s(str, 50, L"fps : %d", (int)fps);
		int len = wcsnlen_s(str, 50); // 문자열 길이

		TextOut(hdc, 0, 0, str, len);
	}
}
