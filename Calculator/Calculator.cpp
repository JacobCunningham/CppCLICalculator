// Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

template <typename inpType>

inpType Evaluate(const inpType& lho, const inpType& rho, const char& operation) {

	switch (operation)
	{
	case '+':
		return lho + rho;

	case '-':
		return lho - rho;

	case '*':
		return lho * rho;

	case '/':
		return lho / rho;

	default:
		cout << "Invalid operator" << endl;
		break;
	}
}

float strtofloat(const string& stringObj) {
	float fVal = 0;

	for (auto strIt = stringObj.cbegin(); strIt != stringObj.cend(); ++strIt) {
		fVal *= 10;
		fVal += *strIt - '0';
	}
	return fVal;
}

void parseInput(float& lhs, float& rhs, char& op, const string& strToParse) {

	set<int> numbers = { 1,2,3,4,5,6,7,8,9,0 };
	string op1;
	string op2;
	bool hitOp = false;

	for (auto strIt = strToParse.cbegin(); strIt != strToParse.cend(); ++strIt) {

		int intComp = *strIt - '0';
		const bool is_in = numbers.find(intComp) != numbers.end();

		if (hitOp == false) {
			if (is_in) {
				op1 += *strIt;
			}
			else {
				if (*strIt == ' ') {
					continue;
				}
				else {
					op = *strIt;
					hitOp = true;
				}
			}
		}
		else if (hitOp == true) {

			if (*strIt == ' ') {
				continue;

			}
			else {
				op2 += *strIt;
			}
		}
	contin:;
	}

	lhs = strtofloat(op1);
	rhs = strtofloat(op2);
}

int main()
{
	string selector;
	do
	{

		cout << "Press m for math. Press q to quit..." << endl;
		cin >> selector;

		if (selector == "m") {

			float lh = 0;
			float rh = 0;
			char op = '0';
			string input;
			string nums;
			cout << "Enter expression: : " << endl;
			cin.ignore();
			getline(cin, input);

			parseInput(lh, rh, op, input);

			cout << lh << ' ' << op << ' ' << rh << " = " << Evaluate(lh, rh, op) << endl;
		}
		else if (selector != "m" or selector != "q") {
			cout << "Invalid Input" << endl;
		}

	} while (selector != "q");

	return 0;
}


