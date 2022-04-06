#include "stage2.h"

//Stage 2, buy fuel.
void stage2() {

	//Stage loop
	for (Player& player : players) {

		updatePlayerInfo();
		uiStage2(player);
		buyResources(player);
	}

	system("CLS");
}

void buyResources(Player& player) {

	// Player is ai
	if (player.get_playerType() == Ai) {
		aiBuyFuel(player);
		return;
	}

	int coal, oil, garbage, uranium;

	std::cout << "You can store: " << player.get_fuelStorage(Coal) << " Coalplant" << std::endl;
	std::cout << "How much Coal do you want do buy?" << std::endl;
	std::cin >> coal;
	buyCoal(player, coal);

	// Update ui
	uiStage2(player);

	std::cout << "You can store: " << player.get_fuelStorage(Oil) << " oil" << std::endl;
	std::cout << "How much oil do you want do buy?" << std::endl;
	std::cin >> oil;
	buyOil(player, oil);

	// Update ui
	uiStage2(player);

	std::cout << "You can store: " << player.get_fuelStorage(Garbage) << " garbage" << std::endl;
	std::cout << "How much garbage do you want do buy?" << std::endl;
	std::cin >> garbage;
	buyGarbage(player, garbage);

	// Update ui
	uiStage2(player);

	std::cout << "You can store: " << player.get_fuelStorage(Uranium) << " uranium" << std::endl;
	std::cout << "How much uranium do you want do buy?" << std::endl;
	std::cin >> uranium;
	buyUranium(player, uranium);

	// Update ui
	uiStage2(player);
}

void buyCoal(Player& player, int coal) {
	for (int i = 0; i < coal; i++) {

		// Check if player can store more fuel
		if (player.get_fuel(Coal) == player.get_fuelStorage(Coal)) {
			std::cout << "You cant store more Coal!" << std::endl;
			break;
		}

		// Check if there is no coal left
		if (game.get_amountOfCoal() == 0) {
			std::cout << "There is no coal left" << std::endl;
			break;
		}

		// Check if player can afford more coal
		if (player.get_money() < ceil(game.get_amountOfCoal() / 3) - 9) {
			std::cout << "You can't afford more Coal!" << std::endl;
			break;
		}

		player.add_money(ceil(game.get_amountOfCoal() / 3) - 9);
		game.add_coal(-1);
		player.add_fuel(Coal, 1);
	}
}

void buyOil(Player& player, int oil) {
	for (int i = 0; i < oil; i++) {

		// Check if player can store more fuel
		if (player.get_fuel(Oil) == player.get_fuelStorage(Oil)) {
			std::cout << "You cant store more oil!" << std::endl;
			break;
		}

		// Check if there is no oil left
		if (game.get_amountOfOil() == 0) {
			std::cout << "There is no oil left" << std::endl;
			break;
		}

		// Check if player can afford more oil
		if (player.get_money() < ceil(game.get_amountOfOil() / 3) - 9) {
			std::cout << "You can't afford more oil!" << std::endl;
			break;
		}

		player.add_money(ceil(game.get_amountOfOil() / 3) - 9);
		game.add_oil(-1);
		player.add_fuel(Oil, 1);
	}
}

void buyGarbage(Player& player, int garbage) {
	for (int i = 0; i < garbage; i++) {

		// Check if player can store more fuel
		if (player.get_fuel(Garbage) == player.get_fuelStorage(Garbage)) {
			std::cout << "You cant store more garbage!" << std::endl;
			break;
		}

		// Check if there is no garbage left
		if (game.get_amountOfGarbage() == 0) {
			std::cout << "There is no garbage left" << std::endl;
			break;
		}

		// Check if player can afford more garbage
		if (player.get_money() < ceil(game.get_amountOfGarbage() / 3) - 9) {
			std::cout << "You cant afford more garbage!" << std::endl;
			break;
		}

		player.add_money(ceil(game.get_amountOfGarbage() / 3) - 9);
		game.add_garbage(-1);
		player.add_fuel(Garbage, 1);
	}
}

// Buy uranium.
void buyUranium(Player& player, int uranium) {

	for (int i = 0; i < uranium; i++) {

		int price = 0;

		// Check if player can store more uranium
		if (player.get_fuel(Uranium) == player.get_fuelStorage(Uranium)) {
			std::cout << "You cant store more uranium!" << std::endl;
			break;
		}

		switch (game.get_amountOfUranium()) {
		case 0:
			std::cout << "There is no uranium left" << std::endl;
			break;

		case 1:
			price = 16;

		case 2:
			price = 14;

		case 3:
			price = 12;

		case 4:
			price = 10;

		case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
			price = 13 - game.get_amountOfUranium();
		}

		// Check if player can afford more uranium
		if (player.get_money() < price) {
			std::cout << "You can't afford more uranium!" << std::endl;
			break;
		}

		game.add_uranium(-price);
		player.add_fuel(Uranium, 1);
	}

	// Each centrifuge produces 1 uranium per turn.
	if (player.get_centrifuges() > 0) {
		std::cout << player.get_name() << " You got: " << player.get_centrifuges() << "Uranium from centrifuges" << std::endl;
		player.add_fuel(Uranium, player.get_centrifuges());
	}
}
