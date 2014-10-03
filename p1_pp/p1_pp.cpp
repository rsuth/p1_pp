#include"p1_pp.h"
#include"MenuNavigationFunctions.h"
#include<string>
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<vector>

using namespace std;

/*
	The following are all defined as constants in <windows.h>:

	BACKGROUND_INTENSITY	= 128;
	BACKGROUND_RED			=  64;
	BACKGROUNDGREEN			=  32;
	BACKGROUND_BLUE			=  16;
	FOREGROUND_INTENSITY	=   8;
	FOREGROUND_RED			=   4;
	FOREGROUND_GREEN		=   2;
	FOREGROUND_BLUE			=   1;

	with the following combinations:

	COLOR NAME		BACKGROUND #	FOREGROUND #

	Black				 0				0		(= No Blue, no Green, no Red)
	Blue				16				1		(= Blue)
	Green				32				2		(= Green)
	Cyan				48				3		(= Blue  + Green)
	Red					64				4		(= Red)
	Magenta				80				5		(= Blue  + Red)
	Yellow				96				6		(= Green + Red)
	White			   112				7		(= Blue  + Green + Red)
	Intensity + Black  128				8		(= Intensity alone)
	Intensity + Blue   144				9		(= Intensity + Blue)
	etc.			   ...			  ...
	Intensity + White  240			   15		(= Intensity + Blue + Green + Red)

	Then, you can combine any backgound color with any foreground color
	simply by adding the two corresponding values, like:

	Background Yellow  + Foreground Red =
	96    +             4   = 100

	Background Intensity + Yellow and Foreground Intensity + Red =
	128      +   96    +                 8     +  4   = 236

	*/
void printMainMenu(bool &quit){

	string user = "USER";
	int rows = 10;
	int balls = 1000;
	int prob = 50;
	bool signedIn = false;
	vector<string> menuContent;

	menuContent.push_back("\t\t\tMain Menu");
	menuContent.push_back("\t\t\t=========");
	menuContent.push_back("\tPlease use the keyboard to make a selection:");
	menuContent.push_back(" ");
	menuContent.push_back("  S. Sign in");
	menuContent.push_back("  L. Display Logo");
	menuContent.push_back("  G. Go Galton");
	menuContent.push_back("  P. Play Galton Game");
	menuContent.push_back("  H. View Game History");
	menuContent.push_back("  Q. Quit Program");
	menuContent.push_back(" ");
	menuContent.push_back("\t\t\t\t\tyou are not signed in.");
	

	do{
		
		if(signedIn){ menuContent[11] = ("\t\t\t\t\tsigned in as: " + user);}

		printBackground(240, ' ');
		printTitle(&user, signedIn);
		printWindow(10, 8, 60, 15, 63);
		printWindowText(menuContent, 10, 9, 63);
		

		switch (toupper(_getch())){
			case 'S':
				signIn(&user, &signedIn);
				break;
			case 'L':
				printLogo();
				break;
			case 'G':
				goGalton(&user, rows, balls, prob);
				break;
			case 'P':
				//goGaltonGame();
				break;
			case 'H':
				//printGameHistory();
				break;
			case 'Q':
				confirmQuit(&quit);
				break;
			default:
				printErrorMessage();
				break;
		}
	
	}while(!quit);

}

void printTitle(const string* username, bool signedIn){
	vector<string> welcomeMsg;
	welcomeMsg.push_back(" ");
	if(signedIn){
		welcomeMsg.push_back("\t\tWelcome, " + *username + ", to ");
		welcomeMsg.push_back("\t\tRick's Galton Board Progam!");
	}
	else{
		welcomeMsg.push_back("\t\tWelcome to ");
		welcomeMsg.push_back("\t\tRick's Galton Board Program! ");
	}

	printWindow(10, 2, 60, 5, 95);
	printWindowText(welcomeMsg, 10, 2, 95);
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

void signIn(string* username, bool* signedIn){
	
	vector<string> prompt;

	prompt.push_back(" ");
	prompt.push_back(" Please Enter Your Name: ");

	printWindow(17,13,45,4, 31);
	printWindowText(prompt, 17, 13);

	getline(cin, *username);

	*signedIn = true;

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

	cout << "\t\tHello, " << *username << ", Thanks for Running the Galton Board.\n";
	
	
	board = initializeBoard(rows);
	runGalton(balls, rows, board);
	printGaltonBoard(username, rows, board);
	printHistogram(board, rows);
	deleteBoard(board, rows);
	
	hitEnter();
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