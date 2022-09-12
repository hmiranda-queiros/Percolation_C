#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "union_find.h"
#include "monte_carlo_uf.h"

int main(int argc, char *argv[]){
    Grid_uf test;
	int height = 300;
	int width = 300;
	int seed = 1024;
	int nb_tot_simu = 50;

	monte_carlo_uf (&test, height, width, seed, nb_tot_simu);

    return 0;

}
