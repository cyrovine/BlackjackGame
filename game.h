#ifndef Game_H
#define Game_H
#include"PokerNumber.h"
#include <string>

using namespace std;

class Game :public PokerNumber
{
public:
	Game();
	void shuffle();
	void gameStart();
	void playerShowCard();
	void haveNewCard();
	void dontHaveCard(bool);
	int playerCardNumSum();
	int computerCardNumSum();
	void playerCheckSum();
	void computerCheckSum();
	bool computerpumpCard();
	void computerShowCard();
	void gameOver();
	string tostring(int var);
private:
	int pokerValue[52]; //撲克亂數
	int pokerQuan[52];
	int pokerPoint[52];
	int playerRDN[5];
	int computerRDN[5];
	int playerCards;
	int computerCards;
	int rdn[10];
	int dex;
};



#endif
