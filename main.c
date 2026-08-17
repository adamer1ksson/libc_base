#include "stdio.h"

#include "./include/base.h"

#include "./include/arena.h"
#include "./include/matrix.h"
#include "./include/vector.h"
#include "./include/linalg.h"
#include "./include/random.h"
#include "./include/sorting.h"

#include "./src/arena.c"
#include "./src/matrix.c"
#include "./src/vector.c"
#include "./src/linalg.c"
#include "./src/random.c"
#include "./src/sorting.c"

int main() {
    random_init();
    f32* arr = (f32*)malloc(10000*sizeof(float));
    for (size_t i = 0; i < 10000; i++) {
        arr[i] = uniform_standard();
    }
    TICK
    bubble_sort(arr, sizeof(f32), (size_t) 10000, compare_float);
    TOCK
    free(arr);
    return 0;

}
