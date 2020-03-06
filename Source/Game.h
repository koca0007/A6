#pragma once

#include <GameDev2D.h>
#include "Tank.h"


namespace GameDev2D
{

	//Class definition
	class Game
	{
	public:
		Game();  //Constructor
		~Game(); //Destructor

		void Update(double delta);
		void Draw();

		void HandleLeftMouseClick(float mouseX, float mouseY);
		void HandleRightMouseClick(float mouseX, float mouseY);
		void HandleMouseMove(float mouseX, float mouseY, float previousX, float previousY);
		void HandleKeyPress(Keyboard::Key key);

	private:
		//Member variables
		Tank* m_Tank;
		
	};
}
