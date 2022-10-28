// Knight Tour Naive

#include <stdio.h>
#include <stdbool.h>

// Board dimension
#define SIZE 8

// Function prototypes
int fillBoard(int arr[][SIZE], size_t s);
void printBoard(const int const arr[][SIZE], size_t s);


// Starting of main Function
int main(void)
{
	int board[SIZE][SIZE] = {{0}};  // 8 by 8 board
	int moves;
	puts("----------------Knight Tour----------------");
	puts("\n");
	moves = fillBoard(board, SIZE);

	printBoard(board, SIZE);
	puts("");
	printf("Number of moves made by knight: %d", moves);
	return 0;
}


// Function for moving the knight on the board
int fillBoard(int arr[][SIZE], size_t size)
{
	int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};  // columns knight moves from current column
	int vertical[8] = {-1, -2, -2 , -1, 1, 2, 2, 1};  // rows knight moves from current row

	// Starting knight from center
	unsigned int current_row = 3;  
	unsigned int current_col = 4;

	arr[current_row][current_col] = 1;
	int count = 1; // Number of moves

	// Continue until break 
	while(true)
	{
		int i = 0; // move number

		for (; i <= 8; i++)  // To try first possible move from 7 moves
		{
			// Row 1, check for going out of bounds
			if (current_row == 0)
			{
				if ((i >= 0) && (i <= 3))
				{
					continue;
				}
				if (current_col == 0)
				{
					if ((i == 4) || (i == 5))
					{
						continue;
					}
				}
				if (current_col == 1)
				{
					if (i == 4)
					{
						continue;
					}
				}
				if (current_col == 7)
				{
					if ((i == 6) || (i == 7))
					{
						continue;
					}
				}
				if (current_col == 6)
				{
					if (i == 7)
					{
						continue;
					}
				}
			}

			// Row 7, Check for going out of bounds
			else if (current_row == 7)
			{
				if ((i >= 4) && (i <= 7))
				{
					continue;
				}
				if (current_col == 0)
				{
					if ((i == 3) || (i == 2))
					{
						continue;
					}
				}
				if (current_col == 1)
				{
					if (i == 3)
					{
						continue;
					}
				}
				if (current_col == 7)
				{
					if ((i == 0) || (i == 1))
					{
						continue;
					}
				}
				if (current_col == 6)
				{
					if (i == 0)
					{
						continue;
					}
				}
			}

			// Row 1, check for going out of bound
			else if (current_row == 1)
			{
				if ((i == 1) || (i == 2))
				{
					continue;
				}
				if (current_col == 1)
				{
					if ((i == 3) || (i == 4))
					{
						continue;
					}
				}
				if (current_col == 6)
				{
					if ((i == 0) || (i == 7))
					{
						continue;
					}
				}
			}

			// Row 6, check for going out of bounds
			else if (current_row == 6)
			{
				if ((i == 5) || (i == 6))
				{
					continue;
				}
				if (current_col == 1)
				{
					if ((i == 3) || (i == 4))
					{
						continue;
					}
				}
				if (current_col == 6)
				{
					if ((i == 0) || (i == 7))
					{
						continue;
					}
				}
			}

			// Column 0, check for going out of bounds
			if (current_col == 0)
			{
				if (i >= 2 && i <= 5)
				{
					continue;
				}
			}

			// Column 7, check for going out of bounds
			else if (current_col == 7)
			{
				if ((i == 0) || (i == 1) || (i == 6) || (i == 7))
				{
					continue;
				}
			}

			// Column 1
			else if (current_col == 1)
			{
				if ((i == 3) || (i == 4))
				{
					continue;
				}
			}

			// Column 6 check for going out of bounds
			else if (current_col == 6)
			{
				if ((i == 0) || (i == 7))
				{
					continue;
				}
			}

			if (i != 8)  // As there is no move number 8 and it is only when we exhuast all 0 to 7 moves
			{	
				// If board position is not filled then fill it with number of moves and change current position
				if (arr[current_row + vertical[i]][current_col + horizontal[i]] == 0)
				{
					count++;
					current_row += vertical[i];
					current_col += horizontal[i];
					arr[current_row][current_col] = count;
					break;
				}
			}

			// If all move exhausted then break 
			if (i == 8)
			{
				break;
			}
		}

		// No possible position to move into
		if (i == 8)
		{
			break;
		}
	}

	return count;
}


// Function for printing board
void printBoard(const int const board[][SIZE], size_t size)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%2d ", board[i][j]);
		}
		puts("");
	}
}