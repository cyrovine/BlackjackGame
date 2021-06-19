#include "Game.h"
#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	srand(time(0));
	int index = rand() % 52;
	char ans='a';
	Game gm;
	
	gm.gameStart();
	
	while (ans == 'a' || ans == 'A' || ans == 'b' || ans == 'B' || ans == 'c' || ans == 'C')
	{
		cout << "是否要牌" << endl;
		cout << "a.是  b.否  c. 離開" << endl;
		cin >> ans;
		if (ans == 'a' || ans == 'A')
			gm.haveNewCard();
		if (ans == 'b' || ans == 'B')
			gm.dontHaveCard(gm.computerpumpCard());
		if (ans == 'c' || ans == 'C')
		{
			cout << "====================掰掰======================";
			break;
		}
		cout << endl;
	}
}
