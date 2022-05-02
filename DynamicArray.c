#include "DynamicArray.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INCREMENT_SIZE 10

DynamicArray* create_dynamic_array(int initialSize) {
    DynamicArray* a = malloc(sizeof(DynamicArray));
    // Failed allocation
    if (!a) return NULL;

    a->size = 0;
    a->maxSize = initialSize;
    a->incrementSize = INCREMENT_SIZE;

    a->array = calloc(initialSize, sizeof(void*));

    return a;
}

void destroy_dynamic_array(DynamicArray* a) {
    free(a->array);
    free(a);
}

int dynamic_array_add_element(DynamicArray* a, void* element) {
    // If size has reached the initial maxSize, realloc the array to add more
    if (a->size == a->maxSize) {
        a->array = realloc(a->array, (a->maxSize + a->incrementSize) * sizeof(void*));
        a->maxSize += a->incrementSize;
    }

    a->array[a->size] = element;

    (a->size)++;

    return 1;
}

int dynamic_array_remove_element(DynamicArray* a, int index) {
    if (index >= a->size) {
		fprintf(stderr, "Index should be less than size\n");
		return 0;
	}
	
	if (index < 1) {
		fprintf(stderr, "Index should be more than 0\n");
		return 0;
	}

    free(a->array[index]);

    // Shifting
    for (int i = index; i < a->size; i++)
        a->array[i] = a->array[i + 1];

    // Null out the last elment that got shifted
    a->array[a->size] = NULL;

    (a->size)--;

    return 1;
}

int dynamic_array_free_contents(DynamicArray* a) {
    for (int i = 0; i < a->size; i++)
        free(a->array[i]);
    return 1;
}
