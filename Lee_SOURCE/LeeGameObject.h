#pragma once

namespace lee {
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Updata();
		void LateUdata();
		void Render(HDC mHdc);
	private:
		float mSpeed;
		float mx;
		float my;
	};
}

