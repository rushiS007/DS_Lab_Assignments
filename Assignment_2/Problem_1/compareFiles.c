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
* @file stddef.h
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
*
* @author Rushiprasad
* 
* @date 07/08/2019
*/

#include<string.h>
FILE * fp,*_fp;
int main(int argc,int* argv[])
{
   fp = fopen("sample_testcase_1.txt", "r");
   _fp=fopen("DecryptedData.txt","r");
   char * buffer = 0;
   char *buf=0;
   int length,length1;
  fseek (fp, 0, SEEK_END);
  fseek (_fp, 0, SEEK_END);
  length = ftell (fp);
  length=length-1;
  length1 = ftell (_fp);
  length1=length1-1;
  
  fseek (fp, 0, SEEK_SET);
  fseek (_fp, 0, SEEK_SET);
  buffer = malloc (length);
  buf = malloc (length1);
  fread (buffer, 1, length, fp);
  fread (buf, 1, length1, _fp);
  int i;
int g=0;
  for(i=0;i<length;i++){
    if(buffer[i]!=buf[i]){
    printf("Differ");
g=1;
break;
    }
  }
if(g==0) printf("Same\n");
}
