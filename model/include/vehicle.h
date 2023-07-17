#ifndef VEHICLE_CLASS_H
#define VEHICLE_CLASS_H

/**
 * class Vehicle {
 *   long price
 *   void printPrice(){
 *     Libc.stdio.printf("%s\n", price);
 *   }
 *   Vehicle(long price){
 *     this.price = price;
 *   }
 * }
*/
struct Vehicle {
	long price;
	void (*printPrice)(struct Vehicle*);
};

struct Vehicle* __constructor__Vehicle(struct Vehicle* vehicle, long price);

#endif