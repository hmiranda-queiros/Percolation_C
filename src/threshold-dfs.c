#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "grid.h"
#include "loader.h"
#include "image_generator.h"
#include "percolate_dfs.h"
#include "monte_carlo_dfs.h"




int main(int argc, char *argv[]) {
	Grid test;
	int height = 300;
	int width = 300;
	int seed = 1024;
	int nb_tot_simu = 50;

	monte_carlo (&test, height, width, seed, nb_tot_simu);

    return 0;    

}
