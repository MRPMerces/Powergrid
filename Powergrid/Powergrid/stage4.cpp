#include "stage4.h"

// Stage 4, get money
void stage4() {

	// Stage loop
	for (Player& P : vec_Player) {
		uiStage4(P);
		powerPowerplant(P);

		std::cout << "You powered: " << P.get_citiesPowered() << "cities!" << std::endl;

		// Add power money to player
		P.add_money(P.get_citiesPowered() * 20);
	}
	winCondition();
	update();
	system("CLS");
}

// Power playerPowerplant
void powerPowerplant(Player& P) {

	char cin_powerPowerPlant;

	for (Powerplant& PPP : P.get_vec_playerPowerplant()) {

		// Check if player has enough fuel to power the powerplant
		if (P.get_fuel(PPP.get_FuelType()) < PPP.get_fuelUsage()) continue;

		// Player is ai
		/// if (P.playerType == "ai") aiPowerPowerplant(P);
		if (P.get_playerType() == Ai) cin_powerPowerPlant = 'y';

		// Player is human
		else {
			uiPlantInfo(PPP);
			std::cout << "Do you want to power thisPowerplant? y/n" << std::endl;

			std::cin >> cin_powerPowerPlant;
		}

		if (cin_powerPowerPlant == 'y') {
			// Find the FuelType
			if (PPP.get_FuelType() == Wind) std::cout << "This plant is powered by the free wind!" << std::endl;
			if (PPP.get_FuelType() == Hybrid) {
				int cin_hybrid;

				std::cout << "How much Coalplant do you want to use? The rest will be oil!" << std::endl;
				std::cin >> cin_hybrid;

				// Check if input is greater that the fuel usage
				if (cin_hybrid > PPP.get_fuelUsage()) cin_hybrid = PPP.get_fuelUsage();
				P.add_fuel(Coal, -cin_hybrid);
				P.add_fuel(Oil, cin_hybrid - PPP.get_fuelUsage());
			}

			else P.add_fuel(PPP.get_FuelType(), PPP.get_fuelUsage() );

			P.add_citiesPowered(PPP.get_citiesPowered());
		}
		else if (cin_powerPowerPlant == 'n');
		else std::cout << "You typed in something invalid" << std::endl;
	}
}

// Wincondition
void winCondition() {
	if (game.get_winCondition()) {
		int mostCitiesPowered = 0;

		Player pos;

		for (Player& P : vec_Player) {
			if (mostCitiesPowered < P.get_citiesPowered()) {
				mostCitiesPowered = P.get_citiesPowered();
				pos = P;
			}

			// Tie
			if (mostCitiesPowered == P.get_citiesPowered()) if (P.get_money() > pos.get_money()) {
				mostCitiesPowered = P.get_citiesPowered();
				pos = P;
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

	if (game.get_era() == 2) {
		game.add_coal(6);
		game.add_uranium(2);
	}

	if (game.get_era() == 3) {
		game.add_coal(5);
		game.add_uranium(2);
	}

	// Draw a new_powerplant card fromPowerplant deck
	if (game.get_era() < 3) {
		vec_Powerplant.push_back(vec_powerplantMarked[vec_powerplantMarked.size() - 1]);
		vec_powerplantMarked.erase(vec_powerplantMarked.begin());
		vec_powerplantMarked.push_back(vec_Powerplant[0]);
		vec_Powerplant.erase(vec_Powerplant.begin());
	}

	// if era = 3 the weakestPowerplant will be erased
	if (game.get_era() == 3) {
		vec_powerplantMarked.erase(vec_Powerplant.begin());
		vec_powerplantMarked.push_back(vec_Powerplant[0]);
	}

	// Find turnorder;
	sort(vec_Player.begin(), vec_Player.end(), comparator);
}
