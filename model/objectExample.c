#include <vehicle.h>
#include <stddef.h>

/**
 * int main(){
 *   local Vehicle stackVehicle = new Vehicle(1000);
 *   ref Vehicle heapVehicle = new Vehicle(2000);
 *   
 *   stackVehicle.printPrice()
 *   heapVehicle.printPrice()
 * }
*/
int main(){
	struct Vehicle stackVehicle;
	__constructor__Vehicle(&stackVehicle, 1000);
	struct Vehicle* heapVehicle = __constructor__Vehicle(NULL, 2000);

	stackVehicle.printPrice(&stackVehicle);
	heapVehicle->printPrice(heapVehicle);
}