#ifndef MODULE_H
#define MODULE_H

#include <stddef.h>
#include "../idt/idt.h"

struct DeletePromise {
    void* pointer;
} __attribute__ (
    (packed)
);

void* new_mem_set(int c, size_t size);

struct idt_state idt_set(struct idt_state state, int interrupt_no, void* address);

struct idtr_desc generate(struct idtr_desc input, struct idt_desc* idt_array);

struct idt_state idt_init(struct idt_state state, void* address);

#endif