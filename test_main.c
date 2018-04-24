#include <stdio.h>
#include <stdlib.h>
#include "tiny_mem_leak_tester.h"

int main(int argc, char** argv)
{
    printf("--Main program start--\n");
    char* t = (char*)malloc(sizeof(char) * 100);
    char* q = (char*)malloc(sizeof(char) * 100);
    char* w = (char*)malloc(sizeof(char) * 100);
    char* e = (char*)malloc(sizeof(char) * 100);
    char* r = (char*)realloc(t, sizeof(char) * 50);
    char* t1 = (char*)malloc(sizeof(char) * 100);
    char* t2 = (char*)malloc(sizeof(char) * 100);
    char* t3 = (char*)malloc(sizeof(char) * 100);
    char* t4 = (char*)malloc(sizeof(char) * 100);
    char* t5 = (char*)malloc(sizeof(char) * 100);
    char* t6 = (char*)malloc(sizeof(char) * 100);
    char* t7 = (char*)malloc(sizeof(char) * 100);
    char* t8 = (char*)malloc(sizeof(char) * 100);
    char* t9 = (char*)malloc(sizeof(char) * 100);
    char* t0 = (char*)malloc(sizeof(char) * 100);
    free(r);
    free(q);
    free(w);
    free(e);
    printf("--Main program end--\n");
    Get_Result();
    return 0;
}