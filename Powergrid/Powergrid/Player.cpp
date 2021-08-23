#include "Player.h"

std::vector <Player> vec_Player;

// Constructor
Player::Player(const std::string& name, playerType type) {
	this->name = name;
	this->type = type;
}

Player::Player() {}

// Name
std::string Player::get_name() const {
	return name;
}

// Playertype
playerType Player::get_playerType() const {
	return type;
}

// Money
int Player::get_money() const {
	return money;
}

void Player::add_money(int m) {
	money += m;
}

// Number of cities
int Player::get_numberOfCities() const {
	return numberOfCities;
}

void Player::add_cities(int noc) {
	numberOfCities += noc;
}

// Resources
int Player::get_fuel(FuelType type) const {
	switch (type) {
	case Coal:
		return coal.get_quantity();

	case Oil:
		return oil.get_quantity();

	case Garbage:
		return garbage.get_quantity();

	case Uranium:
		return uranium.get_quantity();

	default:
		return 0;
		std::cerr << "Invalid fuel type!" << std::endl;
	}
}

void Player::add_fuel(FuelType type, int quantity) {
	switch (type) {
	case Coal:
		coal.add_quantity(quantity);

	case Oil:
		oil.add_quantity(quantity);

	case Garbage:
		garbage.add_quantity(quantity);

	case Uranium:
		uranium.add_quantity(quantity);

	default:
		std::cerr << "Invalid fuel type!" << std::endl;
	}
}

int Player::get_fuelStorage(FuelType type) const {
	switch (type) {
	case Coal:
		return storageCoal.get_quantity();

	case Oil:
		return storageOil.get_quantity();

	case Garbage:
		return storageGarbage.get_quantity();

	case Uranium:
		return storageUranium.get_quantity();

	default:
		return 0;
		std::cerr << "Invalid fuel type!" << std::endl;
	}
}

void Player::add_fuelStorage(FuelType type, int quantity) {
	switch (type) {
	case Coal:
		storageCoal.add_quantity(quantity);

	case Oil:
		storageOil.add_quantity(quantity);

	case Garbage:
		storageGarbage.add_quantity(quantity);

	case Uranium:
		storageUranium.add_quantity(quantity);

	default:
		std::cerr << "Invalid fuel type!" << std::endl;
	}
}

// Reset the fuel storage
void Player::reset_fuelStorage() {
	storageCoal = Fuel(Coal, 0);
	storageOil = Fuel(Oil, 0);
	storageGarbage = Fuel(Garbage, 0);
	storageUranium = Fuel(Uranium, 0);
}

int Player::get_centrifuges() const {
	return centrifuges;
}

void Player::add_centrifuges(int quantity) {
	centrifuges += quantity;
}

// Total cities that can be powered
int Player::get_totalPoweredCities() const {
	return totalPoweredCities;
}

void Player::add_totalPoweredCities(int quantity) {
	totalPoweredCities += quantity;
}

void Player::reset_totalPoweredCities() {
	totalPoweredCities = 0;
}

// Cities powered
int Player::get_citiesPowered() const {
	return citiesPowered;
}

void Player::add_citiesPowered(int quantity) {
	citiesPowered += quantity;
}

void Player::reset_citiesPowered() {
	citiesPowered = 0;
}

// Passed
bool Player::get_passed() const {
	return passed;
}

void Player::set_passed(bool p) {
	passed = p;
}

// Playerpowerplant vector
std::vector<Powerplant> Player::get_vec_playerPowerplant() const {
	return vec_playerPowerplant;
}

void Player::add_playerPowerplant(Powerplant pp) {
	vec_playerPowerplant.push_back(pp);
}

void Player::remove_playerPowerplant(int pos) {
	vec_playerPowerplant.erase(vec_playerPowerplant.begin() + pos);
}

void Player::sort_playerPowerplant() {
	sort(vec_playerPowerplant.begin(), vec_playerPowerplant.end());
}

void players() {

	int cin_inputAmountOfAi = 1;
	//string std::cin_name;
	auto rng = std::default_random_engine{};

	//std::cin >> std::cin_name;

	//while (std::cin){
		//newPlayer.set_name("std::cin_name");
	vec_Player.push_back(Player("Merces", Human));
	//}

	// For loop for adding ai
	for (int i = 1; i < cin_inputAmountOfAi + 1; i++) {
		// Concatenate a string and int
		std::string name = "AI" + std::to_string(i);
		vec_Player.push_back(Player("name", Ai));
	}

	// Shuffles the vector
	shuffle(begin(vec_Player), end(vec_Player), rng);

	// Prints all players
	std::cout << textDivider << std::endl;
	for (Player& P : vec_Player) {
		std::cout << "Player name: " << P.get_name() << std::endl;
		std::cout << "Player type: " << P.get_playerType() << std::endl;
		std::cout << textDivider << std::endl;
	}
}

// Update the fuel storage for every player
void updatePlayerInfo() {

	for (Player& P : vec_Player) {
		P.reset_fuelStorage();
		P.reset_totalPoweredCities();
		P.reset_citiesPowered();

		for (Powerplant& PPP : P.get_vec_playerPowerplant()) {
			if (PPP.get_FuelType() == Coalplant) P.add_fuelStorage(Coal, PPP.get_fuelUsage() * 2);
			if (PPP.get_FuelType() == Oil) P.add_fuelStorage(Oil, PPP.get_fuelUsage() * 2);
			if (PPP.get_FuelType() == Garbage) P.add_fuelStorage(Garbage, PPP.get_fuelUsage() * 2);
			if (PPP.get_FuelType() == Uranium) P.add_fuelStorage(Uranium, PPP.get_fuelUsage() * 2);

			P.add_totalPoweredCities(PPP.get_citiesPowered());
		}
	}
}

// Find the highest plant id for every player
int highestplantId(const Player& p) {
	int highestPlayerplantId = 0;

	for (Powerplant& PPP : p.get_vec_playerPowerplant())
		if (highestPlayerplantId < PPP.get_plantId())
			highestPlayerplantId = PPP.get_plantId();
	return highestPlayerplantId;
}

// Sorting algorithm for vec player
bool comparator(const Player& player1, const Player& player2) {
	if (player1.get_numberOfCities() != player2.get_numberOfCities()) return player1.get_numberOfCities() > player2.get_numberOfCities();
	return highestplantId(player1) > highestplantId(player2);
}