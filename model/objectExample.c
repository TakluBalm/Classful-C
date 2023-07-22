#include <vehicle.h>
#include <stddef.h>

/**
 * int main(){
 *   Vehicle implicitStackVehicle = new Vehicle(1); // local by default
 *   local Vehicle explicitStackVehicle = new Vehicle(2);
 *   ref heapVehicle = new Vehicle(3);
 *   
 *   implicitStackVehicle.printPrice();
 *   explicitStackVehicle.printPrice();
 *   heapVehicle.printPrice();
 * }
*/
int main(){
	struct Vehicle implicitStackVehicle;
	__constructor__Vehicle(&implicitStackVehicle, 1);
	struct Vehicle explicitStackVehicle;
	__constructor__Vehicle(&explicitStackVehicle, 2);
	
	struct Vehicle* heapVehicle = __constructor__Vehicle(NULL, 3);

	implicitStackVehicle.printPrice(&implicitStackVehicle);
	explicitStackVehicle.printPrice(&explicitStackVehicle);
	heapVehicle->printPrice(heapVehicle);
}