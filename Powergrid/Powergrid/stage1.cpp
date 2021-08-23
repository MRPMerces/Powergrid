#include "stage1.h"

int passed;
int raisePriceOfPlant;
int mostPowerfullPowerplant = 0;
int priceOfPlant;

bool choosedPlant;
bool auctioning;

std::vector <Player> vec_PlayerAuction;

// Stage 1 buyPowerplant
void stage1() {

	choosePowerPlant();

	// Sets all Player.passed to false
	for (Player& P : vec_Player) P.set_passed(false);

	passed = 0;

	system("CLS");
}

void powerplantMarked() {

	// Repopulate thePowerplant marked whith Powerplants acording to the era
	if (game.get_era() != 3) {
		while (vec_powerplantMarked.size() < 8) {
			vec_powerplantMarked.push_back(vec_Powerplant[0]);
			vec_Powerplant.erase(vec_Powerplant.begin());
		}
	}

	else {
		while (vec_powerplantMarked.size() < 6) {
			vec_powerplantMarked.push_back(vec_Powerplant[0]);
			vec_Powerplant.erase(vec_Powerplant.begin());
		}
	}

	// Sort vec_powerplantMarked;
	sort(vec_powerplantMarked.begin(), vec_powerplantMarked.end());

	// Prints thePowerplant marked
	std::cout << textDivider << std::endl;
	std::cout << "Current market" << std::endl;

	for (int i = 0; i < 8; i++) {

		Powerplant PPM = vec_powerplantMarked[i];

		// Find somePowerplant stats
		if (i <= 3) if (PPM.get_citiesPowered() > vec_Powerplant[mostPowerfullPowerplant].get_citiesPowered()) mostPowerfullPowerplant = i;
		if (i == 4) std::cout << "Future market" << std::endl;

		// era 3 card
		if (PPM.get_plantId() == 0 && game.get_era() == 2) {
			game.set_eraChange(true);
			std::cout << "Era 3 is triggered!" << std::endl;
			vec_powerplantMarked.erase(vec_powerplantMarked.begin() + i);
		}

		std::cout << textDivider << std::endl;
		uiPlantInfo(PPM);
		std::cout << "Price of plant: " << PPM.get_plantId() << std::endl;
		std::cout << textDivider << std::endl;
	}
}

// Choosing a powerplanbt to auction
void choosePowerPlant() {

	int cin_powerPlantChoose;

	while (passed < vec_Player.size()) for (Player& P : vec_Player) if (!P.get_passed()) {

		powerplantMarked();

		// Chech if player have enough money
		if (P.get_money() < vec_powerplantMarked[0].get_plantId()) {
			system("CLS");
			std::cout << P.get_name() << " You dont have enouth money to buy a plant!" << std::endl;
			P.set_passed(true);
			passed++;
			break;
		}

		// Tell auction that the player can raise by 0
		choosedPlant = true;

		// Player is ai
		if (P.get_playerType() == Ai) auction(mostPowerfullPowerplant);
		///{  int aiChoosePowerplant( int mostPowerfullPowerplant); }

		// Player is human
		else {
			std::cout << "Player money: " << P.get_money() << std::endl;
			std::cout << "Player name: " << P.get_name() << std::endl;

			std::cout << "Which Powerplant do you want do buy? 0 for pass!" << std::endl;
			std::cin >> cin_powerPlantChoose;

			if (cin_powerPlantChoose == 0) {

				// Player cant bid again if passed
				P.set_passed(true);
				passed++;
			}

			/// 4 has to be a variable when era 3 ( all 6Powerplant are avalible) is triggered / implemented
			else for (int i = 0; i < 4; i++) {
				if (cin_powerPlantChoose == vec_powerplantMarked[i].get_plantId()) {
					auction(i);
					break;
				}

				// get_plantId() other than the 4 in the current market was chosen
				if (i == 3) {
					std::cout << "Bad plant id" << std::endl;
					choosePowerPlant();
				}
			}
		}
	}
}

// Auction
void auction(int choosenPlant) {

	Powerplant CPP = vec_powerplantMarked[choosenPlant];
	vec_PlayerAuction = vec_Player;

	priceOfPlant = CPP.get_plantId();

	auctioning = true;

	std::cout << "Auction for plant: " << CPP.get_plantId() << std::endl;

	while (auctioning) {

		int deltaPriceOfPlant = priceOfPlant;

		// Check if player can partake in auction and then remove the player if they cant
		for (int p = 0; p < vec_PlayerAuction.size(); p++)
			if (vec_PlayerAuction[p].get_money() < priceOfPlant || vec_PlayerAuction[p].get_passed())
				vec_PlayerAuction.erase(vec_PlayerAuction.begin() + p);

		for (int p = 0; p < vec_PlayerAuction.size(); p++) {

			Player PA = vec_PlayerAuction[p];

			// There are more players than 1 left in the auction
			if (vec_PlayerAuction.size() > 1) {
				std::cout << "Player name: " << PA.get_name() << std::endl;

				// Chech if player is a ai
				if (PA.get_playerType() == Ai && !choosedPlant) aiAuction(PA, CPP.get_plantId(), priceOfPlant);
				else if (PA.get_playerType() == Ai && choosedPlant) raisePriceOfPlant = 0;

				// If not ai then player is human
				else {

					// If the player has choosed the plant, they can raise by 0
					if (choosedPlant) std::cout << "By how much do you want to raise?" << std::endl;
					else std::cout << "By how much do you want to raise? 0 for pass" << std::endl;

					std::cin >> raisePriceOfPlant;
				}

				// Remove player from auction if "pass"
				if (raisePriceOfPlant == 0 && !choosedPlant) {
					vec_PlayerAuction.erase(vec_PlayerAuction.begin() + p);
					std::cout << PA.get_name() << " Passed!" << std::endl;
				}

				// Chech if player have enough money
				if (vec_Player[p].get_money() < priceOfPlant + raisePriceOfPlant) {
					std::cout << "You dont have enough money for this!" << std::endl;
					priceOfPlant += vec_Player[p].get_money();
				}

				else priceOfPlant += raisePriceOfPlant;
				std::cout << PA.get_name() << " Raised by: " << priceOfPlant - deltaPriceOfPlant << "!" << std::endl;

				choosedPlant = false;
			}
			// Only 1 player is left in the auction
			else for (Player& P : vec_Player) if (vec_PlayerAuction[0].get_name() == P.get_name()) wonAuction(P, CPP, choosenPlant);
		}
	}
}

// Player won the auction
void wonAuction(Player& P, Powerplant& CPP, int choosenPlant) {

	// Adds selectedPowerplant to player
	P.add_playerPowerplant(CPP);
	P.sort_playerPowerplant();

	// Removes selectedPowerplant fromPowerplant marked
	vec_powerplantMarked.erase(vec_powerplantMarked.begin() + choosenPlant);

	system("CLS");

	std::cout << P.get_name() << "You bougth thePowerplant for: " << priceOfPlant << " money" << std::endl;

	// Deducts price of selectedPowerplant, from player money
	P.add_money(-priceOfPlant);

	// Player cant bid again
	P.set_passed(true);
	passed++;

	// Discard 1 plant if player has more than 3 plants.
	if (P.get_vec_playerPowerplant().size() > 3) {

		// Player is ai
		if (P.get_playerType() == Ai)
			/// aiDiscardPowerplant(Player & P);
			;

		// Player is human
		else discardPowerplant(P);
	}

	// Exits auction
	auctioning = false;
}

void discardPowerplant(Player& P) {

	int cin_discardPowerplant;

	std::cout << "You need to discard 1 Powerplant!" << std::endl;

	// Prints player-Powerplant
	for (Powerplant& PPP : P.get_vec_playerPowerplant()) {
		uiPlantInfo(PPP);
	}

	// Chech if player is a ai
	if (P.get_playerType() == Ai) aiDiscardPowerplant(P);

	std::cin >> cin_discardPowerplant;

	for (int i = 0; i < P.get_vec_playerPowerplant().size(); i++) {

		Powerplant PPP = P.get_vec_playerPowerplant()[i];

		if (cin_discardPowerplant == PPP.get_plantId()) {
			std::cout << "Powerplant: " << PPP.get_plantId() << "has been discarded!" << std::endl;
			P.remove_playerPowerplant(i);
		}
	}
}
