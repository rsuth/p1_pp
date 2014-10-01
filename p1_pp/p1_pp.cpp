#include"p1_pp.h"
#include"MenuNavigationFunctions.h"
#include<string>
#include<iostream>
#include<iomanip>
#include<vector>
#include<Windows.h>

using namespace std;

// TITLE:	printMainMenu
// DESC:	prints the main menu and handles menu selection loop 
void printMainMenu(bool &quit){
	
	string user = "bill";
	int rows = 10;
	int balls = 1000;
	int** board = 0;

	board = initializeBoard(rows);
	runGalton(balls, rows, board);
	printGaltonBoard(&user,rows,board);
	hitEnter();
	quit = true;
}

// TITLE:	printGaltonBoard
// DESC:	prints the completed galton board
//			Takes a pointer to the board state array
void printGaltonBoard(const string* username, int rows, int** board){
	
	for(int i = 0; i < rows; i++){

		//Formatting: Print new line, tabs
		cout << "\n\t\t";

		//Formatting: for loop to center each line by printing spaces
		for(int k = (rows - i); k >= 0; k--){
				cout << "  ";
		}
		
		//Print the row contents:
		for (int j = 0; j <= i; j++){
			cout << setw(4);
			cout << *(*(board+j));
			//Sleep(100);					// small pause after each "peg";
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

void signIn(string &username){}

void printIDandStars(){}

// TITLE:	runGalton
// DESC:	Runs the galton board (displays nothing!)
//			returns a pointer to the completed board 
//			state array.
void runGalton(int balls, int rows, int** board){
	
	// SET THE TOP 
	*(*(board)) = balls;

	for(int i = 0; i < balls; i++){
		for(int j = 0; j < rows; j++){
			
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