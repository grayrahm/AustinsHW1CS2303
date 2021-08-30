/*
 ============================================================================
 Name        : ReferenceWordSearch.c
 Author      : Austin and Owen
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "production.h"
#include "teamMembers.h"
#include "tests.h"

int main(int argc, char* argv[]) {
	puts("!!!Hello World, let's do Word Search!!!");
	if(tests())
	{
		puts("The tests all passed.");
		production(argc, argv);
	}
	else
	{
		puts("Not all tests passed; better luck next time");
	}

	return EXIT_SUCCESS;
}

