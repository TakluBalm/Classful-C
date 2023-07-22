#include <car.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * int main(){
 *   Car localCar = new Car("Skoda", 100);
 *   ref Car refCar = new Car("Mercedez", 500);
 *   
 *   localCar.printModel(); // Skoda
 *   localCar.printPrice(); // 100
 * 
 *   refCar.printModel(); // Mercedez
 *   refCar.printPrice(); // 500
 * }
*/
int main(){
	struct Car localCar;
	__constructor_Car(&localCar, "Skoda", 100);
	struct Car* refCar = __constructor_Car(NULL, "Mercedez", 500);

	localCar.printModel(&localCar);
	localCar.__super__Vehicle.printPrice( (struct Vehicle*) &localCar);
	
	refCar->printModel(refCar);
	refCar->__super__Vehicle.printPrice( (struct Vehicle*) refCar);
}