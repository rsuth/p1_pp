#include<string>
#include<vector>


using namespace std;

/****
* Title: printMainMenu
*
* Desc:	prints the main menu, gets user input and runs functions
*		depending on which option the user selects.
* Pre:	A boolean (quit) is set to false. If set to true, the 
*		menu loop will only run once.
* Post: NONE
*/
void printMainMenu(bool &quit);

void printTitle(const string* username, bool signedIn);

/****
* Title: printGaltonBoard
*
* Desc:	Prints the board with a personalized thank you message.
* Pre:	a string "username" has been set by the signIn function.
		if not, "user" will appear in the greeting.
		an integer "rows" has been set to the number of rows in the 
		array pointed to by board.
		and int** "board" has been allocated with size (rows).
* Post: NONE
*/
void printGaltonBoard(const string* username, int rows, int** board);

/****
* Title: printLogo
*
* Desc:	Prints the Logo using color and ascii graphics
* Pre:	NONE
* Post: NONE
*/
void printLogo();

/****
* Title: printGaltonGame
*
* Desc:	Calls printGaltonBoard to print the board and also prints
*		a set of score values on the collums, as well as a different
*		personalized greeting.
* Pre:	a string "username" exists
*		an integer "rows" has been set to the number of rows in the 
*		array pointed to by board. rows matches the size of the 
*		board array.
*		and int** "board" has been allocated with size (rows).
* Post: NONE
*/
void printGaltonGame(const string* username, int rows, int** board);

/****
* Title: printGameHistory
*
* Desc:	Prints the scores of each game.
* Pre:	a username string exists
*		a vector of doubles containing user score totals exists
* Post: NONE
*/
void printGameHistory(const string* username, const vector<double>* scores);

/****
* Title: signIn
* Desc: prompts the user to enter thier name to use to personalize 
*		experience. Gets the name and puts it into a string.
* Pre:	a string exists to hold the username.
* Post: the string parameter is changed to whatever the user enters.
*/
void signIn(string* username, bool* signedIn);

/****
* Title: printIDandStars
* Desc:	Prints the ID info and any STARS attempted.
* Pre: NONE
* Post: NONE
*/
void printIDandStars();

/****
* Title: runGalton
* Desc:	runs the galton board simulation in an jagged 2d array, with each
*		element representing a peg and holding the number of times a ball 
*		hit that peg.
* Pre:	balls has been set to some value between 1 and 9999. 
*		rows has been set to some value > 0 and  < 100.
* Post: board array is filled with values representing how many balls
*		hit each peg, the last row being the number of balls that ended up
*		in each column.
*/
void runGalton(int balls, int rows, int** board);

/****
* Title: runGaltonGame
*/
int** runGaltonGame(int balls, int rows, int** board, vector<int>* scores);

/****
* Title: initializeBoard
*/
int** initializeBoard(int rows);

/****
* Title: printHistogram
*/
void printHistogram(int** board, int rows);

/****
* Title: goGalton
*/
void goGalton(const string* username, int rows, int balls, int prob);
