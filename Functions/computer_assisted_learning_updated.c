// Computer Assisted Learning 
/* Program to check knowledge of user of arithmetic of single and double digits */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Generates a single digit random number
int rand_one(void);

// Generates a double digit random number
int rand_two(void);

// Function for sum
int addition(int x, int y);

// Function for subtraction
int subtraction(int x, int y);

// Function for product
int multiplication(int x, int y);

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
		int problem_type;
		int difficulty; // difficulty level to be entered by the user
		int correct_count = 0;  // Counting how many answers of user are correct
		int wrong_count = 0;  // Counting how many answers of user are incorrect

		// If problem type is not between 1 and 4 then keep asking for problem type
		do
		{
			printf("Enter 1 to check your understanding of addition, "
				   "2 for subtraction, 3 for multiplication, 4 for random problems: ");
			scanf("%d", &problem_type);
		} 
		while ((problem_type <= 1) && (problem_type >= 4));  
		                                                  
		// If difficulty is neither 1 nor zero then keep asking for difficulty
		do
		{
			printf("Enter difficulty level (1 for easy, 2 for hard): ");
			scanf("%d", &difficulty);
		}
		while ((difficulty != 1) && (difficulty != 2));  

		
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

			// Calling functions on basis of problem type entered by the user
			switch(problem_type)
			{
				case 1: 
					play = addition(num1, num2);
					break;

				case 2:
					play = subtraction(num1, num2);
					break;

				case 3:
					play = multiplication(num1, num2);
					break;

				case 4:  // Random problems
					int n = rand() % 3;
					if (n == 0)
					{
						play = addition(num1, num2);
					}
					else if (n == 1)
					{
						play = subtraction(num1, num2);
					}
					else
					{
						play = multiplication(num1, num2);
					}
			}

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
		puts("------- Reset ------");
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


// Function for sum
int addition(int num1, int num2)
{
	int ans;  // Answer to be entered by the user
	int sum = num1 + num2;

	printf("How much is %d + %d: ", num1, num2);
	scanf("%d", &ans);

	if (ans == -1)
	{
		return -1;  // If user doesn't want to continue then return -1
	}

	if (ans == sum)
	{
		return 1;
	}

	return 0;
}


// Function for subtraction
int subtraction(int num1, int num2)
{
	int ans;  // Answer to be entered by the user
	int subtract = num1 - num2;

	printf("How much is %d - %d (1000 to discontinue): ", num1, num2);
	scanf("%d", &ans);

	// Because subtraction of 2 one or two digit number will be less than 1000, so coming out of function
	if (ans == 1000) 
	{
		return -1;  // If user doesn't want to continue then return -1
	}

	if (ans == subtract)
	{
		return 1;
	}

	return 0;
}


// Function for multiplication
int multiplication(int num1, int num2)
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