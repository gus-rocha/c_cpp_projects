#include <stdio.h>
#include <time.h>
#include <stdlib.h> // rand, srand
#include <unistd.h> // Sleep

int genNumZeroToTwo()
{
	int r = rand() % 3;
	return r;
}

void returnGameState(int cpu, char player)
{
	switch (cpu)
	{
		case 0: // Rock
			printf("The CPU chose Rock! ");
			switch (player)
			{
				case 'R': case 'r':
					printf("It's a Draw!");
					break;

				case 'P': case 'p':
					printf("You Win!");
					break;

				case 'S': case 's':
					printf("You Lose!");
					break;
			}
			break;

		case 1: // Paper
			printf("The CPU chose Paper! ");
			switch (player)
			{
				case 'R': case 'r':
					printf("You Lose!");
					break;

				case 'P': case 'p':
					printf("It's a Draw!");
					break;

				case 'S': case 's':
					printf("You Win!");
					break;
			}
			break;

		case 2: // Scissors
			printf("The CPU chose Scissors! ");
			switch (player)
			{
				case 'R': case 'r':
					printf("You Win!");
					break;

				case 'P': case 'p':
					printf("You Lose!");
					break;

				case 'S': case 's':
					printf("It's a Draw!");
					break;
			}
			break;
	}
}

int main()
{
	char userSelection;
	int gameReturn;
	srand(time(0));

	printf("Rock, Paper, Scissors!");
	
	while (1)
	{
		printf("\nChoose your option:\n[R]ock, [P]aper, [S]cissors\n> ");
		scanf(" %c", &userSelection);
		// 0 = Rock
		// 1 = Paper
		// 2 = Scissors
		// gameReturn = genNumZeroToTwo();
		
		// Deffinitely there's a better way of doing this
		if (userSelection != 'R' && userSelection != 'r' && userSelection != 'P' && userSelection != 'p' && userSelection != 'S' && userSelection != 's')
		{
			printf("Please, select a valid option."); 
			sleep(1.4);
		}
		else
		{
			returnGameState(genNumZeroToTwo(), userSelection);
			sleep(1.4);
			printf("\n");
		}
	}
	// printf("%d", genNumZeroToTwo());
	return 0;
}