#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>


#include "union_find.h"


int main(int argc, char *argv[]){
    Grid_uf test;
    int height = 1000;
    int width = 1000;
    test.height = height;
    test.width = width;
    test.p_grid_uf = create_uf(height*width + 2);
    Cell_uf* p_g = test.p_grid_uf;
    int n;
    
    for (int r = 0; r < height; r++ ){
			for (int c = 0; c < width; c++ ){
				
			n = r*width + c;

			if (n%4 == 0){
				merge_uf(&p_g[n],p_g);
				assert(find_uf(&p_g[n]) == find_uf(p_g));
			}

			else if (n%4 == 1){
				merge_uf(&p_g[n],&p_g[1*width]);
				assert(find_uf(&p_g[n]) == find_uf(&p_g[1*width]));
			}

			else if (n%4 == 2){
				merge_uf(&p_g[n],&p_g[2*width]);
				assert(find_uf(&p_g[n]) == find_uf(&p_g[2*width]));
			}

			else if (n%4 == 3){
				merge_uf(&p_g[n],&p_g[3*width]);
				assert(find_uf(&p_g[n]) == find_uf(&p_g[3*width]));
			}

			}
			
		}

    free(p_g);


    return 0;
}
