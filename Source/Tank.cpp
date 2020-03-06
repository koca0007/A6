#include "Tank.h"


namespace GameDev2D
{
	Tank::Tank() : Drawable() 
		
	{
		//Create the 'Tank' Sprite object
		m_Body = new SpriteAtlas("Tank");
        m_Body->UseFrame("Body");
		m_Body->SetAnchor(Vector2(0.5f, 0.5f));

		//Create the 'Turret' Sprite object
		m_Turret = new SpriteAtlas("Tank");
        m_Turret->UseFrame("Turret");
		m_Turret->SetAnchor(Vector2(0.2f, 0.5f));

		m_Shell = new SpriteAtlas("Tank");
		m_Shell->UseFrame("Shell");
		m_Shell->SetAnchor(Vector2(0.5f, 0.5f));

		//Initialize the rest of the member variables
		m_Speed = 0.0f;
        m_Drag = 0.0f;
		m_AngularVelocity = 0.0f;
		m_TurretAngle = 0.0f;
		m_TurretAngularVelocity = 0.0f;
		
		m_Shell->SetDirection(m_Turret->GetDirection());
		isEnabled = false;
		 
	}

	Tank::~Tank()
	{
        if (m_Body != nullptr)
        {
            delete m_Body;
            m_Body = nullptr;
        }

        if (m_Turret != nullptr)
        {
            delete m_Turret;
            m_Turret = nullptr;
        }

		if (m_Shell != nullptr)
		{
			delete m_Shell;
			m_Shell = nullptr;
		}
	}

	void Tank::Update(double aDelta)
	{
		//Rotate the tank
		float angleIncrement = m_AngularVelocity * aDelta;
		SetDegrees(GetDegrees() + angleIncrement);
		m_Body->SetDegrees(GetDegrees());

		//Rotate the turret
		m_TurretAngle += m_TurretAngularVelocity * aDelta;
		m_Turret->SetDegrees(GetDegrees() + m_TurretAngle);

		//Move the tank
		Vector2 direction = GetDirection();
		Vector2 linearVelocity = direction * GetSpeed();
		Vector2 increment = linearVelocity * aDelta;
		SetPosition(GetPosition() + increment);
		m_Body->SetPosition(GetPosition());
		m_Turret->SetPosition(GetPosition());
		
	
		
		

        //Apply drag
        float drag = 1.0f - m_Drag;
        m_Speed *= drag;
        if (m_Speed < 1.25f && m_Drag > 0.0f)
        {
            m_Speed = 0.0f;
        }

		Vector2 turretPosition = m_Turret->GetPosition();

		
		
		/*m_Shell->SetPosition(m_Shell->GetPosition() + shellLinearVelocity);*/
		float posX = turretPosition.x + cosf(m_Turret->GetRadians()) * MAGNITUDE;
		float posY = turretPosition.y + sinf(m_Turret->GetRadians()) * MAGNITUDE;
		
		
		Vector2 shellDirection = m_Shell->GetDirection();
		Vector2 shellLinearVelocity = shellDirection * 1000.0f;
		Vector2 shellIncrement = shellLinearVelocity * aDelta;
		Vector2 position = m_Shell->GetPosition();
		m_Shell->SetPosition(m_Shell->GetPosition() + shellIncrement);
		
		float screenWidth = GetScreenWidth();

		if (IsKeyDown(Keyboard::Spacebar) == true)
		{
			isEnabled = true;
			m_Shell->SetPosition(Vector2(posX, posY));
			m_Shell->SetDirection(m_Turret->GetDirection());
			
		}
		
		if (position.x >= 1280.0f || position.x <= 0.0f || position.y >= 720.0f || position.y <= 0.0f) {
			isEnabled = false;
		}
			
	
		
	}

	void Tank::Draw()
	{
		m_Body->Draw();
		m_Turret->Draw();

		if (isEnabled) {
			m_Shell->Draw();
		}
	}

	float Tank::GetWidth()
	{
		float s = fabsf(sinf(GetRadians()) * m_Body->GetHeight());
		float c = fabsf(cosf(GetRadians()) * m_Body->GetWidth());
		return s + c;
	}

	float Tank::GetHeight()
	{
		float s = fabsf(sinf(GetRadians()) * m_Body->GetWidth());
		float c = fabsf(cosf(GetRadians()) * m_Body->GetHeight());
		return s + c;
	}

	void Tank::SetSpeed(float aSpeed)
	{
		m_Speed = aSpeed;
	}

	float Tank::GetSpeed()
	{
		return m_Speed;
	}

    void Tank::SetDrag(float drag)
    {
        m_Drag = drag;
    }

    float Tank::GetDrag()
    {
        return m_Drag;
    }

	void Tank::SetAngularVelocity(float aAngularVelocity)
	{
		m_AngularVelocity = aAngularVelocity;
	}

	float Tank::GetAngularVelocity()
	{
		return m_AngularVelocity;
	}

	void Tank::SetTurretAngularVelocity(float aTurretAngularVelocity)
	{
		m_TurretAngularVelocity = aTurretAngularVelocity;
	}

	float Tank::GetTurretAngularVelocity()
	{
		return m_TurretAngularVelocity;
	}

	
}