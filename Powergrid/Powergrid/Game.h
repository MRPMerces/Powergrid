#pragma once
/*
 * Game.h
 * Game class
 */
#ifndef Game_H_
#define Game_H_

class Game {
public:
	Game();

	// Cities

	// Tier 1
	int get_tier1City() const;
	void set_tier1City(int quantity);

	//Tier 2
	int get_tier2City() const;
	void set_tier2City(int quantity);

	//Tier 3
	int get_tier3City() const;
	void set_tier3City(int quantity);

#pragma region Resources

	// Coal
	int get_amountOfCoal() const;
	void add_coal(int quantity);

	// Oil
	int get_amountOfOil() const;
	void add_oil(int quantity);

	// Garbage
	int get_amountOfGarbage() const;
	void add_garbage(int quantity);

	// Uranium
	int get_amountOfUranium() const;
	void add_uranium(int quantity);

#pragma endregion

	// Era
	int get_era() const;
	void increment_era();

	// Change era
	bool get_eraChange() const;
	void set_eraChange(bool ec);

	// Wincondition
	bool get_winCondition() const;
	void set_winCondition(bool wc);

private:

	int
		// Cities
		tier1City = 0,
		tier2City = 0,
		tier3City = 0,
		// Resources
		amountOfCoal = 0,
		amountOfOil = 0,
		amountOfGarbage = 0,
		amountOfUranium = 0,
		// Era
		era = 0;

	// Change era
	bool
		eraChange,
		//winCondition
		winCondition;

};

extern Game game;

#endif
