CC = gcc

CFLAGS = -g -Wall -ansi -pedantic -w
INCLUDES = -I ~/{workSpaceDir}/{DonaldSincennes}
OUT_EXE = card_game

all: $(OUT_EXE)

$(OUT_EXE): card_game.o output.o input.o header.h
	$(CC) $(CFLAGS) -o $(OUT_EXE) card_game.o output.o input.o

card_game.o: card_game.c header.h
	$(CC) -c card_game.c

input.o: input.c header.h
	$(CC) -c input.c

output.o: output.c header.h
	$(CC) -c output.c

clean:
	rm *.o card_game