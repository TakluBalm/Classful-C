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

struct Vehicle* __constructor__Vehicle(struct Vehicle* this, long price){
	if(this == NULL){
		this = malloc(sizeof(struct Vehicle));
	}
	this->price = price;
	this->printPrice = Vehicle_printPrice;
	return this;
}