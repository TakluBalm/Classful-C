#include <vehicle.h>
#include <array.h>
#include <stdio.h>

/**
 * Vehicle[] vehicles = new Vehicle[10];
 * Libc.stdio.printf("%ld\n", vehicles.length);
 * for(int i = 0; i < 10; i++){
 *   vehicles[i] = new Vehicle(i);
 * }
 * for(Int i = 0; i < 10; i++){
 *   vehicles[i].printPrice();
 * }
*/
int main(){
	struct array_meta* vehicles = allocate_array(10);
	printf("%ld\n", vehicles->arraySize);

	for(int i = 0; i < 10; i++){
		setIndex_array(vehicles, i, __constructor__Vehicle(NULL, i));
	}

	for(int i = 0; i < 10; i++){
		struct Vehicle* tmp = getIndex_array(vehicles, i);
		tmp->printPrice(tmp);
	}
}