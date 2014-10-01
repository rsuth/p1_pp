#include"p1_pp.h"
#include"MenuNavigationFunctions.h"
#include<string>
#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

// TITLE:	printMainMenu
// DESC:	prints the main menu and handles menu selection loop 
void printMainMenu(bool &quit){
	string user = "bill";
	int rows = 10;
	int** p = initializeBoard(rows);
	printGaltonBoard(&user,rows,p);
	hitEnter();
	quit = true;
}

// TITLE:	printGaltonBoard
// DESC:	prints the completed galton board
//			Takes a pointer to the board state array
void printGaltonBoard(const string* username, int rows, int** board){
	for(int i = 0; i < rows; i++){
		for (int j = 0; j <= i; j++){
			cout << "    " << *(*(board+j));
		}
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
//int** runGalton(int balls, int rows){}

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