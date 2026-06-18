#ifndef TANK_H
#define TANK_H

#include "stdint.h"

uint32_t Tank_GetLevelCM(uint32_t distance_cm);
uint32_t Tank_GetFillPercent(uint32_t level_cm);
uint32_t Tank_GetVolumeML(uint32_t level_cm);
#endif
