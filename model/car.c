#include <car.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void Car_printModel(struct Car* this){
	printf("%s\n", this->model);
}

struct Car* __constructor_Car(struct Car* this, char* model, long price){
	if(this == NULL){
		this = malloc(sizeof(struct Car));
	}
	__constructor__Vehicle(&this->__super__Vehicle, price);
	this->model = model;
	this->printModel = Car_printModel;
	return this;
}