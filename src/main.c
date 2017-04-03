#include <stdio.h>
#include <stdlib.h>
#include "coder.h"

int main(int argc, char *argv[])
{
    CodeUnits* unit = malloc(sizeof(CodeUnits));

    for(uint32_t i = 0; i < pow(2, 21) - 1; i++){
    	encode(i, unit);
    	if(i != decode(unit))
    		printf("%x %x\n", i, decode(unit));
    }

    free(unit);
    return 0;
}