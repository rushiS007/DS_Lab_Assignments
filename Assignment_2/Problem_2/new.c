/**
* @file stdio.h
* @breif this header file will contain the input/output function like scanf and printf.
* 
* @author Rushiprasad
* 
* @date 7/08/2019
*/

#include <stdio.h>

/**
* @file stdlib.h
* @breif this header file will contain the funtions involving memory allocation, process control, 
* conversions and others.
* 
* @author Rushiprasad
* 
* @date 7/08/2019
*/

#include <stdlib.h>

/**
* @file string.h
* @breif this header file contains various string functions.
* @author Rushiprasad
* 
* @date 07/08/2019
*/

#include <string.h>

/**
* @file stdbool.h
* @breif this header file contains four macros for a Boolean data type.
* 
* @author Rushiprasad
* 
* @date 7/08/2019
*/

#include <stdbool.h>

/**
* @file time.h
* @breif this header file contains time and date functions declarations to provide standdardized access
* to time/date manipulation and formatting
*
* @author Rushiprasad
* 
* @date 7/08/2019
*/

#include <time.h>

struct Node { 
    int index;
    int bitValue;
    int level;
    struct Node *prev,*next; 
};

struct Node *first = NULL,*last=NULL;

/*
* This method will check whether all the elements of given quadrant are equal or not.
* @author Rushiprasad
* @param array  integer array where elements are ti be checked.
* @param Row   array's row index.
* @param row   array's column index.
*
* @author Rushiprasad.
* @date 7/08/2019
*/
bool check(int **array,int Row,int row,int turns){
    bool pole=true;
    for(int j=0;pole && j<turns;j++){
        for(int i=0;pole && i<turns;i++){
            if(array[Row+j][row+j]!=array[Row][row]){
                pole=false;
            }
        }
    }
    return pole;
};

/*
* This method will find the nearest exponent of 2 for a number.
* @param num   Number input.
*
* @author Rushiprasad.
* @date 7/08/2019
*/

int nearest2Exponent(int num){
    int expo=num;
    while((expo & (expo-1))!=0){
        expo++;
    }
    return expo;
}

/*
* This method inserts a new node to quad tree.
* 
* @param lev  Level at which new node is to be inserted.
* @param val  Value to be inserted.
* 
* @author Rushiprasad.
* @date 7/08/2019
*/

void addNode(int lev,int val){
    if(first==NULL){
        first=(struct Node*)malloc(sizeof(struct Node));
        first->bitValue=val;
        first->index=1;
        first->level=lev;
        last=first;
        first->prev=NULL;
        last->next=NULL;
    }
    else{
        struct Node* nd=(struct Node*)malloc(sizeof(struct Node));
        nd->bitValue=val;
        nd->level=lev;
        nd->index=last->index+1;
        last->next=nd;
        nd->prev=last;
        last=nd;
        last->next=NULL;
    }
};

/*
* This method create a maximal square array.
* 
* @param **msa input array.
* @param r    Row number of array.
* @param c    Column number of array.
* @param n     space between two iterations.
* @author Rushiprasad.
* @date 7/08/2019
*/

void fillMaximalSquareArray(int **msa,int r,int c,int n){
    int index=1;
    if(first!=NULL){
        index=(last->index)+1;
    }
    for(int i=r;i<(r+n);i++){
        for(int j=c;j<(c+n);j++){
            msa[i][j]=index;
        }
    }
};

/*
* This method provides a partiotion to input array.
* 
* @param **msa input array.
* @author Rushiprasad.
* @date 7/08/2019
*/

void partition(int **msa,int **arr,int Row,int row,int n,int level){
    int turns=n/2;
    
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            int r=Row+i*turns;
            int c=row+j*turns;
            if(check(arr,r,c,turns)){
                fillMaximalSquareArray(msa,r,c,turns);
                addNode(level,arr[r][c]);
            }else{
                partition(msa,arr,r,c,turns,level+1);
            }
            
        }
    }
};

/*
* This method prints the quadTree.
* 
* @author Rushiprasad.
* @date 7/08/2019
*/

void printQuadTree(){
    printf("For given input file Quad-Tree is :\n");
    struct Node* head=first;
    while(head!=NULL){
        printf("(%d , %d , %d)\n",head->index,head->bitValue,head->level);
        head=head->next;
    }
}

/*
* This method prints the maximal square array.
* @param **msa input array.
* @param exp2  nearest greater exponent of two.
* @author Rushiprasad.
* @date 7/08/2019
*/

void printMaximalSquareArray(int **msa,int exp){
    printf("The maximal square array for given input is :\n");
    for(int j=0;j<exp;j++){
        for(int i=0;i<exp;i++){
            printf("%d ",msa[j][i]);
        }
        printf("\n");
    }
};

int main(int argc, char* argv[]){
    
	double time=0.0;
        clock_t start=clock();
	char *filepath=argv[1];
	FILE *fptr;
        char stri[1000];
        int j=0,len=0;
        fptr = fopen(filepath, "r");
        if (fptr == NULL){
        printf("Can not open file %s",filepath);
        }
	fgets(stri, 1000, fptr);
	len=strlen(stri);
	int arr[len/2][len/2];	 
	for(int i=0;i<len-1;i+=2){
		arr[j][i/2]=(stri[i]-'0');
	}   
	j++;
	while (fgets(stri, 1000, fptr) != NULL){
        for(int i=0;i<len-1;i+=2){
			arr[j][i/2]=(stri[i]-'0');
		}   
		j++;   
        }	
        fclose(fptr);
        int row=len/2;
        int exp2=nearest2Exponent(row);
        int *subarr[exp2];
        int *MSA[exp2];
        for(int k=0;k<exp2;k++){
        subarr[k]=(int *)malloc(sizeof(int)*exp2);
        MSA[k]=(int *)malloc(sizeof(int)*exp2);
        }    
        for(int k=0;k<exp2;k++){
        for(int j=0;j<exp2;j++){
            if(k<(exp2-row) || j<(exp2-row)){
                subarr[k][j]=0;
            }else{
                subarr[k][j]=arr[k-(exp2-row)][j-(exp2-row)];
            }
          }
        }
        partition(MSA,subarr,0,0,exp2,1);   
        printMaximalSquareArray(MSA,exp2);
	printQuadTree();
	clock_t end=clock();
        time+=(double)(end-start)/CLOCKS_PER_SEC;
        printf("\nTotal Execution time is : %f (sec)\n",time);
        return 0;

}
