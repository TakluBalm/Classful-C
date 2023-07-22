#include <vehicle.h>
#include <scooter.h>
#include <stddef.h>

/**
 *  ref Scooter scooter = new Scooter("Activa", 100);
 *  scooter.printModel();
 *  ref Vehicle vehicle = scooter;
 *  vehicle.printPrice();
 *  vehicle = new Vehicle("100");
 *  vehicle.printPrice();
 * 
 *  // [Error]: vehicle.printModel();
 *  // [Error]: ref Scooter scooter = vehicle
 *  // [Error]: Vehicle v = new Scooter("Activa", 100)
*/

int main(){
	struct Scooter* scooter = __constructor_Scooter(NULL, "Activa", 100);
	scooter->printModel(scooter);
	struct Vehicle* vehicle = (struct Vehicle*)scooter;
	vehicle->printPrice(vehicle);
	vehicle = __constructor__Vehicle(NULL, 100);
	vehicle->printPrice(vehicle);
}