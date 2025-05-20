#include "Lee_Time.h"
namespace lee
{
	LARGE_INTEGER Time::CpuFrequency = {}; // ���� ������
	LARGE_INTEGER Time::PrevFrequency = {}; // ����������
	LARGE_INTEGER Time::CurrentFrequency = {}; // ����������
	float Time::DeltaTime = 0.0f;

	void Time::Initialize()
	{
		//����������
		QueryPerformanceFrequency(&CpuFrequency);
		//���α׷��� ���������� ������
		QueryPerformanceCounter(&PrevFrequency);
	}
	void Time::Updata()
	{
		//���� ������
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

		wchar_t str[50] = L"";  //���ͷ�
		swprintf_s(str, 50, L"fps : %d", (int)fps);
		int len = wcsnlen_s(str, 50); // ���ڿ� ����

		TextOut(hdc, 0, 0, str, len);
	}
}
