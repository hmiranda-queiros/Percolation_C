#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "image_generator.h"
#include "grid.h"
#include "loader.h"
#include "percolate_dfs.h"
#include "monte_carlo_dfs.h"

void monte_carlo (Grid* p_struct_grid, int height, int width, int seed, int nb_tot_simu){
    p_struct_grid->height = height;
    p_struct_grid->width = width;
    Cell* p_g = NULL;

    srand(seed);
    int z = 0;
    int c = rand()%width;
    int l = rand()%height;

    for (int y = 1; y <= nb_tot_simu; y++ ){
		z = 0;

		create_pointer_Cell(p_struct_grid);

		p_g = p_struct_grid->p_grid;

		for (int i = 0; i < height; i++) {             // We initialize the grid with all the cells closed.
			for (int j = 0; j < width; j++) {
				p_g[i*width + j].row = i;
				p_g[i*width + j].column = j;
				p_g[i*width + j].open = false;
				p_g[i*width + j].visited = true;
				p_g[i*width + j].color = 'B';
			}
		}

        while (!test_percolate_dfs (*p_struct_grid)){
            for (int ip = 0; ip < height; ip++) {           // We clean the grid before testing it with test_percolate_dfs one more time.
                for (int jp = 0; jp < width; jp++) {
                    if (p_g[ip*width + jp].color == 'R'){
                        p_g[ip*width + jp].visited = false;
                        p_g[ip*width + jp].color = 'W';
                    }
                }
            }
            while (p_g[l*width + c].open != false){
                c = rand()%width;
                l = rand()%height;
            }
            p_g[l*width + c].open = true;
            p_g[l*width + c].visited = false;
            p_g[l*width + c].color = 'W';
            z++;

        }
        printf("For the simulation %d the number of cells opened is : %d\n",y,z);

        image_generator_monte_carlo(p_struct_grid, y, seed);

		free(p_g);
    }



}


