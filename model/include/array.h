#ifndef CLASS_ARRAY_H
#define CLASS_ARRAY_H

#include <stdlib.h>

/**
 * array {
 *   long length;
 *   actual_array[];
 * }
*/

struct array_meta {
	long arraySize;
};

void* allocate_array(unsigned long length){
	struct array_meta* array = calloc(1, sizeof(void*)*length + sizeof(struct array_meta));
	array->arraySize = length;
	return array;
}

void* getIndex_array(struct array_meta* array, unsigned int index){
	if(index >= array->arraySize){
		return NULL;
	}
	void** objects = (void**)(array + 1);
	return *(objects+index);
}

void setIndex_array(struct array_meta* array, unsigned int index, void* value){
	if(index >= array->arraySize){
		return;
	}
	void** objects = (void**)(array + 1);
	*(objects + index) = value;
}

#endif