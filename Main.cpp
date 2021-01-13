// Author: Nicholas Flood
// Editing History: Initial Creation: 12/16/2020
// Working on RPS Function: 12/17/2020
// Finishing RPS Function: 12/18/2020
// Working on menu: 12/19/2020
// Working on BDH: 12/30/2020
// Working on BDH: 1/3/2021
// Working on BDH: 1/4/2021
// Finishing BDH, Updating Main: 1/11/2021
// Debugging BDH: 1/12/2021
// More details in text file EditingHistory.txt
// Purpose: This is a code to help boost my resume by having a project to show-off.
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

char option = ' ';

// These Functions are for the RPS (Rock, Paper, Scissors) function.
char RPSoption;

void RPSprint(char option)
{
	// This prints out a hand for the option chosen.
	if (option == 'R')
	{
		cout << "    _______" << endl;
		cout << "---'   ____)" << endl;
		cout << "      (_____)" << endl;
		cout << "      (_____)" << endl;
		cout << "      (____)" << endl;
		cout << "---.__(___)" << endl << endl;
	}
	else if (option == 'P')
	{
		cout << "    _______" << endl;
		cout << "---'   ____)____" << endl;
		cout << "          ______)" << endl;
		cout << "          _______)" << endl;
		cout << "         _______)" << endl;
		cout << "---.__________)" << endl << endl;
	}
	else
	{
		cout << "    _______" << endl;
		cout << "---'   ____)____" << endl;
		cout << "          ______)" << endl;
		cout << "       __________)" << endl;
		cout << "      (____)" << endl;
		cout << "---.__(___)" << endl << endl;
	}
}
void RPS()
{
	// This code is so that if chosen again the game does not just quit
	RPSoption = ' ';

	// This while loop keeps running the code till the player chooses quit.
	while (RPSoption != 'Q')
	{
		// This displays a menu to start the program, and shows two options for the player rules explaining the rules for Rock, Paper Scissors and
		// play allows you to play Rock, Paper, Scissors.
		cout << "+---------------------------------+" << endl;
		cout << "|      Rock, Paper, Scissors      |" << endl;
		cout << "|              R - Rules          |" << endl;
		cout << "|              P - Play           |" << endl;
		cout << "|              Q - Quit           |" << endl;
		cout << "+---------------------------------+" << endl << endl;

		cout << "Pick an option from the menu above: ";
		cin >> RPSoption;
		cout << endl;

		// This gets the option on what the player chose and runs code accordingly.
		RPSoption = toupper(RPSoption);
		switch (RPSoption)
		{
		case 'R':
		{
			cout << "The rules of Rock, Paper, Scissors is you choose Rock, Paper or Scissors and your opponent also chooses one of the three. Paper beats Rock, Rock beats Scissors and Scissors beat Paper." << endl;
			break;
		}
		case 'P':
		{
			// This gets the option from the player on what they choose and make sure it is a valid option.
			char RPSoptionP = 'a';
			while (RPSoptionP != 'R' && RPSoptionP != 'P' && RPSoptionP != 'S')
			{
				cout << "Choose an option R for Rock, P for Paper or S for Scissors." << endl;
				cin >> RPSoptionP;
				RPSoptionP = toupper(RPSoptionP);
				if (RPSoptionP != 'R' && RPSoptionP != 'P' && RPSoptionP != 'S')
				{
					cout << "Please choose a valid option." << endl;
				}
			}

			// This code uses a random number to choose an option for the computer
			char RPSoptionC = 'a';
			int intC;
			srand((unsigned)time(0));
			intC = rand() % 3;
			if (intC == 0)
			{
				RPSoptionC = 'R';
			}
			else if (intC == 1)
			{
				RPSoptionC = 'P';
			}
			else
			{
				RPSoptionC = 'S';
			}
			cout << "Player" << endl;
			RPSprint(RPSoptionP);
			cout << "	vs	" << endl << endl;
			cout << "Computer" << endl;
			RPSprint(RPSoptionC);
			if (RPSoptionC == RPSoptionP)
			{
				cout << "TIE!" << endl;
			}
			else if ((RPSoptionC == 'R' && RPSoptionP == 'P') || (RPSoptionC == 'P' && RPSoptionP == 'S') || (RPSoptionC == 'S' && RPSoptionP == 'R'))
			{
				cout << "PLAYER WINS!" << endl;
			}
			else
			{
				cout << "COMPUTER WINS!" << endl;
			}
			break;
		}
		case 'Q':
		{
			cout << "Goodbye I hope you enjoyed Rock, Paper, Scissors." << endl;
			break;
		}
		default:
		{
			cout << "Please enter a valid option." << endl << endl;
		}
		}
	}
}

// These Functions are for the BDH (Binary Decimal Hexidecimal converter) function
char BDHoption;
char BDHresultOption;
int decimalTranslated;
int binaryMultiplier;
int hexMultiplier;
string binaryTranslated;
string hexTranslated;
string initialBinary;
string initialHex;
int initialDecimal;
// These Functions the name corresponds to the start to finish for example BD is Binary to Decimal.
int BD(string binaryNum)
{
	decimalTranslated = 0;
	binaryMultiplier = 1;
	for (int i = binaryNum.length() - 1; i >= 0; i--)
	{
		if (binaryNum[i] == '1')
		{
			decimalTranslated = decimalTranslated + binaryMultiplier;
		}
		binaryMultiplier = 2 * binaryMultiplier;
	}
	return decimalTranslated;
}
string DB(int decimalNum)
{
	// This code figures out the highest digit in the number for example with the number 22 32 is too high so 16 must be a 1.
	int binaryDigit = 1;
	while ((binaryDigit * 2) <= decimalNum)
	{
		binaryDigit = 2 * binaryDigit;
	}

	// This code sees if the sum of the known binary digits minus the target number is equal to the current digit if it isn't it adds a 0
	// if it is it adds a 1 to the binary string.
	binaryTranslated = "1";
	int binarySum = binaryDigit;
	while ((binaryDigit / 2) > 0)
	{
		// This code divides the binaryDigit by 2 so we go to the next lowest digit to test.
		binaryDigit = binaryDigit / 2;
		if ((decimalNum - binarySum) >= binaryDigit)
		{
			// Here since we know another digit we need to add it to the sum of known 1's
			binaryTranslated += "1";
			binarySum = binarySum + binaryDigit;
		}
		else
		{
			binaryTranslated += "0";
		}
	}
	return binaryTranslated;
}
string DH(int decimalNum)
{
	int hexPower = 1;
	int hexDigit = 0;
	int hexSum = 0;
	hexTranslated = "";

	// This figures out how many digits there are.
	while (pow(16, hexPower) <= decimalNum)
	{
		hexPower += 1;
	}

	// This is a loop that keeps going until till we are done with the last digit.
	while (hexPower > 0)
	{
		hexDigit = 0;

		// This figures out what number a digit is by making sure the number doesn't go over like the any number between 101-199 is below 200.
		while ((hexDigit * pow(16, hexPower)) <= (decimalNum - hexSum))
		{
			hexDigit += 1;
		}

		// This figures out the first digit because using the method above does not work on a 1 digit number
		if (hexPower == 1)
		{
			hexDigit = (decimalNum - hexSum);
		}

		// This code converts the hexDigit to a hexidecimal Character and adds it to the finished translation then lowers hexPower by 1
		// to go to the next digit.
		if (hexDigit == 15)
		{
			hexTranslated += "F";
		}
		else if (hexDigit == 14)
		{
			hexTranslated += "E";
		}
		else if (hexDigit == 13)
		{
			hexTranslated += "D";
		}
		else if (hexDigit == 12)
		{
			hexTranslated += "C";
		}
		else if (hexDigit == 11)
		{
			hexTranslated += "B";
		}
		else if (hexDigit == 10)
		{
			hexTranslated += "A";
		}
		else
		{
			hexTranslated += to_string(hexDigit);
		}
		hexSum += (hexDigit * pow(16, hexPower - 1));
		hexPower -= 1;
	}
	return hexTranslated;
}
int HD(string hexNum)
{
	// This function will br similar to the BD converter except we will need to find which digit it is instead of is it a 0 or 1.
	decimalTranslated = 0;
	hexMultiplier = 1;
	for (int i = hexNum.length() - 1; i >= 0; i--)
	{
		if (hexNum[i] == '1')
		{
			decimalTranslated = decimalTranslated + (hexMultiplier * 1);
		}
		else if (hexNum[i] == '2')
		{
			decimalTranslated = decimalTranslated + (hexMultiplier * 2);
		}
		else if (hexNum[i] == '3')
		{
			decimalTranslated = decimalTranslated + (hexMultiplier * 3);
		}
		else if (hexNum[i] == '4')
		{
			decimalTranslated = decimalTranslated + (hexMultiplier * 4);
		}
		else if (hexNum[i] == '5')
		{
			decimalTranslated = decimalTranslated + (hexMultiplier * 5);
		}
		else if (hexNum[i] == '6')
		{
			decimalTranslated = decimalTranslated + (hexMultiplier * 6);
		}
		else if (hexNum[i] == '7')
		{
			decimalTranslated = decimalTranslated + (hexMultiplier * 7);
		}
		else if (hexNum[i] == '8')
		{
			decimalTranslated = decimalTranslated + (hexMultiplier * 8);
		}
		else if (hexNum[i] == '9')
		{
			decimalTranslated = decimalTranslated + (hexMultiplier * 9);
		}
		else if (hexNum[i] == 'A')
		{
			decimalTranslated = decimalTranslated + (hexMultiplier * 10);
		}
		else if (hexNum[i] == 'B')
		{
			decimalTranslated = decimalTranslated + (hexMultiplier * 11);
		}
		else if (hexNum[i] == 'C')
		{
			decimalTranslated = decimalTranslated + (hexMultiplier * 12);
		}
		else if (hexNum[i] == 'D')
		{
			decimalTranslated = decimalTranslated + (hexMultiplier * 13);
		}
		else if (hexNum[i] == 'E')
		{
			decimalTranslated = decimalTranslated + (hexMultiplier * 14);
		}
		else if (hexNum[i] == 'F')
		{
			decimalTranslated = decimalTranslated + (hexMultiplier * 15);
		}
		hexMultiplier = 16 * hexMultiplier;
	}
	return decimalTranslated;
}
string BH(string binaryNum)
{
	// This code goes from binary to hex by using decimal as a middle man so it goes from binary to decimal to decimal to hex.
	return DH(BD(binaryNum));
}
string HB(string hexNum)
{
	// This is the same as BH but backwards.
	return DB(HD(hexNum));
}
void BDH()
{
	BDHoption = ' ';
	bool isValid;
	while (BDHoption != 'Q')
	{
		BDHresultOption = ' ';
		// This displays the menu for BDH.
		cout << "+----------------------------+" << endl;
		cout << "|        Nick Flood's        |" << endl;
		cout << "|   Binary - Decimal - Hex   |" << endl;
		cout << "|         Converter          |" << endl;
		cout << "|                            |" << endl;
		cout << "|        T - Tutorial        |" << endl;
		cout << "|        B - Binary          |" << endl;
		cout << "|        H - Hexidecimal     |" << endl;
		cout << "|        D - Decimal         |" << endl;
		cout << "|        Q - Quit            |" << endl;
		cout << "+----------------------------+" << endl << endl;

		cout << "Please enter an option: ";
		cin >> BDHoption;

		BDHoption = toupper(BDHoption);

		switch (BDHoption)
		{
		case 'T':
		{
			cout << "To use the converter first you need to select the starting number then you will be asked for the number";
			cout << " then you will be asked for the resulting number then you will be shown the initial number and the result (Hex is 0-F and binary is 1 and 0)." << endl;
			break;
		}
		case 'B':
		{

			// Is valid is to make sure that a valid number is put in whether this be that it isn't the right numbers or it is the wrong type
			// in the case of decimal then it will ask you to enter a valid number
			isValid = false;
			while (isValid != true)
			{
				isValid = true;
				cout << "Please enter the number you want to convert: ";
				cin >> initialBinary;

				// This checks every binary number to make sure it is a 1 or 0.
				for (int i = initialBinary.length() - 1; i > 0; i--)
				{
					if (!(initialBinary[i] == '0' | initialBinary[i] == '1'))
					{
						isValid = false;
					}
				}

				// This is a loop where you have to put in a valid input to exit the loop it works just like above just looping.
				if (isValid == false)
				{
					while (isValid != true)
					{
						cout << "Please enter a valid binary number: " << endl;
						cin >> initialBinary;
						isValid = true;
						for (int i = initialBinary.length() - 1; i > 0; i--)
						{
							if (!(initialBinary[i] == '0' | initialBinary[i] == '1'))
							{
								isValid = false;
							}
						}
					}
				}
			}
			while (!((BDHresultOption == 'D') | (BDHresultOption == 'H')))
			{
				cout << "Please enter the resulting number type: ";
				cin >> BDHresultOption;

				// This checks if the input is a char before making uppercase.
				if (cin.fail())
				{
					while (!cin.fail())
					{
						cout << "please enter a valid option: ";
						cin >> BDHresultOption;
					}
				}

				BDHresultOption = toupper(BDHresultOption);
				switch (BDHresultOption)
				{
				case 'D':
				{
					cout << initialBinary << " in binary is " << BD(initialBinary) << " in decimal." << endl << endl;
					break;
				}
				case 'H':
				{
					cout << initialBinary << " in binary is " << BH(initialBinary) << " in hexidecimal." << endl << endl;
					break;
				}
				default:
				{
					cout << "Please enter a valid option." << endl;
					cin.ignore(numeric_limits<int>::max(), '\n');
				}
				}
			}
			break;
		}
		case 'D':
		{
			cout << "Please enter the number you want to convert: ";
			cin >> initialDecimal;

			if (cin.fail())
			{
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<int>::max(), '\n');
					cout << "Please enter a valid number: ";
					cin >> initialDecimal;
				}
			}
			while (!(BDHresultOption == 'B' | BDHresultOption == 'H'))
			{
				cout << "Please enter the resulting number type: ";
				cin >> BDHresultOption;

				if (cin.fail())
				{
					while (cin.fail())
					{
						cout << "Please enter a valid option: ";
						cin >> initialDecimal;
					}
				}
				BDHresultOption = toupper(BDHresultOption);
				switch (BDHresultOption)
				{
				case 'B':
				{
					cout << initialDecimal << " in decimal is " << DB(initialDecimal) << " in binary." << endl << endl;
					break;
				}
				case 'H':
				{
					cout << initialDecimal << " in decimal is " << DH(initialDecimal) << " in hexidecimal." << endl << endl;
					break;
				}
				default:
				{
					cout << "Please enter a valid option. " << endl;
					cin.ignore(numeric_limits<int>::max(), '\n');
				}
				}
			}
			break;
		}
		case 'H':
		{
			cout << "Please enter the number you want to convert any non-hex digits will be considered 0: ";
			cin >> initialHex;

			isValid = true;
			for (int i = initialBinary.length() - 1; i > 0; i--)
			{
				if (!((initialHex[i] == '0') | (initialHex[i] == '1') | (initialHex[i] == '2') | (initialHex[i] == '3') | (initialHex[i] == '4') | (initialHex[i] == '5') | (initialHex[i] == '6') | (initialHex[i] == '7') | (initialHex[i] == '8') | (initialHex[i] == '9') | (toupper(initialHex[i]) == 'A') | (toupper(initialHex[i]) == 'B') | (toupper(initialHex[i]) == 'C') | (toupper(initialHex[i]) == 'D') | (toupper(initialHex[i]) == 'E') | (toupper(initialHex[i]) == 'F')))
				{
					isValid = false;
				}
			}

			if (isValid == false)
			{
				while (isValid != true)
				{
					cout << "Please enter a valid option: ";
					cin >> initialHex;

					isValid = true;
					for (int i = initialBinary.length() - 1; i > 0; i--)
					{
						if (!(initialHex[i] == '0' | initialHex[i] == '1' | initialHex[i] == '2' | initialHex[i] == '3' | initialHex[i] == '4' | initialHex[i] == '5' | initialHex[i] == '6' | initialHex[i] == '7' | initialHex[i] == '8' | initialHex[i] == '9' | toupper(initialHex[i]) == 'A' | toupper(initialHex[i]) == 'B' | toupper(initialHex[i]) == 'C' | toupper(initialHex[i]) == 'D' | toupper(initialHex[i]) == 'E' | toupper(initialHex[i]) == 'F'))
						{
							isValid = false;
						}
					}
				}
			}

			while (!(BDHresultOption == 'B' | BDHresultOption == 'D'))
			{
				cout << "Please enter the resulting number type: ";
				cin >> BDHresultOption;

				BDHresultOption = toupper(BDHresultOption);
				switch (BDHresultOption)
				{
				case 'B':
				{
					cout << initialHex << " in hexidecimal is " << HB(initialHex) << " in binary." << endl << endl;
					break;
				}
				case 'D':
				{
					cout << initialHex << " in hexidecimal is " << HD(initialHex) << " in decimal." << endl << endl;
					break;
				}
				default:
				{
					cout << "Please enter a valid option." << endl;
					cin.ignore(numeric_limits<int>::max(), '\n');
					cin >> BDHresultOption;
				}
				}
			}
			break;
		}
		case 'Q':
		{
			cout << "Thanks for using the Binary - Decimal - Hex Converter." << endl << endl;
			break;
		}
		default:
		{
			cout << "Please enter a valid option." << endl;
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		}
	}
}
// This is the compilation of all the functions into one program to run all the other functions.
int main()
{
	while (option != 'Q')
	{

		cout << "+---------------------------------+" << endl;
		cout << "|         Nicholas Flood's        |" << endl;
		cout << "|             Mini-Game           |" << endl;
		cout << "|             Emporium            |" << endl;
		cout << "|        R - Rock,Paper,Scissors  |" << endl;
		cout << "|        B - BinaryDecimalHex     |" << endl;
		cout << "|        Q - Quit                 |" << endl;
		cout << "+---------------------------------+" << endl;

		cout << "Enter an option: ";
		cin >> option;
		option = toupper(option);

		switch (option)
		{
		case 'R':
		{
			RPS();
			break;
		}
		case 'B':
		{
			BDH();
			break;
		}
		case 'Q':
		{
			cout << "Thanks for visiting Nicholas Flood's Mini-Game Emporium. This was programmed by Nicholas Flood to show his experience in coding." << endl;
			break;
		}
		default:
		{
			cout << "Please enter a valid option." << endl << endl;
		}
		}
	}
}
