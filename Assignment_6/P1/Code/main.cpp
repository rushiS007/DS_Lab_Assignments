#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
//!structure to represent each node in adjacency list
struct adjls{
   int data;
   int distc;
   int dia;
   adjls* next;
};

//!structure to represent a list in adjacency list
struct adjl{
   adjls* head;
};

//!structure to represent the graph
struct Graph{
 int V;
 adjl* arr;
};

//!making graph
Graph* makegraph(int V){
      int i;
      Graph* graph=new Graph;
      graph->V=V;
      graph->arr = (struct adjl*)malloc(V * sizeof(struct adjl));
      for(i=0;i<V;i++){
        graph->arr[i].head=NULL;
      }
      return graph;
}

//!inserting edges in the graph
void inser(Graph* graph,int st,int en){
   // cout<<"in insert"<<endl;
  //  cout<<"st is:"<<st<<endl;
    /*if(graph->arr[st].head==NULL){
        adjls* node1=new adjls;
     node1->data=st;
    // cout<<"next to it:"<<node1->data<<endl;
     node1->distc=0;
     node1->next=NULL;
     graph->arr[st].head=node1;
     }*/
     adjls* node=new adjls;
     node->data=en;
     node->distc=0;
     node->next=NULL;
     adjls* p=graph->arr[st].head;
     while(p->next!=NULL){
        p=p->next;
     }
     p->next=node;
     /*if(graph->arr[en].head==NULL){
        adjls* node2=new adjls;
     node2->data=en;
     cout<<"next to it:"<<node2->data<<endl;
     node2->distc=0;
     node2->next=NULL;
     graph->arr[en].head=node2;
     }*/
     adjls* nod=new adjls;
     nod->data=st;
     nod->distc=0;
     nod->next=NULL;
     adjls* q=graph->arr[en].head;
     while(q->next!=NULL){
        q=q->next;
     }
     q->next=nod;
}

//!BFS for a graph
void bfs(Graph* graph,adjl* arr){
    int i;
    adjls* p=new adjls;
    p=graph->arr[0].head;
   adjls* t=p;
   adjls* u=p;
   adjls* q=p;
   //graph->arr[p->data].head->distc=1;
   while(p!=NULL){
   //cout<<"want111"<<graph->arr[p->data].head->distc<<endl;
  u=graph->arr[p->data].head;
  while(u->next!=NULL){
        if((graph->arr[u->next->data].head->distc)==0){

        t->next=u->next;
       // cout<<"u->next->data"<<u->next->data<<endl;

        t->next->distc=1;
        graph->arr[t->next->data].head->distc=1;
        t=t->next;
        }
    u=u->next;
  }
  if(graph->arr[p->data].head->distc!=2){
  p->distc=2;
  graph->arr[p->data].head->distc=2;
  //cout<<"p->data:"<<p->data<<endl;
  //cout<<"want"<<graph->arr[p->data].head->distc<<endl;
  char f=65+p->data;
  cout<<f<<" ";
  }
  p=p->next;
   }
}

//!DFS for a graph
adjl* dfs(Graph* graph,adjl* arr,adjls* v){
      adjls* x=graph->arr[v->data].head;
      adjls* y=x;
      y->distc=1;
      char c=65+y->data;
      cout<<c<<" ";
      while(y!=NULL){
          y=y->next;
          if(y!=NULL){
        if((graph->arr[y->data].head->distc)==0){
               // cout<<"Yes it is"<<endl;
                graph->arr=dfs(graph,graph->arr,y);
        }
      }
      }
      return arr;
  }

//!taking out diameter of the graph
int* diame(Graph* graph,adjl* arr,adjls* p,int *a){
    adjls* k=graph->arr[p->data].head;
   // adjls* n=graph->arr[p->data].head;
    int t=0;
    k=k->next;
    while(k!=NULL){
        t=a[p->data]+1;
        if(t<=a[k->data]){
                a[k->data]=t;
                a=diame(graph,arr,k,a);
               }
               k=k->next;
            }
        return a;
    }

//!finding if there is a cycle in the graph
adjl* findcycle(Graph* graph,adjl* arr,adjls* v){
    adjls* x=graph->arr[v->data].head;
      adjls* y=x;
      y->distc=1;
      while(y!=NULL){
          y=y->next;
          if(y!=NULL){
        if((graph->arr[y->data].head->distc)==0){
               // cout<<"Yes it is"<<endl;
                graph->arr=findcycle(graph,graph->arr,y);
                y->distc=2;
                graph->arr[y->data].head->distc=2;
        }else if((graph->arr[y->data].head->distc)==2){
               //cout<<"Yes there is a cycle"<<endl;
               graph->arr[y->data].head->dia=1000;
        }
      }
      }
      return arr;
}

//!main method to initialize and call other methods
int main()
{
     int t1=0,i,j,lm=0;
    string* s=new string[8];
    ifstream inFile("L6_Q1_sample_input.txt",ios::in);
	if(!inFile)
	{
		cout<<"Couldn't open the file"<<endl;
	}

	string line;
	while( getline(inFile, line)  )
        {
           s[t1]=line;
           t1++;
        }
        int y=t1;
        int n = s[0].length();
    char c1[8][n + 1];
    char c2[8][2];
    int a[8][2];
    for(t1=0;t1<8;t1++){
    strcpy(c1[t1], s[t1].c_str());
    }
    int k=0;
    for (int i = 0; i < 8; i++){
            for(j=0;j<n+1;j++){
             if(j%2==0){
                c2[i][k]=c1[i][j];
                k++;
             }
            }k=0;
    }
   // cout<<c2[0][0]<<c2[0][1]<<c2[0][2]<<endl;
     for (int i = 0; i < 8; i++){
            for(j=0;j<2;j++){
                    a[i][j]=c2[i][j]-65;
            }
            a[i][j]=c2[i][j]-'0';
     }
     int V=7,E=y;
     Graph* graph=makegraph(V);
     for(i=0;i<V;i++){
        adjls* no=new adjls;
     no->data=i;
     no->distc=0;
     no->dia=10000;
     no->next=NULL;
     graph->arr[i].head=no;
     }
    for(i=0;i<E;i++){
            //cout<<"getting to i"<<endl;
    inser(graph,a[i][0],a[i][1]);
    }
    inFile.close();
    char g;
     for(i=0;i<V;i++){
         adjls* p=graph->arr[i].head;
     while(p!=NULL){
            g=65+p->data;
        cout<<g<<" ";
        p=p->next;
     }
     cout<<""<<endl;
     }
     int var,choice;
     bool bo=true;
      int *t=new int[V];
    int m[V][V];
    int diameter=0;
     cout<<"To find out cycle press 1"<<endl;
     cout<<"To do DFS press 2"<<endl;
     cout<<"To find the diameter press 3"<<endl;
     cout<<"To do BFS press 4"<<endl;
     while(bo){
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice){
        case 1:
                findcycle(graph,graph->arr,graph->arr[0].head);
            for(i=0;i<V;i++){
         adjls* p=graph->arr[i].head;
         if(p->dia==1000){
            lm++;
            p->dia=10000;
         }
     while(p!=NULL){
        p->distc=0;
        p=p->next;
     }
     }
     if(lm==0){
         cout<<"No cycle is present"<<endl;
     }else{
         cout<<"Yes cycle is present"<<endl;
     }
     for(i=0;i<V;i++){
         adjls* p=graph->arr[i].head;
     while(p!=NULL){
        p->distc=0;
        p->dia=10000;
        p=p->next;
     }
     }
     cout<<""<<endl;
     break;
        case 2:
          graph->arr=dfs(graph,graph->arr,graph->arr[0].head);
          for(i=0;i<V;i++){
         adjls* p=graph->arr[i].head;
     while(p!=NULL){
        p->distc=0;
        p=p->next;
     }
     }
     cout<<""<<endl;
     break;
        case 3:
    for(i=0;i<V;i++){
           t[i]=10000;
    }
     for(i=0;i<V;i++){
         adjls* p=graph->arr[i].head;
        t[i]=0;
        t=diame(graph,graph->arr,p,t);
      //  cout<<"val:";
        for(j=0;j<V;j++){
            m[i][j]=t[j];
          //  cout<<m[i][j]<<" ";
        }
       // cout<<""<<endl;
        for(j=0;j<V;j++){
        t[j]=10000;
        }
     }
    // cout<<"diameter is:"<<diameter<<endl;
     for(i=0;i<V;i++){
        for(j=0;j<V;j++){
           if(m[i][j]>=diameter){
            diameter=m[i][j];
           }
        }
     }
     cout<<"diameter:"<<diameter<<endl;
     for(i=0;i<V;i++){
         adjls* p=graph->arr[i].head;
     while(p!=NULL){
        p->distc=0;
        p=p->next;
     }
     }
     cout<<""<<endl;
     break;
        case 4:
      bfs(graph,graph->arr);
             for(i=0;i<V;i++){
         adjls* p=graph->arr[i].head;
     while(p!=NULL){
        p->distc=0;
        p=p->next;
     }
     }
     cout<<""<<endl;
     break;
        }
        cout<<"Enter to either continue(1) or not(0):";
        cin>>var;
        if(var==0){
            bo=false;
        }if(var==1){
        bo=true;
        }
     }
    return 0;
}
