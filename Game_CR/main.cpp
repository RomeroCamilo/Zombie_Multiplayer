#include "Omega.h"
#include <iostream>


class MyGame : public omg::OmegaApp<MyGame> {

public:

	MyGame() {
		SetKeyPressedCallback([this](const omg::KeyPressed& e) {OnKeyPress(e);  });
	}
	
	virtual void OnUpdate() override {
		std::cout << "Omega running." << std::endl;

		//Draw(x, y, mPic);

		Draw(mUnit);
	}

	
	void OnKeyPress(const omg::KeyPressed& e) {
		if (e.GetKeyCode() == OMEGA_KEY_RIGHT)
			//x += 50;
			mUnit.UpdateXCoord(50);
		else if (e.GetKeyCode() == OMEGA_KEY_LEFT)
			//x -= 50;
			mUnit.UpdateXCoord(-50);
		else if (e.GetKeyCode() == OMEGA_KEY_UP)
			mUnit.UpdateYCoord(50);
			//y += 50;
		else if (e.GetKeyCode() == OMEGA_KEY_DOWN)
			mUnit.UpdateYCoord(-50);
			//y -= 50;
		
	}
	
	

private:
	omg::Picture mPic{ "../Assets/Pictures/test2.png" };
	omg::Unit mUnit{ "../Assets/Pictures/test2.png", 100, 500 };

	int x{ 100 };
	int y{ 100 };
};

OMEGA_APPLICATION_START(MyGame);