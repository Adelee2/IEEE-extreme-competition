#include <iostream>
#include <vector>
#include <bits/stdc++.h>
//#include <algorithm>

using namespace std;

int solution(long long int &);

int main()
{
	long long int input;
	
	cin>>input;
	cout<<"\n"; 
	
		cout<<solution(input)<<"\n";	
	
	return 0;
}


int solution(long long int &N)
{
	vector<int> inarr;
	vector<int> outarr;
	int temp=0,counter=0,result=0;
		
	//first convert the integer to binary
	while(N!=0){
		temp= N % 2;
		inarr.push_back(temp);
		N=N/2;
	}
	reverse(inarr.begin(),inarr.end());
	
	//display the binary form
	for(auto j :inarr)
		cout<<j;
cout<<"\n";

	bool checker=false;
	auto len=inarr.size();
	
	size_t j,m=0;
	for(size_t i=0;i<len;i++){
		if(inarr[i]==1 && inarr[i+1] == 0){
			for(j=i+1;j<len;j++){
		  		if(inarr[j]==1){
		  			checker=true;
		  			break;
		  		}
				else{
				 	 checker=false;
				 }
		  	}
		  	if(checker==true){
		  		int temp= j - (i+1);
		  		
		  		outarr.push_back(temp);
		  	    
		    }
		    	checker=false;
		}
 }
 	auto outsize=outarr.size();
// 	cout<<"\n outarr size is "<<outsize<<"\n";
 	for(auto j=0;j<outsize;j++)
 	{
 		if(outarr[j]>result)
 			result=outarr[j];
	 }
	 
	 return result;
}
