#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "union_find.h"


Cell_uf* create_uf(int nb){
    Cell_uf* p_grid_uf = malloc(nb*sizeof(Cell_uf));
    
    for (int i = 0; i < nb; i++){
        p_grid_uf[i].rank_uf = 0;
        p_grid_uf[i].p_cell_uf =  &p_grid_uf[i];
        p_grid_uf[i].open = false;
    }

    return p_grid_uf;
}

Cell_uf* find_uf(Cell_uf* e){
	if (e == e->p_cell_uf) return e;
	
	e->p_cell_uf = find_uf(e->p_cell_uf);
	
	return e->p_cell_uf;
}


void merge_uf(Cell_uf* e1, Cell_uf* e2){
    Cell_uf* r1 = find_uf(e1);
    Cell_uf* r2 = find_uf(e2);

    if (e1->rank_uf == e2->rank_uf){
        r2->p_cell_uf = r1;
        r1->rank_uf ++;
    }

    else if (e1->rank_uf > e2->rank_uf){
        r2->p_cell_uf = r1;
    }

    else {
        r1->p_cell_uf = r2;
    }

}


