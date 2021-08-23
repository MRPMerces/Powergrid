#include "Powerplants.h"

std::vector <Powerplant> vec_Powerplant;
std::vector <Powerplant> vec_powerplantMarked;

void powerPlants() {
	auto rng = std::default_random_engine{};

	//Plant 11
	vec_Powerplant.push_back(Powerplant(Fuel(Uranium, 1), Nuclearplant, 11, 2));

	//Plant 12
	vec_Powerplant.push_back(Powerplant(Fuel(Hybrid, 2), Hybridplant, 12, 2));

	//Plant 14
	vec_Powerplant.push_back(Powerplant(Fuel(Garbage, 2), Garbageplant, 14, 2));

	//Plant 15
	vec_Powerplant.push_back(Powerplant(Fuel(Coal, 2), Coalplant, 15, 3));

	//Plant 16
	vec_Powerplant.push_back(Powerplant(Fuel(Coal, 2), Coalplant, 16, 3));

	//Plant 17	
	vec_Powerplant.push_back(Powerplant(Fuel(Uranium, 1), Nuclearplant, 17, 2));

	//Plant 18
	vec_Powerplant.push_back(Powerplant(Fuel(Wind, 0), Windplant, 18, 2));

	//Plant 19
	vec_Powerplant.push_back(Powerplant(Fuel(Garbage, 2), Garbageplant, 19, 3));

	//Plant 20
	vec_Powerplant.push_back(Powerplant(Fuel(Coal, 3), Coalplant, 20, 5));

	//Plant 21
	vec_Powerplant.push_back(Powerplant(Fuel(Hybrid, 2), Hybridplant, 21, 4));

	//Plant 22
	vec_Powerplant.push_back(Powerplant(Fuel(Wind, 0), Windplant, 22, 2));

	//Plant 23
	vec_Powerplant.push_back(Powerplant(Fuel(Uranium, 1), Nuclearplant, 23, 3));

	//Plant 24
	vec_Powerplant.push_back(Powerplant(Fuel(Garbage, 2), Garbageplant, 21, 4));

	//Plant 25
	vec_Powerplant.push_back(Powerplant(Fuel(Coal, 2), Coalplant, 25, 5));

	//Plant 26
	vec_Powerplant.push_back(Powerplant(Fuel(Oil, 2), Oilplant, 26, 5));

	//Plant 27
	vec_Powerplant.push_back(Powerplant(Fuel(Wind, 0), Windplant, 27, 3));

	//Plant 28
	vec_Powerplant.push_back(Powerplant(Fuel(Uranium, 1), Nuclearplant, 28, 4));

	//Plant 29
	vec_Powerplant.push_back(Powerplant(Fuel(Hybrid, 1), Hybridplant, 28, 4));

	//Plant 30
	vec_Powerplant.push_back(Powerplant(Fuel(Garbage, 3), Garbageplant, 30, 6));

	//Plant 31
	vec_Powerplant.push_back(Powerplant(Fuel(Coal, 3), Coalplant, 31, 6));

	//Plant 32
	vec_Powerplant.push_back(Powerplant(Fuel(Oil, 3), Oilplant, 32, 6));

	//Plant 33
	vec_Powerplant.push_back(Powerplant(Fuel(Wind, 0), Windplant, 33, 4));

	//Plant 34
	vec_Powerplant.push_back(Powerplant(Fuel(Uranium, 1), Nuclearplant, 34, 5));

	//Plant 35
	vec_Powerplant.push_back(Powerplant(Fuel(Oil, 1), Oilplant, 35, 5));

	//Plant 36
	vec_Powerplant.push_back(Powerplant(Fuel(Coal, 3), Coalplant, 36, 7));

	//Plant 37
	vec_Powerplant.push_back(Powerplant(Fuel(Wind, 0), Windplant, 37, 4));

	//Plant 38
	vec_Powerplant.push_back(Powerplant(Fuel(Garbage, 3), Garbageplant, 38, 7));

	//Plant 39
	vec_Powerplant.push_back(Powerplant(Fuel(Uranium, 1), Nuclearplant, 39, 6));

	//Plant 40
	vec_Powerplant.push_back(Powerplant(Fuel(Oil, 2), Oilplant, 40, 6));

	//Plant 42
	vec_Powerplant.push_back(Powerplant(Fuel(Coal, 2), Coalplant, 42, 6));

	//Plant 44
	vec_Powerplant.push_back(Powerplant(Fuel(Wind, 0), Windplant, 44, 4));

	//Plant 46
	vec_Powerplant.push_back(Powerplant(Fuel(Hybrid, 3), Hybridplant, 46, 7));

	//Plant 50
	vec_Powerplant.push_back(Powerplant(Fuel(Wind, 0), Windplant, 50, 6));

	// Shuffles the vector
	shuffle(begin(vec_Powerplant), end(vec_Powerplant), rng);

	//Era 3 card
	vec_Powerplant.push_back(Powerplant(Fuel(Era, 0), Eracard, 0, 0));

	// Plant 13
	vec_Powerplant.push_back(Powerplant(Fuel(Wind, 0), Windplant, 13, 1));

	//Plant 3
	vec_Powerplant.push_back(Powerplant(Fuel(Oil, 2), Oilplant, 3, 1));

	//Plant 4
	vec_Powerplant.push_back(Powerplant(Fuel(Coal, 2), Coalplant, 4, 1));

	//Plant 5
	vec_Powerplant.push_back(Powerplant(Fuel(Hybrid, 2), Hybridplant, 5, 2));

	//Plant 6
	vec_Powerplant.push_back(Powerplant(Fuel(Garbage, 1), Garbageplant, 6, 1));

	//Plant 7
	vec_Powerplant.push_back(Powerplant(Fuel(Oil, 3), Oilplant, 7, 2));

	//Plant 8
	vec_Powerplant.push_back(Powerplant(Fuel(Coal, 3), Coalplant, 8, 2));

	//Plant 9	
	vec_Powerplant.push_back(Powerplant(Fuel(Oil, 1), Oilplant, 9, 1));

	// Plant 10
	vec_Powerplant.push_back(Powerplant(Fuel(Coal, 2), Coalplant, 10, 2));
}
