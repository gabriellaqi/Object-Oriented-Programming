#include <iostream> 

using namespace std;

int main()
{
	cout << "\nMy name is Jingnan Qi\nAssignment 1\n";

	char response;

	// obtain cents value from user
	cout << "\nDo you have a cents value to convert to coins? (Enter Y or N): ";
	cin >> response;

	// result is 0 if respond negative at the beginning
	if (response == 'N' || response == 'n')
		cout << "\nTotal value input is 0";

	// reprompt user to input correct response if invalid
	while (response != 'Y' && response != 'y' && response != 'N' && response != 'n') {
		cout << "Invalid response, please enter Y or N: ";
		cin >> response;
	}

	int cents,
		quarters,
		dimes,
		nickles,
		pennies;
	float sum = 0;

	// compute and output coins when respond affirmative
	while (response == 'Y' || response == 'y') {
		cout << "Enter a cents value to be converted to coins: ";
		cin >> cents;
		sum = sum + cents / 100.0;
		quarters = cents / 25;
		dimes = cents % 25 / 10;
		nickles = cents % 25 % 10 / 5;
		pennies = cents % 25 % 10 % 5;
		cout << cents
			<< " cents is equal to\n"
			<< quarters
			<< " quarters, "
			<< dimes
			<< " dimes, "
			<< nickles
			<< " nickles and "
			<< pennies
			<< " pennies\n"
			<< "\n"
			<< "Would you like to process another value? (Y/N): ";
		cin >> response;
		while (response != 'Y' && response != 'y' && response != 'N' && response != 'n') {
			cout << "\nWould you like to process another value? (Y/N): ";
			cin >> response;
		}

		// output total value when exit
		if (response == 'N' || response == 'n')
			cout << "\nTotal value input is " 
				<< sum << endl;
	}

}