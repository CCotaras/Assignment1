/********************************************************************************
** File Name :				Link.cpp
** Student Name :			
** Student Number :			
** Assignment Number :		1
** Assignment Name :		ass1.cpp
** Course :					C++ Programming		
** Lab Section :			301
** Professor :				Andrew Tyler
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
#include "Link.h"


Player* pPlayer;
Link* pNext;
Link* pPrev;


/********************************************************************
Function name:        Link
Purpose:		      Constructor to build and set head of 
                      doubly linked list.
In parameters:		  Link*, Link*,Player*
Out parameters:	      none
Version:		      1.0
Author:			      Chris Cotaras
**********************************************************************/
Link::Link(Link* pPrev, Link* pNext, Player* pPlayer){
	this->pPrev = pPrev;
	this->pNext = pNext;
	this->pPlayer = pPlayer;

}

/********************************************************************
Function name:        ~Link
Purpose:              Deconstructs the list entry
In parameters:		  none
Out parameters:	      none
Version:		      1.0
Author:			      Chris Cotaras
**********************************************************************/

Link::~Link(){

	if (pPlayer != nullptr) delete pPlayer;
	pPlayer = nullptr;

}