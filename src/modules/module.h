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

void idt_set(struct idt_state state, int interrupt_no, void* address);

struct idtr_desc generate(struct idtr_desc input, struct idt_desc* idt_array) {
    input.limit = sizeof(idt_array) - 1;
    input.base = idt_array;
    return input;
}

struct idt_state idt_init(struct idt_state state, void* address) {
    state.idt_descriptors = new_mem_set(0, sizeof(state.idt_descriptors));
    state.idtr_descriptor.limit = sizeof(state.idt_descriptors) - 1;
    state.idtr_descriptor.base = state.idt_descriptors;
    return state;
}

#endif