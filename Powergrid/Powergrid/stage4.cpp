#include "stage4.h"

// Stage 4, get money
void stage4() {

	// Stage loop
	for (Player& player : players) {
		uiStage4(player);
		powerPowerplant(player);

		std::cout << "You powered: " << player.get_citiesPowered() << "cities!" << std::endl;

		// Add power money to player
		player.add_money(player.get_citiesPowered() * 20);
	}

	winCondition();
	update();
	system("CLS");
}

// Power playerPowerplant
void powerPowerplant(Player& player) {
	char powerPowerPlant;

	for (Powerplant& powerplant : player.get_playerPowerplants()) {

		// Check if player has enough fuel to power the powerplant
		if (player.get_fuel(powerplant.get_FuelType()) < powerplant.get_fuelUsage()) {
			continue;
		}

		// Player is ai
		/// if (P.playerType == "ai") aiPowerPowerplant(P);
		if (player.get_playerType() == Ai) {
			powerPowerPlant = 'y';
		}

		// Player is human
		else {
			uiPlantInfo(powerplant);
			std::cout << "Do you want to power thisPowerplant? y/n" << std::endl;

			std::cin >> powerPowerPlant;
		}

		switch (powerPowerPlant)
		{
		case 'y':
			// Find the FuelType
			if (powerplant.get_FuelType() == Wind) {
				std::cout << "This plant is powered by the free wind!" << std::endl;
			}

			else if (powerplant.get_FuelType() == Hybrid) {
				int coal;

				std::cout << "How much coal do you want to use? The rest will be oil!" << std::endl;
				std::cin >> coal;

				// Check if input is greater that the fuel usage
				if (coal > powerplant.get_fuelUsage()) {
					coal = powerplant.get_fuelUsage();
				}

				player.add_fuel(Coal, -coal);
				player.add_fuel(Oil, coal - powerplant.get_fuelUsage());
			}

			else player.add_fuel(powerplant.get_FuelType(), powerplant.get_fuelUsage());

			player.add_citiesPowered(powerplant.get_citiesPowered());

		case 'n':
			break;

		default:
			std::cout << "You typed in something invalid" << std::endl;
		}
	}
}

// Wincondition
void winCondition() {
	if (game.get_winCondition()) {
		int mostCitiesPowered = 0;

		Player pos;

		for (Player player : players) {
			if (mostCitiesPowered < player.get_citiesPowered()) {
				mostCitiesPowered = player.get_citiesPowered();
				pos = player;
			}

			// Tie
			if (mostCitiesPowered == player.get_citiesPowered() && player.get_money() > pos.get_money()) {
				mostCitiesPowered = player.get_citiesPowered();
				pos = player;
			}
		}
		system("CLS");
		std::cout << pos.get_name() << "Have won the game!" << std::endl;;
	}
}

//Update gamestats
void update() {

	//Change era
	if (game.get_eraChange()) {
		game.increment_era();
		game.set_eraChange(false);
	}

	//Add resources based on era
	if (game.get_era() == 1) {
		game.add_coal(4);
		game.add_uranium(1);
	}

	else if (game.get_era() == 2) {
		game.add_coal(6);
		game.add_uranium(2);
	}

	else if (game.get_era() == 3) {
		game.add_coal(5);
		game.add_uranium(2);
	}

	// Draw a new_powerplant card fromPowerplant deck
	if (game.get_era() < 3) {
		powerplants.push_back(powerplantMarked[powerplantMarked.size() - 1]);
		powerplantMarked.erase(powerplantMarked.begin());
		powerplantMarked.push_back(powerplants[0]);
		powerplants.erase(powerplants.begin());
	}

	// if era = 3 the weakestPowerplant will be erased
	if (game.get_era() == 3) {
		powerplantMarked.erase(powerplants.begin());
		powerplantMarked.push_back(powerplants[0]);
	}

	// Find turnorder;
	sort(players.begin(), players.end(), comparator);
}
