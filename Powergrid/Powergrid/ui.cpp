#include "ui.h"

void uiStage2(Player& player) {
	system("CLS");
	std::cout << textDivider << std::endl;
	std::cout << "Player: " << player.get_name() << std::endl << std::endl;
	std::cout << "Money:" << player.get_money() << std::endl;
	std::cout << "You can power: " << player.get_totalPoweredCities() << " cities" << std::endl;
	std::cout << "Coal:" << player.get_fuel(Coal) << std::endl;
	std::cout << "Oil:" << player.get_fuel(Oil) << std::endl;
	std::cout << "Garbage:" << player.get_fuel(Garbage) << std::endl;
	std::cout << "Uranium:" << player.get_fuel(Uranium) << std::endl;
	std::cout << textDivider << std::endl;
}

void uiStage3(Player& player) {
	system("CLS");
	std::cout << textDivider << std::endl;
	std::cout << "Player: " << player.get_name() << std::endl << std::endl;
	std::cout << "Money:" << player.get_money() << std::endl;
	std::cout << "Player cities: " << player.get_numberOfCities() << std::endl;
	std::cout << "You can power: " << player.get_totalPoweredCities() << " cities" << std::endl;
	std::cout << "Player centrifuges: " << player.get_centrifuges() << std::endl;
	std::cout << "There are: " << game.get_tier1City() << " tier 1 cities left." << std::endl;
	std::cout << "There are: " << game.get_tier2City() << " tier 2 cities left." << std::endl;
	std::cout << "There are: " << game.get_tier3City() << " tier 3 cities left." << std::endl;
	std::cout << textDivider << std::endl;
}

void uiStage4(Player& player) {
	system("CLS");
	std::cout << textDivider << std::endl;
	std::cout << "Player: " << player.get_name() << std::endl << std::endl;;
	std::cout << "Money:" << player.get_money() << std::endl;
	std::cout << "Coal:" << player.get_fuel(Coal) << std::endl;
	std::cout << "Oil:" << player.get_fuel(Oil) << std::endl;
	std::cout << "Garbage:" << player.get_fuel(Garbage) << std::endl;
	std::cout << "Uranium:" << player.get_fuel(Uranium) << std::endl;
	std::cout << textDivider << std::endl;
}

void uiPlantInfo(Powerplant& powerplant) {
	std::cout << "Plant id: " << powerplant.get_plantId() << std::endl;
	std::cout << "Fuel type: " << powerplant.get_FuelType() << std::endl;
	std::cout << "Fuel usage: " << powerplant.get_fuelUsage() << std::endl;
	std::cout << "Cities powered: " << powerplant.get_citiesPowered() << std::endl;
}
