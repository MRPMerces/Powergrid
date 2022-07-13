#include "ailogic.h"

bool raise;

void ai_auctionstage1()
{
	Powerplant mostPowerfullPowerplant = game.powerplantMarked[0];
	for (int i = 0; i < 4; i++) {
		// Find some Powerplant stats
		if (game.powerplantMarked[i].get_citiesPowered() > mostPowerfullPowerplant.get_citiesPowered()) {
			mostPowerfullPowerplant = game.powerplantMarked[i];
		}
	}

	auction(mostPowerfullPowerplant);
}

//Ai desition when auctioning
void aiAuction(Player& PA, int faceValue, int priceOfPlant) {

	//If the current price of plant is less than the facevalue (get_plantId()) +5, then raise by 1
	if (priceOfPlant < faceValue + 5 && PA.get_money() > 0) raisePriceOfPlant++;

	//else pass
	else raisePriceOfPlant = 0;

}

void aiDiscardPowerplant(Player& P) {

	int lowestCitiesPowered = P.get_playerPowerplants()[0].get_citiesPowered();
	int lowestCitiesPoweredPosition = 0;

	for (int i = 0; i < P.get_playerPowerplants().size(); i++) {
		Powerplant PPP = P.get_playerPowerplants()[i];

		if (lowestCitiesPowered > PPP.get_citiesPowered()) {
			lowestCitiesPowered = PPP.get_citiesPowered();
			lowestCitiesPoweredPosition = i;
		}

		if (i == P.get_playerPowerplants().size() - 1) { // ?
			std::cout << "Powerplant: " << PPP.get_plantId() << "has been discarded!" << std::endl;
			P.remove_playerPowerplant(lowestCitiesPoweredPosition);
		}
	}

	//tiebreaker is fuel price
	//Second tie breaker?
}

void aiBuyFuel(Player& P) {
	int aiBuyCoalplant;
	int aiBuyOil;
	int aiBuyGarbage;
	int aiBuyUranium;

	if (P.get_fuelStorage(Coal) / 2 - P.get_fuel(Coal) > 0) {
		aiBuyCoalplant = P.get_fuelStorage(Coal) / 2 - P.get_fuel(Coal);
		buyCoal(P, aiBuyCoalplant);
	}

	if (P.get_fuelStorage(Oil) / 2 - P.get_fuel(Oil) > 0) {
		aiBuyOil = P.get_fuelStorage(Oil) / 2 - P.get_fuel(Oil);
		buyOil(P, aiBuyOil);
	}

	if (P.get_fuelStorage(Garbage) / 2 - P.get_fuel(Garbage) > 0) {
		aiBuyGarbage = P.get_fuelStorage(Garbage) / 2 - P.get_fuel(Garbage);
		buyGarbage(P, aiBuyGarbage);
	}

	if (P.get_fuelStorage(Uranium) / 2 - P.get_fuel(Uranium) > 0) {
		aiBuyUranium = P.get_fuelStorage(Uranium) / 2 - P.get_fuel(Uranium);
		buyUranium(P, aiBuyUranium);
	}
}

void aiBuyCities(Player& P) {
	int aiBuyCities = 0;

	aiBuyCities = P.get_totalPoweredCities() - P.get_numberOfCities();

	/// Make under free???

	// At era 2 it will buy another city per round
	if (game.get_era() > 1) aiBuyCities++;

	// At era 3 it will buy another city per round
	if (game.get_era() == 3) aiBuyCities++;

	buyCities(P, aiBuyCities);
}

void aiPowerPowerplant() {
	/*allways power all cities if can*/
	//in cheapest fuel order.
}