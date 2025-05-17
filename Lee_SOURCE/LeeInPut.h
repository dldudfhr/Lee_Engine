#pragma once
#include "Commonlnclude.h"

namespace lee {
	enum class eKeyState {
		Down,
		Pressed,
		Up,
		None,
	};
	enum class eKeyCode {
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Up, Down,
		End,
	};
	class InPut
	{
	public:
		struct key {
			eKeyCode KeyCode;
			eKeyState state;
			bool bPressed;
		};
		static void Initailize();
		static void Updata();

		static bool GetKeyDown(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Down;}
		static bool GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Up;}
		static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Pressed;}
	private:
		static void createKey();
		static void updataKey();
		static std::vector<key> mKeys;
	};
}

