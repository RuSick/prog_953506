#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void vivod(int** mas, int rows, int colls)
{
	for (int i = 0; i < rows; i++)
	{
		printf("\n");
		for (int j = 0; j < colls; j++)
		{
			printf("%d ", mas[i][j]);
		}
	}
}
int main()
{
	int n, m;
	printf("write array size:");
	do { scanf("%d%d", &n, &m); } while (n < 0 && m < 0);
	
	int** arr;
	arr = (int**)malloc(n* sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int*)malloc(m*sizeof(int));  
	}
	int flag = 0;
	for (int i = 0; i < n; i++) //zapolnenie 1 stolbca
	{
		if (flag == 0)
		{
			arr[i][0] = 1;
			flag++; 
			continue;
		}
		if (flag == 1)
		{
			arr[i][0] = 3;
			flag--; 
		}
	}
	int a=0;               //ostalnoe zapolnenie
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (arr[i][j-1] == 4)
			{
				arr[i][j] = 1;
				continue;
			}
			a = arr[i][j - 1];
			a++;
			arr[i][j]=a;	
		}
	}
	vivod(arr, n, m);
	for (int i = 0; i < n; i++)
		free(arr[i]);
	free(arr);
}