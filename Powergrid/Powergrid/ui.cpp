#include "ui.h"

//UI stage 2
void uiStage2(Player& P) {
	system("CLS");
	std::cout << textDivider << std::endl;
	std::cout << "Player: " << P.get_name() << std::endl << std::endl;
	std::cout << "Money:" << P.get_money() << std::endl;
	std::cout << "You can power: " << P.get_totalPoweredCities() << " cities" << std::endl;
	std::cout << "Coal:" << P.get_fuel(Coal) << std::endl;
	std::cout << "Oil:" << P.get_fuel(Oil) << std::endl;
	std::cout << "Garbage:" << P.get_fuel(Garbage) << std::endl;
	std::cout << "Uranium:" << P.get_fuel(Uranium) << std::endl;
	std::cout << textDivider << std::endl;
}

//UI
void uiStage3(Player& P) {
	system("CLS");
	std::cout << textDivider << std::endl;
	std::cout << "Player: " << P.get_name() << std::endl << std::endl;
	std::cout << "Money:" << P.get_money() << std::endl;
	std::cout << "Player cities: " << P.get_numberOfCities() << std::endl;
	std::cout << "You can power: " << P.get_totalPoweredCities() << " cities" << std::endl;
	std::cout << "Player centrifuges: " << P.get_centrifuges() << std::endl;
	std::cout << "There are: " << game.get_tier1City() << " tier 1 cities left." << std::endl;
	std::cout << "There are: " << game.get_tier2City() << " tier 2 cities left." << std::endl;
	std::cout << "There are: " << game.get_tier3City() << " tier 3 cities left." << std::endl;
	std::cout << textDivider << std::endl;
}

void uiStage4(Player& P) {
	system("CLS");
	std::cout << textDivider << std::endl;
	std::cout << "Player: " << P.get_name() << std::endl << std::endl;;
	std::cout << "Money:" << P.get_money() << std::endl;
	std::cout << "Coalplant:" << P.get_fuel(Coal) << std::endl;
	std::cout << "Oil:" << P.get_fuel(Oil) << std::endl;
	std::cout << "Garbage:" << P.get_fuel(Garbage) << std::endl;
	std::cout << "Uranium:" << P.get_fuel(Uranium) << std::endl;
	std::cout << textDivider << std::endl;
}

void uiPlantInfo(Powerplant& P) {
	std::cout << "Plant id: " << P.get_plantId() << std::endl;
	std::cout << "Fuel type: " << P.get_FuelType() << std::endl;
	std::cout << "Fuel usage: " << P.get_fuelUsage() << std::endl;
	std::cout << "Cities powered: " << P.get_citiesPowered() << std::endl;
}
