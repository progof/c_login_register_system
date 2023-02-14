TARGET = LogRegSys
BUILD_DIR = build
PREF_SRC = ./src/
PREF_OBJ = ./$(BUILD_DIR)/obj/
CC = gcc

SRC = $(wildcard $(PREF_SRC)*.c)
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))

build_dir:
  if [ ! -d $(BUILD_DIR) ]; then mkdir $(BUILD_DIR); fi

$(TARGET) : $(OBJ) build_dir
  $(CC) $(OBJ) -o ./$(BUILD_DIR)/$(TARGET)

$(PREF_OBJ)%.o : $(PREF_SRC)%.c build_dir
  $(CC) -c $< -o $@

clean:
  rm -r ./$(BUILD_DIR)/*
