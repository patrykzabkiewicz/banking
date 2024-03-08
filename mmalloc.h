#ifndef MMALLOC_H
#define MMALLOC_H

#include <unistd.h>

static class MMA {
public:
	static void mmalloc() {}
	static void mfree() {}
};

typedef struct free_block {
    size_t size;
    struct free_block* next;
} free_block;

static free_block free_block_list_head = { 0, 0 };
static const size_t overhead = sizeof(size_t);
static const size_t align_to = 16;

void* mmalloc(size_t size);

void mfree(void* ptr);

#endif // MMALLOC_H
