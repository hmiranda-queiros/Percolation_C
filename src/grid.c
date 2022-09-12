#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "grid.h"


void create_pointer_Cell(Grid* p_struct_grid) {
    int height = p_struct_grid->height;
    int width = p_struct_grid->width;

    p_struct_grid->p_grid = malloc(height*width*sizeof(Cell));

}


void print_grid(Grid test) {
    int height = test.height;
    int width = test.width;
    Cell* p_g = test.p_grid;

    for (int i = 0; i < height; i++) {
        for (int j=0; j < width; j++) {
            if (p_g[i*test.width + j].color == 'B') printf("#");
            else if (p_g[i*test.width + j].color == 'W') printf(" ");
            else if (p_g[i*test.width + j].color == 'R') printf("X");

        }
        printf("\n");
    }
}


void free_grid(Grid test){
    free(test.p_grid);
}
