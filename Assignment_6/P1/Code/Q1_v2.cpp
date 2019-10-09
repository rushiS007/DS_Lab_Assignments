#include<bits/stdc++.h>

using namespace std;


typedef long long int ll;

struct Node{
   int a;
   int b[100];
   int size=0;
};
void depth_first_search(Node graph[],bool visited[],int current){
   if(visited[current]){
      return;
   }
   cout<<(char)(current+'A')<<" ";
   visited[current]=true;
   for(int i=0;i<graph[current].size;i++){
     if(!visited[graph[current].b[i]]){
        depth_first_search(graph,visited,graph[current].b[i]);
     }
   }
}

void bredth_first_search(Node graph[],bool visited[]){
    int l=0;
    int r=1;
    int size=1;
    int current[1000]={0};
    visited[0]=true;
    while(size!=0){
       for(int i=0;i<graph[current[l]].size;i++){
          if(!visited[graph[current[l]].b[i]]){
           visited[graph[current[l]].b[i]]=true;
           current[r++]=graph[current[l]].b[i];
           size++;
          }
       }
       cout<<(char)(current[l++]+'A')<<" ";
       size--;
    }
}

bool cycle(Node graph[]){
   int vertices=0;
   int edges=0;
   for(int i=0;i<100;i++){
       if(graph[i].size){
          vertices++;
          edges+=graph[i].size;
       }
   }
   edges/=2;
   if(edges>vertices-1){
     return true;
   }
   return false;
}
void diadepth_first_search(Node graph[],int current,int dis[100],int d){
    if(dis[current]<=d){
      return;
    }
    dis[current]=d;
    for(int i=0;i<graph[current].size;i++){
         diadepth_first_search(graph,graph[current].b[i],dis,d+1);
    }
}


int main(){
    cout<<"1. Inset edges from input.txt\n2. bredth_first_search traversal\n3. depth_first_search traversal\n4. Check wheather graph is cyclic or not\n5. Calculate diameter of the graph\n";
    int choice;
    cin>>choice;
    Node graph[100];
    while(choice!=-1){
       if(choice==1){
          char a,b;
          cout<<"ENTER VERTICES:\n";
          string line;
          ifstream myfile ("input.txt");
          if (myfile.is_open())
          {
            while ( getline (myfile,line) )
            {
              cout << line << '\n';
              a = line[0];
              b = line[2];
              int x=a-'A';
              int y=b-'A';
              graph[x].b[graph[x].size]=y;
              graph[x].size++;
              graph[y].b[graph[y].size]=x;
              graph[y].size++;
            }
          }
            myfile.close();
          }
          
          
       else if(choice==2){
          bool visited[100]={0};
          bredth_first_search(graph,visited);
          cout<<"\n";
       }
       else if(choice==3){
          bool visited[100]={0};
          depth_first_search(graph,visited,0);
          cout<<"\n";
       }
       else if(choice==4){
         bool check=cycle(graph);
         if(check){
           cout<<"YES\n";
         }
         else{
           cout<<"NO\n";
         }
       }
       else if(choice==5){
            int diameter=0;
            int dis[100];
            for(int i=0;i<100;i++){
               if(graph[i].size!=0){
                  memset(dis,1000000,sizeof(dis));
                  diadepth_first_search(graph,i,dis,0);
                  for(int i=0;i<100;i++){
                    if(graph[i].size!=0){
                      if(dis[i]>diameter){
                         diameter=dis[i];
                      }
                    }
                  }
               }
            }
            cout<<diameter<<endl;
       }
       cout<<"1. Inset edge\n2. bredth_first_search traversal\n3. depth_first_search traversal\n4. Cycle finding in the graph\n5. Calculate diameter of the graph\n";
       cin>>choice;
    }
	return 0;
}