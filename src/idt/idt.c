#include "idt.h"
#include "config.h"



struct InterruptDescriptorTable table;


extern void idt_load(struct idtr_desc* ptr);

void idt_zero() {
    print("Divide by zero error\n");
}

void setState(struct idt_state newState) {
    cleanUp(table.state);
    table.state = newState;
}


void _idt_init() {
    setState(idt_init(table.state, idt_zero));
    idt_load(&table.state.idtr_descriptor);
}