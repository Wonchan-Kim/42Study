#include <stdio.h>
#include <stdbool.h>

int sudoku[9][9] = {false, };
int check_row[9][10] = {false, };
int check_column[9][10] = {false, };
int check_square[9][10] = {false, };
void print_ans(void); //print the result
void solve_sudoku(void);//recursive function for solving sudoku
int validity_check(void); //before checking the sudoku, check whether it is valid sudoku on the current status
void get_sudoku(void)
{
	int user_input = 0;

	   for(int i = 0; i<9; i++)
			for(int j = 0; j<9; j++)
				{
					scanf("%d", &user_input);
					sudoku[i][j] = user_input;
				}
}

void solve_sudoku(void)
{	

	int r = -1;
	int c = -1;
	
	for(int i = 0; i<9; i++)
		for(int j = 0; j<9; j++)
			if(sudoku[i][j] == false)
			{
				r = i;
				c = j;
			}
	
	if(r == -1)
		return;

	int square = (r/3)*3 + c/3;
	for(int number = 1; number<10; number++)
		if(!check_row[r][number] && !check_column[c][number] && !check_square[square][number])
			{
				sudoku[r][c] = number;
				check_row[r][number] = check_column[c][number] = check_square[square][number] = true;
				solve_sudoku();
			}
}

int main(void)
{
	int save_r, save_c;
	int user_input = 0;
	for(int i = 0; i< 9; i++)
		for(int j= 0; j<9; j++)
			{
				 scanf("%d ", &user_input);
				 sudoku[i][i] = user_input;
				 save_r = i;
				 save_c = j;
	    	}
	
	int square = (save_r/3)*3 + save_c/3;
	check_row[save_r][user_input] = true;
	check_column[save_c][user_input] = true;
	check_square[square][user_input] = true;

	printf("----------------------------");
	solve_sudoku();
	return 0;
}


