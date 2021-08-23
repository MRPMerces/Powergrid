#include "Powerplants.h"

Powerplant::Powerplant(Fuel fuel, PlantType type, int plantId, int citiesPowered) {
	this->fuel = fuel;
	this->type = type;
	this->plantId = plantId;
	this->citiesPowered = citiesPowered;
}

FuelType Powerplant::get_FuelType() const {
	return fuel.get_type();
}

PlantType Powerplant::get_PlantType() const {
	return type;
}

int Powerplant::get_plantId() const {
	return plantId;
}

int Powerplant::get_citiesPowered() const {
	return citiesPowered;
}

int Powerplant::get_fuelUsage() const {
	return fuel.get_quantity();
}
