#include "stage1.h"

int raisePriceOfPlant;
int priceOfPlant;

Player playerChoosedPlant;

std::vector <Player> playerAuction;
std::vector <Player> passedPlayers;
std::vector <Player> playersInAuction; // New passedplayers

// Stage 1 buy Powerplant
void stage1() {
	playersInAuction = players;
	while (passedPlayers.size() < players.size()) {
		processPowerplantMarked();
		choosePowerPlant();
	}

	passedPlayers.clear();
	system("CLS");
}

void processPowerplantMarked() {
	// Repopulate the Powerplant marked whith Powerplants acording to the era
	while (game.powerplantMarked.size() < (game.get_era() != 3 ? 8 : 6)) {
		game.powerplantMarked.push_back(game.powerplants[0]);
		game.powerplants.erase(game.powerplants.begin());
	}

	// Sort the PowerplantMarked from lowest to highest plant id
	sort(game.powerplantMarked.begin(), game.powerplantMarked.end());

	// Prints the Powerplant marked
	std::cout << textDivider << std::endl;
	std::cout << "Current market" << std::endl;

	for (int i = 0; i < 8; i++) {
		Powerplant powerplant = game.powerplantMarked[i];
		if (i == 4) {
			std::cout << "Future market" << std::endl;
		}

		// Era 3 card
		if (powerplant.get_plantId() == 0 && game.get_era() == 2) {
			game.set_eraChange(true);
			std::cout << "Era 3 is triggered!" << std::endl;
			game.powerplantMarked.erase(game.powerplantMarked.begin() + i);
		}

		std::cout << textDivider << std::endl;
		uiPlantInfo(powerplant);
		std::cout << "Price of plant: " << powerplant.get_plantId() << std::endl;
		std::cout << textDivider << std::endl;
	}
}

// Choosing a powerplant to auction
void choosePowerPlant() {
	for (std::vector<Player>::iterator player = playersInAuction.begin(); player != playersInAuction.end(); player++) {
		// Chech if player have enough money
		if (player->get_money() < game.powerplantMarked[0].get_plantId()) {
			system("CLS");
			std::cout << player->get_name() << " You dont have enouth money to buy a plant!" << std::endl;
			playersInAuction.erase(player);
			continue;
		}

		// Tell auction that the player can raise by 0
		playerChoosedPlant = *player;

		// Player is ai
		if (player->get_playerType() == Ai) {
			ai_auctionstage1();
			return;
		}
		// Player is human

		std::cout << "Player money: " << player->get_money() << std::endl;
		std::cout << "Player name: " << player->get_name() << std::endl;

		std::cout << "Which Powerplant do you want do buy? 0 for pass!" << std::endl;
		int chosenPlantID;
		std::cin >> chosenPlantID;

		// Player cant bid again if passed.
		if (chosenPlantID == 0) {
			playersInAuction.erase(player);
			player->passed = true;
			continue;
		}

		for (int i = 0; i < (game.get_era() == 3 ? 4 : 6); i++) {
			if (chosenPlantID == game.powerplantMarked[i].get_plantId()) {
				auction(game.powerplantMarked[i]);

				// Removes selected Powerplant from Powerplant marked.
				game.powerplantMarked.erase(game.powerplantMarked.begin() + i);

				processPowerplantMarked();
				break;
			}

			// A different plant id was chosen than the once in the current market.
			if (i == (game.get_era() == 3 ? 4 : 6)) {
				std::cout << "Bad plant id" << std::endl;
				choosePowerPlant();
			}
		}
	}
}

void auction(Powerplant& choosenPowerplant) {
	playerAuction = players;

	priceOfPlant = choosenPowerplant.get_plantId();

	std::cout << "Auction for plant: " << choosenPowerplant.get_plantId() << std::endl;

	// Check if player can partake in auction and then remove the player if they cant
	for (int i = 0; i < playerAuction.size(); i++) {
		/// Unsafe?
		if (playerAuction[i].get_money() < priceOfPlant || (std::find(passedPlayers.begin(), passedPlayers.end(), playerAuction[i]) != passedPlayers.end())) {
			playerAuction.erase(playerAuction.begin() + i);
			playerAuction[i].passed = true;
			i--;
		}
	}

	bool auctioning = true;
	while (auctioning) {
		int deltaPriceOfPlant = priceOfPlant;

		for (std::vector<Player>::iterator currentPlayer = playersInAuction.begin(); currentPlayer != playersInAuction.end(); currentPlayer++) {

			// Only 1 player is left in the auction
			if (playersInAuction.size() == 1) {
				wonAuction(playersInAuction[0], choosenPowerplant);
				playersInAuction.clear();
				break;
				auctioning = false;
			}

			// There are more players than 1 left in the auction
			std::cout << "Player name: " << currentPlayer->get_name() << std::endl;

			// Chech if player is a ai
			if (currentPlayer->get_playerType() == Ai) {
				if (currentPlayer->get_name() == playerChoosedPlant.get_name()) {
					raisePriceOfPlant = 0;
				}
				else {
					aiAuction(*currentPlayer, choosenPowerplant.get_plantId(), priceOfPlant);
				}
			}

			// If not ai then player is human
			else {
				// If the player has choosed the plant, they can raise by 0
				if (*currentPlayer == playerChoosedPlant) {
					std::cout << "By how much do you want to raise?" << std::endl;
					std::cin >> raisePriceOfPlant;
				}

				else {
					std::cout << "By how much do you want to raise? 0 for pass" << std::endl;
					std::cin >> raisePriceOfPlant;

					// Remove player from auction if "pass"
					if (raisePriceOfPlant == 0) {
						playerAuction.erase(currentPlayer);
						std::cout << currentPlayer->get_name() << " Passed!" << std::endl;
						continue;
					}
				}
			}

			// Chech if player have enough money
			if (currentPlayer->get_money() < priceOfPlant + raisePriceOfPlant) {
				std::cout << "You dont have enough money for this!" << std::endl;
				priceOfPlant += currentPlayer->get_money();
			}

			else {
				priceOfPlant += raisePriceOfPlant;
			}

			std::cout << currentPlayer->get_name() << " Raised by: " << priceOfPlant - deltaPriceOfPlant << "!" << std::endl;
		}
	}
}

// Player won the auction
void wonAuction(Player& player, Powerplant& powerplant) {
	// Adds selectedPowerplant to player
	player.add_playerPowerplant(powerplant);

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
		else {
			discardPowerplant(player);

		}
	}
}

void discardPowerplant(Player& P) {
	// Chech if player is a ai
	if (P.get_playerType() == Ai) {
		aiDiscardPowerplant(P);
		return;
	}

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
