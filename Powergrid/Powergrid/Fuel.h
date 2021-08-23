#pragma once
/*
 * Fuel.h
 * Fuel class
 */
#ifndef Fuel_H_
#define Fuel_H_

enum FuelType{ Oil, Coal, Garbage, Uranium, Hybrid, Wind, Era};

class Fuel {
public:

	Fuel(FuelType type, int quantity);

	Fuel();

	FuelType get_type() const;

	int get_quantity() const;
	void add_quantity(int quantity);

private:
	FuelType type;

	int quantity;
};

#endif
