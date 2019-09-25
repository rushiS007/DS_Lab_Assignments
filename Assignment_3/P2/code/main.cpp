/**
* @file stdio.h
* @brief this header file will contain the input/output function like scanf and printf.
* 
* @author Rushiprasad
* 
* @date 21/08/2019
*/

#include <stdio.h>
/**
* @file stdlib.h
* @brief this header file will contain the funtions involving memory allocation, process control, 
* conversions and others.
* 
* @author Rushiprasad
* 
* @date 21/08/2019
*/
#include <stdlib.h>

/**
* @file string.h
* @brief this header file contains various string functions.
*
* @author Rushiprasad
* 
* @date 21/08/2019
*/
#include <string.h>

struct QueNode{
    int i,j,k;
    struct QueNode* link;
};
struct QueNode *QueFirst = NULL,*QueLast=NULL;
void store(int i2,int j2,int k2){
    struct QueNode* nd=(struct QueNode*)malloc(sizeof(struct QueNode));
    nd->i=i2+1;
    nd->j=j2+1;
    nd->k=k2+1;
    
    if(QueLast==NULL){
        QueFirst=QueLast=nd;
        QueLast->link=NULL;
    }
    else{
        QueLast->link=nd;
        QueLast=nd;
        nd->link=NULL;
    }
}

struct Node{
    int data;
    struct Node* next,* prev;
};

struct Node *first = NULL,*last=NULL;
int length=0;

/**
* This method will insert an element to linked list.
* @author Rushiprasad
* @param d key value to be inserted in linked list
* @date 21/08/2019
*/

void insert(int d){
    struct Node* nd=(struct Node*)malloc(sizeof(struct Node));
    nd->data=d;
    if(last==NULL){
        first=last=nd;
        first->prev=NULL;
        last->next=NULL;
    }
    else{
        last->next=nd;
        nd->prev=last;
        last=nd;
        nd->next=NULL;
    }
    length++;
}

/**
* This method xors the numbers between a range given.
* @author Rushiprasad
* @param Node* head  start point
* @param Node* rear  end point
* @date 21/08/2019
*/

int Xorfunc(struct Node* head,struct Node* rear){
    int output=0;
    do{
        output^=head->data;
        head=head->next;
    }while(head!=rear->next);
    return output;
}

/**
* This method counts the number of j.
* @author Rushiprasad
* @param Node* head  start point
* @param Node* rear  end point
* @param i  changing start point
* @param j changing  end point
* @date 21/08/2019
*/

int count(struct Node *head,struct Node *rear,int i,int k){
    int j=i+1;
    int counter=0;
    struct Node* middle=head->next;
    while(middle!=rear->next){
        if(Xorfunc(head,middle->prev)==Xorfunc(middle,rear)){
            
            store(i,j,k);
            counter++;
        }
        j++;
        middle=middle->next;
    }
    return counter;
}

/**
* This method counts the number of triplets.
* @author Rushiprasad
* @param Node* hd  start point
* @param Node* lst  end point
* @date 21/08/2019
*/

int countTriplets(struct Node* hd,struct Node*lst){
    int c=0;
    
    struct Node* head1=hd;
    int i=0;
    while(head1!=NULL){
        int k=i+1;
        struct Node* head2=head1->next;
        while(head2!=NULL){
            int x=Xorfunc(head1,head2);
            if(x==0){
                c+=count(head1,head2,i,k);
            }
            k++;
            head2=head2->next;
        }
        i++;
        head1=head1->next;
    }
    return c;
}

/**
* This method prints the triplets.
* @author Rushiprasad
* @date 21/08/2019
*/

void showTriplets(){
    struct QueNode* hd=QueFirst;
    while(hd!=NULL){
        printf("( %d , %d , %d )\n",hd->i,hd->j,hd->k);
        hd=hd->link;
    }
}

int main()
{
    int n;
    printf("Enter the number of positive integers.\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the numbers.\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        insert(a[i]);
    }
   
    int c=countTriplets(first,last);
    printf("%d\n",c);
    showTriplets();
    return 0;
}
