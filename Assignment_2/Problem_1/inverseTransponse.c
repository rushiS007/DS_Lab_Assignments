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
* @file stdio.h
* @breif this header file will contain the input/output function like scanf and printf.
* 
* @author Rushiprasad
* 
* @date 7/08/2019
*/

#include <stdio.h>

/**
* @file string.h
* @breif this header string functions.
*
* @author Rushiprasad
* 
* @date 07/08/2019
*/

#include <string.h>

FILE * fptr,*fptr1;
int len=0;

/**
* This method will search for a value in an integer array.
* @author Rushiprasad
* @param num number of elements in the array
* @param buf[] integer array in which value is to be searched.
* @param qu  value to be searched.
* @date 7/08/2019
*/

int search(int num,int buf[num],int qu){
    int j;
    for(j=0;j<num;j++){
        if(buf[j]==qu){
            buf[j]=num;
            return j;
        }
    }
}

/**
* This method will decrypt the Encrypted file.
* @author Rushiprasad
* @param *arr character array to be encrypted
* @param n0 any integer greater than 1
* @param a any integer
* @param q any integer
* @date 7/08/2019
*/

void decrypt(char *arr,int n0,int a,int q){
    int n1=len;
    int encr=n1%n0;
    encr=n1+(n0-encr)%n0;
    
    char c[encr];
    int b[encr],d[encr];
    int i,j;
    for(i=0;i<encr;i++){
        b[i]=i%n0;
        d[i]=(a*i+q)%n0;
        if(i>=n1){
            c[i]='\0';
        }
        else{
            c[i]=arr[i];
        }
    }
     for(j=0;j<encr;j++){
        int t=search(encr,b,d[j]);
        printf("%c",c[t]);
        fprintf(fptr1,"%c",c[t]);
    }printf("\n");
}
int main(int argc,char* argv[])
{
   printf("Enter decryption inputs n,a',b'\n");
   int c,a,b;
   scanf("%d,%d,%d",&c,&a,&b);
   fptr = fopen("EncryptedData.txt", "r");
   fptr1=fopen("DecryptedData.txt","w");
   char * buff = 0;
   int leng;
   fseek (fptr, 0, SEEK_END);
   leng = ftell (fptr);
   leng=leng-1;
   len=leng;
   fseek (fptr, 0, SEEK_SET);
   buff = malloc (len);
   fread (buff, 1, leng, fptr);
   decrypt(buff,c,a,b);
}
