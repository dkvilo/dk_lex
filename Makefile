CC 							:= cc -std=c99 -w
FRAMEWORK 			:= .
SANDBOX_SOURCE 	:= source
BUILD_DIR 			:= build
BIN 						:= kc

FINAL_CFLAGS 		:= -I./$(FRAMEWORK) -Wno-deprecated
OPT							:= -Ofast

prepare:
	mkdir build

clean_bin:
	rm $(BUILD_DIR)/$(BIN)

clean:
	rm -rf $(BUILD_DIR)

build:
	make prepare && $(CC) $(SANDBOX_SOURCE)/*.c $(FINAL_CFLAGS) $(OPT) -o $(BUILD_DIR)/$(BIN)

.PHONY:
	build clean
