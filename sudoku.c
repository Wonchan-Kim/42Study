#include <stdio.h>
#include <stdbool.h>

int sudoku[9][9] = {0, };
int check_row[9][10] = {false, };
int check_column[9][10] = {false, };
int check_square[9][10] = {false, };
void get_sudoku(void); //print the result
void solve_sudoku(void);//recursive function for solving sudoku

void get_sudoku(void)
{

	   for(int i = 0; i<9; i++)
	   {

			for(int j = 0; j<9; j++)
				{
					printf("%d ", sudoku[i][j]);
						
				}
			printf("\n");
	   }

}

void solve_sudoku(void)
{	

	int r = -1;
	int c = -1;
	
	for(int i = 1; i<9; i++)
	{
		for(int j = 0; j<9; j++)
		{
			if(sudoku[i][j] == 0)
			{
				r = i;
				c = j;
				break;
			}
		}
		if (r != -1) 
			break;
	}
	
	if(r == -1)
		get_sudoku();


	int square = (r/3)*3 + c/3;
	for(int number = 1; number<10; number++)
		if(!check_row[r][number] && !check_column[c][number] && !check_square[square][number])
			{
				check_row[r][number] = check_column[c][number] = check_square[square][number] = true;
				sudoku[r][c] = number;
				solve_sudoku();
			}
}

int main(void)
{
	int save_r, save_c, square;
	int user_input = 0;
	for(int i = 0; i< 9; i++)
		for(int j= 0; j<9; j++)
			{
				 scanf("%d ", &user_input);
				 sudoku[i][j] = user_input;
				 save_r = i;
				 save_c = j;
			    square = (save_r/3)*3 + save_c/3;
				check_row[save_r][user_input] = true;
				check_column[save_c][user_input] = true;
				check_square[square][user_input] = true;
	    	}
	

	printf("----------------------------");
	solve_sudoku();
	return 0;
}


