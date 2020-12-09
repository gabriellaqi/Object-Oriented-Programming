#include <iostream>

using namespace std;

bool IsPrime(int num);
bool IsPerfect(int num);
int MenuOption();

int main()
{
	// Jingnan Qi Assignment 3

	int primeUpper,
		perfectUpper,
		countPrime = 0,
		countPerfect = 0;

	// if user selected Option 1 or 2

	while (countPrime >= 0) {

		switch (MenuOption()) {
		// if user selected Option 1
		case 1:
			cout << "What is the upper limit for the values in the list? ";
			cin >> primeUpper;
			for (int i = 1; i <= primeUpper; i++)
				if (IsPrime(i)) {
					cout << i
						<< "\t";
					countPrime += 1;
					if (countPrime % 5 == 0)
						cout << "\n";
				}
			break;

		// if user selected Option 2
		case 2:
			cout << "What is the upper limit for the values in the list? ";
			cin >> perfectUpper;
			for (int j = 1; j <= perfectUpper; j++)
				if (IsPerfect(j)) {
					cout << j
						<< "\t";
					countPerfect += 1;
					if (countPerfect % 5 == 0)
						cout << "\n";
				}
			break;

		// if user selected Option 3
		case 3:
			cout << "Thank you for using this program\n" << endl;
			return 0;
		}
	}
}

int MenuOption()
{
	int inValue;

	do {
		// obtain option value from user 
		cout << "\nPlease select from the following options:\n"
			<< "\n\t1:\tList prime numbers"
			<< "\n\t2:\tList perfect numbers"
			<< "\n\t3:\tTerminate the program\n"
			<< "\nOption? ";
		cin >> inValue;
	} while (inValue != 1 && inValue != 2 && inValue != 3);

	return inValue;
}

bool IsPrime(int num)
{
	bool result = true;

	if (num < 2)
		return false;
	else
		for (int divisor = 2; divisor <= num / 2 && result != false; divisor++)
			if (num % divisor == 0)
				result = false;

	return result;
}

bool IsPerfect(int num)
{
	bool result = true;
	int total = 0;

	if (num < 2)
		return false;
	else
		for (int divisor = 1; divisor < num; divisor++)
			if (num % divisor == 0)
				total += divisor;
		if (total != num)
			result = false;

	return result;
}