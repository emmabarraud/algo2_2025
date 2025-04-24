#ifndef _WUTILS_H
#define _WUTILS_H

#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "weather_table.h"

int menortempmin(WeatherTable a);
//Una función que obtenga la menor temperatura mínima histórica registrada en la ciudad de Córdoba según los datos del arreglo 

void max_temp_max(WeatherTable table, int output[YEARS]);

void month_max_rainfall(WeatherTable table, month_t output[YEARS]);

#endif