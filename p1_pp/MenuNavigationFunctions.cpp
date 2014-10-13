/*****************************************************************
		Information											
																
		TITLE:			MenuNavigationFunctions.cpp
		Programmer:		Rick Sutherland

/*****************************************************************
		Custom Defined Function List
		
		changeColor
		hitEnter
		moveCursor
		printBackground
		printErrorMessage
		printRobot
		printWindow
		printWindowText
																
*****************************************************************/
#include"MenuNavigationFunctions.h"
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<stdio.h>
#include<string>
#include<vector>

using namespace std;

void moveCursor(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printBackground(int colorValue, char patternChar){
	moveCursor(0,0);
	changeColor(colorValue);
	for(int i = 0; i < 40; i++){
		for(int j = 0; j < 80; j++){
			cout << patternChar;
		}
	}
	moveCursor(0,0);
	changeColor(7);
}

void changeColor(int colorValue){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorValue);
}

void printWindow(int startX, int startY){
	
	int defaultWindowHeight = 20;
	int defaultWindowWidth = 45;
	
	// First print shadow
	moveCursor(startX+1, startY+1);
	changeColor(7);		// to print a black shadow
	for(int j = startY+1; j < startY + defaultWindowHeight + 1; j++){
		for(int i = 0; i <= defaultWindowWidth; i++){
			cout << " ";
		}
		moveCursor(startX+1, j);
	}

	// Now Print Window
	moveCursor(startX, startY);
	changeColor(116);		// defualt color: green
	for(int j = startY; j < startY + defaultWindowHeight; j++){
		for(int i = 0; i <= defaultWindowWidth; i++){
			cout << " ";
		}
		moveCursor(startX, j);
	}
	
	// Put the cursor at the start of the window
	moveCursor(startX, startY+1);

}

// overload to accept custom dimensions
void printWindow(int startX, int startY, int width, int height){
		
	int WindowHeight = height;
	int WindowWidth = width;
	
	// First print shadow
	moveCursor(startX+1, startY+1);
	changeColor(0);		// to print a black shadow
	for(int j = startY+1; j < startY + WindowHeight + 1; j++){
		for(int i = 0; i <= WindowWidth; i++){
			cout << " ";
		}
		moveCursor(startX+1, j);
	}

	// Now Print Window
	moveCursor(startX, startY);
	changeColor(116);		// defualt color: red on white
	for(int j = startY; j < startY + WindowHeight; j++){
		for(int i = 0; i <= WindowWidth; i++){
			cout << " ";
		}
		moveCursor(startX, j);
	}
	
	// Put the cursor at the start of the window
	moveCursor(startX, startY+1);

}

//overload to accept dimensions + color
void printWindow(int startX, int startY, int width, int height, int colorCode){
		
	int WindowHeight = height;
	int WindowWidth = width;
	
	// First print shadow
	moveCursor(startX+1, startY+1);
	changeColor(7);		// to print a black shadow
	for(int j = startY+1; j < startY + WindowHeight + 1; j++){
		for(int i = 0; i <= WindowWidth; i++){
			cout << " ";
		}
		moveCursor(startX+1, j);
	}

	// Now Print Window
	moveCursor(startX, startY);
	changeColor(colorCode);	
	for(int j = startY; j < startY + WindowHeight; j++){
		for(int i = 0; i <= WindowWidth; i++){
			cout << " ";
		}
		moveCursor(startX, j);
	}
	
	// Put the cursor at the start of the window
	moveCursor(startX, startY+1);

}

//overload to accept dimensions + color + choice of shadow or no shadow
void printWindow(int startX, int startY, int width, int height, int colorCode, bool shadow){
		
	int WindowHeight = height;
	int WindowWidth = width;
	
	// First print shadow (if shadow = true)
	if (shadow){
	moveCursor(startX+1, startY+1);
	changeColor(7);		// to print a black shadow
	for(int j = startY+1; j < startY + WindowHeight + 1; j++){
		for(int i = 0; i <= WindowWidth; i++){
			cout << " ";
		}
		moveCursor(startX+1, j);
	}
	}
	// Now Print Window
	moveCursor(startX, startY);
	changeColor(colorCode);	
	for(int j = startY; j < startY + WindowHeight; j++){
		for(int i = 0; i <= WindowWidth; i++){
			cout << " ";
		}
		moveCursor(startX, j);
	}
	
	// Put the cursor at the start of the window
	moveCursor(startX, startY+1);

}

void printWindowText(vector<string> &content, int xPos, int yPos){
	for(unsigned int i = 0; i < content.size(); i++){
		moveCursor(xPos, yPos + i);
		cout << content[i];
	}
}

void printWindowText(vector<string> &content, int xPos, int yPos, int colorCode){
	changeColor(colorCode);
	for(unsigned int i = 0; i < content.size(); i++){
		moveCursor(xPos, yPos + i);
		cout << content[i];
	}
}

void printErrorMessage(){
	
	vector<string> invalidMsg_Content;
	invalidMsg_Content.push_back("  INVALID KEY");
	printWindow(30, 12, 15, 4, 79);
	printWindowText(invalidMsg_Content, 30,13,79);
	Sleep(800);

}


void hitEnter(){
	moveCursor(70, 20);
	changeColor(188);
	cout << "[ENTER]";
	cin.ignore(10000, '\n');
}

void confirmQuit(bool* quit, const string* username){
	vector<string> confirmText;
	confirmText.push_back(*username +", Are you sure you want to quit(Y/N)?");
	printWindow(19, 13, 50, 4, 111);
	printWindowText(confirmText, 20, 14, 111);
	if(toupper(_getch()) == 'Y'){
		*quit = true;
	}
}
