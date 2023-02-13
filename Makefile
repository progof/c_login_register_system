BUILD_DIR = build
CC = gcc

build_dir:
	if [ ! -d $(BUILD_DIR) ]; then mkdir $(BUILD_DIR); fi

run: main.c
	gcc ./src/main.c -o ./$(BUILD_DIR)/main

clean:
	rm -r ./$(BUILD_DIR)/*	