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

void stage1();
void powerplantMarked();
void choosePowerPlant();
void auction(int choosenPlant);
void wonAuction(Player& P, Powerplant& CPP, int choosenPlant);
void discardPowerplant(Player& P);

//External dependencies
extern const std::string textDivider;

#endif
