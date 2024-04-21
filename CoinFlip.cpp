#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#define HEAD 0
#define TAIL 1

using namespace std;

//Functions declaration

int flipCoin();
void drawLine(int n, char symbol);
void rules();


int main()
{
	string choice, Player_choice, playerName;
	int total_heads = 0, total_tails = 0, bettingAmount;
	int amount; // hold player's balance amount

	srand(time(0)); // "Seed" the random generator

	drawLine(100, '_');
	cout << "\n\n\n\t\tWelcome to Bellagio Casino, Las vegas!!\n\n\n\n";
	drawLine(100, '_');

	cout << "\n\nEnter Your Name : ";
	getline(cin, playerName);


	rules();

	cout << "\n\nEnter Deposit amount to play game : $";
	cin >> amount;

	do
	{
		system("cls");

		cout << "\n\nYour current balance is $ " << amount << "\n";

		// Get player's betting amount
		do
		{
			cout << playerName << ", enter money to bet : $";
			cin >> bettingAmount;
			if (bettingAmount > amount)
				cout << "Your betting amount is more than your current balance\n" << "\nRe-enter data\n ";

			if (amount == 0)
			{
				cout << "You have no money to play ";
				break;
			}
		} while (bettingAmount > amount);

		cout << "Would you like to flip the coin? (y/n)" << endl;
		cin >> choice;
		cout << endl;
		while (choice == "y" || choice == "Y")
		{
			cout << "What do you think you will get? (Head/Tail)" << endl;
			cin >> Player_choice;
			cout << endl;
			srand((unsigned int)time(NULL));

			if (flipCoin() == HEAD && Player_choice == "Head")
			{
				total_heads++;
				cout << "Good luck!! It's a HEAD!! You won: $" << bettingAmount * 2 << endl;
				amount = amount + bettingAmount * 2;
				cout << "Your amount is $" << amount << endl;
			}
			else if (flipCoin() == TAIL && Player_choice == "Tail")
			{
				total_tails++;
				cout << "Good luck!! It's a TAIL!! You won: $" << bettingAmount * 2 << endl;
				amount = amount + bettingAmount * 2;
				cout << "Your amount is $" << amount << endl;
			}
			else if (flipCoin() == TAIL)
			{
				total_tails++;
				cout << "Bad Luck this time!! You lost $" << bettingAmount << endl;
				amount = amount - bettingAmount;
				cout << "Your amount is $" << amount << endl;
			}
			else
			{
				total_heads++;
				cout << "Bad Luck this time!! You lost $" << bettingAmount << endl;
				amount = amount - bettingAmount;
				cout << "Your amount is $" << amount << endl;
			}

			if (amount == 0)
			{
				cout << "You have no money to play ";
				break;
			}

			cout << "Would you like to flip again? (y/n)" << endl;
			cin >> choice;
			cout << endl;
		}
		if (choice == "n" || choice == "N")
		{
			cout << "Would you like to see how many heads and tails you got? (y/n)" << endl;
			cin >> choice;
			cout << endl;
			if (choice == "Y" || choice == "y")
				cout << "HEADS: " << total_heads << endl << "TAILS: " << total_tails << endl;
		}

		cout << "\n\n-->Do you want to play again (y/n)? ";
		cin >> choice;

	} while (choice == "Y" || choice == "y");

	cout << "\n\n\n";
	drawLine(70, '=');
	cout << "\n\nThanks for playing game. Your balance amount is $ " << amount << "\n\n";
	drawLine(70, '=');
	return 0;
}

//Functions

int flipCoin()
{
	if (rand() % 2 == 0) return HEAD;
	else
		return TAIL;
}

void drawLine(int n, char symbol)
{
	for (int i = 0; i < n; i++)
		cout << symbol;
	cout << "\n";
}

void rules()
{
	system("cls");
	cout << "\n\n";
	drawLine(80, '-');
	cout << "\t\tCoinFlip\n";
	drawLine(80, '-');
	cout << "\t\tRULES OF THE GAME\n";
	drawLine(80, '-');
	cout << "\t1. Choose between HEAD or TAIL\n";
	cout << "\t2. If you win you will get 2 times of money you bet\n";
	cout << "\t3. If you bet on the wrong choice you will lose your betting amount\n\n";
	drawLine(80, '-');
}