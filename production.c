/*
 * production.c
 *
 *  Created on: Feb 6, 2021
 *      Author: theresesmith
 */

#include "production.h"


bool production(int argc, char* argv[])
{
	bool answer = true;
	char string4Search[MAXSTRINGLENGTH+1];
	bzero2(string4Search, MAXSTRINGLENGTH+1);
	int foundStringLength = -1;//initialize to obviously wrong value

		if(argc <=1) //no interesting information
		{
			puts("Didn't find any arguments.");
			fflush(stdout);
			answer = false;
		}
		else //there is interesting information
		{
			printf("Found %d arguments.\n", argc);
			fflush(stdout);

			for(int i = 1; i<argc; i++) //don't want to read argv[0]
			{//argv[i] is a string
				//in this program our arguments are a filename followed by the max of rooms, followed by max of treasure
				switch(i)
				{
				case 1:
					foundStringLength = strlen(argv[i]);

					//this is the string to be searched
                    if (foundStringLength <= MAXSTRINGLENGTH)
                    {
                    	strcpy(string4Search, argv[i]);
                    }

					printf("Length of input string is %d\n",foundStringLength);fflush(stdout);
					break;

				default:
					puts("Unexpected argument count."); fflush(stdout);
					answer = false;
					break;
				}//end of switch
			}//end of for loop on argument count
			puts("after reading arguments"); fflush(stdout);
		}//end of command line arguments

		//now that we have our input,
		//what is to be done:
		int resultsArray[foundStringLength-1];
		for(int i = 0; i<foundStringLength; i++)
			{
				resultsArray[i]=0;
			}
		substringExtraction(string4Search, resultsArray);

	    //print output
		printOut(resultsArray, foundStringLength-1);

		return answer;
}
bool getYesNo(char* query)
{
   bool answer = true; //so far
   char said = 'x';
   do
   {
	 printf("%s (y/n):",query);
     fflush(stdout);
     fflush(stdin);
     scanf("%c",&said);
   }while((said!= 'y')&&(said!='n'));
   if(said=='n')
   {
	   answer=false;
   }


   return answer;
}

void substringExtraction(char* whole, int* results)
{
	int theLength = strlen(whole);
	char target[theLength+1];
	bzero2(target, theLength+1);
	char query[100];
	bzero2(query, 100);
	for(int size = 1; size<=theLength-1; size++)
	{
		int howMany = theLength-size+1;
		printf("There are %d substrings of length %d.\n", howMany, size);
		for(int startS = 0; startS<theLength-size+1; startS++)
		{
		    //The substrings should be extracted.
			strncpy(target, whole+startS, size);
		    //then ask the user whether those substrings are words
			sprintf(query, "Is |%s| a word?\n", target);
			if(getYesNo(query)) //if the user says yes, increment the appropriate location in the results array
			{
				results[size - 1]++;

			}

		}
	}

}

void printOut(int* results, int arrSize){
	for(int i = 0; i < arrSize; i++){
		printf("There are %d words of length %d.\n", results[i], i + 1);
	}
}

void bzero2(char *s, int n)
{
  for (int i = 0; i < n; ++i){
    *(s+i) = 0;
  }
}

