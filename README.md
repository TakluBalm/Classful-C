Classful-C
===

A new language that transpiles to C and has OOP features at its disposal

## Description
- Class keyword
- No structs
- Declaration and Definition together
- Everything is object
- Standard C library can be accessed
- Two types of variables for local and heap access:
	- `local` keyword for stack allocation
	```Java
	//	Vehicle object on stack
	local Vehicle = new Vehicle(100);
	```
	- `ref` keyword for heap allocation
	```Java
	//	Vehicle object on heap
	ref Vehicle = new Vehicle(1000);
	```