#include<string>

using namespace std;

void printMainMenu(bool &quit);
void printGaltonBoard(const string* username,int rows, int** board);
void printLogo();
void printGaltonGame(const string* username, int* board);
void printGameHistory();
string signIn();
void printIDandStars();
void runGalton(int balls, int rows, int** board);
int** runGaltonGame(int balls, int rows);
int** initializeBoard(int rows);
void goGalton(const string* username, int rows, int balls, int prob);
int hitAPeg();