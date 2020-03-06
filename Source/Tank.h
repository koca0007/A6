#pragma once

#include <GameDev2D.h>
#include "Constants.h"

namespace GameDev2D
{
	class Tank : public Drawable
	{
	public:
		Tank();
		~Tank();

		void Update(double delta);
		void Draw();

		float GetWidth();
		float GetHeight();

		void SetSpeed(float speed);
		float GetSpeed();

        void SetDrag(float drag);
        float GetDrag();

		void SetAngularVelocity(float angularVelocity);
		float GetAngularVelocity();

		void SetTurretAngularVelocity(float turretAngularVelocity);
		float GetTurretAngularVelocity();

	private:
		SpriteAtlas* m_Body;
        SpriteAtlas* m_Turret;
		SpriteAtlas* m_Shell;
		float m_Speed;
        float m_Drag;
		float m_AngularVelocity;
		float m_TurretAngle;
		float shellVelocity;
		float m_TurretAngularVelocity;
		bool isEnabled;
		SpriteFont* m_Label;
	};
}