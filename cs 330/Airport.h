// Define the Airport data structure
typedef struct {
   char *code;	// code
   char *name;	// name of airport
   char *city;	// city
   char *state;	// state
   char *country;	// duh
} Airport;

// Functions relating to Airport type
void show(Airport a);	// prints out a given airport object
Airport parseAirport(char * str);	// Parses str into an Airport object
