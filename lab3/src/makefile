CC=gcc
CFLAGS=-I.

BUILD_DIR=build/
BIN_DIR=bin/

all: sequential_min_max parallel_min_max forx_exec

sequential_min_max : $(BUILD_DIR)utils.o $(BUILD_DIR)find_min_max.o
	mkdir -p $(BIN_DIR)
	$(CC) -o "$(BIN_DIR)$@" $^ sequential_min_max.c $(CFLAGS)

parallel_min_max : $(BUILD_DIR)utils.o $(BUILD_DIR)find_min_max.o
	mkdir -p $(BIN_DIR)
	$(CC) -o "$(BIN_DIR)$@" $^ parallel_min_max.c $(CFLAGS)

$(BUILD_DIR)utils.o : utils.c
	mkdir -p $(BUILD_DIR)
	$(CC) -o $@ -c $^ $(CFLAGS)

$(BUILD_DIR)find_min_max.o : find_min_max.c
	mkdir -p $(BUILD_DIR)
	$(CC) -o $@ -c $^ $(CFLAGS)

fork_exec : $(BUILD_DIR)fork_exec.o sequential_min_max
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BIN_DIR)
	$(CC) -o $(BIN_DIR)$@ $(BUILD_DIR)fork_exec.o $(CFLAGS)

$(BUILD_DIR)fork_exec.o : fork_exec.c
	mkdir -p $(BUILD_DIR)
	$(CC) -o $@ -c $^ $(CFLAGS)

clean :
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)
	rm -f .shared_data.txt
