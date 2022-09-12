#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "grid.h"

int main(int argc, char *argv[]) {
    Grid test;
    test.height = 5;
    test.width = 2;

    create_pointer_Cell(&test);

    Cell* p_g = test.p_grid;

    for (int i = 0; i < test.height; i++) {
        for (int j = 0; j < test.width; j++){
            p_g[i*test.width + j].color = 'B';

        }
    }

    print_grid(test);

    free_grid(test);

    return 0;

}
