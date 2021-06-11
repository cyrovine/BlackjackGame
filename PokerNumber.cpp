#include"PokerNumber.h"
#include"PokerSuits.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>

using namespace std;

PokerNumber::PokerNumber()
{
    for (int i = 0; i < 52; i++)             //|用建構函式初始化
    {
        switch (i % 13)                     //|
        {                                   //|
        case 0:                             //|
        {                                   //|
            pokerNumber[i] = "A";           //|
            break;                          //|
        }                                   //|
        case 1:                             //|
        {                                   //|
            pokerNumber[i] = "2";           //|
            break;                          //|
        }                                   //|
        case 2:                             //|
        {                                   //|
            pokerNumber[i] = "3";           //|
            break;                          //|
        }                                   //|
        case 3:                             //|
        {                                   //|
            pokerNumber[i] = "4";           //|
            break;                          //|
        }                                   //|
        case 4:                             //|
        {                                   //|
            pokerNumber[i] = "5";           //|
            break;                          //|
        }                                   //|
        case 5:                             //|
        {                                   //|
            pokerNumber[i] = "6";           //|
            break;                          //|
        }                                   //|
        case 6:                             //|
        {                                   //|
            pokerNumber[i] = "7";           //|
            break;                          //|
        }                                   //|
        case 7:                             //|
        {                                   //|
            pokerNumber[i] = "8";           //|
            break;                          //|
        }                                   //|
        case 8:                             //|
        {                                   //|
            pokerNumber[i] = "9";           //|
            break;                          //|
        }                                   //|
        case 9:                             //|
        {                                   //|
            pokerNumber[i] = "10";          //|
            break;                          //|
        }                                   //|
        case 10:                            //|
        {                                   //|
            pokerNumber[i] = "J";           //|
            break;                          //|
        }                                   //|
        case 11:                            //|
        {                                   //|
            pokerNumber[i] = "Q";           //|
            break;                          //|
        }                                   //|
        case 12:                            //|
        {                                   //|
            pokerNumber[i] = "K";           //|
            break;                          //|
        }                                   //|
        }                                       //|for結束
    }
}
string PokerNumber::getPokerNumber(int var)
{
    return pokerNumber[var];
}
string PokerNumber::tostring(int var)
{
    stringstream Number;

    Number << setw(3) << pokerNumber[var] << " of " << getPokerSuits(var) << endl;

    return Number.str();                     //|用tostring印出
}
