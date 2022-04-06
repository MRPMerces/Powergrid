#include "stage3.h"

//Stage 3, buy cities.
void stage3() {

	//Stage loop
	for (Player& player : players) {

		uiStage3(player);

		// Player is ai
		if (player.get_playerType() == Ai) {
			aiBuyCities(player);
			/// if (P.get_money() > 99) aiBuyCentrifuges(P);
		}

		// Player is human
		else {

			int city, buyCentrifuges;

			// Buying cities
			std::cout << "How many cities do you want do buy?" << std::endl;

			std::cin >> city;
			buyCities(player, city);

			uiStage3(player);

			// Buying centrifuges
			if (player.get_money() >= 100) {
				std::cout << "How many centrifuges do you want do buy?" << std::endl;
				std::cin >> buyCentrifuges;
				player.add_centrifuges(buyCentrifuges);
				player.add_money(-(buyCentrifuges * 100));
			}
		}

		// Era 2 trigger
		if (player.get_numberOfCities() >= 7 && game.get_era() == 1) {
			game.set_eraChange(true);
			std::cout << "Step 2 is triggered!" << std::endl;
		}

		// winCondition
		if (player.get_numberOfCities() >= 17) {
			game.set_winCondition(true);
			std::cout << "Wincondition!" << std::endl;
		}
	}

	system("CLS");
}

void buyCities(Player& player, int buyCities) {
	for (int i = 0; i < buyCities; i++) {

		if (game.get_tier3City() == 0) {
			std::cout << "There is no cities left!" << std::endl;
			break;
		}

		if (game.get_tier1City() > 0 && player.get_money() >= 10) {
			player.add_money(-10);
			player.add_cities(1);
			game.set_tier1City(-1);
			break;
		}

		if (game.get_tier2City() > 0 && game.get_era() > 1 && player.get_money() >= 15) {
			player.add_money(-15);
			player.add_cities(1);
			game.set_tier2City(-1);
			break;
		}

		if (game.get_tier3City() > 0 && game.get_era() == 3 && player.get_money() >= 20) {
			player.add_money(-20);
			player.add_cities(1);
			game.set_tier3City(-1);
			break;
		}

		std::cout << player.get_name() << " You don't have enough money to buy more cities!" << std::endl;
		break;
	}
}
