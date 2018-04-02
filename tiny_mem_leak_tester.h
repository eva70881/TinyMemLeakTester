#ifndef TINY_MEM_LEAK_TESTER_H_
#define TINY_MEM_LEAK_TESTER_H_

void* tiny_mem_leak_malloc(size_t size, const char *file, int line, const char *func);
void* tiny_mem_leak_realloc(void* pointer, size_t size, const char *file, int line, const char *func);
void tiny_mem_leak_free(void* pointer, const char *file, int line, const char *func);

#define malloc(X) tiny_mem_leak_malloc( X, __FILE__, __LINE__, __FUNCTION__)
#define realloc(X, Y) tiny_mem_leak_realloc(X, Y, __FILE__, __LINE__, __FUNCTION__)
#define free(X) tiny_mem_leak_free( X, __FILE__, __LINE__, __FUNCTION__)

void Get_Result();

#endif