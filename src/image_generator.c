#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "image_generator.h"
#include "grid.h"
#include "loader.h"

int image_generator(int argc, char *argv[], Grid* p_struct_grid) {
    int height = p_struct_grid->height;
    int width = p_struct_grid->width;
    Cell* p_g = p_struct_grid->p_grid;

    FILE *p_file = NULL;

    char my_string[100];
    sprintf (my_string, "./out/%s.ppm", argv[1]);
    
	
    p_file = fopen(my_string, "w");

    if (p_file == NULL) {
        fprintf(stderr, "Cannot write ! \n");
        exit(EXIT_FAILURE);
    }

    fprintf(p_file, "P%d\n",3);
    fprintf(p_file, "%d %d\n", width, height);
    fprintf(p_file, "%d\n", 255);

    for (int i = 0; i < height; i++) {

        for (int j = 0; j < width; j++){
            if ( p_g[i*width + j].color == 'B'){
                fprintf(p_file, "%d %d %d  ", 0, 0, 0);
            }

            if (p_g[i*width + j].color == 'R'){
                fprintf(p_file, "%d %d %d  ", 255, 0, 0);
            }

            if (p_g[i*width + j].color == 'W'){
                fprintf(p_file, "%d %d %d  ", 255, 255, 255);
            }
        }
        fprintf(p_file, "\n");
    }

    fclose(p_file);

    p_file = NULL;

    return EXIT_SUCCESS;

}



int image_generator_monte_carlo (Grid* p_struct_grid, int nb_simu, int seed){
    int height = p_struct_grid->height;
    int width = p_struct_grid->width;
    Cell* p_g = p_struct_grid->p_grid;

    FILE *p_file = NULL;

    char my_string[100];
    sprintf (my_string, "./out/test-mc-dfs-%d-%d.ppm",seed,nb_simu);

    p_file = fopen(my_string, "w");

    if (p_file == NULL) {
        fprintf(stderr, "Cannot write ! \n");
        exit(EXIT_FAILURE);
    }

    fprintf(p_file, "P%d\n",3);
    fprintf(p_file, "%d %d\n", width, height);
    fprintf(p_file, "%d\n", 255);

    for (int i = 0; i < height; i++) {

        for (int j = 0; j < width; j++){
            if (p_g[i*width + j].color == 'B'){
                fprintf(p_file, "%d %d %d  ", 0, 0, 0);
            }

            if (p_g[i*width + j].color == 'R'){
                fprintf(p_file, "%d %d %d  ", 255, 0, 0);
            }

            if (p_g[i*width + j].color == 'W'){
                fprintf(p_file, "%d %d %d  ", 255, 255, 255);
            }
        }
        fprintf(p_file, "\n");
    }

    fclose(p_file);

    p_file = NULL;

    return EXIT_SUCCESS;

}


