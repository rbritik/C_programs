// Craps game (two dice) 
/*
 rolls two dice. calcuate their sum
If sum is 7 or 11 on the first throw, the player wins (Total 8 instances)
if the sum is 2, 3 or 12 on the first throw, the player loses (Total 4 instances).
 If the sum is 4,5,6,8,9 or 10 on first throw, then that sum becomes player's point.
 Keep rolling until you make the point ( you win) or if you roll 7 earlier then you lose */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Enumeration constant represent game status
enum Status {CONTINUE, WON, LOST};

// Size of arrays containing information about length of a game
#define SIZE 21   

// Function Prototype
int rollDice();
int game_duration(int a[], int c);
void printArray(int arr1[]);


// Starting of main function 
int main(void)
{
	srand(time(NULL));  // For Random dice outputs
	enum Status gameStatus;

	// How many game are won or lost
	int won_count = 0;  
	int lost_count = 0;

	int game_won[SIZE] = {0};  // To store number of rolls at which the game is won
	int game_lost[SIZE] = {0};  // To store number of rolls at which the game is lost 

	int total_count;  // total Length

	for(int i = 0; i < 1000; i++)
	{
		int count = 0;  // To count number of roll it takes to won a game

		int myPoint; // player must make this point to win

		int sum = rollDice();  // Calling function for giving sum of two dies rolls

		switch(sum)
		{
			// win on first roll
			case 7:  // 7 is a winner
			case 11: // 11 is a winner
			    gameStatus = WON;
			    count++;
			    break;

			// Lose on first roll
			case 2:  // 2 is a loser
			case 3:  // 3 is a loser
			case 12: // 12 is a loser
			    gameStatus = LOST;
			    count++;
			    break;

			// remember point
			default: 
				gameStatus = CONTINUE;
				myPoint = sum;
				count++;
			    break;
		}

		// while game is not complete
		while (gameStatus == CONTINUE)
		{
			sum = rollDice();

			if (sum == myPoint)
			{
				count++;
				gameStatus = WON;
				break;
			}

			else if (sum == 7)
			{
				count++;
				gameStatus = LOST;
				break;
			}

			count++;

		}

		total_count += count; 


		// If wins
		if (WON == gameStatus)
		{
			won_count++;
			game_duration(game_won, count);
		}

		// If lose
		else
		{
			lost_count++;
			game_duration(game_lost, count);
		}
	}	

	puts("------Game Won--------");
	printf("Number of game won: %d\n", won_count);
	printArray(game_won);

	puts("");
	puts("------Game Lost-------");
	printf("Number of game lost: %d\n", lost_count);
	printArray(game_lost);

	// Printing average length of game in 1000 games
	puts("");
	printf("Average game length: %d", (total_count / 1000));
	return 0;
}

// Function for rolling two dices and calculating their sum
int rollDice()
{
	int die1 = (rand() % 6) + 1;
	int die2 = (rand() % 6) + 1;

	return die1 + die2;
}


// Function to store at what length the game terminated
int game_duration(int arr[], int count)
{
	int game_len = count - 1;
	if (game_len < SIZE - 1)
	{
		arr[game_len]++;
	}
	else
	{
		arr[SIZE - 1]++;
	}

	return 0;
}

// Function to print at each length how many game terminated
void printArray(int arr[])
{
	puts("Rolls    Count");
	for (size_t i = 0; i < SIZE - 1; i++)
	{
		printf("%3u  %5d\n", (i + 1), arr[i]);
	}
	printf(">20  %5d\n", arr[SIZE - 1]);
}


/* From above program we get nearly equal chances of winning or losing crap games (about 500 each). So, crap game is 
 a fair game. Also the probability of winning at first roll is double than chance of losing at first roll, which can be 
 counted mathematically also. P(win) = 8 / 36 = 0.22, P(loss) = 4 / 36 = 0.11. Average length of crap game is 3.*/