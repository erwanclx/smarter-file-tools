CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = main.c
OUT = smartmv smartcp

all: $(OUT)

smartmv: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o smartmv

smartcp: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o smartcp

clean:
	rm -f $(OUT)

.PHONY: all clean
