# Makefile de l'interpréteur (TP3, TP4 et TP5)
#
#   make          compile l'interpréteur (seuls les fichiers modifiés sont recompilés)
#   make run      compile puis lance l'interpréteur
#   make debug    compile avec les informations de débogage pour gdb (-ggdb3, sans optimisation)
#   make clean    supprime les fichiers objets et l'exécutable

CC      = gcc
CFLAGS  = -Wall -Wextra -O2
LDLIBS  = -lm

SRC     = $(wildcard src/*.c)
OBJ     = $(SRC:.c=.o)
EXEC    = interpreteur

all: $(EXEC)

# Édition de liens : les fichiers objets forment l'exécutable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDLIBS)

# Compilation séparée : un .c (et les .h du dossier) donne un .o
src/%.o: src/%.c $(wildcard src/*.h)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(EXEC)
	./$(EXEC)

debug: CFLAGS = -Wall -Wextra -ggdb3 -O0
debug: clean $(EXEC)

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all run debug clean
