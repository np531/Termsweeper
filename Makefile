# Makefile for Termsweeper

CC = gcc
CFLAGS = -O2 -Wall
TARGET = termsweeper
SRC = termsweeper.c

termsweeper: termsweeper.o
	$(CC) $(SRC) $(CFLAGS) -o $(TARGET)

termsweeper.o: termsweeper.c
	$(CC) -c $(SRC)

clean:
	rm $(TARGET)
