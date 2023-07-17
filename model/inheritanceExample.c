#include <car.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * int main(){
 *   local Car stackCar = new Car("Skoda", 100);
 *   ref Car heapCar = new Car("Mercedez", 500);
 *   
 *   ref Vehicle vehicle = new Car("Test", 300)
 * 
 *   vehicle.printPrice(); // 300
 *   
 *   stackCar.printModel(); // Skoda
 *   stackCar.printPrice(); // 100
 * 
 *   heapCar.printModel(); // Mercedez
 *   heapCar.printPrice(); // 500
 * }
*/
int main(){
	struct Car stackCar;
	__constructor_Car(&stackCar, "Skoda", 100);
	struct Car* heapCar = __constructor_Car(NULL, "Mercedez", 500);

	struct Vehicle* vehicle = (struct Vehicle*) __constructor_Car(NULL, "Test", 300);

	vehicle->printPrice(vehicle);

	stackCar.printModel(&stackCar);
	stackCar.__super__Vehicle.printPrice( (struct Vehicle*) &stackCar);
	
	heapCar->printModel(heapCar);
	heapCar->__super__Vehicle.printPrice( (struct Vehicle*) heapCar);
}