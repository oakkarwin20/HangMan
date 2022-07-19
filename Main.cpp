#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;

//Set variables used throughout the game
int tries{ 6 };  //Number of attempts for correct guess 
char guess; //The letter guessed
bool correctGuess = false;
char previousGuesses[7]; // an array of guesses needs to be 1 longer than the user can guess
string Word;   //This is the word players have to guess
string WordList[99]; // array of 100 strings

void startScreen() 
{
	//START SCREEN
	char start{};

	system("CLS");//really shouldn't use this

	cout << "================================" << endl;
	cout << "           Hang-Man	         " << endl;
	cout << "================================" << endl;
	cout << "_______________________________" << endl;
	cout << "               )               " << endl;
	cout << "               O               " << endl;
	cout << "              _|_              " << endl;
	cout << "             / | \\            " << endl;
	cout << "            / _|_ \\           " << endl;
	cout << "             /   \\            " << endl;
	cout << "            /     \\           " << endl;
	cout << "_______________________________" << endl;
	cout << "\nPress 'any key' and 'Enter' to start" << endl;
	cout << "_______________________________" << endl;
	cin >> start;

	//clear screen
	system("CLS");//really shouldn't use this
}

void switchStatement() 
{
	switch (tries)
	{
	case 6:
	{
		cout << "_______________________________" << endl;
		cout << "               }               " << endl;
		cout << "                               " << endl;
		cout << "                               " << endl;
		cout << "                               " << endl;
		cout << "                               " << endl;
		cout << "                               " << endl;
		cout << "                               " << endl;
		cout << "-------------------------------" << endl;
		break;
	}
	case 5:
	{
		cout << "_______________________________" << endl;
		cout << "               }               " << endl;
		cout << "               O               " << endl;
		cout << "                               " << endl;
		cout << "                               " << endl;
		cout << "                               " << endl;
		cout << "                               " << endl;
		cout << "                               " << endl;
		cout << "-------------------------------" << endl;

		if (correctGuess == false) 
		{
			previousGuesses[0] = guess;
		}
		break;
	}
	case 4:
	{
		cout << "_______________________________" << endl;
		cout << "               }               " << endl;
		cout << "               O               " << endl;
		cout << "              _|_              " << endl;
		cout << "                               " << endl;
		cout << "                               " << endl;
		cout << "                               " << endl;
		cout << "                               " << endl;
		cout << "-------------------------------" << endl;

		if (correctGuess == false) 
		{
			previousGuesses[1] = guess;
		}
		break;
	}
	case 3:
	{
		cout << "_______________________________" << endl;
		cout << "               }               " << endl;
		cout << "               O               " << endl;
		cout << "              _|_              " << endl;
		cout << "             / | \\            " << endl;
		cout << "                               " << endl;
		cout << "                               " << endl;
		cout << "                               " << endl;
		cout << "-------------------------------" << endl;

		if (correctGuess == false)
		{
			previousGuesses[2] = guess;
		}
		break;
	}
	case 2:
	{
		cout << "_______________________________" << endl;
		cout << "               }               " << endl;
		cout << "               O               " << endl;
		cout << "              _|_              " << endl;
		cout << "             / | \\            " << endl;
		cout << "            / _|_ \\           " << endl;
		cout << "                               " << endl;
		cout << "                               " << endl;
		cout << "-------------------------------" << endl;

		if (correctGuess == false) 
		{
			previousGuesses[3] = guess;
		}
		break;
	}
	case 1:
	{
		cout << "_______________________________" << endl;
		cout << "               }               " << endl;
		cout << "               O               " << endl;
		cout << "              _|_              " << endl;
		cout << "             / | \\            " << endl;
		cout << "            / _|_ \\           " << endl;
		cout << "             /   \\            " << endl;
		cout << "                               " << endl;
		cout << "-------------------------------" << endl;

		if (correctGuess == false) 
		{
			previousGuesses[4] = guess;
		}
		break;
	}
	case 0:
	{
		cout << "\nGAME-OVER!" << endl;
		cout << "_______________________________" << endl;
		cout << "               }               " << endl;
		cout << "               O               " << endl;
		cout << "              _|_              " << endl;
		cout << "             / | \\            " << endl;
		cout << "            / _|_ \\           " << endl;
		cout << "             /   \\            " << endl;
		cout << "            /     \\           " << endl;
		cout << "-------------------------------" << endl;

		tries = -1;
		break;
	}
	default: 
		{
			cout << "Error" << endl;
		}
	}
}

int main() {

	startScreen();

	previousGuesses[0] = '\0';

	for (int i = 1; i < 6; i++) 
	{
		previousGuesses[i] = '-';
	}

	previousGuesses[6] = '\0';
	
	//Get random word
	srand(time(NULL)); // generates random number to retrieve word from "Word.txt" file
	ifstream RandomWord; //This file stream reads in the variable
	RandomWord.open("Words.txt"); // reads in the "Word.txt" file with list of words

	for (int i = 0; i < 99; i++)
	{
		RandomWord >> WordList[i];
		//cout << WordList[i] << endl; // Testing purposes only
	}

	int RandomNum = rand() % 100; // returns a number from 0 - 99
	Word = WordList[RandomNum];
	cout << Word << endl; // Testing purposes
	RandomWord.close();

	string MysteryWord(Word.length(), '*'); //Makes word a mystery and replaces each letter of word with "*" and stores in MysteryWord 
	//cout << MysteryWord << endl; // test the word (will be used later)

	while (tries >= 0)
	{
		//reset bool
		correctGuess = false;

		//Display info related to word for player hints
		cout << "_______________________________" << endl;
		cout << "This word has " << MysteryWord.length() << " letters: " << MysteryWord << endl;
		cout << "You have " << tries << " guesses left." << endl;

		if (previousGuesses[0] == '\0') 
		{
			cout << endl;
		}
		else 
		{
			cout << "You guessed '" << previousGuesses << "'" << endl;
		}

		//get player guess
		cout << "Guess a letter: ";
		cin >> guess;

		//Check if guess correct
		for (int i = 0; i < MysteryWord.length(); i++) //for the length of the word (using myster) do the following
		{
			if (Word[i] == guess) //check does the word (actual) have guess in it 
			{
				MysteryWord[i] = guess;

				correctGuess = true;
			}
		}

		switchStatement();

		if (Word == MysteryWord)
		{
			cout << "_______________________________" << endl;
			cout << "\n\nCongratulations! You've got the word correct! " << MysteryWord << endl;
			break;
		}

		if (correctGuess == false)
		{
			tries--;
			cout << "_______________________________" << endl;
			cout << "Sorry, '" << guess << "' is not part of the word" << endl;
		}
		else
		{
			cout << "_______________________________" << endl;
			cout << "Yay, '" << guess << "' is one of the letters!" << endl;
		}
	}
	return 0;
}