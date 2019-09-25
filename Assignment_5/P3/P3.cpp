#include <bits/stdc++.h>
#include "fibonacci.h"
#define INF 999999
using namespace std;

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
        x = p.second;
        if (marked[x] == true)
            continue;
        // cout<<p.first<<" "<<p.second<<endl;
        minimumCost += p.first;
        marked[x] = true;
        for (int i = 0; i < adj[x].size(); ++i)
        {
            y = adj[x][i].second;
            if (marked[y] == false && adj[x][i].first < darr[y])
            {
                int tmp = darr[y];
                darr[y] = adj[x][i].first;
                Q.decrease_key({tmp, y}, adj[x][i]);
                cout<<adj[x][i].first<<" "<<adj[x][i].second<<endl;
            }
        }
    }
    return minimumCost;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vpp> adj(v + 1);
    marked.resize(v + 1);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    int k;
    cin >> k;
    clock_t begin = clock();
    ll minimumCost = prim(k, adj);
    clock_t end = clock();
    ofstream fout;
    fout.open("tmp/fibo_time", ios::out | ios::app);
    fout << 1.0 * (end - begin) / CLOCKS_PER_SEC << endl;
    fout.close();
    cout << minimumCost << endl;
    return 0;
}