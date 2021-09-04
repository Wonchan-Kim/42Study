#include <stdio.h>

int main(void)
{
	int r,c;
	scanf("%d %d", &r, &c);
	int arr[r][c];
	int user;

	printf("enter -1 for mine, 0 for non-mine\n");
	
	for(int i =0; i<r; i++)
	{
		for(int j = 0; j< c; j++)
		{
			scanf("%d", &user);
			arr[i][j] = user;
		}
	}
	
	int get_value;
	
	for(int i =0; i<r; i++)
	{
		for(int j = 0; j< c; j++)
		{
			get_value = arr[i][j];
			if(get_value == -1)
			{
					int cnt = 1;
						for(int a = i -1; a< i+2; a++)
							{
								if(a<0 || a>r)
									continue;
								for(int b = j-1; b< j+2; b++)
									{	
										if(b<0 || b>c)
											continue;
										else if(arr[a][b] == -1)
												continue;
										else
									{
										arr[a][b] += cnt;
									}
									}

							}
			}
		}
	}
	for(int i = 0; i<r; i++)
	{
		for(int j = 0; j<c; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

