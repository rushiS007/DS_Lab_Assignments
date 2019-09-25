#include <bits/stdc++.h>
#include "fibonacci.h"
using namespace std;

void solve(int n)
{
    FibonacciHeap<int> h;
    while (n--)
    {
        /*
            0 : insert
            1 : get minimum
            2 : extract minimum
            3 : decrease key
         */
        int c;
        cin >> c;
        int inp=0;
        int d_x, d_y;
        switch (c)
        {
            case 0:
                cin >> inp;
                h.insert(inp);
                break;
            case 1:
                cout << h.get_min()<<endl;
                break;
            case 2:
                h.extract_min();
                break;
            case 3: 
                cin >> d_x >> d_y;
                h.decrease_key(d_x, d_y);
                break;
            default:
                break;
        }
    }
}

int main()
{
    long long n;
    cin >> n;
    clock_t begin = clock();
    solve(n);
    clock_t end = clock();
    ofstream fout;
    fout.open("tmp/fibo_time",ios::out | ios::app);
    fout << 1.0 * (end - begin) / CLOCKS_PER_SEC << endl;
    fout.close();
    return 0;
}