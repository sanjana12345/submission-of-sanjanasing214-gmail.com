Problem Statement:
For a newly opened hospital, opened on 1st, you have data of entry and exit date of patients between date 1st to 10th. You have to find the date on which there are most number of patients in the hospital.
For example, you have array of entry and exit date of patients(entry, exit) like [(1,3),(2,5),(4,8),(9,10),(5,6),(4,7),(7,10)] then your output will be date 5 as this date has 4 number of patients.

Code Link:https://ideone.com/NZurHN
Code:
Time complexity:O(n)
Space Complexity:O(n)
#include<bits/stdc++.h> 
using namespace std;
int main() 
{ 
    int a,b,i,n,s=0,ans=INT_MIN,ind;
    cin>>n;
    vector<pair<int,int> > v;
    for(i=0;i<n;++i){
    	cin>>a>>b;
    	v.push_back(make_pair(a,b));
	}
    int day[11]={0};
    for (i=0;i<n;++i){  
        day[v[i].first]+=1; 
        day[v[i].second+1]-=1; 
    } 
    for(i=1;i<11;++i){ 
        s+=day[i]; 
        if(ans<s){
        	ans=s;
        	ind=i;
		} 
    }
	cout<<ind;  
    return 0; 
}

