CC = gcc

CFLAGS = -g -Wall -ansi -pedantic -w
INCLUDES = -I ~/{workSpaceDir}/{DonaldSincennes}
OUT_EXE = dice_new

all: $(OUT_EXE)

$(OUT_EXE): dice_new.o output.o user_inputs.o header.h
	$(CC) $(CFLAGS) -o $(OUT_EXE) dice_new.o output.o user_inputs.o

dice_new.o: dice_new.c header.h
	$(CC) -c dice_new.c

user_inputs.o: user_inputs.c header.h
	$(CC) -c user_inputs.c

outputs.o: output.c header.h
	$(CC) -c output.c

clean:
	rm *.o dice_new