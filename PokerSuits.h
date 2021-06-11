#ifndef pokerSuits_h
#define pokerSuits_h
#include <string>

using namespace std;

class PokerSuits
{
public:
	PokerSuits();
	string getPokerSuits(int var);
private:
	string pokerSuits[52]; //撲克花色
};
#endif
