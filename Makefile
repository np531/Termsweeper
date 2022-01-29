# Makefile for Termsweeper

CC = gcc
CFLAGS = -O2 -Wall -g 
TARGET = termsweeper
SRC = termsweeper.c

all: $(TARGET)

termsweeper: termsweeper.o leaderboard.o
	$(CC) termsweeper.o leaderboard.o $(CFLAGS) -o $(TARGET)

termsweeper.o: termsweeper.c leaderboard.h
	$(CC) $(CFLAGS) -c $(SRC)

leaderboard.o: leaderboard.c leaderboard.h
	$(CC) $(CFLAGS) -c leaderboard.c

clean:
	rm $(TARGET)
