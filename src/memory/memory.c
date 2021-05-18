#include "memory.h"




void* new_mem_set(int c, size_t size) {
    char* result = malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < size; i++) {
        result[i] = (char) c;
    }
    return (void*) result;
}

void _mem_set(void** ptr, int c, size_t size) {
    *ptr = new_mem_set(c, size);
}