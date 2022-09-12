#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "grid.h"
#include "loader.h"


int main(int argc, char *argv[]) {
    Grid test ;

    get_shape(argc, argv, &test.height, &test.width);

    create_pointer_Cell(&test);

    build_struct(argc, argv, test);

    print_grid(test);

    free_grid(test);

    return 0;

}
