/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <iterator> 
#include <map>
#include <vector>

using namespace std;

int main()
{   
    map<int, int> poly1;
    vector<int> a ;
    cout<<"Enter no. of terms in expression 1 : ";
    int n1;
    cin>>n1;
    cout<<"Exponent\tCoefficient "<<endl;
    while(n1--){int expo,coeff;
        cin>>expo>>coeff;
        poly1.insert(pair<int, int>(expo,coeff));
        a.push_back(coeff);
    }
    int n2;
    cout<<"Enter no. of terms in expression 2 : ";
    cin>>n2;
   
    map<int, int> poly2;
    vector<int> b;
    cout<<"Exponent\tCoefficient "<<endl;
    while(n2--){int expo,coeff;
        cin>>expo>>coeff;
        poly2.insert(pair<int, int>(expo,coeff));
        b.push_back(coeff);
    }
    
    /*
    map<int, int> poly1;
    poly1.insert(pair<int, int>(0,6));
    poly1.insert(pair<int, int>(1,5));
    poly1.insert(pair<int, int>(2,2));
    
    map<int, int> poly2;
    poly2.insert(pair<int, int>(0,1));
    poly2.insert(pair<int, int>(1,1));
    poly2.insert(pair<int, int>(2,5));
    poly2.insert(pair<int, int>(3,2));
    */
    while(1){
    cout<<"Enter 1 to add or 2 for multiply \n";
    int m;
    cin>>m;
    if(m==1){
    map<int, int> :: iterator itr;
     map<int, int> poly3;
    poly3 = poly1;
    for ( auto const& item : poly2 )
        {
            poly3[item.first] += item.second;
        }
     
    
    cout << "\tCOEFF\tEXPO\n"; 
    itr=poly3.end();
    itr=--itr;
    
    for (itr; itr != poly3.begin(); --itr) { 
        cout << '\t' << itr->second ;
            cout << '\t' << itr->first << '\n'; 
    } 
    itr=itr++;
     cout << '\t' << itr->second ;
            cout << '\t' << itr->first << '\n'; 
    cout << endl; }
    ////////////////////////////////////////////////////////////////////////
   // vector<int> a = {6,5,2};

    // make polynomial coefs vector
    if(m==2){
    int A = 1;
    const int as = a.size();
    int ap = 1;
    for(int ai = 0; ai<as; ++ai){
        a[ai] *= ap;
        ap *= A;
    }

    //vector<int> b = {1,1,5,2};
    const int bs = b.size();

    // result vector
    vector<int> c(as + bs - 1, 0);

    // multiply vectors
    for(int ai = 0; ai<as; ++ai)
        for(int bi = 0; bi<bs; ++bi){
            c[ai+bi] += a[ai]*b[bi];
        }
    cout << "\tCOEFF\tEXPO\n"; 
    for(int i=c.size()-1;i>=0;i--)
       {cout <<"\t"<< c[i] << ' ';
        cout<<"\t"<<c.size()-1-i<<" "<<endl;           
       }
    }
}
    return 0;
}


