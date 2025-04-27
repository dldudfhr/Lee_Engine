#pragma once

namespace lee {
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void setPosition(float, float);
		float GetPositionX();
		float GetPositionY();
	private:
		float mx;
		float my;
	};
}

