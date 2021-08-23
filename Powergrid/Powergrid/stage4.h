#pragma once
/*
 * stage4.h
 * Code for stage 4
 */
#ifndef stage4_H_
#define stage4_H_

#include "Game.h"
#include "Player.h"
#include "Powerplants.h"
#include "ui.h"

void stage4();
void powerPowerplant(Player& P);
void winCondition();
void update();

//External dependencies
extern const std::string textDivider;

#endif
