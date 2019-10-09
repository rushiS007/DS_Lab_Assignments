#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Node{
   int data,deg;
   Node *par,*child,*sib;
};

Node* newnode(int dat){
     Node *node=new Node;
     node->data=dat;
     node->deg=0;
     node->child=node->par=node->sib=NULL;
     return node;
}

Node* merg(Node* head,Node* p){
   // cout<<"in merg"<<endl;
    Node *q=p->sib;
        if((p->data)>(q->data)){
                //cout<<"YES 111"<<endl;
            p->sib=q->child;
            if(q->child!=NULL){
            q->child->par=NULL;
            }
            p->par=q;
            q->child=p;
            q->deg=(q->deg)+1;
            if(p==head){
                   // cout<<"YES"<<endl;
                head=q;
            }
            p=q;
            q=q->sib;
            if(q!=NULL){
            if((p->deg)==(q->deg)){
                merg(head,p);
            }else{
                return head;
            }
            }else{
               return head;
            }
        }else{
           // cout<<"YES 222"<<endl;
         p->sib=q->sib;
         q->sib=p->child;
         p->child=q;
         q->par=p;
         if(q->sib!=NULL){
         q->sib->par=NULL;
         }
         p->deg=(p->deg)+1;
         if(q==head){
                head=p;
        }
        q=p->sib;
        if(q!=NULL){
        if((p->deg)==(q->deg)){
                merg(head,p);
            }else{
              return head;
            }
            }else{
              return head;
            }
}
}

Node* makeheap(Node** head,Node** temp){
     //cout<<"in makeheap"<<endl;
      Node* p=*temp;
      Node* q =*head;
      p->sib=q;
            if((p->deg)!=(q->deg)){
                   // cout<<"no no"<<endl;
               *head=p;
               Node* t=*head;
             //  cout<<"fu:"<<t->data<<endl;
            return *head;
      }else{
        //  cout<<"oh yes!"<<endl;
      *head=merg(*head,p);
      return *head;
      }
}

Node* iniheap(int a[],int n,Node* head){
    //cout<<"in initheap"<<endl;
    int i;
     for(i=1;i<n;i++){
        Node* temp=newnode(a[i]);
       // cout<<"made:"<<i<<endl;
        head=makeheap(&head,&temp);
       // cout<<"fu1:"<<head->data<<endl;
     }
     return head;
}

void Print(Node* m,int j){
    if(m==NULL){
        return;
    }
    int c=m->deg;
    if(c>=j){
        cout<<"\norder:"<<m->deg<<" "<<"ELements:";
        j=c;
    }
    cout<<m->data<<" ";
    Print(m->child,j);
    Print(m->sib,j);
    return;
}

void M(ofstream &fout,Node* head,Node* q){
    Node* t=q;
    Node* p=q;
    while(t->child!=NULL){
        fout<<t->data<<"--"<<t->child->data<<";";
        t=t->child;
    }
    Node* w=t->par;
    if(w==NULL){
        return;
    }
  //  cout<<w->data<<endl;
    Node* l=t;
    while(w!=NULL){
            t=w->child;
            t=t->sib;
         while(t!=NULL){
              fout<<w->data<<"--"<<t->data<<";";
             // cout<<t->data<<endl;
              M(fout,head,t);
              t=t->sib;
        }
         w=w->par;
    }
    }

int main()
{
    int n,i;
    cout<<"Enter the number of nodes:";
    cin>>n;
    cout<<"Enter the nodes values:";
    int *a=new int[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    Node* head=newnode(a[0]);
   // cout<<"here"<<endl;
    head=iniheap(a,n,head);
    Print(head,0);
    Node* y=head;
    Node* x=head;
    ofstream fout;
    fout.open("output.dot",ios::out);
    while (fout) {
          fout<<"graph G {"<<endl;
          /* for (i = 0; i < q; ++i){
            fout <<s[i][0]<<"--"<<s[i][1]<<"[label="<<t<<s[i][2]<<t<<"];"<<endl;
           }*/
          // cout<<"start111"<<endl;
           while(y!=NULL){
               if(y->sib!=NULL){
                fout<<y->data<<"--"<<y->sib->data<<";";
               }
           M(fout,x,y);
           y=y->sib;
           }
           //cout<<"endl111"<<endl;
        fout<<"}"<<endl;
        break;
    }
    fout.close();
}
