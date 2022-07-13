#pragma once
/*
 * stage1.h
 * Code for stage 1
 */
#ifndef stage1_H_
#define stage1_H_

#include "Powerplants.h"
#include "Game.h"
#include "Player.h"
#include "ailogic.h"

#include <vector>
#include <algorithm>

void stage1();
void processPowerplantMarked();
void choosePowerPlant();
void choosePowerPlant();
void auction(Powerplant& choosenPlant);
void wonAuction(Player& P, Powerplant& CPP);
void discardPowerplant(Player& P);

//External dependencies
extern const std::string textDivider;

#endif
