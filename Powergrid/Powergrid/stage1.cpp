#include "stage1.h"

int passed;
int raisePriceOfPlant;
int mostPowerfullPowerplant = 0;
int priceOfPlant;

bool choosedPlant;
bool auctioning;

std::vector <Player> playerAuction;

// Stage 1 buyPowerplant
void stage1() {

	choosePowerPlant();

	// Sets all Player.passed to false
	for (Player& P : players) {
		P.set_passed(false);
	}

	passed = 0;

	system("CLS");
}

void processPowerplantMarked() {
	// Repopulate thePowerplant marked whith Powerplants acording to the era
	while (powerplantMarked.size() < game.get_era() != 3 ? 8 : 6) {
		powerplantMarked.push_back(powerplants[0]);
		powerplants.erase(powerplants.begin());
	}

	// Sort vec_powerplantMarked;
	sort(powerplantMarked.begin(), powerplantMarked.end());

	// Prints the Powerplant marked
	std::cout << textDivider << std::endl;
	std::cout << "Current market" << std::endl;

	for (int i = 0; i < 8; i++) {
		Powerplant powerplant = powerplantMarked[i];

		// Find somePowerplant stats
		if (i <= 3 && powerplant.get_citiesPowered() > powerplants[mostPowerfullPowerplant].get_citiesPowered()) {
			mostPowerfullPowerplant = i;
		}

		if (i == 4) {
			std::cout << "Future market" << std::endl;
		}

		// era 3 card
		if (powerplant.get_plantId() == 0 && game.get_era() == 2) {
			game.set_eraChange(true);
			std::cout << "Era 3 is triggered!" << std::endl;
			powerplantMarked.erase(powerplantMarked.begin() + i);
		}

		std::cout << textDivider << std::endl;
		uiPlantInfo(powerplant);
		std::cout << "Price of plant: " << powerplant.get_plantId() << std::endl;
		std::cout << textDivider << std::endl;
	}
}

// Choosing a powerplanbt to auction
void choosePowerPlant() {
	int chosenPlantID;

	while (passed < players.size()) {
		for (Player& P : players) {
			if (!P.get_passed()) {

				processPowerplantMarked();

				// Chech if player have enough money
				if (P.get_money() < powerplantMarked[0].get_plantId()) {
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
					std::cin >> chosenPlantID;

					if (chosenPlantID == 0) {
						// Player cant bid again if passed
						P.set_passed(true);
						passed++;
					}

					/// 4 has to be a variable when era 3 ( all 6Powerplant are avalible) is triggered / implemented
					else {
						for (int i = 0; i < 4; i++) {
							if (chosenPlantID == powerplantMarked[i].get_plantId()) {
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
		}
	}
}

void auction(int choosenPlantID) {
	Powerplant powerplant = powerplantMarked[choosenPlantID];
	playerAuction = players;

	priceOfPlant = powerplant.get_plantId();

	auctioning = true;

	std::cout << "Auction for plant: " << powerplant.get_plantId() << std::endl;

	while (auctioning) {
		int deltaPriceOfPlant = priceOfPlant;

		// Check if player can partake in auction and then remove the player if they cant
		for (int i = 0; i < playerAuction.size(); i++) {
			if (playerAuction[i].get_money() < priceOfPlant || playerAuction[i].get_passed()) {
				playerAuction.erase(playerAuction.begin() + i);
			}
		}

		for (int i = 0; i < playerAuction.size(); i++) {
			Player player = playerAuction[i];

			// There are more players than 1 left in the auction
			if (playerAuction.size() > 1) {
				std::cout << "Player name: " << player.get_name() << std::endl;

				// Chech if player is a ai
				if (player.get_playerType() == Ai && !choosedPlant) {
					if (choosedPlant) {
						raisePriceOfPlant = 0;
					}
					else {
						aiAuction(player, powerplant.get_plantId(), priceOfPlant);
					}
				}

				// If not ai then player is human
				else {
					// If the player has choosed the plant, they can raise by 0
					if (choosedPlant) {
						std::cout << "By how much do you want to raise?" << std::endl;
					}

					else {
						std::cout << "By how much do you want to raise? 0 for pass" << std::endl;
					}

					std::cin >> raisePriceOfPlant;
				}

				// Remove player from auction if "pass"
				if (raisePriceOfPlant == 0 && !choosedPlant) {
					playerAuction.erase(playerAuction.begin() + i);
					std::cout << player.get_name() << " Passed!" << std::endl;
				}

				// Chech if player have enough money
				if (players[i].get_money() < priceOfPlant + raisePriceOfPlant) {
					std::cout << "You dont have enough money for this!" << std::endl;
					priceOfPlant += players[i].get_money();
				}

				else {
					priceOfPlant += raisePriceOfPlant;
				}
				std::cout << player.get_name() << " Raised by: " << priceOfPlant - deltaPriceOfPlant << "!" << std::endl;

				choosedPlant = false;
			}

			// Only 1 player is left in the auction
			else {
				for (Player& P : players) {
					if (playerAuction[0].get_name() == P.get_name()) {
						wonAuction(P, powerplant, choosenPlantID);
					}
				}
			}
		}
	}
}

// Player won the auction
void wonAuction(Player& player, Powerplant& powerplant, int choosenPlantID) {
	// Adds selectedPowerplant to player
	player.add_playerPowerplant(powerplant);
	player.sort_playerPowerplant();

	// Removes selected Powerplant from Powerplant marked
	powerplantMarked.erase(powerplantMarked.begin() + choosenPlantID);

	system("CLS");

	std::cout << player.get_name() << "You bougth thePowerplant for: " << priceOfPlant << " money" << std::endl;

	// Deducts price of selectedPowerplant, from player money
	player.add_money(-priceOfPlant);

	// Player cant bid again
	player.set_passed(true);
	passed++;

	// Discard 1 plant if player has more than 3 plants.
	if (player.get_playerPowerplants().size() > 3) {

		// Player is ai
		if (player.get_playerType() == Ai)
			/// aiDiscardPowerplant(Player & P);
			;

		// Player is human
		else discardPowerplant(player);
	}

	// Exits auction
	auctioning = false;
}

void discardPowerplant(Player& P) {
	// Chech if player is a ai
	if (P.get_playerType() == Ai) {
		aiDiscardPowerplant(P);
	}

	else {
		int discardPowerplantID;

		std::cout << "You need to discard 1 Powerplant!" << std::endl;

		// Prints player-Powerplant
		for (Powerplant& powerplant : P.get_playerPowerplants()) {
			uiPlantInfo(powerplant);
		}

		std::cin >> discardPowerplantID;

		for (int i = 0; i < P.get_playerPowerplants().size(); i++) {
			Powerplant powerplant = P.get_playerPowerplants()[i];

			if (discardPowerplantID == powerplant.get_plantId()) {
				std::cout << "Powerplant: " << powerplant.get_plantId() << "has been discarded!" << std::endl;
				P.remove_playerPowerplant(i);
			}
		}
	}
}
