/*****************************************************************
		ID information											
																
		Programmer:				Rick Sutherland
		Assignment #:			P#1PP
		Assignment Name:		Pointer Power
		Course # and Title:		CISC 205 OOPS		
		Class Meeting Time:		T/TH 9:35
		Instructor:				Larry Foreman				
		Hours:					
		Difficulty:				
		Competion Date:								
		Project Name:			p1_pp

*****************************************************************/
/*****************************************************************
		Program Description										
																
*****************************************************************/
/*****************************************************************
		Custom Defined Function List
									
*****************************************************************/

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
