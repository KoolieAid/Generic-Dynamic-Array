#include "DynamicArray.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

struct TestObject {
    int a;
    char* b;
};

int main() {
    // Usage
    struct TestObject* obj = malloc(sizeof(struct TestObject));
    obj->a = 1;
    obj->b = "yo";

    struct TestObject* obj2 = malloc(sizeof(struct TestObject));
    obj2->a = 2;
    obj2->b = "string literal";

    // Creating the array
    DynamicArray* dyArr = create_dynamic_array(10);
    // Adding the object
    dynamic_array_add_element(dyArr, obj);
    dynamic_array_add_element(dyArr, obj2);
    dynamic_array_add_element(dyArr, calloc(1, sizeof(struct TestObject)));

    // Printing the objects (Up to the user of how it prints, because you have to type cast it)
    for (int i = 0; i < dyArr->size; i++) {
        struct TestObject* a = (struct TestObject*) dyArr->array[i]; // Need to cast from void*
        printf("a: %d\nb: %s\n", a->a, a->b);
    }
    
    bool b = dynamic_array_remove_element(dyArr, 3); // Will give false, because it errored
    printf("\nError? %d\n\n", b);

    dynamic_array_remove_element(dyArr, 1); // Will remove last element

    // Just a copy of the printing part
    for (int i = 0; i < dyArr->size; i++) {
        struct TestObject* a = (struct TestObject*) dyArr->array[i]; // Need to cast from void*
        printf("a: %d\nb: %s\n", a->a, a->b);
    }

    dynamic_array_free_contents(dyArr); // Freeing util function so you dont have to do it yourself
    // Make sure not to use the contents after doing using this function, since everything is already freed

    // After using, make sure to destroy the array itself
    destroy_dynamic_array(dyArr);

    // Make sure not use the Dynamic Array after destroying it

    return 0;
}
