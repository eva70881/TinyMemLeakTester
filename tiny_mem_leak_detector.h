#ifndef TINY_MEM_LEAK_TESTER_H_
#define TINY_MEM_LEAK_TESTER_H_

void* tiny_mem_leak_malloc(size_t size, const char *file, int line, const char *func);

#define malloc(X) tiny_mem_leak_malloc( X, __FILE__, __LINE__, __FUNCTION__)

#endif