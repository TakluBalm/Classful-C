Classful-C
===

A new language that transpiles to C and has OOP features at its disposal

## Description
- Class keyword
- No structs
- Declaration and Definition together
- Everything is object.
- Every class definition inherits from a Object class (provided by the language)
- Standard C library can be accessed
- Objects can be of 2 types:
	1. Local: Allocated on the stack and thus faster allocation
		- Prefix initialization with the keyword `local`
		```java
		local Vehicle vehicle1 = new Vehicle(10);
		```
	2. Referencing: Allocated on heap and thus slower allocation
		- Prefix initialization with the keyword `ref`
		- It is the `default` type.
		```java
		//	Both are reference variables
		ref Vehicle vehicle = new Vehicle(10);
		Vehicle vehicle2 = new Vehicle(20)
		```
- Both types of objects can be converted into one another
- Local variable can be assigned a local/ref variable of same time only
- Ref variable can be assigned a local/ref variable of same or inherited type only