#ifndef CLASS_SCOOTER_H
#define CLASS_SCOOTER_H

#include "vehicle.h"

/**
 * class Scooter extends Vehicle {
 *   char* model;
 *   
 *   Car(long price, char* model){
 *     super(price);
 *     this.model = model;
 *   }
 * 
 *   void printPrice(){
 *     Libc.stdio.printf("Price of the scooter is: %ld", price);
 *   }
 * 
 *   void printModel(){
 *     Libc.stdio.printf("%s\n", model);
 *   }
 *   
 * }
*/
struct Scooter {
	struct Vehicle __super__Vehicle;
	char* model;
	void (*printModel)(struct Scooter*);
};

struct Scooter* __constructor_Scooter(struct Scooter* this, char* model, long price);


#endif