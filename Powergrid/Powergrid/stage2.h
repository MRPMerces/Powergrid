#pragma once
/*
 * stage2.h
 * Code for stage 2
 */
#ifndef stage2_H_
#define stage2_H_

#include "Game.h"
#include "Player.h"
#include "ailogic.h"
#include "ui.h"

void stage2();
void buyResources(Player& P);
void buyCoalplant(Player& P, int buyCoalplant);
void buyOil(Player& P, int buyOil);
void buyGarbage(Player& P, int buyGarbage);
void buyUranium(Player& P, int buyUranium);

//External dependencies
extern const std::string textDivider;

#endif
