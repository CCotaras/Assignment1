#ifndef LINK_H
#define LINK_H

struct Link
{
	Player* pPlayer;
	Link* pNext;
	Link* pPrev;
	Link()
	{
		pPrev = nullptr;
		pNext = nullptr;
	}
	Link(Link*, Link*, Player*);
	~Link();
};

#endif