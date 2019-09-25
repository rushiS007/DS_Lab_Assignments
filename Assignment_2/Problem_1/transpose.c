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
* @file stdlib.h
* @breif this header file will various variable types and macros.
* 
* @author Rushiprasad
* 
* @date 7/08/2019
*/

#include <stddef.h>

/**
* @file string.h
* @breif this header file contains various string functions.
* @author Rushiprasad
* 
* @date 07/08/2019
*/

#include<string.h>


FILE * fptr,*fptr1;
int len=0;

/**
* This method will search for a value in an integer array.
* @author Rushiprasad
* @param n number of elements in the array
* @param c[] integer array in which value is to be searched.
* @param qu  value to be searched.
* @date 7/08/2019
*/

int search(int n,int c[n],int qu){
    int j;
    for(j=0;j<n;j++){
        if(c[j]==qu){
            c[j]=n;
            return j;
        }
    }
}

/**
* This method will encrypt the file using transposition cipher.
* @author Rushiprasad
* @param *arr character array to be encrypted
* @param n0 any integer greater than 1
* @param a any integer
* @param b any integer
* @date 7/08/2019
*/

void encrypt(char *arr,int n0,int a,int q){
    int n1=len;

    int en=n1%n0;

    en=n1+(n0-en)%n0;

  //  printf("%d\n%d\n",en,n1);

    char c[en];

    int b[en],d[en];

    int i,j;

    for(i=0;i<en;i++){
        b[i]=i%n0;
        d[i]=(a*i+q)%n0;
        if(i>=n1){
            c[i]='\0';
        }
        else{
            c[i]=arr[i];
        }
    }
  
	for(j=0;j<en;j++){
        int t=search(en,b,d[j]);
        printf("%c",c[t]);
        fprintf(fptr1,"%c",c[t]);
    }
}

int main(int argc,char* argv[])
{

	char* fpointer;
   	int n,a,b;
	n=atoi(argv[1]);
	a=atoi(argv[2]);
	b=atoi(argv[3]);
	fpointer=argv[4];
	if(n<1){printf("-1\n");exit(-1);}
   	fptr = fopen(fpointer, "r");
   	fptr1=fopen("EncryptedData.txt","w");
	int length;   	
	char * temp;
   	fseek (fptr, 0, SEEK_END);
  	length = ftell (fptr);
  	len=--length;
  	//printf("%d\n",len);
  	fseek(fptr, 0, SEEK_SET);
  	temp = malloc (length+2);
  	fread(temp, 1, length, fptr);
  	encrypt(temp,n,a,b);
	
}
