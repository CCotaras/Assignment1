/********************************************************************************
** File Name :				Player.cpp
** Student Name :			
** Student Number :			
** Assignment Number :		1
** Assignment Name :		ass1.cpp
** Course :					C++ Programming		
** Lab Section :			301
** Professor :				
** Date due:				Feb 20, 2016
** Submission Date:			Feb 20, 2016
** Source / Header Files:	src - ass1.c, SoccerClub.cpp, Link.cpp, Player.cpp;
**							headers - SoccerClub.h, Link.h, Player.h.h;
**
** Purpose :				Keep a Linked List of a soccer league of players
**							with firstName, lastName, and Subscriptions
**
** Author:					
** Editted by:				
*********************************************************************************/

#include "Player.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

/********************************************************************
Function name:        Player
Purpose:              
In parameters:		  none
Out parameters:	      none
Version:		      1.0
Author:			     
**********************************************************************/
Player::Player(){
	firstName = nullptr;
	lastName = nullptr;
	subscription = 0;
}

/********************************************************************
Function name:        Player
Purpose:              Creates entry for new player
In parameters:		  char*, char*, double
Out parameters:	      none
Version:		      1.0
Author:			      
**********************************************************************/
Player::Player(char* firstName, char*lastName, double sub){

	/*Allocate memory of correct size to variables, ie malloc*/
	this->firstName = new char(strlen(firstName) + 1);
	this->lastName = new char(strlen(lastName) + 1);
	/*Assign text to newly allocated memory*/
	strcpy(this->firstName, firstName);
	strcpy(this->lastName, lastName);
	/*make subscription equal subscription....*/
	this->subscription = sub;
}

/********************************************************************
Function name:        Player
Purpose:              Deletes entry
In parameters:		  char*, char*, double
Out parameters:	      none
Version:		      1.0
Author:			      
**********************************************************************/

Player::~Player(){
	/*DeAllocate and set to null*/
	if (firstName != nullptr){
		delete[]firstName;
		firstName = nullptr;
	}
	/*DeAllocate memory ans set to null*/
	if (lastName != nullptr){
		delete[]lastName;
		lastName = nullptr;
	}
}
