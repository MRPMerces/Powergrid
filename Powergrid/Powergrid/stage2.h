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
void buyResources(Player&);
void buyCoal(Player&, int);
void buyOil(Player&, int);
void buyGarbage(Player&, int);
void buyUranium(Player&, int);

//External dependencies
extern const std::string textDivider;

#endif
