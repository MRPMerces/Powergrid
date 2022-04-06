#include "Game.h"

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

	era = 1;

	eraChange = false;
	winCondition = false;
}

int Game::get_tier1City() const {
	return tier1City;
}

void Game::set_tier1City(int quantity) {
	tier1City += quantity;
}

int Game::get_tier2City() const {
	return tier2City;
}

void Game::set_tier2City(int quantity) {
	tier2City += quantity;
}

int Game::get_tier3City() const {
	return tier3City;
}

void Game::set_tier3City(int quantity) {
	tier3City += quantity;
}

#pragma region Resources
int Game::get_amountOfCoal() const {
	return amountOfCoal;
}

void Game::add_coal(int quantity) {
	amountOfCoal += quantity;

	if (amountOfCoal > 24) {
		amountOfCoal = 24;
	}
}

int Game::get_amountOfOil() const {
	return amountOfOil;
}

void Game::add_oil(int quantity) {
	amountOfOil += quantity;

	if (amountOfOil > 24) {
		amountOfOil = 24;
	}
}

int Game::get_amountOfGarbage() const {
	return amountOfGarbage;
}

void Game::add_garbage(int quantity) {
	amountOfGarbage += quantity;

	if (amountOfGarbage > 24) {
		amountOfGarbage = 24;
	}
}

int Game::get_amountOfUranium() const {
	return amountOfUranium;
}

void Game::add_uranium(int quantity) {
	amountOfUranium += quantity;

	if (amountOfOil > 12) {
		amountOfOil = 12;
	}
}

#pragma endregion

int Game::get_era() const {
	return era;
}

void Game::increment_era() {
	era++;
}

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
