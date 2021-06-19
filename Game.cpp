#include "Game.h"
#include"PokerNumber.h"
#include"Pokerpoint.h"
#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include<sstream>
#include <string>

using namespace std;



Game::Game()
{
	dex = 0;
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		rdn[i] = rand() * 51 / 32767 + 1;//產生隨機數陣列
	}
	for (int i = 0; i < 13; i++)           //|用建構函式初始化
    {                                      //|
		pokerValue[i] = i + 1;             //|
		pokerValue[i + 13] = i + 1;        //|
		pokerValue[i + 26] = i + 1;	       //|
		pokerValue[i + 39] = i + 1;        //|
    } 
	for (int i = 0; i < 52; i++)
	{
		pokerQuan[i]=i;
	}
	for (int i = 0; i < 52; i++)
	{
		if (pokerValue[i] <= 10)
			pokerPoint[i] = pokerValue[i];
		else
			pokerPoint[i] = 10;
	}
}
void Game::gameStart()
{
	
	cout << "21點    遊戲開始" << endl;
	cout << "=============================================" << endl;
	playerRDN[0] = rdn[dex++];
	playerRDN[1] = rdn[dex++];
	computerRDN[0] = rdn[dex++];
	computerRDN[1] = rdn[dex++];

	playerCards = 2;
	computerCards = 2;

	cout << "你現有的牌" << endl;
	playerShowCard();
	cout << "現在點數: " << playerCardNumSum() << endl;
	cout << endl;
}
void Game::playerShowCard()								//|
{														//|
	for (int i = 0; i < playerCards; i++)				//|列出牌
	{													//|
		cout << tostring(pokerQuan[playerRDN[i]]);		//|
	}													//|
}
int Game::playerCardNumSum()						//|玩家卡牌點數
{
	int tot = 0;
	for (int i = 0; i < playerCards; i++)
		tot += pokerPoint[playerRDN[i]];
	return tot;
}
int Game::computerCardNumSum()						//|電腦卡牌點數
{	
	int tot = 0;
	for (int i = 0; i < computerCards; i++)
		tot += pokerPoint[computerRDN[i]];
	return tot;
}

void Game::haveNewCard()							//|要牌
{
	if (playerCards >= 5)
	{
		cout << "手牌過多" << endl;
		cout << endl;
		gameOver();
	}
	else if (playerCards < 5)
	{
		playerRDN[playerCards++] = rdn[dex++];
		playerShowCard();
		cout << "現在點數: " << playerCardNumSum() << endl;
		playerCheckSum();
		cout << endl;
	}
}
void Game::dontHaveCard(bool ans)
{
	cout << endl;
	cout << "玩家現有手牌:" << endl;
	playerShowCard();
	cout << "現在點數: " << playerCardNumSum() << endl;
	playerCheckSum();
	cout << endl;
	computerShowCard();
	while (ans)
	{
		if (computerCards <= 5)
		{
			if (ans)
			{
				computerCards++;
				computerShowCard();
				
			}
		}
	}
	gameOver();
}
void Game::playerCheckSum()
{
	if (playerCardNumSum() > 21)
	{
		cout << "你超過21點你爆了" << endl;
		exit(0);
	}
}
void Game::computerCheckSum()
{
	if (computerCardNumSum() > 21)
	{
		cout << "莊家超過21點 莊家爆了" << endl;
		cout << "你贏了" << endl;
		exit(0);
	}
}
bool Game::computerpumpCard()							//|判斷電腦是否要牌
{
	float choose = ((21 - computerCardNumSum()) / 21.0) * 100;
	float rate = rand() % 100 + 1;
	if (computerCardNumSum() < 12)
		choose += 50;
	else if (computerCardNumSum() < 14)
		choose += 40;
	else if (computerCardNumSum() < 15)
		choose += 20;
	else if (computerCardNumSum() < 17)
		choose += 8;

	if (rate > choose || computerCards >= 5)
		return   false;
	else
		return   true;
	
}

void Game::computerShowCard()					//|電腦要牌
{
	computerRDN[computerCards] = rdn[dex++];
	cout << "莊家手牌" << endl;
	for (int i = 0; i < computerCards; i++)		//|列出牌
	{											//|
		cout << tostring(pokerQuan[computerRDN[i]]);					//|
	}
	cout << "莊家點數: " << computerCardNumSum() << endl;
	computerCheckSum();
	cout << endl;
}

void Game::gameOver()
{
	if (computerCardNumSum() > 21)
	{
		cout << "莊家超過21點  莊家爆了" << endl;
		cout << "你贏了" << endl;
		exit(0);
	}
	else if (computerCardNumSum() >= playerCardNumSum())
	{
		cout << "你輸了" << endl;
		exit(0);
	}
	else
	{
		cout << "你贏了" << endl;
		exit(0);
	}
}

string Game::tostring(int var )																	//				
{																								//
	stringstream cardName;																		//印出數字及花色
																								//
	cardName << setw(3) << getPokerNumber(var) << " of " << getPokerSuits(var) << endl;		//
																								//
	return cardName.str();																		//
}
