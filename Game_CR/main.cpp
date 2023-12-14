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

		Draw(player1);
		Draw(player2);

		check_collision();

		if (collided == true) {
			handle_collision();
		}

		//Draw(0, 500, mPic);
	}

	/* IDEA MAKE IT A MULTIPLAYER GAME. PLAYER 1 USES KEYBOARD, PLAYER 2 USES AWSD */
	
	void OnKeyPress(const omg::KeyPressed& e) {

		if (e.GetKeyCode() == OMEGA_KEY_RIGHT)
			player1.UpdateXCoord( player1_speed);
		else if (e.GetKeyCode() == OMEGA_KEY_LEFT)
			player1.UpdateXCoord( 0 - player1_speed );
		else if (e.GetKeyCode() == OMEGA_KEY_UP)
			player1.UpdateYCoord( player1_speed );
		else if (e.GetKeyCode() == OMEGA_KEY_DOWN)
			player1.UpdateYCoord( 0 - player1_speed );
		else if (e.GetKeyCode() == OMEGA_KEY_D)
			player2.UpdateXCoord( player2_speed );
		else if (e.GetKeyCode() == OMEGA_KEY_A)
			player2.UpdateXCoord( 0 - player2_speed );
		else if (e.GetKeyCode() == OMEGA_KEY_W)
			player2.UpdateYCoord( player2_speed );
		else if (e.GetKeyCode() == OMEGA_KEY_S)
			player2.UpdateYCoord( 0 - player2_speed );;
		
	}

	/* function that will check whether player has collided with player2*/
	void check_collision() {
		if ((std::abs(player1.GetXCoord() - player2.GetXCoord()) <= 40 ) 
			&& (std::abs(player1.GetYCoord() - player2.GetYCoord()) <= 40 )) {
			collided = true;
		}
	}

	/* if both players collided, draw the end game screen and the game/program will then end in a couple seconds */
	void handle_collision() {

		secondIteration++;

		Draw(0, 0, gameOver);

		if (secondIteration == 2) {
			std::chrono::seconds wait( 2 );
			std::this_thread::sleep_for( wait );
			mShouldContinue = false;
		}

		std::chrono::microseconds wait( 500000 );
		std::this_thread::sleep_for(wait);
	}
	
	

private:
	omg::Picture mPic{ "../Assets/Pictures/zombiee.png" };
	omg::Picture background{"../Assets/Pictures/background.png" };
	omg::Picture gameOver{ "../Assets/Pictures/gameover2.png" };
	omg::Unit player1{ "../Assets/Pictures/character.png", 0, 0 };
	omg::Unit player2 { "../Assets/Pictures/zombiee.png",0, 500 };
	bool collided = false; /* storing whether player has collided with player 2 (zombie) */
	int secondIteration = 0; /* tracking if game over image fully loaded */
	int player1_speed = 55;
	int player2_speed = 30;

	int x{ 100 };
	int y{ 100 };
};

OMEGA_APPLICATION_START(MyGame);