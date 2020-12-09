#include <iostream>
#include <string>

using namespace std;

void ReadDate(int& m, int& d, int& y);

int OrdinalDay(int m, int d, int y);

bool IsLeapYear(int y);

int main()
{
	// Jingnan Qi Assignment 2

	int month = 0,
		date = 0,
		year = 0,
		count = 0;

	string response;

	// reads a calendar date

	do {
		ReadDate(month, date, year);

		cout << month << '/' << date << '/' << year
			<< '\t'
			<< '='
			<< '\t'
			<< year
			<< '-'
			<< OrdinalDay(month, date, year);

		count += 1;

		// determine if there is another value to be processed
		cout << "\nWould you like to process another date? (yes/no): ";
		cin >> response;

		// validate value input to response
		while (response != "yes" && response != "no") {
			cout << "Invalid response, please enter \"yes\" or \"no\": ";
			cin >> response;
		}
	} while (response == "yes");

	// output total count and terminate
	cout << "\n\nThe number of dates processed: "
		<< count
		<< '\n';

	return 0;
}

void ReadDate(int& m, int& d, int& y)
{
	char skip;
	int days;

	// obtain value from user
	cout << "\nEnter date value (mm/dd/yyyy) to be converted: ";
	cin >> m >> skip >> d >> skip >> y;

	if (m >= 1 && m <= 12)
		m = m;
	else
		m = 0;

	if (m == 2) {
		if (IsLeapYear(y))
			days = 29;
		else
			days = 28;
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11)
		days = 30;
	else
		days = 31;

	if (d >= 1 && d <= days)
		d = d;
	else
		d = 0;

	if (y > 0)
		y = y;
	else
		y = 0;

	// validate value input to date
	while (m == 0 || d == 0 || y == 0) {
		cout << "Invalid date, please enter date again: ";
		cin >> m >> skip >> d >> skip >> y;
	
		if (m >= 1 && m <= 12)
			m = m;
		else
			m = 0;

		if (m == 2) {
			if (IsLeapYear(y))
				days = 29;
			else
				days = 28;
		}
		else if (m == 4 || m == 6 || m == 9 || m == 11)
			days = 30;
		else
			days = 31;

		if (d >= 1 && d <= days)
			d = d;
		else
			d = 0;

		if (y > 0)
			y = y;
		else
			y = 0;
	}
}

int OrdinalDay(int m, int d, int y)
{
	int dayYear = 0,
		febDays;

	if (IsLeapYear(y))
		febDays = 29;
	else
		febDays = 28;

	if (m == 1)
		dayYear = d;
	else if (m == 2)
		dayYear = 31 + d;
	else if (m == 3)
		dayYear = 31 + febDays + d;
	else if (m == 4)
		dayYear = 2 * 31 + febDays + d;
	else if (m == 5)
		dayYear = 2 * 31 + febDays + 30 + d;
	else if (m == 6)
		dayYear = 3 * 31 + febDays + 30 + d;
	else if (m == 7)
		dayYear = 3 * 31 + 2 * 30 + febDays + d;
	else if (m == 8)
		dayYear = 4 * 31 + 2 * 30 + febDays + d;
	else if (m == 9)
		dayYear = 5 * 31 + 2 * 30 + febDays + d;
	else if (m == 10)
		dayYear = 5 * 31 + 3 * 30 + febDays + d;
	else if (m == 11)
		dayYear = 6 * 31 + 3 * 30 + febDays + d;
	else if (m == 12)
		dayYear = 6 * 31 + 4 * 30 + febDays + d;

	return dayYear;
}

bool IsLeapYear(int y)
{
	bool result;

	if (y % 4 == 0) {
		if (y % 100 == 0 && y % 400 != 0)
			result = false;
		else
			result = true;
	}
	else
		result = false;

	return result;
}