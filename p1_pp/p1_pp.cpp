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

const string MY_NAME = "Rick";

void printMainMenu(bool &quit){

	string user = "USER";
	int rows = 10;
	int balls = 1000;
	int prob = 50;
	bool signedIn = false;
	vector<string> menuContent;
	vector<game> gameList;
	int gameNumber = 0;

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

		printBackground(112, ' ');
		printTitle(&user, signedIn);
		printWindow(10, 8, 60, 15, 26);
		printWindowText(menuContent, 10, 9, 26);
		

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
				gameNumber++;
				gameList.push_back(goGaltonGame(&user, rows, balls, prob, gameNumber));
				break;
			case 'H':
				printGameHistory(&user, gameList);
				break;
			case 'Q':
				confirmQuit(&quit, &user);
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
		welcomeMsg.push_back("\t\t" + MY_NAME + "'s Galton Board Progam!");
	}
	else{
		welcomeMsg.push_back("\t\tWelcome to ");
		welcomeMsg.push_back("\t\t" + MY_NAME+ "'s Galton Board Program! ");
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

void printLogo(){

	vector<string> logoContent2;
	logoContent2.push_back("     )))                            ");
	logoContent2.push_back("    (((                             ");
	logoContent2.push_back("  +-----+                           ");
	logoContent2.push_back("  | R S |] Rick Sutherland Software ");
	logoContent2.push_back("  `-----'                           "); // James Christopher Goodwin

	vector<string> frame1;
	frame1.push_back("     )))");
	frame1.push_back("    ((( ");
	
	vector<string> frame2;
	frame2.push_back("    ((( ");
	frame2.push_back("     ))) ");

	printBackground(176, '.');
	printWindow(20,5,37,8,80);
	printWindowText(logoContent2, 21, 6, 241);
	
	for(int i = 0; i < 3; i++){
		printWindowText(frame2, 21, 6, 241);
		Sleep(800);
		printWindowText(frame1, 21, 6, 241);
		Sleep(800);
	}

	hitEnter();
}

void printGaltonGame(const string* username, int* board){}

void printGameHistory(const string* username, vector<game> gameList){
	
	printBackground(240, ' ');
	changeColor(240);

	cout << "Welcome, " << *username << " to the Game History Screen." << endl << endl;
	
	if (gameList.size() != 0){ cout << "Loading History..." << endl; }

	Sleep(300);

	for(int i = 0; i < gameList.size(); i++){
		cout << "\nGAME #: " << gameList[i].gameNumber;
		cout << "\nSCORE: " << gameList[i].score << endl;
	}

	hitEnter();
	
}

void signIn(string* username, bool* signedIn){
	
	vector<string> prompt;

	prompt.push_back(" ");
	prompt.push_back(" Please Enter Your Name: ");

	printWindow(17,13,45,4, 31);
	printWindowText(prompt, 17, 13);

	getline(cin, *username);

	*signedIn = true;

}

void printIDandStars(){
	
	// Change the time into a human readable format FROM:
	//http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
	time_t rawtime;
	time(&rawtime);
	
	printBackground(240, ' ');
	changeColor(242);
	cout << endl << "\t\t" << ctime(&rawtime);
	cout << "\t\tID INFORMATION" << endl
		<< "\t\t==============" << endl
		<< "\t\tProgrammer: Rick Sutherland" << endl
		<< "\t\tAssignment #: P#1_PP" << endl
		<< "\t\tAssignment Name: Pointer Power" << endl
		<< "\t\tCourse: CISC205 OOPS" << endl
		<< "\t\tClass Meeting Time: T/Th 9:35-12:45" << endl
		<< "\t\tInstructor: Larry Forman" << endl
		<< "\t\tHours: 14" << endl
		<< "\t\tDifficulty: 7" << endl
		<< "\t\tCompletion Date: 10/09/2014" << endl
		<< "\t\tProject Name: p1_pp" << endl;
	changeColor(244);
	cout << "\t\tStars: " << endl
		<< "\t\t=====" << endl
		<< "\t\t1. Center Screen Output" << endl
		<< "\t\t2. Demo Early" << endl
		<< "\t\t3 & 4. Print Histogram (2 Stars)" << endl
		<< "\t\t5. Perfectly Align weight and score values" << endl
		<< "\t\t6. Effectively Implement a pointer to const item" << endl
		<< "\t\t7. Effectively Implement a pointer to a pointer" << endl
		<< "\t\t8. After the user signs in, use name in all prompts" << endl;
	changeColor(245);
	cout << "\t\tTOTAL STARS: 8" << endl;

	hitEnter();
	
	printBackground(7, ' ');
	changeColor(11);
	cout << endl;
	cout << "\t\tCredits:" << endl
		<< "\t\t=======" << endl
		<< "\t\tThanks to Professor Forman, Ati G., and everyone else in" << endl
		<< "\t\tCisc205 OOPS for their presentations on pointers, and for" << endl
		<< "\t\tgiving me the opportunity to learn by participating in my" << endl
		<< "\t\tclass demos and by asking me for help on their programs." << endl << endl;
	changeColor(12);
	cout << "\t\tResources: " << endl
		<< "\t\t=========" << endl
		<< "\t\t\"Starting Out With C++, 7th Ed.\", Tony Gaddis, 2012" << endl
		<< "\t\thttp://www.cplusplus.com/doc/tutorial/pointers/" << endl
		<< "\t\thttp://www.cprogramming.com/tutorial/lesson6.html" << endl;

	hitEnter();

}

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

game goGaltonGame(const string* username, int rows, int balls, int prob, int gameNumber){
	
	int** board = 0;
	double tempScore = 0;
	double multipliers[10] = {126, 14, 3.5, 1.5, 1, 1, 1.5, 3.5, 14, 126};
	game thisGame;

	printBackground(240, ' ');
	moveCursor(0,0);
	changeColor(240);
	cout << "\t\tHello, " << *username << ", Thanks for Playing the Galton Game.\n";
	board = initializeBoard(rows);
	runGalton(balls, rows, board);
	printGaltonBoard(username, rows, board);
	changeColor(249);
	cout << "\nWeight:\t     ";
	for(int j = 0; j < rows; j++){
		cout << setw(6) << multipliers[j];
	}
	changeColor(252);
	cout << "\nCollumn:     ";
	for(int i = 0; i < rows; i++){
		double colPoints = board[(rows-1)][i] * multipliers[i];
		tempScore = colPoints + tempScore;
		cout << setw(6) << colPoints;
	}
	
	thisGame.gameNumber = gameNumber;
	thisGame.score = tempScore;
	
	cout << "\n\n\t\tGAME NUMBER: " << thisGame.gameNumber << "\n\t\tTOTAL SCORE: " << thisGame.score;
	
	deleteBoard(board, rows);

	hitEnter();

	return thisGame;

}