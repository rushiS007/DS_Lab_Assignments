#include <bits/stdc++.h>
#include "fibonacci_heap.h"
#define INF 999999
using namespace std;
int minKey(int key[], bool mstSet[],int V);
#define ll long long
#define vpp vector<pair<ll, ll>>
vector<bool> marked;

ll prim(int x, vector<vpp> &adj)
{
    FibonacciHeap<pair<ll, ll>> Q;
    for (int i = 1; i < adj.size(); i++)
    {
        Q.insert({INF, i});
    }
    ll y;
    ll minimumCost = 0;
    vector<int> darr(adj.size(), INF);
    pair<ll, ll> p;
    Q.decrease_key({INF, x}, {0, x});
    darr[x] = 0;
    while (Q.heap)
    {
        p = Q.get_min();
        Q.extract_min();
        //cout<<x<<"    asasas    "<<p.second<<"  aasaa    "<<p.first<<endl;
        x = p.second;
        //if (marked[x] == true)
           // continue;
        minimumCost += p.first;
        //cout<<x<<"    asasas    "<<p.second<<"  aasaa    "<<p.first<<endl;
        marked[x] = true;
        for (int i = 0; i < adj[x].size(); ++i)
        {
            y = adj[x][i].second;
            if (marked[y] == false && adj[x][i].first < darr[y])
            {
                int tmp = darr[y];
                darr[y] = adj[x][i].first;
                Q.decrease_key({tmp, y}, adj[x][i]);
            }
        }
    }
    return minimumCost;
}

int main()
{
    fstream fin;
    fstream fin2;
    fin.open("input.csv");
    fin2.open("input.csv");
    int lines=0;
    string asas;
    while(fin2){
        getline(fin2,asas);
        //cout<<asas<<endl;
        lines++;
    }
    //cout<<lines<<endl;
    string word ,eachword;
    int count=0,i=0;
    char arr[lines*3-3];
    getline(fin,word);
    while(fin){
            int no=0;
        count++;
        string ssss = word;
        std::stringstream s(word);
        while(getline(s,eachword,',')){
            arr[i] = eachword[0];
            i++;
        }
        getline(fin,word);
    }
    int vertices=0;int j=0;
    while(j<(lines*3-3)){
       int  no=0;
        for(int k=0;k<j;k++){
            if(arr[j]==arr[k]){
                no++;
                break;
            }
        }
        if(no==0)
            vertices++;
        j=j+3;
    }
    j=1;
    while(j<(lines*3-3)){
        int no=0;
        for(int k=0;k<j;k++){
            if(arr[j]==arr[k]){
                no++;
                break;
            }
        }
        if(no==0)
            vertices++;
        j=j+3;
    }
    //cout<<vertices<<"----"<<lines-1<<endl;
    int v, e;
    v=vertices;
    e=lines-1;
    vector<vpp> adj(v + 1);
    marked.resize(v + 1);
    for (int i = 0; i < e*3; i=i+3)
    {
        int u, v, w;
        u=int(arr[i])-65+1;
        v=int(arr[i+1])-65+1;
        w = arr[i+2]-'0';
        //cout<<u<<"  "<<v<<"  "<<w<<endl;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    int k = 3;
    //cin >> k;
    //clock_t begin = clock();
    ll minimumCost = prim(k, adj);
    //clock_t end = clock();
    ofstream fout;
    //fout.open("tmp/fibo_time", ios::out | ios::app);
    //fout << 1.0 * (end - begin) / CLOCKS_PER_SEC << endl;
    //fout.close();
    cout << minimumCost << endl;

    int verArray [vertices][vertices];
    for(int k=0;k<vertices;k++){
        for(int l=0;l<vertices;l++)
            verArray[k][l]=0;
    }
    for(int k=0;k<(lines*3-1);k=k+3){
        int a = int(arr[k])-65;
        int b = int (arr[k+1])-65;
        verArray[a][b] = arr[k+2]-'0';
        verArray[b][a] = arr[k+2]-'0';
    }

    cout << "Hello world!" << endl;
    /*for(int k=0;k<vertices;k++){
        for(int l=0;l<vertices;l++)
            //cout<<verArray[k][l]<<"  ";
        //cout<<endl;
    }*/
    //PrintMst
    int V = vertices;
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet,vertices);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (verArray[u][v] && mstSet[v] == false && verArray[u][v] < key[v])
                parent[v] = u, key[v] = verArray[u][v];
    }
    //cout<<"Maa ka bhinsda";
    //cout<<"Edge \tWeight\n";
    int weightt=0;
    for (int i = 1; i < V; i++){
        char q = 'A'+ parent[i];
        char w = 'A'+ i;;
        cout<<q<<" - "<<w<<" \t"<<verArray[i][parent[i]]<<" \n";
        weightt = weightt + verArray[i][parent[i]];
    }
    return 0;
}

int minKey(int key[], bool mstSet[],int V)
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}
