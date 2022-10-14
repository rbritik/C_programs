// Computer Assisted Learning 
/* Program to check knowledge of user on single or double digit multiplication */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Generates a single digit random number
int rand_one(void);

// Generates a double digit random number
int rand_two(void);

// Function for taking user input and comparing it with correct answer
int product(int x, int y);

// Function for calculating what percentage of answers are correct
void percentage(int right, int wrong);


// main Function Starts
int main()
{
	srand(time(NULL));  // For generating a random seed depending upon current time
	int num1, num2;
	int play;  // Asking player whether he want to continue or not (-1 to discontinue the game)

	puts("---------------Computer Assisted Learning---------------");
	// get two random one digit numbers
	while (true) 
	{
		int difficulty; // difficulty level to be entered by the user
		int correct_count = 0;  // Counting how many answers of user are correct
		int wrong_count = 0;  // Counting how many answers of user are incorrect

		do{
			printf("Enter difficulty level (1 for easy, 2 for hard): ");
			scanf("%d", &difficulty);
		} while ((difficulty != 1) && (difficulty != 2));  // If difficulty is neither 1 nor zero then keep asking for 
		                                                   // difficulty
		
		for(int q_no = 1; q_no <= 10; q_no++)   // Ask 10 questions
		{
			if (difficulty == 1)  // Single digit numbers
			{	num1 = rand_one();
				num2 = rand_one(); 
			}

			else  // Two digit numbers
			{
				num1 = rand_two();
				num2 = rand_two();
			}
			play = product(num1, num2);

			if (play == -1) // Ask whether the user want to discontinue
			{
				printf("Enter -1 if you want to discontinue answering more: ");
				scanf("%d", &play);

				if (play == -1)  // If user entered -1 then break out of program
				{
					return 1;
				}
			}

			if (play == 1)  // If answer is correct
			{
				correct_count++;
			} 
			else  // If answer is wrong
			{
				wrong_count++;
			}
		}

		percentage(correct_count, wrong_count);
		puts("");
		puts("For new user");
	}
	return 0;
}  // Ending of main function


// Function to return a 1 digit random generated number
int rand_one(void)
{
	int num;  
	num = rand() % 10;  // Generates a random number between 0 and 9
	return num;
}// Ending of function


// Function to return a 2 digit random generated number
int rand_two(void)
{
	int num2;
	num2 = (rand() % 90) + 10; // Number between 10 and 100
	return num2;
}  // Function ends


// Function for asking user for answer 
int product(int num1, int num2)
{
	int ans;  // Answer entered by the user
	int product = num1 * num2;

	printf("How much is %d times %d: ", num1 , num2);
	scanf("%d", &ans);

	if (ans == -1)
	{
		return -1;  // If user doesn't want to continue then return -1
	}

	if (ans == product)
	{
		return 1;
	}

	return 0;
}  // End of function


// Function to calculate percentage
void percentage(int correct_count, int wrong_count)
{
	float percent;  // Variable to store percentage

	percent = ((float) (correct_count) / (correct_count + wrong_count)) * 100;
	printf("Correct responses: %d\n", correct_count);
	printf("wrong_resposes responses: %d\n", wrong_count);
	printf("%.2f\n", percent);

	if (percent < 75)
	{
		puts("Please ask your teacher for extra help.");
	}
	else
	{
		puts("Congratulations, you are ready to go to the next level!");
	}
}  // Ending of function