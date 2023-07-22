#include <scooter.h>
#include <stdio.h>
#include <stdlib.h>

void printModel_Scooter(struct Scooter* this){
	printf("%s\n", this->model);
}

void printPrice_Scooter(struct Scooter* this){
	printf("Price of the scooter is: %ld\n", this->__super__Vehicle.price);
}

struct Scooter* __constructor_Scooter(struct Scooter* this, char* model, long price){
	if(this == NULL){
		this = calloc(1, sizeof(struct Scooter));
	}
	__constructor__Vehicle((struct Vehicle*) this, price);
	this->__super__Vehicle.printPrice = (void (*)(struct Vehicle *)) printPrice_Scooter;
	this->printModel = printModel_Scooter;
	this->model = model;
	return this;
}