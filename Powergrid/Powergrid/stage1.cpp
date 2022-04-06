#include "stage1.h"

int raisePriceOfPlant;
int mostPowerfullPowerplant = 0;
int priceOfPlant;

Player playerChoosedPlant;

std::vector <Player> playerAuction;
std::vector <Player> passedPlayers;

// Stage 1 buyPowerplant
void stage1() {
	while (passedPlayers.size() < players.size()) {
		choosePowerPlant();
	}

	passedPlayers.clear();
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

		// Find some Powerplant stats
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
	for (Player& player : players) {
		if (!(std::find(passedPlayers.begin(), passedPlayers.end(), player) != passedPlayers.end())) {

			// Chech if player have enough money
			if (player.get_money() < powerplantMarked[0].get_plantId()) {
				system("CLS");
				std::cout << player.get_name() << " You dont have enouth money to buy a plant!" << std::endl;
				passedPlayers.push_back(player);
				continue;
			}

			// Tell auction that the player can raise by 0
			playerChoosedPlant = player;

			// Player is ai
			if (player.get_playerType() == Ai) {
				auction(mostPowerfullPowerplant);
				return;
			}

			// Player is human
			std::cout << "Player money: " << player.get_money() << std::endl;
			std::cout << "Player name: " << player.get_name() << std::endl;

			std::cout << "Which Powerplant do you want do buy? 0 for pass!" << std::endl;
			int chosenPlantID;
			std::cin >> chosenPlantID;

			// Player cant bid again if passed
			if (chosenPlantID == 0) {
				passedPlayers.push_back(player);
				continue;
			}

			for (int i = 0; i < game.get_era() == 3 ? 4 : 6; i++) {
				if (chosenPlantID == powerplantMarked[i].get_plantId()) {
					auction(powerplantMarked[i]);

					// Removes selected Powerplant from Powerplant marked
					powerplantMarked.erase(powerplantMarked.begin() + i);

					processPowerplantMarked();
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

void auction(Powerplant& choosenPowerplant) {
	playerAuction = players;

	priceOfPlant = choosenPowerplant.get_plantId();

	std::cout << "Auction for plant: " << choosenPowerplant.get_plantId() << std::endl;

	// Check if player can partake in auction and then remove the player if they cant
	for (std::vector<Player>::iterator player = playerAuction.begin(); player != playerAuction.end(); player++) {
		if (player->get_money() < priceOfPlant || (std::find(passedPlayers.begin(), passedPlayers.end(), player) != passedPlayers.end())) {
			playerAuction.erase(player);
			player--;
		}
	}

	bool auctioning = true;
	while (auctioning) {
		int deltaPriceOfPlant = priceOfPlant;

		for (std::vector<Player>::iterator player = playerAuction.begin(); player != playerAuction.end(); player++) {

			// There are more players than 1 left in the auction
			if (playerAuction.size() > 1) {
				std::cout << "Player name: " << player->get_name() << std::endl;

				// Chech if player is a ai
				if (player->get_playerType() == Ai) {
					if (player->get_name() == playerChoosedPlant.get_name()) {
						raisePriceOfPlant = 0;
					}
					else {
						aiAuction(*player, choosenPowerplant.get_plantId(), priceOfPlant);
					}
				}

				// If not ai then player is human
				else {
					// If the player has choosed the plant, they can raise by 0
					if (player->get_name() == playerChoosedPlant.get_name()) {
						std::cout << "By how much do you want to raise?" << std::endl;
					}

					else {
						std::cout << "By how much do you want to raise? 0 for pass" << std::endl;
					}

					std::cin >> raisePriceOfPlant;
				}

				// Remove player from auction if "pass"
				if (raisePriceOfPlant == 0 && player->get_name() != playerChoosedPlant.get_name()) {
					playerAuction.erase(player);
					std::cout << player->get_name() << " Passed!" << std::endl;
					player--;
					continue;
				}

				// Chech if player have enough money
				if (player->get_money() < priceOfPlant + raisePriceOfPlant) {
					std::cout << "You dont have enough money for this!" << std::endl;
					priceOfPlant += player->get_money();
				}

				else {
					priceOfPlant += raisePriceOfPlant;
				}
				std::cout << player->get_name() << " Raised by: " << priceOfPlant - deltaPriceOfPlant << "!" << std::endl;
			}

			// Only 1 player is left in the auction
			else {
				wonAuction(playerAuction[0], choosenPowerplant);
				auctioning = false;
			}
		}
	}
}

// Player won the auction
void wonAuction(Player& player, Powerplant& powerplant) {
	// Adds selectedPowerplant to player
	player.add_playerPowerplant(powerplant);
	player.sort_playerPowerplant();

	system("CLS");

	std::cout << player.get_name() << "You bougth thePowerplant for: " << priceOfPlant << " money" << std::endl;

	// Deducts price of selectedPowerplant, from player money
	player.add_money(-priceOfPlant);

	// Player cant bid again
	passedPlayers.push_back(player);

	// Discard 1 plant if player has more than 3 plants.
	if (player.get_playerPowerplants().size() > 3) {

		// Player is ai
		if (player.get_playerType() == Ai)
			/// aiDiscardPowerplant(Player & P);
			;

		// Player is human
		else discardPowerplant(player);
	}
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
