#ifndef SOCCER_H
#define SOCCER_H

class SoccerClub
{
	Link* pPlayers;
public:
	SoccerClub();
	~SoccerClub();
	void AddPlayer();
	void DeletePlayer();
	void PrintPlayersForward();
	void PrintPlayersReverse();
};

#endif