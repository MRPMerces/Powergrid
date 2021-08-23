#include "stage3.h"

//Stage 3, buy cities.
void stage3() {

	//Stage loop
	for (Player& P : vec_Player) {

		uiStage3(P);

		// Player is ai
		if (P.get_playerType() == Ai) {
			aiBuyCities(P);
			/// if (P.get_money() > 99) aiBuyCentrifuges(P);
		}

		// Player is human
		else {

			int
				cin_city,
				cin_buy_centrifuges;

			// Buying cities
			std::cout << "How many cities do you want do buy?" << std::endl;

			std::cin >> cin_city;
			buyCities(P, cin_city);

			uiStage3(P);

			// Buying centrifuges
			if (P.get_money() >= 100) {
				std::cout << "How many centrifuges do you want do buy?" << std::endl;
				std::cin >> cin_buy_centrifuges;
				P.add_centrifuges(cin_buy_centrifuges);
				P.add_money(-(cin_buy_centrifuges * 100));
			}
		}

		// Era 2 trigger
		if (P.get_numberOfCities() >= 7 && game.get_era() == 1) {
			game.set_eraChange(true);
			std::cout << "Step 2 is triggered!" << std::endl;
		}
		// winCondition
		if (P.get_numberOfCities() >= 17) {
			game.set_winCondition(true);
			std::cout << "Wincondition!" << std::endl;
		}
	}
	system("CLS");
}

void buyCities(Player& P, int buyCities) {


	for (int i = 0; i < buyCities; i++) {

		if (game.get_tier3City() == 0) {
			std::cout << "There is no cities left!" << std::endl;
			break;
		}

		if (game.get_tier1City() > 0 && P.get_money() >= 10) {
			P.add_money(-10);
			P.add_cities(1);
			game.set_tier1City(-1);
		}

		else if (game.get_tier2City() > 0 && game.get_era() > 1 && P.get_money() >= 15) {
			P.add_money(-15);
			P.add_cities(1);
			game.set_tier2City(-1);
		}

		else if (game.get_tier3City() > 0 && game.get_era() == 3 && P.get_money() >= 20) {
			P.add_money(-20);
			P.add_cities(1);
			game.set_tier3City(-1);
		}

		else {
			std::cout << P.get_name() << " You don't have enough money to buy more cities!" << std::endl;
			break;
		}
	}
}
