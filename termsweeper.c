#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "leaderboard.h"

#define MAXSIZE 16
#define ZONESIZE 4

int **board;
int num_mines = 50;

void help(void);
int parse_choice(int choice, int *mines_exist);
int **init_board(void);
void print_board(void);
void free_board(int **board);
void place_mines();
int check_adj_mines(int x, int y);

// 0 means empty hidden, 1 means empty visible, 2 means means mine, 3 means flag

int main(void) {
	int choice;
	int mines_exist = 0;
	srand(time(NULL));

	printf("========================================================\n");
	printf("Welcome to Termsweeper, minesweeper for your terminal!\n");
	printf("========================================================\n\n");
	printf("Type 'h' for help\n\n");

	init_board();

	printf("Input: ");
	choice = getchar();
	while (parse_choice(choice, &mines_exist)) {
		printf("Input:");
		while(getchar() != '\n'); // Clears stdin buffer
		choice = getchar();
	}

	return 0;
}


int parse_choice(int choice, int *mines_exist) {
	switch((char)choice) {
		case 'h':
			help();
			break;
		case 'c':
			if ((*mines_exist) == 0) {
				place_mines();	
				*mines_exist = 1;
			}
			print_board();
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


void place_mines(void) {
	/* Alernate generation algorithm. Breaks up the board into ZONESIZE*ZONESIZE sized zones randomly, */ 
	/* distributing the mines across the zone evently to avoid clumps */  
	/* int mines = num_mines; */
	/* int last_zone = MAXSIZE - ZONESIZE + 1; */
	/* while (1) { */
	/* 	for (int a = 0; a < last_zone; a=a+4) { */
	/* 		for (int b = 0; b < last_zone; b=b+4) { */
	/* 			board[a+rand()%ZONESIZE][b+rand()%ZONESIZE] = 1; */
	/* 			if (mines <= 0) { */
	/* 				return; */
	/* 			} */
	/* 			mines--; */
	/* 		} */
	/* 	} */
	/* } */

	// Randomly assigns num_mines mines
	for (int count = 0; count < num_mines; count++) {
		board[rand()%MAXSIZE][rand()%MAXSIZE] = 9;
	}

	// updates the adjacency count of each non-mine cell
	/* int num_adj = 0; */
	for (int i = 0; i < MAXSIZE; i++) {
		for (int j = 0; j < MAXSIZE; j++) {
			if (board[i][j] != 9) {
				board[i][j] = check_adj_mines(i,j); 
			}
		}	
	}

}

int check_adj_mines(int x, int y){
	int count = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (board[i][j] == 9) {
				count++;	
			}
		}
	}

	return count;
}

void print_board(void){
	printf("\n");
	for (int i = 0; i < MAXSIZE; i++) {
		for (int j = 0; j < MAXSIZE; j++){
			printf("%d", board[i][j]);
		}
		printf("\n");
	}
	return;	
}


int **init_board(){
	board = (int **)malloc(MAXSIZE*sizeof(int *));
	for (int i = 0; i < MAXSIZE; i++) {
		board[i] = (int *)malloc(MAXSIZE*sizeof(int));
	}

	// TODO assign starting values to each square 
	for (int i = 0; i < MAXSIZE; i++) {
		for (int j = 0; j < MAXSIZE; j++){
			board[i][j] = 0;
		}
	}

	return board;

}


/* void free_board(int **board){ */

/* } */


void help(void) {
	printf("The aim of the game is to clear the board without clicking on any of the mines. You can place flags on squares your suspect may have a mine. You can record your fastest times on the leaderboard.\n\n");
	printf("c - Check square\nf - Place flag\nh - show this help message\nq - quit\n\n");
}

