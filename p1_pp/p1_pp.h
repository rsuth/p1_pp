#include<string>

using namespace std;

void printMainMenu(bool &quit);
void printGaltonBoard(const string* username, int* board);
void printLogo();
void printGaltonGame(const string* username, int* board);
void printGameHistory();
void signIn(string &username);
void printIDandStars();
int* runGalton(int balls, int rows);
int* runGaltonGame(int balls, int rows);