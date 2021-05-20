#include "idt.h"
#include "config.h"



struct InterruptDescriptorTable table;

void setState(struct idt_state newState) {
    cleanUp(table.state);
    table.state = newState;
}
