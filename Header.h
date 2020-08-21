#define _CRT_SECURE_NO_WARNINGS
#define RULES 1
#define BANK 2
#define PLAY 3
#define EXIT 4

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

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

int get_option(void);
int game_menu(void);
void print_game_menu(void);
void print_game_rules(void);
double add_amount(void);
void change_bank_balance(int account, double bank1, double bank2, double bank3, double bank4, double bank5, double* ptrbank1, double* ptrbank2, double* ptrbank3, double* ptrbank4, double* ptrbank5);
double get_wager_amount(void);
char continue_option(void);
char continue_game_prompt(void);
int roll_die(void);
void turn(double bank, double* wager, int* ptrsum);
int get_players(void);
void gameplay(int players, double bank1, double bank2, double bank3, double bank4, double bank5, double* ptrbank1, double* ptrbank2, double* ptrbank3, double* ptrbank4, double* ptrbank5, FILE* infile);
void output_sum(FILE* infile, int sum);
int get_max(FILE* infile);
void get_bank_accounts(double bank1, double bank2, double bank3, double bank4, double bank5);
