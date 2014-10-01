#include<string>

using namespace std;

void printMainMenu(bool &quit);
void printGaltonBoard(const string* username,int rows, int** board);
void printLogo();
void printGaltonGame(const string* username, int* board);
void printGameHistory();
void signIn(string &username);
void printIDandStars();
void runGalton(int balls, int rows, int** board);
int** runGaltonGame(int balls, int rows);
int** initializeBoard(int rows);
int hitAPeg();