#ifndef MEMORY_H
#define MEMORY_H
#include <stddef.h>




void* mem_init(int c, size_t size);

void _mem_set(void** ptr, int c, size_t size);



#endif