/****
*  ID information																										
*  ==============	
*	Programmer:	Rick Sutherland
*	Assignment #: P#1PP
*	Assignment Name: Pointer Power
*	Course: CISC 205 OOPS		
*	Class Meeting Time:	T/TH 9:35	
*	Instructor:	Larry Forman				
*	Hours:
*	Difficulty:
*	Competion Date:
*	Project Name: p1_pp
*/

/****
* Program Description
* ===================		
*		This menu-based program simulates the use of a Galton 
*	board, which consists of rows of pegs on a tilted board.
*	at the top of the board, balls are released and move down
*	down the board, hitting each peg and bouncing to the left 
*	or to the right, with chance of either being 50/50.
*	The balls eventually accumulate in collumns at the bottom 
*	in a binomial distribution.
*/

/****
* Custom Defined Functions List
* =============================	
*/

/****
* Stars
* =====
*	(1) Center Output
*	(2) Print Histogram
*	(2) Print Histogram "right side up"
*	(1) Demo early 
*/

#include"MenuNavigationFunctions.h"
#include"p1_pp.h"
#include<iostream>
#include<Windows.h>

using namespace std;

int main(){
	
	bool quit = false;

	while(!quit){
		printMainMenu(quit);
	}
	printIDandStars();

	return 0;

}
