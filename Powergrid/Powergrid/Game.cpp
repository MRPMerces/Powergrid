#include "Game.h"

// Constructor
Game::Game() {
	// Cities
	tier1City = 10;
	tier2City = 10;
	tier3City = 10;

	// Resources
	amountOfCoal = 24;
	amountOfOil = 24;
	amountOfGarbage = 24;
	amountOfUranium = 4;

	// Era
	era = 1;

	// Change era
	eraChange = false;

	// Wincondition
	winCondition = false;
}

// Cities

// Tier 1
int Game::get_tier1City() const {
	return tier1City;
}

void Game::set_tier1City(int quantity) {
	tier1City += quantity;
}

// Tier 2
int Game::get_tier2City() const {
	return tier2City;
}

void Game::set_tier2City(int quantity) {
	tier2City += quantity;
}

// Tier 3
int Game::get_tier3City() const {
	return tier3City;
}

void Game::set_tier3City(int quantity) {
	tier3City += quantity;
}

#pragma region Resources
// Coalplant
int Game::get_amountOfCoal() const {
	return amountOfCoal;
}

void Game::add_coal(int quantity) {
	amountOfCoal += quantity;

	// Make sure there is no more than 24 coal
	if (amountOfCoal > 24) {
		amountOfCoal = 24;
	}
}

// Oil
int Game::get_amountOfOil() const {
	return amountOfOil;
}

void Game::add_oil(int quantity) {
	amountOfOil += quantity;

	// Make sure there is no more than 24 oil
	if (amountOfOil > 24) {
		amountOfOil = 24;
	}
}

// Garbage
int Game::get_amountOfGarbage() const {
	return amountOfGarbage;
}

void Game::add_garbage(int quantity) {
	amountOfGarbage += quantity;

	// Make sure there is no more than 24 garbage
	if (amountOfGarbage > 24) {
		amountOfGarbage = 24;
	}
}

// Uranium
int Game::get_amountOfUranium() const {
	return amountOfUranium;
}

void Game::add_uranium(int quantity) {
	amountOfUranium += quantity;

	// Make sure there is no more than 24 uranium
	if (amountOfOil > 12) {
		amountOfOil = 12;
	}
}

#pragma endregion

// Era
int Game::get_era() const {
	return era;
}

void Game::increment_era() {
	era++;
}

// Change era
bool Game::get_eraChange() const {
	return eraChange;
}

void Game::set_eraChange(bool ec) {
	eraChange = ec;
}

bool Game::get_winCondition() const {
	return winCondition;
}

void Game::set_winCondition(bool wc) {
	winCondition = wc;
}

Game game;
