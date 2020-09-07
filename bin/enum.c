/**
 * @file enum.cpp
 *
 * @version 01.01 2020-08-15
 *
 * @brief 
 *
 * @ingroup enum
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Castellani Davide
 *
 * Contact: contacts@castellanidavide.it
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status
{
	CONTINUE,
	WOW,
	LOST
};

int roolDice(void);

int main()
{
	srand(time(NULL)); // Setup random

	int myPoint;
	enum Status gameStatus;
	int sum = roolDice();

	switch (sum)
	{
	case 7:
	case 11:
		gameStatus = WOW;
		break;

	case 2:
	case 3:
	case 12:
		gameStatus = LOST;
		break;

	default:
		gameStatus = CONTINUE;
		myPoint = sum;
		printf("Point is %d\n", myPoint);
		break;
	}

	while (CONTINUE == gameStatus)
	{
		sum = roolDice();

		if (sum == myPoint)
		{
			gameStatus = WOW;
		}
		else
		{
			if (7 == sum)
			{
				gameStatus = LOST;
			}
		}
	}

	if (WOW == gameStatus)
	{
		puts("Player wins!\n");
	}

	if (LOST == gameStatus)
	{
		puts("Player losts!\n");
	}

	return 0;
}

int roolDice(void)
{
	int die1 = 1 + (rand() % 6);
	int die2 = 1 + (rand() % 6);

	printf ("Dice are %d %d\n", die1, die2);

	return die1 + die2;
}