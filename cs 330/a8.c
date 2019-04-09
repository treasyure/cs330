// FILE: a8.c
// Purpose: To define a data type using structs
//		Enables the reading of a database of airport codes
//		from a file code.txt
// 		and allows user to search for airports by their code
// Usage:	./airports code.txt
// Written By: Deepak Kumar
// Date: March 15, 2018

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "Airport.h"
void readData(char *file, List *l, int *n);
int comp(void* item1, void* item2);
int more();
int main(int argc, char *argv[]) {

   List l=newList();	// A list of all airports
   int nA = 0;			// How many airports known

   // Load database...
   if (argc != 2) {
      printf("Cannot proceed: Missing file name.\n");
      exit(EXIT_FAILURE);
   }
   readData(argv[1],&l, &nA);

   // Begin user interaction
   char code[5];
   int result;
   do {
       printf("Enter the three-letter code for an airport: ");
       scanf("%s", code);
       printf("Searching: %s\n", code);
	  Airport *result=contains(&l,code,comp);
       if (result!=NULL) {
          printf("Success: ");
          show(*result);
       }
       else
          printf("Unsuccessful: %s is not a known airport.\n", code);

   } while (more());
   printf("This was a databse of %d airports.\n",nA);
   printf("Goodbye!\n");

   return(0);
} // main()
int comp(void* item1,void* item2){
	const Airport *a= item1;
	return (strcmp(a->code,item2)==0);
}
int more() {
   char resp[5];
   while (1) {
       printf("Would you like to search again (Y/N)? ");
       scanf("%s", resp);
       if ((strcmp(resp, "Y") == 0) || (strcmp(resp, "y") == 0))
	  return 1;
       else if ((strcmp(resp, "N") == 0) || (strcmp(resp, "n") == 0))
	  return 0;
       else
          printf("Please enter a Y or a N.\n");
   }
} // more()

void readData(char *file, List *l, int *n) {
   // Load airport database into list[] from file, set n

   FILE *fp;

   int i = 0;

   printf("Opening file: %s\n", file);
   fp = fopen(file, "r");
   if (fp == NULL) {
      printf("Unable to open file %s.\n", file);
      exit(EXIT_FAILURE);
   }
   printf("Opened file %s.\n", file);
   printf("Reading...");

   char line[80];
   fgets(line, sizeof(line), fp); // ignore first line
   while ( (fgets(line, sizeof(line), fp)) != NULL) {
      int L = strlen(line);
      line[L-1] = '\0';
	 Airport result=parseAirport(line);
      add(l,&result);
	 print(l);
	 printf("\n");
      i++;
   }
   *n = i;
   fclose(fp);
   printf("...done. [%d]\n", i);
} // readData()
