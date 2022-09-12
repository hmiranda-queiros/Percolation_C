#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "union_find.h"
#include "monte_carlo_uf.h"

void monte_carlo_uf(Grid_uf* p_struct_grid, int height, int width, int seed, int nb_tot_simu){
    p_struct_grid->height = height;
    p_struct_grid->width = width;
    Cell_uf* p_g = NULL;

    srand(seed);
    int z = 0;
    int c;
    int l;

    int top = height*width;
    int bottom = height*width + 1;
    Cell_uf* r;

    for (int y = 1; y <= nb_tot_simu; y++ ){
		z = 0;

		p_struct_grid->p_grid_uf = create_uf(height*width + 2);

		p_g = p_struct_grid->p_grid_uf;

		while (find_uf(&p_g[top]) != find_uf(&p_g[bottom])){
            c = rand()%width;
            l = rand()%height;
			
			while (p_g[l*width + c].open != false){
				c = rand()%width;
				l = rand()%height;	
				}
			
			p_g[l*width + c].open = true;
			
            if (l == 0){
                r = find_uf(&p_g[c]);
                r->p_cell_uf = &p_g[top];
            }

            if (l == height - 1){
                r = find_uf(&p_g[l*width + c]);
                r->p_cell_uf = &p_g[bottom];
            }

            else {
                if ( c != width && p_g[l*width + c + 1].open == true){
                    merge_uf(&p_g[l*width + c], &p_g[l*width + c + 1]);
                }

                if ( c != 0 && p_g[l*width + c - 1].open == true){
                    merge_uf(&p_g[l*width + c], &p_g[l*width + c - 1]);
                }

                if ( l != height && p_g[(l + 1)*width + c].open == true){
                    merge_uf(&p_g[l*width + c], &p_g[(l + 1)*width + c]);
                }

                if ( l != 0 && p_g[(l - 1)*width + c].open == true){
                    merge_uf(&p_g[l*width + c], &p_g[(l - 1)*width + c]);
                }

            }

            z++;

		}

		printf("For the simulation %d the number of cells opened is : %d\n",y,z);

		free(p_g);

    }

}
