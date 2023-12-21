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
	}

	/* IDEA MAKE IT A MULTIPLAYER GAME. PLAYER 1 USES KEYBOARD, PLAYER 2 USES AWSD */
	void OnKeyPress(const omg::KeyPressed& e) {

		/* PLAYER 1 MOVEMENTS */
		if (e.GetKeyCode() == OMEGA_KEY_RIGHT) {
			if (check_Xbounds_right(player1, player1_speed))
				player1.UpdateXCoord(player1_speed);
		}
		else if (e.GetKeyCode() == OMEGA_KEY_LEFT)
		{
			if (check_Xbounds_left(player1, player1_speed))
				player1.UpdateXCoord(0 - player1_speed);
		}
		else if (e.GetKeyCode() == OMEGA_KEY_UP) {
			if (check_Ybounds_top(player1, player1_speed))
				player1.UpdateYCoord(player1_speed);
		}
		else if (e.GetKeyCode() == OMEGA_KEY_DOWN) {
			if (check_Ybounds_bottom(player1, player1_speed))
				player1.UpdateYCoord(0 - player1_speed);
		}
		/* PLAYER 2 MOVEMENTS BELOW */
		else if (e.GetKeyCode() == OMEGA_KEY_D) {
			if (check_Xbounds_right(player2, player2_speed))
				player2.UpdateXCoord(player2_speed);
		}
		else if (e.GetKeyCode() == OMEGA_KEY_A) {
			if (check_Xbounds_left(player2, player2_speed))
				player2.UpdateXCoord(0 - player2_speed);
		}
		else if (e.GetKeyCode() == OMEGA_KEY_W) {
			if (check_Ybounds_top(player2, player2_speed))
				player2.UpdateYCoord(player2_speed);
		}
		else if (e.GetKeyCode() == OMEGA_KEY_S) {
			if (check_Ybounds_bottom(player2, player2_speed))
				player2.UpdateYCoord(0 - player2_speed);
		}
	}

	/* function that is used to check if we are going out of bounds of the screen on the left x coordinate */
	bool check_Xbounds_left(omg::Unit& player, int speed) {
		/* if we can still have a valid movement to the left */
		if (player.GetXCoord() - speed > -200)
			return true;
		else
			return false;
	}

	/* function that is used to check if we are going out of bounds of the screen on the right x coordinate */
	bool check_Xbounds_right(omg::Unit& player, int speed) {
		if (player.GetXCoord() + speed < 800)
			return true;
		else
			return false;
	}

	/* function that is used to check if we are going out of bounds of the screen on the bottom y coordinate */
	bool check_Ybounds_bottom(omg::Unit& player, int speed) {
		/* if we can still have a valid movement to the left */
		if (player.GetYCoord() - speed > -60)
			return true;
		else
			return false;
	}

	/* function that is used to check if we are going out of bounds of the screen on the upper y coordinate*/
	bool check_Ybounds_top(omg::Unit& player, int speed) {
		if (player.GetYCoord() + speed < 550)
			return true;
		else
			return false;
	}

	/* function that will check whether player1 has collided with player2*/
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

		/* use 2 iterations to confirm drawing for endgame screen has been rendered */
		if (secondIteration == 2) {
			std::chrono::seconds wait( 1 );
			std::this_thread::sleep_for( wait );
			mShouldContinue = false;
		}

		std::chrono::seconds wait( 1 );
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
	int player2_speed = 25;

	int x{ 100 };
	int y{ 100 };
};

OMEGA_APPLICATION_START(MyGame);