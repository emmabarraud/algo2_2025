#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "weather_table.h"

int menortempmin(WeatherTable table) {
    int result;
 
 
    result = table[0][0][0]._min_temp;
    for (unsigned int year = 0u; year < YEARS; ++year) { //cambiade años
        for (month_t month = january; month <= december; ++month) { //cambiade mes
            for (unsigned int day = 0u; day < DAYS; ++day) { //cambiade dia
                if (table[year][month][day]._min_temp < result) {
                    result = table[year][month][day]._min_temp;
                }
            }
        }
    }
 
 
    return result;
 }
 
 void max_temp_max(WeatherTable table, int output[YEARS]) { //mayot temp ,axima de x año
    for (unsigned int year = 0; year < YEARS; year++) {    
        // mayor temperatura del año `year`
        int max_temp_year = table[year][0][0]._max_temp;
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (table[year][month][day]._max_temp > max_temp_year) {
                    max_temp_year = table[year][month][day]._max_temp;
                }
            }
        }
 
 
        output[year] = max_temp_year;
    }
 }
 

 void month_max_rainfall(WeatherTable table, month_t output[YEARS]) {
    month_t month_max = january;
    unsigned int max_rainfall = 0;
    // calcular suma de lluvias para el mes `month`
    unsigned int month_rainfall = 0;

    for (unsigned int year = 0; year < YEARS; year++) {
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                month_rainfall += table[year][month][day]._rainfall;
            }
            // ver si es el máximo para este año
            if (month_rainfall > max_rainfall) {
                // guardar nuevo máximo y su mes
                max_rainfall = month_rainfall;
                month_max = month;
            }
        }
        output[year] = month_max;
    }
 }