Problem Statement:
On election day, a voting machine writes data in the form (voter_id, candidate_id). Write a program that takes data as array of (voter_id, candidate_id) and returns the top 3 candidates at any given time. If you find a voter voting more than once, report this as fraud and dont count this voter's any vote and print these voters id as fraud candidates.
Example: For data: [(1,2), (2,3),(3,2), (1,3), (4,3), (5,3),(6,2), (7,3), (8,2), (9,3),(10,1), (11,4), (12,4)] , output should be,
Top Three candidate ids: 3, 2, 4
Fraud voter ids: 1
Solution Link: https://ideone.com/rc6qOm
Code:
Time Complexity: O(n)
Space Complexity:O(n)

#include<bits/stdc++.h>
using namespace std;
void findTopThreeCandidate(int arr[], int arr_size) 
{ 
    int i, first, second, third, firstcand=-1,secondcand=-1, thirdcand=-1; 
     third = first = second = INT_MIN;
     
    for (i = 0; i < arr_size ; i ++) 
    { 
    	if (arr[i] > first) 
        { 
            third = second; 
            thirdcand=secondcand;
            second = first; 
            secondcand=firstcand;
            first = arr[i]; 
            firstcand=i;
        } 
   else if (arr[i] > second) 
        { 
            third = second; 
            thirdcand=secondcand;
            second = arr[i]; 
            secondcand=i;
        } 
   
        else if (arr[i] > third) {
            third = arr[i]; 
            thirdcand=i;}
            
    } 
 cout<<"Top Three Candidates ids "<<firstcand<<" "<<secondcand<<" "<<thirdcand<<endl;
}  

int main(){
	vector<pair<int,int> >v; 
	int n,voter_id,cand_name;  //Assuming n people voted that day
	cin>>n; 
	int hash[n]={0}; 
	int Fraud[n]={0};
	
	for(int i=0; i<n; i++){
		cin>>voter_id>>cand_name;
		v.push_back(make_pair(voter_id,cand_name)); // for each vote pusing voterid and candidate id
	}
	for (int i=0; i<n; i++) {  // getting count of votes by each individual
   	Fraud[v[i].first]++;
    }
    cout<<"Fraud voter ids ";
	for (int i=0; i<n; i++) { 
   	if(Fraud[i]>1)  // if a voter casted vote more than once that is fraud 
   	cout<<i<<" "; // getting printed fraud voter id
    }
    cout<<endl;
    
  for (int i=0; i<n; i++) { // keeping count of existance of each candidate
   	hash[v[i].second]++;
    }
   findTopThreeCandidate(hash,n); //this function will find the top three candidates
	return 0;
}
