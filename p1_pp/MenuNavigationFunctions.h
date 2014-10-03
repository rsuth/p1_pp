/****
*	Information																						
*	===========
*	
*	TITLE:	MenuNavigationFunctions.h
*	
*	Programmer:	Rick Sutherland
*	
*	Description: A collection of functions useful 
*				 for drawing windows and menus and other 
*				 graphical items in the console.
*	
*	Note: In any comments in this file the term 
*		  "print" refers to writing program output 
*		  to the console.
*						
*/

/****
*	Custom Defined Function List
*		
*	changeColor
*	hitEnter
*	moveCursor
*	printBackground
*	printErrorMessage
*	printRobot
*	printWindow
*	printWindowText															
*/

#ifndef MENUNAVIGATIONFUNCTIONS_H
#define MENUNAVIGATIONFUNCTIONS_H

/****
* INCLUDES
*/
#include<string>
#include<vector>

/*****
* NAMESPACE
*/
using namespace std;

/****
* TITLE: moveCursor
* Desc:	Moves the cursor to parameters x, y coordinates.
*/
void moveCursor(int x, int y);

/****
* TITLE: changeColor
* Desc:	Changes the color to a Windows.h console color 
*		designated by an integer RGB value.
*/
void changeColor(int colorCode);

/****
* TITLE: printBackground
* Desc:	Prints the screen area with a colorvalue(parameter 1)
*		and a repeating char(parameter 2).
*/
void printBackground(int colorValue, char patternChar);

/****
* TITLE: printWindow (Overloaded)
* Desc:	prints a window, with the top left corner at the
*			position startX and startY (parameters 1 and 2).
*/
void printWindow(int startX, int startY);

/****
* TITLE: printWindow (Overload)
* Desc:	Accepts parameters for the dimensions of the 
*		created window.
*/
void printWindow(int startX, int startY, int width, int height);

/****
* TITLE: printWindow (Overload)
* Desc:	Accepts parameters for the dimensions of the created 
*		window and the RGB color value of the window.
*/
void printWindow(int startX, int startY, int width, int height, int colorCode);

/****
* TITLE: printWindow (Overload)
* Desc:	Accepts parameters for the dimensions of the created 
* 		window, the RGB color value of the window, and 
*		a bool value which draws a shadow behind the window 
*		only when true. (default is true).
*/
void printWindow(int startX, int startY, int width, int height, int colorCode, bool shadow);

/****
* TITLE: printWindowText (Overloaded) 
* Desc:	Accepts a vector of strings as a parameter, prints
*		the vector with each string being a line of screen
*		output. Starts the printing at integer coordinates
*		x, y (parameters 2, 3).
*/
void printWindowText(vector<string> &content, int xPos, int yPos);

/****
* TITLE: printWindowText (Overload) 
* Desc:	Expands printWindowText to take a color value as 
*		a parameter, in which the window text will be 
*		printed to console.
*/
void printWindowText(vector<string> &content, int xPos, int yPos, int colorCode);

/****
* TITLE: printErrorMessage 
* Desc:	displays an error window for a second in center of 
*		screen.
*/
void printErrorMessage();

/****
* TITLE: printRobot
* Desc:	prints an ASCII art robot to the screen.
*/
void printRobot();

/****
* TITLE: hitEnter
* Desc:	prompts the user to hit the enter key. Waits for the 
* 		enter key to be pressed before continuing. 
*/
void hitEnter();

#endif /*MENUNAVIGATIONFUNCTIONS_H*/