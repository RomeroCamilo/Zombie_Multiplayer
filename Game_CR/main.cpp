#include "Omega.h"
#include <iostream>


class MyGame : public omg::OmegaApp<MyGame> {

	public:
		virtual void OnUpdate() override {
			std::cout << "Omega running." << std::endl;
		}
};

OMEGA_APPLICATION_START(MyGame);