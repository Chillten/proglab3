#compile
CC = gcc
CFLAG = -Wall -Werror
ENDFLAG = -lm
TESTFLAG = -I thirdparty -I $(SRC) $(CFLAG)
#folder define
SRC = src
BIN = bin
BUILD = build/src
DIRGUARD=@mkdir -p $(@D)
#target
TARGET   = main
#sources
SOURCES  := $(wildcard $(SRC)/*.c)
#INCLUDES := $(wildcard $(SRC)/*.h)
#objects
OBJECTS  := $(SOURCES:$(SRC)/%.c=$(BUILD)/%.o)

rm       = rm -f

#target
$(BIN)/$(TARGET): $(OBJECTS)
	@$(DIRGUARD)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(ENDFLAG)
	@echo "Linking complete!"

#build objects
$(OBJECTS): $(BUILD)/%.o : $(SRC)/%.c
	@$(DIRGUARD)
	@$(CC) $(CFLAGS) -c $< -o $@ $(ENDFLAG)
	@echo "Compiled "$<" successfully!"


.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@$(rm) $(OBJECTSTEST)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BIN)/*
	@echo "Executable removed!"