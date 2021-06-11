#ifndef pokerNumber_h
#define pokerNumber_h
#include <string>
#include"PokerSuits.h"

using namespace std;

class PokerNumber :public PokerSuits
{
public:
	PokerNumber();
	string getPokerNumber(int var);
	string tostring(int var);
private:
	string pokerNumber[52]; //¼³§J¦W
};
#endif
