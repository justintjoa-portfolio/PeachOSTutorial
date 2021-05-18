#ifndef IDT_H
#define IDT_H

#include <stdint.h>

struct idt_desc {
    uint16_t offset_1; //Offset bits 0 - 15
    uint16_t selector; //Selector that is in our GDT
    uint8_t zero;
    uint8_t type_attr;
    uint16_t offset_2; 

} __attribute__(
    (packed)
);

struct idtr_desc {
    uint16_t limit; //Size of descriptor table - 1
    uint32_t base; //Base addreess of the start of the table

} __attribute__(
    (packed)
);


struct idt_state {
    struct idt_desc descriptor;
    struct idtr_desc counter;

} __attribute__(
    (packed)
);

#endif
