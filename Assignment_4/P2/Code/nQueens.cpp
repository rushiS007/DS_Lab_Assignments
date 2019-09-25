/**
* @file bits/stdc++.h
* @breif this header file will contain the input/output function like scanf and printf.
* 
* @author Rushiprasad
* 
* @date 3/09/2019
*/
#include<bits/stdc++.h> 
using namespace std;
int X=0;

/*
* This method prints the solution.
* @param *board[] Solution board
* @param N        Size of board
* @author Rushiprasad.
* @date 3/09/2019
*/

void printSolution(int *board[],int N) 
{ 
	static int k = 1; 
	printf("%d-\n",k++); 
	for (int i = 0; i < N; i++) 
	{ 
		for (int j = 0; j < N; j++) {
			printf(" %d ", board[i][j]);} 
		printf("\n"); X++;
	} 
	printf("\n"); 
} 

/*
* This method will check if a queen can be placed on board[row][col]. 
* @param *board[]  board as 2d array
* @param row Row number
* @param col Column number
* @param N No. of queens
* @author Rushiprasad.
* @date 3/09/2019
*/

bool isSafe(int *board[], int row, int col,int N) 
{ 
	int i, j; 

	for (i = 0; i < col; i++) 
		if (board[row][i]) 
			return false; 

	for (i=row, j=col; i>=0 && j>=0; i--, j--) 
		if (board[i][j]) 
			return false; 
	for (i=row, j=col; j>=0 && i<N; i++, j--) 
		if (board[i][j]) 
			return false; 

	return true; 
} 



/*
* This method solves N-queen problem recursively.
* @param *board[]  board as 2d array
* @param col Column number
* @param N No. of queens
* @author Rushiprasad.
* @date 3/09/2019
*/

bool solveNQUtil(int *board[], int col,int N) 
{ 
	if (col == N) 
	{ 
		printSolution(board,N); 
		return true; 
	} 

	bool res = false; 
	for (int i = 0; i < N; i++) 
	{ 
		if ( isSafe(board, i, col,N) ) 
		{ 
		
			board[i][col] = 1; 

			res = solveNQUtil(board, col + 1,N) || res; 

			board[i][col] = 0;
		} 
	} 

	
	return res; 
} 

/*
* This method solves N-queen problem using backtracking.
* @param N No. of queens
* @author Rushiprasad.
* @date 3/09/2019
*/

void solveNQ(int N) 
{ 
	int *board[N];
    for(int i=0;i<N;i++) 
	board[i]=new int[N];
    

	if (solveNQUtil(board, 0,N) == false) 
	{ 
		printf("Solution does not exist\n"); 
		return ; 
	} 

	return ; 
} 

int main() 
{ 
    printf("Enter N :\n");
    int N;
    scanf("%d",&N);

	solveNQ(N); 
	cout<<"Total number of combinations: "<<X/N<<endl;
	return 0; 
} 
