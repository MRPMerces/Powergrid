#pragma once
/*
 * ailogic.h
 * ai code
 */
#ifndef ailogic_H_
#define ailogic_H_

#include "stage2.h"
#include "stage3.h"
#include "Player.h"
#include "Powerplants.h"

void aiAuction(Player& PA, int faceValue, int priceOfPlant);
void aiDiscardPowerplant(Player& P);
void aiBuyFuel(Player& P);
void aiBuyCities(Player& P);

//External dependencies
extern  int cin_powerPlantChoose;
extern  int raisePriceOfPlant;

#endif
