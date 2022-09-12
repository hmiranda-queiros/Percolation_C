#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#include "union_find.h"


int main(int argc, char *argv[]){
    FILE *p_file = NULL;

    char my_string[100];
    sprintf (my_string, "union_find_complexity.csv");

    p_file = fopen(my_string, "w");

    if (p_file == NULL) {
        fprintf(stderr, "Cannot write ! \n");
        exit(EXIT_FAILURE);
    }

    Grid_uf test;
    Cell_uf* p_g;
    int e;
    
    for (int n =10; n <= 1280; n += 2){
		
        test.p_grid_uf = create_uf(n*n + 2);
        p_g = test.p_grid_uf;
        
        
        
        double time_merge = 0;
        
        clock_t startm = clock();

		for (int r = 0; r < n; r++ ){
			for (int c = 0; c < n; c++ ){
		
				e= (rand()%n)*n + rand()%n;
				
				merge_uf(&p_g[r*n + c],&p_g[e]);
				
			}
		}
				
		clock_t endm = clock();
				
		time_merge = (double) (endm - startm) / CLOCKS_PER_SEC;



        double time_find = 0;
        
        clock_t startf = clock();
        
        for (int r = 0; r < n; r++ ){
                for (int c = 0; c < n; c++ ){
					
                    find_uf(&p_g[r*n + c]);
                }
        }
        
        clock_t endf = clock();
        
        time_find = (double) (endf - startf) / CLOCKS_PER_SEC;
        
        fprintf(p_file, "%d, %f, %f\n", n, time_merge, time_find);
        
        free(p_g);
    }

    fclose(p_file);

    p_file = NULL;

    return 0;
}


