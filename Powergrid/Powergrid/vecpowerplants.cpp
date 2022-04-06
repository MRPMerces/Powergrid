#include "Powerplants.h"

std::vector <Powerplant> powerplants;
std::vector <Powerplant> powerplantMarked;

void powerPlants() {
	//Plant 11
	powerplants.push_back(Powerplant(Fuel(Uranium, 1), Nuclearplant, 11, 2));

	//Plant 12
	powerplants.push_back(Powerplant(Fuel(Hybrid, 2), Hybridplant, 12, 2));

	//Plant 14
	powerplants.push_back(Powerplant(Fuel(Garbage, 2), Garbageplant, 14, 2));

	//Plant 15
	powerplants.push_back(Powerplant(Fuel(Coal, 2), Coalplant, 15, 3));

	//Plant 16
	powerplants.push_back(Powerplant(Fuel(Coal, 2), Coalplant, 16, 3));

	//Plant 17	
	powerplants.push_back(Powerplant(Fuel(Uranium, 1), Nuclearplant, 17, 2));

	//Plant 18
	powerplants.push_back(Powerplant(Fuel(Wind, 0), Windplant, 18, 2));

	//Plant 19
	powerplants.push_back(Powerplant(Fuel(Garbage, 2), Garbageplant, 19, 3));

	//Plant 20
	powerplants.push_back(Powerplant(Fuel(Coal, 3), Coalplant, 20, 5));

	//Plant 21
	powerplants.push_back(Powerplant(Fuel(Hybrid, 2), Hybridplant, 21, 4));

	//Plant 22
	powerplants.push_back(Powerplant(Fuel(Wind, 0), Windplant, 22, 2));

	//Plant 23
	powerplants.push_back(Powerplant(Fuel(Uranium, 1), Nuclearplant, 23, 3));

	//Plant 24
	powerplants.push_back(Powerplant(Fuel(Garbage, 2), Garbageplant, 21, 4));

	//Plant 25
	powerplants.push_back(Powerplant(Fuel(Coal, 2), Coalplant, 25, 5));

	//Plant 26
	powerplants.push_back(Powerplant(Fuel(Oil, 2), Oilplant, 26, 5));

	//Plant 27
	powerplants.push_back(Powerplant(Fuel(Wind, 0), Windplant, 27, 3));

	//Plant 28
	powerplants.push_back(Powerplant(Fuel(Uranium, 1), Nuclearplant, 28, 4));

	//Plant 29
	powerplants.push_back(Powerplant(Fuel(Hybrid, 1), Hybridplant, 28, 4));

	//Plant 30
	powerplants.push_back(Powerplant(Fuel(Garbage, 3), Garbageplant, 30, 6));

	//Plant 31
	powerplants.push_back(Powerplant(Fuel(Coal, 3), Coalplant, 31, 6));

	//Plant 32
	powerplants.push_back(Powerplant(Fuel(Oil, 3), Oilplant, 32, 6));

	//Plant 33
	powerplants.push_back(Powerplant(Fuel(Wind, 0), Windplant, 33, 4));

	//Plant 34
	powerplants.push_back(Powerplant(Fuel(Uranium, 1), Nuclearplant, 34, 5));

	//Plant 35
	powerplants.push_back(Powerplant(Fuel(Oil, 1), Oilplant, 35, 5));

	//Plant 36
	powerplants.push_back(Powerplant(Fuel(Coal, 3), Coalplant, 36, 7));

	//Plant 37
	powerplants.push_back(Powerplant(Fuel(Wind, 0), Windplant, 37, 4));

	//Plant 38
	powerplants.push_back(Powerplant(Fuel(Garbage, 3), Garbageplant, 38, 7));

	//Plant 39
	powerplants.push_back(Powerplant(Fuel(Uranium, 1), Nuclearplant, 39, 6));

	//Plant 40
	powerplants.push_back(Powerplant(Fuel(Oil, 2), Oilplant, 40, 6));

	//Plant 42
	powerplants.push_back(Powerplant(Fuel(Coal, 2), Coalplant, 42, 6));

	//Plant 44
	powerplants.push_back(Powerplant(Fuel(Wind, 0), Windplant, 44, 4));

	//Plant 46
	powerplants.push_back(Powerplant(Fuel(Hybrid, 3), Hybridplant, 46, 7));

	//Plant 50
	powerplants.push_back(Powerplant(Fuel(Wind, 0), Windplant, 50, 6));

	// Shuffles the powerplants
	shuffle(begin(powerplants), end(powerplants), std::default_random_engine{});

	//Era 3 card
	powerplants.push_back(Powerplant(Fuel(Era, 0), Eracard, 0, 0));

	// Plant 13
	powerplants.push_back(Powerplant(Fuel(Wind, 0), Windplant, 13, 1));

	//Plant 3
	powerplants.push_back(Powerplant(Fuel(Oil, 2), Oilplant, 3, 1));

	//Plant 4
	powerplants.push_back(Powerplant(Fuel(Coal, 2), Coalplant, 4, 1));

	//Plant 5
	powerplants.push_back(Powerplant(Fuel(Hybrid, 2), Hybridplant, 5, 2));

	//Plant 6
	powerplants.push_back(Powerplant(Fuel(Garbage, 1), Garbageplant, 6, 1));

	//Plant 7
	powerplants.push_back(Powerplant(Fuel(Oil, 3), Oilplant, 7, 2));

	//Plant 8
	powerplants.push_back(Powerplant(Fuel(Coal, 3), Coalplant, 8, 2));

	//Plant 9	
	powerplants.push_back(Powerplant(Fuel(Oil, 1), Oilplant, 9, 1));

	// Plant 10
	powerplants.push_back(Powerplant(Fuel(Coal, 2), Coalplant, 10, 2));
}
