#include <stdlib.h>
#include <stdio.h>
#include <vehicle.h>

/**
 * Objects are bascially structs in C.
 * Methods are function pointers
 * - Static methods are direct functions
 * - Normal methods have the object as the first argument
 * Variables are struct members
*/

void Vehicle_printPrice(struct Vehicle* this){
	printf("%ld\n", this->price);
}

struct Vehicle* __constructor__Vehicle(struct Vehicle* vehicle, long price){
	if(vehicle == NULL){
		vehicle = malloc(sizeof(struct Vehicle));
	}
	vehicle->price = price;
	vehicle->printPrice = Vehicle_printPrice;
	return vehicle;
}