#pragma once

#include "base.h"
#include "stdlib.h"

#define SWAP(a, b, temp, size)  memcpy(temp, a, size);          \
                                memcpy(a, b, element_size);     \
                                memcpy(b, temp, element_size);

typedef bool (*compare_func)(const void*, const void*);

bool compare_uint(const void* a, const void* b);
bool compare_int(const void* a, const void* b);
bool compare_float(const void* a, const void* b);
bool compare_double(const void* a, const void* b);

static inline bool swap_by_long_check(void* a, void* b, size_t size);
static void swap(void* a, void* b, size_t size, bool swap_by_long);
void bubble_sort(void* array, size_t element_size, size_t length, compare_func compare);
void insertion_sort(void* array, size_t element_size, size_t length, compare_func compare);
void quick_sort(void* array, size_t element_size, size_t length, compare_func compare);

