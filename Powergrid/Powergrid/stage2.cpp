#include "stage2.h"

//Stage 2, buy fuel.
void stage2() {

	//Stage loop
	for (Player& P : vec_Player) {

		updatePlayerInfo();
		uiStage2(P);
		buyResources(P);
	}

	system("CLS");
}

void buyResources(Player& P) {

	// Player is ai
	if (P.get_playerType() == Ai) {
		aiBuyFuel(P);
	}

	// Player is human
	else {
		int cin_buyCoalplant;
		int cin_buyOil;
		int cin_buyGarbage;
		int cin_buyUranium;

		std::cout << "You can store: " << P.get_fuelStorage(Coal) << " Coalplant" << std::endl;
		std::cout << "How much Coalplant do you want do buy?" << std::endl;
		std::cin >> cin_buyCoalplant;
		buyCoalplant(P, cin_buyCoalplant);

		// Update ui
		uiStage2(P);

		std::cout << "You can store: " << P.get_fuelStorage(Oil) << " oil" << std::endl;
		std::cout << "How much oil do you want do buy?" << std::endl;
		std::cin >> cin_buyOil;
		buyOil(P, cin_buyOil);

		// Update ui
		uiStage2(P);

		std::cout << "You can store: " << P.get_fuelStorage(Garbage) << " garbage" << std::endl;
		std::cout << "How much garbage do you want do buy?" << std::endl;
		std::cin >> cin_buyGarbage;
		buyGarbage(P, cin_buyGarbage);

		// Update ui
		uiStage2(P);

		std::cout << "You can store: " << P.get_fuelStorage(Uranium) << " uranium" << std::endl;
		std::cout << "How much uranium do you want do buy?" << std::endl;
		std::cin >> cin_buyUranium;
		buyUranium(P, cin_buyUranium);

		// Update ui
		uiStage2(P);
	}
}

// Buy Coalplant
void buyCoalplant(Player& P, int buyCoalplant) {

	for (int i = 0; i < buyCoalplant; i++) {

		// Check if player can store more fuel
		if (P.get_fuel(Coal) == P.get_fuelStorage(Coal)) {
			std::cout << "You cant store more Coal!" << std::endl;
			break;
		}

		// Check if there is no Coalplant left
		if (game.get_amountOfCoal() == 0) {
			std::cout << "There is no Coalplant left" << std::endl;
			break;
		}

		else {

			double Coalplant = game.get_amountOfCoal();

			// Check if player can afford more Coalplant
			if (P.get_money() < ceil(Coalplant / 3) - 9) {
				std::cout << "You can't afford more Coal!" << std::endl;
				break;
			}

			else {
				P.add_money(ceil(Coalplant / 3) - 9);
				game.add_coal(-1);
				P.add_fuel(Coal, 1);
			}
		}
	}
}

// Buy oil
void buyOil(Player& P, int buyOil) {

	for (int i = 0; i < buyOil; i++) {

		// Check if player can store more fuel
		if (P.get_fuel(Oil) == P.get_fuelStorage(Oil)) {
			std::cout << "You cant store more oil!" << std::endl;
			break;
		}

		// Check if there is no oil left
		if (game.get_amountOfOil() == 0) {
			std::cout << "There is no oil left" << std::endl;
			break;
		}

		else {

			double oil = game.get_amountOfOil();

			// Check if player can afford more oil
			if (P.get_money() < ceil(oil / 3) - 9) {
				std::cout << "You can't afford more oil!" << std::endl;
				break;
			}

			else {
				P.add_money(ceil(oil / 3) - 9);
				game.add_oil(-1);
				P.add_fuel(Oil, 1);
			}
		}
	}
}

// Buy garbage
void buyGarbage(Player& P, int buyGarbage) {

	for (int i = 0; i < buyGarbage; i++) {

		// Check if player can store more fuel
		if (P.get_fuel(Garbage) == P.get_fuelStorage(Garbage)) {
			std::cout << "You cant store more garbage!" << std::endl;
			break;
		}

		// Check if there is no garbage left
		if (game.get_amountOfGarbage() == 0) {
			std::cout << "There is no garbage left" << std::endl;
			break;
		}

		else {

			double garbage = game.get_amountOfGarbage();

			// Check if player can afford more garbage
			if (P.get_money() < ceil(garbage / 3) - 9) {
				std::cout << "You cant afford more garbage!" << std::endl;
				break;
			}

			else {
				P.add_money(ceil(garbage / 3) - 9);
				game.add_garbage(-1);
				P.add_fuel(Garbage, 1);
			}
		}
	}
}

// Buy uranium.
void buyUranium(Player& P, int buyUranium) {

	for (int i = 0; i < buyUranium; i++) {

		int setMoney = 0;

		// Check if player can store more uranium
		if (P.get_fuel(Uranium) == P.get_fuelStorage(Uranium)) {
			std::cout << "You cant store more uranium!" << std::endl;
			break;
		}

		switch (game.get_amountOfUranium()) {

		case 0:
		{
			std::cout << "There is no uranium left" << std::endl;
			break;
		}

		case 1: setMoney = 16;
		case 2: setMoney = 14;
		case 3: setMoney = 12;
		case 4: setMoney = 10;
		case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
			setMoney = 13 - game.get_amountOfUranium();
		}

		// Check if player can afford more uranium
		if (P.get_money() < setMoney) {
			std::cout << "You can't afford more uranium!" << std::endl;
			break;
		}

		game.add_uranium(-setMoney);
		P.add_fuel(Uranium, 1);
	}

	// Each centrifuge produces 1 uranium per turn.
	if (P.get_centrifuges() > 0) {
		std::cout << P.get_name() << " You got: " << P.get_centrifuges() << "Uranium from centrifuges" << std::endl;
		P.add_fuel(Uranium, P.get_centrifuges());
	}
}
