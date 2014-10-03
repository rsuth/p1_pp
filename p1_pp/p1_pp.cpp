#include"p1_pp.h"
#include"MenuNavigationFunctions.h"
#include<string>
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<vector>

using namespace std;


void printMainMenu(bool &quit){
	
	printBackground(98, ' ');
	changeColor(7);
	
	string user = "default";
	int rows = 10;
	int balls = 1000;
	int prob = 50;
	
	signIn(&user);

	goGalton(&user, rows, balls, prob);
	hitEnter();
}

void printGaltonBoard(const string* username, int rows, int** board){
		
	for(int row = 0; row < rows; row++){

		//Formatting: Print new line, tabs
		cout << "\nRow#: " << row;

		//Formatting: for loop to center each line by printing spaces
		for(int k = (rows - row); k >= 0; k--){
				cout << "   ";
		}
		
		//Print the row contents:
		for (int col = 0; col <= row; col++){
			cout << setw(6);
			cout << *(*(board+row)+col);
			Sleep(25);					// small pause after each "peg";
		}

		//Finished with row, make a new line.
		//cout << "\n";

	}

}

void printLogo(){}

void printGaltonGame(const string* username, int* board){}

void printGameHistory(){}

void signIn(string* username){
	
	vector<string> prompt;

	prompt.push_back(" ");
	prompt.push_back(" Please Enter Your Name: ");

	printWindow(15,15,45,4, 24);
	printWindowText(prompt, 15, 15);

	getline(cin, *username);

}

void printIDandStars(){}

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
	
	printBackground(240, ' ');
	moveCursor(0,0);
	changeColor(240);

	cout << "\t\tHello, " << *username << ", Thanks for Running the Galton Board.";
	
	
	board = initializeBoard(rows);
	runGalton(balls, rows, board);
	printGaltonBoard(username, rows, board);
	printHistogram(board, rows);
	deleteBoard(board, rows);

}

void printHistogram(int** board, int rows){
	int* endCount = new int[rows];
	int* starCount = new int[rows];
	int stars;
	cout << setw(6) << "\t";
	
	for(int i = 0; i < rows; i++){
		endCount[i] = board[rows-1][i];
	}
	for (int k = rows;k >= 0; k--){
		cout << endl;
		cout << "\t\t";
		for(int j = 0; j < rows; j++){
		
			if((endCount[j]+5)/(20*(k+1)) > 0)
				cout << setw(6) << "*    ";
			else
				cout << setw(6) << "     ";
		}
	
	}

}