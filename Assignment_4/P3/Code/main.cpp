/**
* @file bits/stdc++.h
* @breif this header file will contain the input/output function like scanf and printf.
* 
* @author Rushiprasad
* 
* @date 3/09/2019
*/
#include <bits/stdc++.h> 
using namespace std; 

/*
* This method prints the solution.
* @param arr[] an array
* @author Rushiprasad.
* @date 3/09/2019
*/
void lenOfLongSubarr(int arr[], 
					int n, 
					int k) 
{ 

  	int begin =0,end=0;
	
	unordered_map<int, int> um; 
	int sum = 0, maxLen = 0; 

	
	for (int i = 0; i < n; i++) { 

		
		sum += arr[i]; 

		
		if (sum == k) {
        	maxLen = i + 1; 
		begin=0;
          	end=i;
        }
      
		
		if (um.find(sum) == um.end()) 
			um[sum] = i; 

		
		if (um.find(sum - k) != um.end()) { 

			
			if (maxLen < (i - um[sum - k])) {
            	maxLen = i - um[sum - k];
              	begin=um[sum-k]+1;
              	end=i;
            } 
		} 
	} 

  	cout<<"Length is "<<maxLen<<endl;
  	cout<<"Starting from "<<begin<<" to end "<<end<<endl;
	
} 

int main()
{      
  
	 
	int k,N;
	cout<<"Enter N"<<endl;
	cin>>N;
	int arr[N];
	cout<<"Enter array"<<endl;
	for(int i=0;i<N;i++){cin>>arr[i];};
	cout<<"Enter n"<<endl;
	cin>>k;
  
	lenOfLongSubarr(arr, N, k); 
	return 0; 
} 

