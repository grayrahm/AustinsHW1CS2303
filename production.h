/*
 * production.h
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <stdio.h>
#include <stdbool.h>
#include <string.h>//strncpy
#include <strings.h>
#include <stdlib.h>//strtol

#define MAXSTRINGLENGTH (100)

bool production(int argc, char* argv[]);
bool getYesNo(char* query);
void substringExtraction(char* whole, int* results);
void bzero2(char *s, int n);
void printOut(int* results, int arrSize);



#endif /* PRODUCTION_H_ */
