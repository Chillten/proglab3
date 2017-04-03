//
// Created by chillten on 02.04.17.
//
#include "coder.h"
#include "math.h"

uint32_t getBits(uint32_t from, uint32_t to){
    return pow(2, from + 1) - pow(2, to);
}

int encode(uint32_t code_point, CodeUnits *code_units){
    size_t size = 1;
    if((code_point & getBits(20, 16)) > 0){
        size = 4;
    } else if((code_point & getBits(15, 11)) > 0){
        size = 3;
    } else if((code_point & getBits(10, 7)) > 0){
        size = 2;
    }
    code_units->length = size;
    for(int isize = size; isize > 1; isize--, code_point >>= 6){
        code_units->code[isize - 1] = (0x80 | (getBits(5,0) & code_point));
    }
    if(size > 1){
        code_units->code[0] = (((uint8_t)pow(2, size) - 1) << (8 - size)) | code_point;
    } else {
        code_units->code[0] = code_point;
    }
    return 0;
}
uint32_t decode(const CodeUnits *code_units){
    uint32_t a = 0;
    for(int i = 0; i < code_units->length - 1; i++){
        a |= ((getBits(5,0) & code_units->code[code_units->length - i - 1])) << (6 * i);
    }  
    a |= (getBits(8 - code_units->length - 1,0) & code_units->code[0]) << ((code_units->length - 1) * 6);
    return a;
}
int read_next_code_unit(FILE *in, CodeUnits *code_units){
    
}
int write_code_unit(FILE *out, const CodeUnits *code_units){
    if(out != NULL){
        fwrite(code_units->code, sizeof(uint8_t), code_units->length, out);
        return 0;
    } else {
        return -1;
    }
}