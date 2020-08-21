#include "Header.h"

/*
	Name: Koji Natsuhara

	Date: 10/7/2019

	Description: The purpose of the PA4 Write a program that implements a variation of the 
	game of Blackjack Dice. Blackjack Dice is a multiplayer game that involves rolling a single 
	6-sided die, multiple times, with the objective of obtaining as close to 21 without going over.

	IN THIS PROGRAM I WILL HAVE TO:
	1. Open and close files
	2. Read, write to, and update files
	3. Apply standard library functions: fopen (), fclose (), fscanf (), and fprintf ()
	4. Compose decision statements ("if" conditional statements)
	5. Create and utilize compound conditions
	6. Be able to include while(), do-while(), and for() loops
*/


/*
Function: get_option
Date Created: 10/7/2019
Date Modified: 10/7/2019
Description: Asks user for an integer as an option.
Input Parameters: void
Returns: integer 
Preconditions: Initialized integer variable for the function
Postconditions: An integer variable inputted by the user
*/
int get_option(void)
{
	int option = 0;
	printf("Select a valid option: ");
	scanf("%d", &option);
	return option;
}

/*
Function: game_menu
Date Created: 10/7/2019
Date Modified: 10/7/2019
Description: A function which repeatedly asks the user for an integer between 1 and 4
Input Parameters: void
Returns: Integer between 1 and 4
Preconditions: Initialized integer variable for the function
Postconditions: An integer variable inputted by the user
*/
int game_menu(void)
{
	int x = 0;
	do 
	{
		print_game_menu();
		x = get_option();
	} while (x < RULES || x > EXIT);

	return x;
}

/*
Function: print_game_menu
Date Created: 10/7/2019
Date Modified: 10/7/2019
Description: Prints out the game menu
Input Parameters: void
Returns: prints out the game menu to the screen
Preconditions: none
Postconditions: none
*/
void print_game_menu(void)
{
	printf("------Welcome to Blackjack Dice------\n");
	printf("1.    Display game rules\n");
	printf("2.    Add funds to bank balance.\n");
	printf("3.    Play game.\n");
	printf("4.    Exit.\n");
}

/*
Function: print_game_rules
Date Created: 10/7/2019
Date Modified: 10/7/2019
Description: Prints out the game rules
Input Parameters: void
Returns: Prints out the game rules
Preconditions: none
Postconditions: none
*/
void print_game_rules(void)
{
	printf("1. During each turn a player rolls a single die multiple times.\n");
	printf("2. Before each roll, a player has the option to bet some money. The amount should not exceed the player’s current back balance.\n");
	printf("3. Each roll is added to the player’s total. A player can roll the single die as many times as they desire.\n");
	printf("4. When a player has scored 16 or more, they have the option to stop rolling. If he/she stops rolling, then it is the next player’s turn.\n");
	printf("5. If the player’s score exceeds 21, then the player loses, and it is the next player’s turn.\n");
	printf("6. The objective is to score 21 or as close as possible without going over 21.\n");
	printf("7. Each player that scores 21 earns double the money he/she bet.\n");
	printf("8. If no player scores 21, then the player closest without going over earns 1.5 times the money he/she bet. If multiple players earn the same high score for the game, and it is not 21, then the players get the money they bet back. All other players lose their bet.\n");
	printf("9. The game is played until one player decides to stop.\n");
}

/*
Function: add_amount
Date Created: 10/7/2019
Date Modified: 10/7/2019
Description: Asks for the user to input a double to add to a bank account
Input Parameters: void
Returns: A double inputted by the user
Preconditions: an intialized double
Postconditions: a double with a value inputted by the user
*/
double add_amount(void)
{
	double money = 0;
	printf("How much money would you like to add to the account?: ");
	scanf("%lf", &money);
	return money;
}

/*
Function: change_bank_balance
Date Created: 10/7/2019
Date Modified: 10/7/2019
Description: based on the amount that the user previous submits, the value is added to a bank account
Input Parameters:int account, double bank1, double bank2, double bank3, double bank4, double bank5, double* ptrbank1, double* ptrbank2, double* ptrbank3, double* ptrbank4, double* ptrbank5
Returns: a double which is added to the specific bank
Preconditions: The user must have specified which bank they want to deposit/withdraw money from
Postconditions: 5 bank accounts with varying/non varying amounts
*/
void change_bank_balance(int account, double bank1, double bank2, double bank3, double bank4, double bank5, double* ptrbank1, double* ptrbank2, double* ptrbank3, double* ptrbank4, double* ptrbank5)
{
	double deposit = 0;
	if (account == 1)
	{
		deposit = add_amount();
		*ptrbank1 = bank1 + deposit;
	}
	if (account == 2)
	{
		deposit = add_amount();
		*ptrbank2 = bank2 + deposit;
	}
	if (account == 3)
	{
		deposit = add_amount();
		*ptrbank3 = bank3 + deposit;
	}
	if (account == 4)
	{
		deposit = add_amount();
		*ptrbank4 = bank4 + deposit;
	}
	if (account == 5)
	{
		deposit = add_amount();
		*ptrbank5 = bank5 + deposit;
	}
}

/*
Function: get_wager_amount
Date Created: 10/7/2019
Date Modified: 10/7/2019
Description: Prompts the user for a double
Input Parameters: void
Returns: double inputted by the user
Preconditions: an initialized double variable set to the function
Postconditions: a double variable with a value submitted by the user
*/
double get_wager_amount(void)
{
	double wager = 0;
	printf("What is your wager?: ");
	scanf("%lf", &wager);
	return wager;
}

/*
Function: continue_option
Date Created: 10/7/2019
Date Modified: 10/7/2019
Description: prompts the user for a character
Input Parameters: void
Returns: a character inputted by the user
Preconditions: an intitalized character variable set equal to the function
Postconditions: a character variable with a character submitted by the user
*/
char continue_option(void)
{
	char c = '\0';
	printf("Would you like to continue (Y/N)?: ");
	scanf(" %c", &c);
	return c;
}

/*
Function: continue_game_prompt
Date Created: 10/7/2019
Date Modified: 10/7/2019
Description: prompts the user for a character
Input Parameters: void
Returns: a character inputted by the user
Preconditions: an intitalized character variable set equal to the function
Postconditions: a character variable with a character submitted by the user
*/
char continue_game_prompt(void)
{
	char c = '\0';
	printf("Do you want to play another round (Y/N)?: ");
	scanf(" %c", &c);
	return c;
}

/*
Function: roll_die
Date Created: 10/7/2019
Date Modified: 10/7/2019
Description: Produces a random number from 1 to 6.
Input Parameters: void
Returns: an integer between 1 to 6
Preconditions: an intialized integer variable set to the function
Postconditions: an integer variable with a random integer from 1 to 6 
*/
int roll_die(void)
{
	int die_value = 0;

	die_value = rand() % 6 + 1;

	return die_value;
}

/*
Function: turn
Date Created: 10/7/2019
Date Modified: 10/7/2019
Description: This function keeps track of a player's bank, wager and sum of the dice rolled. If the sum of the dice rolled is over 16, the user will
get a prompt asking whether or not they want to continue rolling, and if the sum of the dice exceeds 21 the ptrsum is set to -1. Before every roll, the user is 
asked if they would like make a wager.
Input Parameters:double bank, double* wager, int* ptrsum
Returns: void
Preconditions: Intialized variables bank, wager, sum
Postconditions: The addresses of wager and sum will be set to addresses of the wager and ptrsum
*/
void turn(double bank, double* wager, int* ptrsum)
{
	double bet = 0.0, total_bet = 0.0;
	int sum = 0, count = 0;
	char cont = 'Y';
	while (sum < 21 && cont == 'Y')
	{
		printf("---------------------------------------\n");
		bet = get_wager_amount();
		total_bet += bet;
		if (total_bet > bank)
		{
			printf("********You are going all in!********\n");
			total_bet = bank;
		}
		count = roll_die();
		sum += count;

		printf("You rolled a %d!\nYour total sum is %d!\n", count, sum);
		printf("Your wager total: %.2lf\n", total_bet);
		printf("---------------------------------------\n");
		if (sum >= 16)
		{
			cont = continue_option();
		}
	}
	if (sum > 21)
	{
		printf("_________You've already busted!_________\n");
		sum = -1;
	}
	*wager = total_bet;
	*ptrsum = sum;
}

/*
Function: get_players
Date Created: 10/7/2019
Date Modified: 10/7/2019
Description: Asks the user how many players will be in the game and returns an integer between 2 and 5
Input Parameters: void
Returns: an integer between 2 and 5
Preconditions: an intialized integer that is set to the function
Postconditions: an integer with the number of players playing between 2 and 5
*/
int get_players(void)
{
	int players = 0;
	do
	{
		printf("How many players are there?: ");
		scanf("%d", &players);
	} while (players < 2 || players > 5);

	return players;
}

/*
Function: gameplay
Date Created: 10/7/2019
Date Modified: 10/7/2019
Description: This function will take into account how many players are playing as well as the bank account of each of the players. The gameplay function
will run a separate game based on the amount of players playing. Each player will get a turn and the gameplay function will calculate the max
dice sum rolled and then calculate how much money each player won or lost and manipulates their bank account accordingly.
Input Parameters:
Returns:
Preconditions:
Postconditions:
*/
void gameplay(int players, double bank1, double bank2, double bank3, double bank4, double bank5, double *ptrbank1, double *ptrbank2, double *ptrbank3, double *ptrbank4, double *ptrbank5, FILE* infile)
{
	/*
		ask wager (must not exceed bank balance)
		roll (must not exceed 21)
		return value on turn
		can stop after 16
		if player gets 21 the player's bet doubles
		person closet to 21 earns 1.5 times the money
		tied players get money back and all other players lose
		after each round a player gets to choose whether or not to continue
	*/
	double wager1 = 0.0, wager2 = 0.0, wager3 = 0.0, wager4 = 0.0, wager5 = 0.0;
	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
	int winner1 = 0, winner2 = 0, winner3 = 0, winner4 = 0, winner5 = 0, numWin = 0;
	int max = 0;

	switch (players)
	{
		case 2:
				printf("============Player 1 it is your turn!============\n");
				turn(bank1, &wager1, &sum1);
				output_sum(infile, sum1);
				printf("============Player 2 it is your turn!============\n");
				turn(bank2, &wager2, &sum2);
				output_sum(infile, sum2);
				max = get_max(infile);
			break;
		case 3:
				printf("============Player 1 it is your turn!============\n");
				turn(bank1, &wager1, &sum1);
				output_sum(infile, sum1);
				printf("============Player 2 it is your turn!============\n");
				turn(bank2, &wager2, &sum2);
				output_sum(infile, sum2);
				printf("============Player 3 it is your turn!============\n");
				turn(bank3, &wager3, &sum3);
				output_sum(infile, sum3);
				max = get_max(infile);
			break;
		case 4:
				printf("============Player 1 it is your turn!============\n");
				turn(bank1, &wager1, &sum1);
				output_sum(infile, sum1);
				printf("============Player 2 it is your turn!============\n");
				turn(bank2, &wager2, &sum2);
				output_sum(infile, sum2);
				printf("============Player 3 it is your turn!============\n");
				turn(bank3, &wager3, &sum3);
				output_sum(infile, sum3);
				printf("============Player 4 it is your turn!============\n");
				turn(bank4, &wager4, &sum4);
				output_sum(infile, sum4);
				max = get_max(infile);
			break;
		case 5:
				printf("============Player 1 it is your turn!============\n");
				turn(bank1, &wager1, &sum1);
				output_sum(infile, sum1);
				printf("============Player 2 it is your turn!============\n");
				turn(bank2, &wager2, &sum2);
				output_sum(infile, sum2);
				printf("============Player 3 it is your turn!============\n");
				turn(bank3, &wager3, &sum3);
				output_sum(infile, sum3);
				printf("============Player 4 it is your turn!============\n");
				turn(bank4, &wager4, &sum4);
				output_sum(infile, sum4);
				printf("============Player 5 it is your turn!============\n");
				turn(bank5, &wager5, &sum5);
				output_sum(infile, sum5);
				max = get_max(infile);
			break;
	}

	if (max == sum1 && sum1 != -1)
	{
		winner1 = 1;
		numWin++;
		if (sum1 == 21)
		{
			*ptrbank1 = bank1 + 2 * wager1;
			printf("Player 1 doubled up!\n");
		}
	}
	else
	{
		*ptrbank1 = bank1 - wager1;
	}
	if (max == sum2 && sum2 != -1)
	{
		winner2 = 1;
		numWin++;
		if (sum2 == 21)
		{
			*ptrbank2 = bank2 + 2 * wager2;
			printf("Player 2 doubled up!\n");
		}
	}
	else
	{
		*ptrbank2 = bank2 - wager2;
	}
	if (max == sum3 && sum3 != -1)
	{
		winner3 = 1;
		numWin++;
		if (sum3 == 21)
		{
			*ptrbank3 = bank3 + 2 * wager3;
			printf("Player 3 doubled up!\n");
		}
	}
	else
	{
		*ptrbank3 = bank3 - wager3;
	}
	if (max == sum4 && sum4 != -1)
	{
		winner4 = 1;
		numWin++;
		if (sum4 == 21)
		{
			*ptrbank4 = bank4 + 2 * wager4;
			printf("Player 4 doubled up!\n");
		}
	}
	else
	{
		*ptrbank4 = bank4 - wager4;
	}
	if (max == sum5 && sum5 != -1)
	{
		winner5 = 1;
		numWin++;
		if (sum5 == 21)
		{
			*ptrbank5 = bank5 + 2 * wager5;
			printf("Player 5 doubled up!\n");
		}
	}
	else
	{
		*ptrbank5 = bank5 - wager5;
	}
	if (numWin == 1)
	{
		if (winner1 == 1)
		{
			*ptrbank1 = bank1 + 1.5 * wager1;
			printf("Player 1 won!\n");
			if (sum1 == 21)
			{
				*ptrbank1 = bank1 + 2 * wager1;
				printf("Player 1 doubled up!\n");
			}
		}
		if (winner2 == 1)
		{
			*ptrbank2 = bank2 + 1.5 * wager2;
			printf("Player 2 won!\n");
			if (sum2 == 21)
			{
				*ptrbank2 = bank2 + 2 * wager2;
				printf("Player 2 doubled up!\n");
			}
		}
		if (winner3 == 1)
		{
			*ptrbank3 = bank3 + 1.5 * wager3;
			printf("Player 3 won!\n");
			if (sum3 == 21)
			{
				*ptrbank3 = bank3 + 2 * wager3;
				printf("Player 3 doubled up!\n");
			}
		}
		if (winner4 == 1)
		{
			*ptrbank4 = bank4 + 1.5 * wager4;
			printf("Player 4 won!\n");
			if (sum4 == 21)
			{
				*ptrbank4 = bank4 + 2 * wager4;
				printf("Player 4 doubled up!\n");
			}
		}
		if (winner5 == 1)
		{
			*ptrbank5 = bank5 + 1.5 * wager5;
			printf("Player 5 won!\n");
			if (sum5 == 21)
			{
				*ptrbank5 = bank5 + 2 * wager5;
				printf("Player 5 doubled up!\n");
			}
		}
	}
}

/*
Function: output_sum
Date Created: 10/7/2019
Date Modified: 10/7/2019
Description: This function prints an integer to input.txt
Input Parameters: FILE* infile, int sum
Returns: void
Preconditions: must have a integer variable already intialized and infile must be open
Postconditions: one line down in the file
*/
void output_sum(FILE* infile, int sum)
{
	fprintf(infile, "%d\n", sum);
}

/*
Function: get_max
Date Created: 10/7/2019
Date Modified: 10/7/2019
Description: Reads integers from a txt file and then returns the max of those values
Input Parameters:FILE* infile
Returns: the max integer in the file
Preconditions: file must be open and the file pointer must be reset
Postconditions: file pointer will be located at the bottom
*/
int get_max(FILE* infile)
{
	rewind(infile);
	int max = -1;
	int value = 0;
	while (!feof(infile))
	{
		
		fscanf(infile, "%d ", &value);
		if (max < value)
		{
			max = value;
		}
	}
	return max;
}

/*
Function: get_bank_accounts
Date Created: 10/7/2019
Date Modified: 10/7/2019
Description: Prints out all 5 of the players bank accounts
Input Parameters: double bank1, double bank2, double bank3, double bank4, double bank5
Returns: void
Preconditions: none
Postconditions: none
*/
void get_bank_accounts(double bank1, double bank2, double bank3, double bank4, double bank5)
{
	printf("----------------Bank Accounts----------------\n");
	printf("Player 1: %.2lf..............................\n", bank1);
	printf("Player 2: %.2lf..............................\n", bank2);
	printf("Player 3: %.2lf..............................\n", bank3);
	printf("Player 4: %.2lf..............................\n", bank4);
	printf("Player 5: %.2lf..............................\n", bank5);
}


