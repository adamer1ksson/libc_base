#include "../include/sorting.h"
#include "../include/base.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

bool compare_uint(const void* a, const void* b) {
    u64* x = (u64*)a;
    u64* y = (u64*)b;
    return x[0] < y[0];
}

bool compare_int(const void* a, const void* b) {
    i64* x = (i64*)a;
    i64* y = (i64*)b;
    return x[0] < y[0];
}

bool compare_float(const void* a, const void* b) {
    f32* x = (f32*)a;
    f32* y = (f32*)b;
    return x[0] <= y[0];
}

bool compare_double(const void* a, const void* b) {
    f64* x = (f64*)a;
    f64* y = (f64*)b;
    return x[0] <= y[0];
}

static inline bool swap_by_long_check(void* a, void* b, size_t size) {
    bool aligned = ( ( (uintptr_t) a | (uintptr_t) b ) % sizeof(u64) ) == 0;
    return (aligned && (size % sizeof(u64) == 0));
}

static void swap(void* a, void* b, size_t size, bool swap_by_long) {
    if (!swap_by_long) {
        u8 temp;
        u8* x = (u8*)a;
        u8* y = (u8*)b;
        for (size_t i = 0; i < size; i++) {
            temp = x[i];
            x[i] = y[i];
            y[i] = temp;
        }
    } else { // swap_by_long == true
        u64 temp;
        u64* x = (u64*) a;
        u64* y = (u64*) b;
        for (size_t i = 0; i < size; i++) {
            temp = x[i];
            x[i] = y[i];
            y[i] = temp;
        }
    }
}

void bubble_sort(void* array, size_t element_size, size_t length, compare_func compare) {
    u32 swaps = 1;
    void* temp = malloc(element_size);
    u8* base_ptr = (u8*)array;

    while (swaps > 0) {
        swaps = 0;
        for (size_t i = 0; i < length - 1; i++) {
            void* a = base_ptr + i*element_size;
            void* b = base_ptr + (i+1)*element_size;
            if (compare(a, b) == false) {
                SWAP(a, b, temp, element_size);
                swaps += 1;
            }         
        } 
    }

    free(temp);
}

void insertion_sort(void* array, size_t element_size, size_t length, compare_func compare) {
    void* temp = malloc(element_size);
    u8* base_ptr = (u8*)array;
    for (size_t i = 1; i < length; i++) {
        void* curr_el = base_ptr + i*element_size;
        while (compare(curr_el, curr_el - element_size) == false) {
            SWAP(curr_el, curr_el - element_size, temp, element_size);
        }
        
    }
    free(temp);
}

void quick_sort(void* array, size_t element_size, size_t length, compare_func compare);

