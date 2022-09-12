CC = gcc
CFLAGS = -g -std=c99 -Wall -Werror -O3 -I ./include
LDFLAGS = -O3 -flto

run_all : test_loader test_image test_percolate threshold-dfs
	./test_loader grid_visited.txt
	./test_image grid_visited.txt
	./test_percolate grid_p_9.txt
	./threshold-dfs 
	./test_correcteness
	./test_complexity
	./threshold-uf
	
run_valgrind : test_loader test_image test_percolate threshold-dfs
	valgrind ./test_loader grid_visited.txt
	valgrind ./test_image grid_visited.txt
	valgrind ./test_percolate grid_p_9.txt
	valgrind ./threshold-dfs 
	valgrind ./test_correcteness
	valgrind ./test_complexity
	valgrind ./threshold-uf

run_test_grid_val : test_grid
	valgrind ./$^

run_test_loader_val : test_loader
	valgrind ./$^ grid_visited.txt

run_test_image_val : test_image
	valgrind ./$^ grid_visited.txt

run_test_percolate_val : test_percolate
	valgrind ./$^ grid_p_9.txt

run_threshold-dfs_val : threshold-dfs
	valgrind ./$^

run_test_correcteness_val : test_correcteness
	valgrind ./$^

run_test_complexity_val : test_complexity
	valgrind ./$^

run_threshold-uf_val : threshold-uf
	valgrind ./$^

%.o: ./src/%.c
	$(CC) $(CFLAGS) -o $@ -c $^


test_grid : grid.o test-print-grid.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_loader : loader.o grid.o test-loader.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_image : loader.o grid.o image_generator.o test-generate-image.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_percolate : loader.o grid.o test-percolate.o percolate_dfs.o image_generator.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

threshold-dfs : loader.o grid.o percolate_dfs.o image_generator.o monte_carlo_dfs.o threshold-dfs.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_correcteness : union_find.o test-union-find-correcteness.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_complexity : union_find.o test-union-find-complexity.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

threshold-uf : union_find.o monte_carlo_uf.o threshold-uf.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


doc:
	doxygen conf/doxygen.conf
