#include"Header.h"
#include<iostream>
using namespace std;

int BMI::numberOfBMI = 0;

BMI::BMI()
{
	numberOfBMI++;
}
BMI::BMI(double newWeight, double newHeight)
{
	weight = newWeight;
	height = newHeight;
	numberOfBMI++;
}
void BMI::setWeight(double newWeight)
{
	weight = newWeight;
}
void BMI::setHeight(double newHeight)
{
	height = newHeight;
}
const double BMI::getWeight()
{
	return weight;
}
const double BMI::getHeight()
{
	return height;
}
int BMI::getNumberOfBMI()
{
	return numberOfBMI;
}
void BMI::print()
{
	cout << weight / (height * height) <<" "<< numberOfBMI;
}