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

int main(void)
{
	FILE* infile = fopen("input.txt", "w+");

	double bank1 = 100.00, bank2 = 100.00, bank3 = 100.00, bank4 = 100.00, bank5 = 100.00;
	int option = 0, players = 0, account = 0;
	char proceed = 'Y';

	srand(time(NULL));

	while (option != EXIT)
	{
		option = game_menu();
		switch (option)
		{
		case RULES:
			print_game_rules();
			break;
		case BANK:
			get_bank_accounts(bank1, bank2, bank3, bank4, bank5);
			printf("Which bank account number would you like to change?");
			scanf("%d", &account);
			change_bank_balance(account, bank1, bank2, bank3, bank4, bank5, &bank1, &bank2, &bank3, &bank4, &bank5);
			get_bank_accounts(bank1, bank2, bank3, bank4, bank5);
			break;
		case PLAY:
			players = get_players();
			do
			{
				gameplay(players, bank1, bank2, bank3, bank4, bank5, &bank1, &bank2, &bank3, &bank4, &bank5, infile);
				get_bank_accounts(bank1, bank2, bank3, bank4, bank5);
				proceed = continue_game_prompt();
			} while (proceed == 'Y');
			break;
		case EXIT:
			break;
		}
	}

	fclose(infile);

	return 0;
}

