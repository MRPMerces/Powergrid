#include "Powerplants.h"

void powerPlants() {
	//Plant 11
	game.powerplants.push_back(Powerplant(Fuel(Uranium, 1), Nuclearplant, 11, 2));

	//Plant 12
	game.powerplants.push_back(Powerplant(Fuel(Hybrid, 2), Hybridplant, 12, 2));

	//Plant 14
	game.powerplants.push_back(Powerplant(Fuel(Garbage, 2), Garbageplant, 14, 2));

	//Plant 15
	game.powerplants.push_back(Powerplant(Fuel(Coal, 2), Coalplant, 15, 3));

	//Plant 16
	game.powerplants.push_back(Powerplant(Fuel(Coal, 2), Coalplant, 16, 3));

	//Plant 17	
	game.powerplants.push_back(Powerplant(Fuel(Uranium, 1), Nuclearplant, 17, 2));

	//Plant 18
	game.powerplants.push_back(Powerplant(Fuel(Wind, 0), Windplant, 18, 2));

	//Plant 19
	game.powerplants.push_back(Powerplant(Fuel(Garbage, 2), Garbageplant, 19, 3));

	//Plant 20
	game.powerplants.push_back(Powerplant(Fuel(Coal, 3), Coalplant, 20, 5));

	//Plant 21
	game.powerplants.push_back(Powerplant(Fuel(Hybrid, 2), Hybridplant, 21, 4));

	//Plant 22
	game.powerplants.push_back(Powerplant(Fuel(Wind, 0), Windplant, 22, 2));

	//Plant 23
	game.powerplants.push_back(Powerplant(Fuel(Uranium, 1), Nuclearplant, 23, 3));

	//Plant 24
	game.powerplants.push_back(Powerplant(Fuel(Garbage, 2), Garbageplant, 21, 4));

	//Plant 25
	game.powerplants.push_back(Powerplant(Fuel(Coal, 2), Coalplant, 25, 5));

	//Plant 26
	game.powerplants.push_back(Powerplant(Fuel(Oil, 2), Oilplant, 26, 5));

	//Plant 27
	game.powerplants.push_back(Powerplant(Fuel(Wind, 0), Windplant, 27, 3));

	//Plant 28
	game.powerplants.push_back(Powerplant(Fuel(Uranium, 1), Nuclearplant, 28, 4));

	//Plant 29
	game.powerplants.push_back(Powerplant(Fuel(Hybrid, 1), Hybridplant, 28, 4));

	//Plant 30
	game.powerplants.push_back(Powerplant(Fuel(Garbage, 3), Garbageplant, 30, 6));

	//Plant 31
	game.powerplants.push_back(Powerplant(Fuel(Coal, 3), Coalplant, 31, 6));

	//Plant 32
	game.powerplants.push_back(Powerplant(Fuel(Oil, 3), Oilplant, 32, 6));

	//Plant 33
	game.powerplants.push_back(Powerplant(Fuel(Wind, 0), Windplant, 33, 4));

	//Plant 34
	game.powerplants.push_back(Powerplant(Fuel(Uranium, 1), Nuclearplant, 34, 5));

	//Plant 35
	game.powerplants.push_back(Powerplant(Fuel(Oil, 1), Oilplant, 35, 5));

	//Plant 36
	game.powerplants.push_back(Powerplant(Fuel(Coal, 3), Coalplant, 36, 7));

	//Plant 37
	game.powerplants.push_back(Powerplant(Fuel(Wind, 0), Windplant, 37, 4));

	//Plant 38
	game.powerplants.push_back(Powerplant(Fuel(Garbage, 3), Garbageplant, 38, 7));

	//Plant 39
	game.powerplants.push_back(Powerplant(Fuel(Uranium, 1), Nuclearplant, 39, 6));

	//Plant 40
	game.powerplants.push_back(Powerplant(Fuel(Oil, 2), Oilplant, 40, 6));

	//Plant 42
	game.powerplants.push_back(Powerplant(Fuel(Coal, 2), Coalplant, 42, 6));

	//Plant 44
	game.powerplants.push_back(Powerplant(Fuel(Wind, 0), Windplant, 44, 4));

	//Plant 46
	game.powerplants.push_back(Powerplant(Fuel(Hybrid, 3), Hybridplant, 46, 7));

	//Plant 50
	game.powerplants.push_back(Powerplant(Fuel(Wind, 0), Windplant, 50, 6));

	// Shuffles the powerplants
	shuffle(begin(game.powerplants), end(game.powerplants), std::default_random_engine{});

	//Era 3 card
	game.powerplants.push_back(Powerplant(Fuel(Era, 0), Eracard, 0, 0));

	// Plant 13
	game.powerplants.push_back(Powerplant(Fuel(Wind, 0), Windplant, 13, 1));

	//Plant 3
	game.powerplants.push_back(Powerplant(Fuel(Oil, 2), Oilplant, 3, 1));

	//Plant 4
	game.powerplants.push_back(Powerplant(Fuel(Coal, 2), Coalplant, 4, 1));

	//Plant 5
	game.powerplants.push_back(Powerplant(Fuel(Hybrid, 2), Hybridplant, 5, 2));

	//Plant 6
	game.powerplants.push_back(Powerplant(Fuel(Garbage, 1), Garbageplant, 6, 1));

	//Plant 7
	game.powerplants.push_back(Powerplant(Fuel(Oil, 3), Oilplant, 7, 2));

	//Plant 8
	game.powerplants.push_back(Powerplant(Fuel(Coal, 3), Coalplant, 8, 2));

	//Plant 9	
	game.powerplants.push_back(Powerplant(Fuel(Oil, 1), Oilplant, 9, 1));

	// Plant 10
	game.powerplants.push_back(Powerplant(Fuel(Coal, 2), Coalplant, 10, 2));
}
