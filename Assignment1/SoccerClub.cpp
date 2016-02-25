/**********************************************************************
Filename:		     SoccerClub.cpp
Version: 		     1.0
Author:		         
Student No:  	     040 677 879
Course Name/Number:	 Intro to Programming   
Lab Sect: 	         310
Assignment #:	     01
Assignment name:	 Soccer Club
Due Date:		     Febuary, 20, 2016
Submission Date:	 
Professor:	         Andrew Tyler
Purpose:			 Control actions of program and run proper functions
*********************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include "Player.h"
#include "Link.h"
#include "SoccerClub.h"

using namespace std;

Link* pPlayers;

/********************************************************************
Function name:        SoccerClub
Purpose:              Deconstructs the list entry
In parameters:		  none
Out parameters:	      none
Version:		      1.0
Author:			    
**********************************************************************/

SoccerClub::SoccerClub(){
	pPlayers = nullptr;

}

/********************************************************************
Function name:        AddPlayer
Purpose:              Adds a new player
In parameters:		  none
Out parameters:	      none
Version:		      1.0
Author:			     
**********************************************************************/

void SoccerClub::AddPlayer(){
	Link* link = new Link;
	char firstName[50],lastName[50];
	double sub;

	/*Check that memory allocated properly.*/

	if (link == nullptr){
		cout << "Not enough memory to run program" << endl;
		return;
	}

	cout << "ADDING AN PLAYER" << endl;

	/*Clear the buffer for user inputs*/
	fflush(stdin);

	/*Collect data from user*/
	cout << "Please enter the Player first name: " ;
	cin.getline(firstName,strlen(firstName));

	cout << "Please enter the Player last name: ";
	cin.getline(lastName, strlen(lastName));

	cout << "Please enter the Player subscription: ";
	cin >> sub;

	/*Check input was correct double*/
	while(cin.good() == false){
		fflush(stdin);
		cin.clear();
		cout << "Error please enter a proper subscription value.";
		cin >> sub;
	}

	/*Check if entry is first entry*/
	if (pPlayers == nullptr){
		link->pPlayer = new Player(firstName, lastName, sub);
		link->pNext = nullptr;
		link->pPrev = nullptr;
		pPlayers = link;
	}
	else{
		/*Add new player at head and update link*/

		link->pPlayer = new Player(firstName, lastName, sub);

		link->pNext = pPlayers;
		pPlayers->pPrev = link;
		pPlayers = link;
	}
}

/********************************************************************
Function name:        DeletePlayer
Purpose:              Delete player at head
In parameters:		  none
Out parameters:	      none
Version:		      1.0
Author:			      
**********************************************************************/
void SoccerClub::DeletePlayer(){
	Link* temp = new Link;
	cout << "DELETE A PLAYER" << endl;

	if (pPlayers->pNext == nullptr){
		if (pPlayers->pPlayer == nullptr){
			delete pPlayers->pPlayer;
		}
		cout << "Player Deleted" << endl;
	}
	else{
		temp = pPlayers->pNext;
		temp->pPrev = nullptr;
		delete pPlayers->pPrev;
		pPlayers = temp;
		cout << "Player Deleted" << endl;
	}
	
	
}

/********************************************************************
Function name:        PrintPlayersForward
Purpose:              Print Players in forward order
In parameters:		  none
Out parameters:	      none
Version:		      1.0
Author:			     
**********************************************************************/

void SoccerClub::PrintPlayersForward(){
	Link* temp = pPlayers;
	char *firstName, *lastName;
	double sub;
	double count = 1;

	cout << "FORWARD PRINTING PLAYERS" << endl;

	/*Check if current is still valid*/
	while (temp != nullptr){

		/*Collect data from current link*/
		firstName = temp->pPlayer->getFirstName();
		lastName = temp->pPlayer->getLastName();
		sub = temp->pPlayer->getSubscription();

		/*Display data*/
		cout << "Player " << count++ << endl;
		cout << "first name = " << firstName << endl;
		cout << "last name = " << lastName << endl;
		cout << "subscription = " << fixed << sub << setprecision(2)<< "\n\n";

		/*Move to next link*/
		temp = temp->pNext;
	}

}

/********************************************************************
Function name:        PrintPlayersReverse
Purpose:              Print players in revers order
In parameters:		  none
Out parameters:	      none
Version:		      1.0
Author:			     
**********************************************************************/

void SoccerClub::PrintPlayersReverse(){
	Link* temp = pPlayers;
	char *firstName, *lastName;
	double sub;
	double count = 1;

	cout << "REVERSE PRINTING PLAYERS" << endl;

	while (temp->pNext != nullptr){
		temp = temp->pNext;
		count++;
	} 

	/*Check if current is still valid*/
	do {

		/*Collect data from current link*/
		firstName = temp->pPlayer->getFirstName();
		lastName = temp->pPlayer->getLastName();
		sub = temp->pPlayer->getSubscription();

		/*Display data*/
		cout << "Player " << count-- << endl;
		cout << "first name = " << firstName << endl;
		cout << "last name = " << lastName << endl;
		cout.precision(2);
		cout << "subscription = " << fixed << sub << "\n\n";

		/*Move to previous link*/
		temp = temp->pPrev;
	} while (temp != nullptr);
}

/********************************************************************
Function name:        ~SoccerClub
Purpose:              Deconstructs the list entry
In parameters:		  none
Out parameters:	      none
Version:		      1.0
Author:			      
**********************************************************************/

SoccerClub::~SoccerClub(){

}