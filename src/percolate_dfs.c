#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "image_generator.h"
#include "grid.h"
#include "loader.h"
#include "percolate_dfs.h"

bool test_percolate_dfs (Grid test){
    int width = test.width;
    Cell* p_g = test.p_grid;

    for (int j = 0; j < width; j++){
        if (p_g[j].color == 'W' && percolate_dfs(test, p_g, 0, j)){    // We start from the first row.
            return true;

        }
    }
    return false;

}

bool percolate_dfs (Grid test, Cell* p_g, int i, int j){
    bool Boo = false;
    int width = test.width;

    if (p_g[i*width + j].color == 'W'){
        p_g[i*width + j].color = 'R';
        p_g[i*width + j].visited = true;
    }

    if (i == (test.height - 1) && p_g[i*width + j].color == 'R'){
        return true;
    }

    if (i != (test.height - 1) && p_g[(i + 1)*width + j].color == 'W'){
        Boo = percolate_dfs(test, p_g, i + 1, j);
    }

    if (Boo) return Boo;

    if ( j != 0 && p_g[i*width + j - 1].color == 'W'){
        Boo = percolate_dfs(test, p_g, i, j - 1);
    }

    if (Boo) return Boo;

    if (j != (test.width - 1) && p_g[i*width + j + 1].color == 'W'){
        Boo = percolate_dfs(test, p_g , i, j + 1);
    }

    if (Boo) return Boo;

    if ( i != 0 && p_g[(i - 1)*width + j].color == 'W'){
        Boo = percolate_dfs(test, p_g, i - 1, j);
    }


    return Boo;

}
