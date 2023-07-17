#ifndef CLASS_CAR_H
#define CLASS_CAR_H

#include "vehicle.h"

/**
 * class Car extends Vehicle {
 *   char* model;
 *   
 *   Car(long price, char* model){
 *     super(price);
 *     this.model = model
 *   }
 * 
 *   void printModel(){
 *     Libc.stdio.printf(model);
 *   }
 * }
*/
struct Car {
	struct Vehicle __super__Vehicle;
	char* model;
	void (*printModel)(struct Car*);
};

struct Car* __constructor_Car(struct Car* car, char* model, long price);


#endif