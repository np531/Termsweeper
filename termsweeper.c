#include <stdio.h>
#include <stdlib.h>
#include "leaderboard.h"

#define MAXSIZE 8

int **board;

void help(void);
int parse_choice(int choice);
void print_board(void);


int main(void) {
	int choice;

	printf("========================================================\n");
	printf("Welcome to Termsweeper, minesweeper for your terminal!\n");
	printf("========================================================\n\n");
	printf("Type 'h' for help\n\n");

	printf("Input: ");
	choice = getchar();
	while (parse_choice(choice)) {
		printf("Input:");
		while(getchar() != '\n'); // Clears stdin buffer
		choice = getchar();
	}

	return 0;
}

int parse_choice(int choice) {
	switch((char)choice) {
		case 'h':
			help();
			break;
		case 'c':
			printf("Not yet implemented\n");
			break;
		case 'f':
			printf("Not yet implemented\n");
			break;
		case 'q':
			return 0;
			break;
		default:
			printf("Unrecognised command\n\n");
	}

	return 1;
}

void print_board(void){
	
	return;	
}

int **init_board(){
	board = (int **)malloc(MAXSIZE*sizeof(int *));
	for (int i = 0; i < MAXSIZE; i++) {
		board[i] = (int *)malloc(MAXSIZE*sizeof(int));
	}

	// TODO assign starting values to each square 
	// TODO implement free_board function

}

void help(void) {
	printf("The aim of the game is to clear the board without clicking on any of the mines. You can place flags on squares your suspect may have a mine. You can record your fastest times on the leaderboard.\n\n");
	printf("c - Check square\nf - Place flag\nh - show this help message\nq - quit\n\n");
}
