#include "Fuel.h"

Fuel::Fuel(FuelType type, int quantity) {
	this->type = type;
	this->quantity = quantity;
}

Fuel::Fuel() {}

FuelType Fuel::get_type() const {
	return type;
}

int Fuel::get_quantity() const {
	return quantity;
}

void Fuel::add_quantity(int quantity) {
	this->quantity += quantity;
}
