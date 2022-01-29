#include <stdio.h>
#include <stdlib.h>

void help(void);
int parse_choice(int choice);

int main(void) {
	printf("Welcome to Termsweeper, minesweeper but worse\n");
	printf("Type 'h' for help\n\n");
	int choice;

	printf("Input: ");
	choice = getchar();
	/* while(getchar() != '\n'); // Clears stdin buffer */
	while (parse_choice(choice)) {
		printf("Input:");
		while(getchar() != '\n'); // Clears stdin buffer
		choice = getchar();
	}

	return 0;
}

int parse_choice(int choice) {
	/* printf("%c", (char)choice); */
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

void help(void) {
	printf("The aim of the game is to clear the board without clicking on any of the mines. You can place flags on squares your suspect may have a mine. You can record your fastest times on the leaderboard.\n\n");
	printf("c - Check square\nf - Place flag\nh - show this help message\nq - quit\n\n");
}
