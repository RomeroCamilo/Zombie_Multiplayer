#include "Omega.h"
#include <iostream>


class MyGame : public omg::OmegaApp<MyGame> {

public:

	MyGame() {
		SetKeyPressedCallback([this](const omg::KeyPressed& e) {OnKeyPress(e);  });
	}
	
	virtual void OnUpdate() override {
		//std::cout << "Omega running." << std::endl;
		Draw(0, 0, background);

		Draw(player);
		Draw(enemy);

		//Draw(0, 500, mPic);
	}

	/* IDEA MAKE IT A MULTIPLAYER GAME. PLAYER 1 USES KEYBOARD, PLAYER 2 USES AWSD */
	
	void OnKeyPress(const omg::KeyPressed& e) {

		if (e.GetKeyCode() == OMEGA_KEY_RIGHT) {
			x += 50;
			player.UpdateXCoord(50);
		}
		else if (e.GetKeyCode() == OMEGA_KEY_LEFT)
			//x -= 50;
			player.UpdateXCoord(-50);
		else if (e.GetKeyCode() == OMEGA_KEY_UP)
			player.UpdateYCoord(50);
			//y += 50;
		else if (e.GetKeyCode() == OMEGA_KEY_DOWN)
			player.UpdateYCoord(-50);
			//y -= 50;
		else if (e.GetKeyCode() == OMEGA_KEY_D)
			//x -= 50;
			enemy.UpdateXCoord(50);
		else if (e.GetKeyCode() == OMEGA_KEY_A)
			//x -= 50;
			enemy.UpdateXCoord(-50);
		else if (e.GetKeyCode() == OMEGA_KEY_W)
			enemy.UpdateYCoord(50);
		//y += 50;
		else if (e.GetKeyCode() == OMEGA_KEY_S)
			enemy.UpdateYCoord(-50);;
		//y -= 50;
		
	}
	
	

private:
	omg::Picture mPic{ "../Assets/Pictures/zombiee.png" };
	omg::Picture background{"../Assets/Pictures/background.png" };
	omg::Unit player{ "../Assets/Pictures/test2.png", 0, 500 };
	omg::Unit enemy { "../Assets/Pictures/zombiee.png",0, 500 };

	int x{ 100 };
	int y{ 100 };
};

OMEGA_APPLICATION_START(MyGame);