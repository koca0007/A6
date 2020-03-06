#include "Game.h"


namespace GameDev2D
{
	Game::Game() 
		
	{
		LoadTexture("Tank");

		m_Tank = new Tank();
	}

	Game::~Game()
	{
        if (m_Tank != nullptr)
        {
            delete m_Tank;
            m_Tank = nullptr;
        }

        UnloadTexture("Tank");
	}

	void Game::Update(double delta)
	{
		//Handle the tank's turret controls
		float turretAngularVelocity = 0.0f;
		if (IsKeyDown(Keyboard::Comma) == true)
		{
			turretAngularVelocity += TURRET_ANGULAR_SPEED;
		}
		if (IsKeyDown(Keyboard::Period) == true)
		{
			turretAngularVelocity -= TURRET_ANGULAR_SPEED;
		}
		m_Tank->SetTurretAngularVelocity(turretAngularVelocity);

		//Handle the tank's speed controls
		float speed = m_Tank->GetSpeed();
		
        float drag = 0.0f;
		if (IsKeyDown(Keyboard::Up) == true && IsKeyDown(Keyboard::Down) == false)
		{
			speed += TANK_ACCELERATION * delta;
            if (speed > TANK_MAX_SPEED)
            {
                speed = TANK_MAX_SPEED;
            }
		}
		else if (IsKeyDown(Keyboard::Down) == true && IsKeyDown(Keyboard::Up) == false)
		{
			speed -= TANK_ACCELERATION * delta;
            if (speed < -TANK_MAX_SPEED)
            {
                speed = -TANK_MAX_SPEED;
            }
		}
        else if (IsKeyDown(Keyboard::Down) == false && IsKeyDown(Keyboard::Up) == false)
        {
            drag = TANK_DRAG;
        }

        m_Tank->SetSpeed(speed);
        m_Tank->SetDrag(drag);

		//Handle the tank's rotation controls
		float angularVelocity = 0.0f;
		if (IsKeyDown(Keyboard::Left) == true)
		{
			angularVelocity += TANK_ANGULAR_SPEED;
		}
		if (IsKeyDown(Keyboard::Right) == true)
		{
			angularVelocity -= TANK_ANGULAR_SPEED;
		}

        float speedRation = speed / TANK_MAX_SPEED;
		m_Tank->SetAngularVelocity(angularVelocity * speedRation);

		
		
		
		

		//Update the Tank
		m_Tank->Update(delta);
	}

	void Game::Draw()
	{
		m_Tank->Draw();
	}

	void Game::HandleLeftMouseClick(float aMouseX, float aMouseY)
	{
	
	}

	void Game::HandleRightMouseClick(float aMouseX, float aMouseY)
	{

	}

	void Game::HandleMouseMove(float aMouseX, float aMouseY, float aPreviousX, float aPreviousY)
	{
		
	}

	void Game::HandleKeyPress(Keyboard::Key aKey)
	{
  
	}
}