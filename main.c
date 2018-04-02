#include <stdio.h>
#include <stdlib.h>
#include "tiny_mem_leak_tester.h"

int main(int argc, char** argv)
{
    printf("Start\n");
    char* t = (char*)malloc(sizeof(char) * 100);
    free(t);
    return 0;
}