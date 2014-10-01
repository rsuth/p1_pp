#include"p1_pp.h"
#include"MenuNavigationFunctions.h"
#include<string>
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

// TITLE:	printMainMenu
// DESC:	prints the main menu and handles menu selection loop 
void printMainMenu(bool &quit){
	printBackground(1, ' ');
	changeColor(7);
	
	string user = "bill";
	int rows = 10;
	int balls = 1000;
	int prob = 50;

	goGalton(&user, rows, balls, prob);

	hitEnter();
	quit = true;
}

// TITLE:	printGaltonBoard
// DESC:	prints the completed galton board
//			Takes a pointer to the board state array
void printGaltonBoard(const string* username, int rows, int** board){
		
	for(int row = 0; row < rows; row++){

		//Formatting: Print new line, tabs
		cout << "\n\tRow#: " << row << "\t";

		//Formatting: for loop to center each line by printing spaces
		for(int k = (rows - row); k >= 0; k--){
				cout << "  ";
		}
		
		//Print the row contents:
		for (int col = 0; col <= row; col++){
			cout << setw(4);
			cout << *(*(board+row)+col);
			Sleep(25);					// small pause after each "peg";
		}

		//Finished with row, make a new line.
		cout << "\n";

	}

}

// TITLE:	printLogo
// DESC:	prints a Logo
void printLogo(){}

// TITLE:	printGaltonGame
// DESC:	prints the completed galton board, also prints 
//			the users score, takes a pointer to the 
//			board state array.
void printGaltonGame(const string* username, int* board){}

void printGameHistory(){}

string signIn(){
	return "PLACEHOLDER";
}

void printIDandStars(){}

// TITLE:	runGalton
// DESC:	Runs the galton board (displays nothing!)
//			returns a pointer to the completed board 
//			state array.
void runGalton(int balls, int rows, int** board){
	srand(time(NULL));
	*(*(board)) = balls;
	
	for(int row = 1; row < rows; row++){
		for(int col = 0; col < row; col++){
			for(int i = 0; i < (*(*(board+row-1)+col)); i++){
				if((rand() % 2) != 0)
					(*(*(board+row)+col))++;
				else
					(*(*(board+row)+col+1))++;
			}
		}
	}
}

//int** runGaltonGame(int balls, int rows){}

//int hitAPeg(int probability){}

int** initializeBoard(int rows){
	
	int** board = new int*[rows];

	for(int i = 0; i < rows; i++){
		
		int* row = new int[i+1];
		
		for(int j = 0; j <= i; j++){
			row[j] = 0;
		}

		board[i] = row;
	}

	return board;
}

void deleteBoard(int** board, int rows){
	for(int i = 0; i < rows; i++){
		delete[] board[i];
	}
	delete[] board;
}

void goGalton(const string* username, int rows, int balls, int prob){
	
	int** board = 0;
	
	board = initializeBoard(rows);
	runGalton(balls, rows, board);
	printGaltonBoard(username, rows, board);
	deleteBoard(board, rows);

}