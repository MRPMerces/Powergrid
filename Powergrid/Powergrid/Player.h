#pragma once
/*
 * Player.h
 * Player class
 */
#ifndef Player_H_
#define Player_H_

#include <iostream>
#include "Powerplants.h"
#include "Fuel.h"
#include <algorithm>
#include <random>
#include <string>
#include <vector>

 // External dependencies
extern const std::string textDivider;

enum playerType { Human, Ai };

class Player {
public:

	Player();
	// Constructor
	Player(const std::string& name, playerType type);

	// Name
	std::string get_name() const;

	// Playertype
	playerType get_playerType() const;

	// Money
	int get_money() const;
	void add_money(int quantity);

	// Number of cities
	int get_numberOfCities() const;
	void add_cities(int quantity);

	// Resources
	int get_fuel(FuelType type) const;
	void add_fuel(FuelType type, int quantity);

	int get_fuelStorage(FuelType type) const;
	void add_fuelStorage(FuelType type, int quantity);
	// Centrifuges
	int get_centrifuges() const;
	void add_centrifuges(int quantity);

	// Total powered cities
	int get_totalPoweredCities() const;
	void add_totalPoweredCities(int quantity);
	void reset_totalPoweredCities();

	// Cities powered
	int get_citiesPowered() const;
	void add_citiesPowered(int quantity);
	void reset_citiesPowered();

	// Fuel storage

	// Reset the fuel storage
	void reset_fuelStorage();

	// Playerpowerplant vector
	std::vector <Powerplant> get_playerPowerplants() const;
	void add_playerPowerplant(Powerplant pp);
	void remove_playerPowerplant(int pos);
	void sort_playerPowerplant();

	// Overload == operator
	bool operator == (const Player& rhs) {
		return (name == rhs.get_name());
	}

private:

	std::string name;
	playerType type;

	Fuel coal = Fuel(Coal, 0);
	Fuel oil = Fuel(Oil, 0);
	Fuel garbage = Fuel(Garbage, 0);
	Fuel uranium = Fuel(Uranium, 0);

	Fuel storageCoal = Fuel(Coal, 0);
	Fuel storageOil = Fuel(Oil, 0);
	Fuel storageGarbage = Fuel(Garbage, 0);
	Fuel storageUranium = Fuel(Uranium, 0);

	int money = 30;
	int numberOfCities = 0;
	int centrifuges = 0;
	int totalPoweredCities = 0;
	int citiesPowered = 0;

	std::vector <Powerplant> vec_playerPowerplant;
};

// Update the fuel storage for every player
void updatePlayerInfo();

// Find the highest plant id for every player
int highestplantId(const Player& p);

// Sorting algorithm for vec player
bool comparator(const Player& player1, const Player& player2);

extern std::vector <Player> players;

#endif
