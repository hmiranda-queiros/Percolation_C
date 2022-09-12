#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "grid.h"
#include "loader.h"
#include "image_generator.h"
#include "percolate_dfs.h"

int main(int argc, char *argv[]) {
    Grid test;

    get_shape(argc, argv, &test.height, &test.width);

    create_pointer_Cell(&test);

    build_struct(argc, argv, test);

    if (test_percolate_dfs(test)) printf ("it percolates");

    else printf ("it does not percolate");

    image_generator(argc, argv, &test);

    free_grid(test);

    return 0;

}
