#ifndef DYNA_ARR_H
#define DYNA_ARR_H

struct DynamicArray {
    int size;
    int maxSize;
    int incrementSize;
    void** array; // Array of void* pointers
};

typedef struct DynamicArray DynamicArray;

DynamicArray* create_dynamic_array(int initialSize);

void destroy_dynamic_array(DynamicArray* a);

int dynamic_array_add_element(DynamicArray* a, void* element);

int dynamic_array_remove_element(DynamicArray* a, int index);

int dynamic_array_free_contents(DynamicArray* a);

#endif
