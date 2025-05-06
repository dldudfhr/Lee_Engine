#include "LeeInPut.h"

namespace lee {
	std::vector<InPut::key> InPut::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] = {
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN
	};

	void InPut::Initailize()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++) 
		{
			key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.KeyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}
	void InPut::Updata()
	{
		//����Ƽ�� ������ Ű �Է��� ����
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++) {//Ű�� ���Ǵ��� �ƴ���
			if (GetAsyncKeyState(ASCII[i]) & 0x8000) {
				if (mKeys[i].bPressed == true) {
					mKeys[i].state = eKeyState::Pressed;
				}
				else {
					mKeys[i].state = eKeyState::Down;
				}
				mKeys[i].bPressed = true;
			}
			else {//�ȴ���
				if (mKeys[i].bPressed == true) {
					mKeys[i].state = eKeyState::Up;
				}
				else {
					mKeys[i].state = eKeyState::None;
				}
			}
		}

	}
}
