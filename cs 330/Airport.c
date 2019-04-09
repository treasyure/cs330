#include "Airport.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void show(Airport a) {	// print Airport object
   printf("%s - %s, %s, %s (%s).\n",a.code,a.name,a.city,a.state,a.country);
} // show()
Airport parseAirport(char * str) { // Parse srt into an Airport object

   Airport result;

   char *token;
   token = strtok(str, ",");	// code
   result.code=malloc(sizeof(char)*(strlen(token)+1));
   strcpy(result.code, token);

   token = strtok(NULL, ",");	// name
   result.name=malloc(sizeof(char)*(strlen(token)+1));
   strcpy(result.name, token);

   token = strtok(NULL, ",");	// city
   result.city=malloc(sizeof(char)*(strlen(token)+1));
   strcpy(result.city, token);

   token = strtok(NULL, ",");	// state
   result.state=malloc(sizeof(char)*(strlen(token)+1));
   strcpy(result.state, token);

   token = strtok(NULL, ",");	// country
   result.country=malloc(sizeof(char)*(strlen(token)+1));
   strcpy(result.country, token);

   return result;
} // parseAirport()
