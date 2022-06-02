#pragma once
/*
 *Powerplant.h
 *Powerplant class
 */
#ifndef Powerplant_H_
#define Powerplant_H_

#include <algorithm>
#include <random>
#include "Fuel.h"

void powerPlants();
void markedPowerplants();

enum PlantType { Coalplant, Oilplant, Hybridplant, Garbageplant, Nuclearplant, Windplant, Eracard};

class Powerplant {
public:
	Powerplant();
	Powerplant(Fuel fuel, PlantType type, int plantId, int citiesPowered);
	// Fuel type
	FuelType get_FuelType() const;

	PlantType get_PlantType() const;

	// Plant id
	int get_plantId()const;

	// Cities powered
	int get_citiesPowered()const;

	// Fuel usage
	int get_fuelUsage()const;

	// Overload < operator, to sort
	bool operator < (const Powerplant& Powerplant) const {
		return (plantId < Powerplant.get_plantId());
	}

private:
	Fuel fuel;

	PlantType type;

	int plantId;
	int citiesPowered;
};

//External dependencies
extern std::vector <Powerplant> powerplants;
extern std::vector <Powerplant> powerplantMarked;

#endif
