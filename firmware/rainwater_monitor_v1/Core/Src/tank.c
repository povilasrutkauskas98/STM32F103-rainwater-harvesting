#include "tank.h"

#define DISTANCE_EMPTY_CM 16
#define DISTANCE_FULL_CM 2
#define TANK_DIAMETER_CM 11.5f

uint32_t Tank_GetLevelCM(uint32_t distance_cm)
{
    if(distance_cm >= DISTANCE_EMPTY_CM)
        return 0;
    if(distance_cm <= DISTANCE_FULL_CM)
    	return DISTANCE_EMPTY_CM - DISTANCE_FULL_CM;
    return DISTANCE_EMPTY_CM - distance_cm;
}

uint32_t Tank_GetFillPercent(uint32_t level_cm)
{
    return (level_cm * 100) / (DISTANCE_EMPTY_CM - DISTANCE_FULL_CM);
}

uint32_t Tank_GetVolumeML(uint32_t level_cm)
{
    float volume =
        3.1416f *
        (TANK_DIAMETER_CM / 2.0f) *
        (TANK_DIAMETER_CM / 2.0f) *
        level_cm;

    return (uint32_t)volume;
}
