#pragma once

#include "stdint.h"
#include "stdbool.h"

typedef uint8_t     u8 ;
typedef uint16_t    u16;
typedef uint32_t    u32;
typedef uint64_t    u64;
typedef int8_t      i8 ;
typedef int16_t     i16;
typedef int32_t     i32;
typedef int64_t     i64;

typedef float       f32;
typedef double      f64;

#ifndef PI
#define PI 3.14159265358979323846
#endif

#define MAX(a, b) ( (a) > (b) ? (a) : (b))
#define MIN(a, b) ( (a) > (b) ? (b) : (a))

#define NUM_FLOATS(n) ( (u64)n*sizeof(f32) )
#define TICK struct timespec start, end; clock_gettime(CLOCK_MONOTONIC, &start);
#define TOCK clock_gettime(CLOCK_MONOTONIC, &end); \
             printf("Exec time: %0.3f ms\n", ((end.tv_sec - start.tv_sec) + \
             (end.tv_nsec - start.tv_nsec) / 1e9) * 1000);
