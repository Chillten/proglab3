//
// Created by chillten on 02.04.17.
//

#ifndef PROGLAB3_CODER_H
#define PROGLAB3_CODER_H

#include <sys/types.h>
#include <stdio.h>
#include <inttypes.h>

enum {
    MaxCodeLength = 4
};

typedef struct {
    uint8_t code[MaxCodeLength];
    size_t length;
} CodeUnits;
uint32_t getBits(uint32_t from, uint32_t to);
int encode(uint32_t code_point, CodeUnits *code_units);
uint32_t decode(const CodeUnits *code_units);
int read_next_code_unit(FILE *in, CodeUnits *code_units);
int write_code_unit(FILE *out, const CodeUnits *code_units);

#endif //PROGLAB3_CODER_H
