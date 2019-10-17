#include <bits/stdc++.h>

using namespace std;

void print(map<int,int>p){
    for(int i=p.begin()->first;i<=p.rbegin()->first;i++){
        if(p[i])
        cout<<"Power:- "<<i<<" Coefficient:- "<<p[i]<<endl;
    }
    cout<<endl;
}

void add(map<int,int>p1,map<int,int>p2){
    map<int,int> p3;
    int a=p1.begin()->first;
    int b=p2.begin()->first;
    for(int i=min(a,b);i<=max(p1.rbegin()->first,p2.rbegin()->first);i++){
        p3[i]=p1[i]+p2[i];
    }
    print(p3);
}

void multiply(map<int,int>p1,map<int,int>p2){
    int p1max=p1.rbegin()->first;
    int p2max=p2.rbegin()->first;
    int p1min=p1.begin()->first;
    int p2min=p2.begin()->first;
    map<int,int> p3;
    int p3max=p1max+p2max;
    int p3min=p1min+p2min;
    for(int i=p3min;i<=p3max;i++){
        for(int j=p3min;j<=i-p3min;j++){
            p3[i]+=(p1[j]*p2[i-j]);
        }
    }
    print(p3);
}

int main(){
    int n=0;
    cout<<"No. of terms in the expression:";
    cin>>n;
    cout<<endl;
    map<int,int>  p1;
    for(int i=0;i<n;i++){
        int p,c;
        cout<<"Power:- ";
        cin>>p;
        cout<<"Coefficient:- ";
        cin>>c;
        p1.insert(pair<int,int>(p,c));
        cout<<endl;
    }
    cout<<"No. of terms in the expression:";
    cin>>n;
    cout<<endl;
    map<int,int>  p2;
    for(int i=0;i<n;i++){
        int p,c;
        cout<<"Power:- ";
        cin>>p;
        cout<<"Coefficient:- ";
        cin>>c;
        p2.insert(pair<int,int>(p,c));
        cout<<endl;
    }
    int state=0;
    while(state!=3){
        cout<<"Enter\n";
        cout<<"1->Add\n";
        cout<<"2->Multiply\n";
        cout<<"3->Exit\n";
        cin>>state;
        if(state==1){
            add(p1,p2);
        }
        else if(state==2){
            multiply(p1,p2);
        }
        else if(state==3){
            cout<<"Bye!!\n";
        }else{
            cout<<"Enter something valid!!\n";
        }
    }
}