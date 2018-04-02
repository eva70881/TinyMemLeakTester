#include <stdio.h>
#include <stdlib.h>
#include "tiny_mem_leak_tester.h"

int main(int argc, char** argv)
{
    printf("Start\n");
    char* t = (char*)malloc(sizeof(char) * 100);
    char* q = (char*)malloc(sizeof(char) * 100);
    char* w = (char*)malloc(sizeof(char) * 100);
    char* e = (char*)malloc(sizeof(char) * 100);
    char* r = (char*)realloc(t, sizeof(char) * 50);
    free(r);
    free(q);
    free(w);
    free(e);
    Get_Result();
    return 0;
}