#include <stddef.h>
#include "./module.h"


struct DeletePromise {
    void* pointer;
} __attribute__ (
    (packed)
);

void* new_mem_set(int c, size_t size) {
    char* result = malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < size; i++) {
        result[i] = (char) c;
    }
    return (void*) result;
}

void _idt_set(struct idt_state state, int interrupt_no, void* address) {
    struct idt_desc desc = state.idt_descriptors[interrupt_no];
    desc.offset_1 = (uint32_t) address & 0x0000ffff;
    desc.selector = KERNEL_CODE_SELECTOR;
    desc.zero = 0x00;
    return state;
}

struct idtr_desc generate(struct idtr_desc input, struct idt_desc* idt_array) {
    input.limit = sizeof(idt_array) - 1;
    input.base = idt_array;
    return input;
}

struct idt_state _idt_init(struct idt_state state) {
    state.idt_descriptors = new_mem_set(0, sizeof(state.idt_descriptors));
    state.idtr_descriptor.limit = sizeof(state.idt_descriptors) - 1;
    state.idtr_descriptor.base = state.idt_descriptors;
    return state;
}