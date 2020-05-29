/*Problem Statement:
The “King Number” is a prime number that is the factor of the most numbers in a given list. Can you find the “King Number”  in each list? For example, for the list {2, 3, 5, 6, 9, 14, 20}, the answer is 2, since it's a factor of 2, 6, 14 and 20, while 3 is only a factor of 3, 6 and 9.

Code Link: https://ideone.com/d7hfHr
COde:
Time Complexity:O(n^2)
Space Complexity:O(1)
*/

#include<bits/stdc++.h>
using namespace std;
bool isPrime(int N){
	for (int i = 2; i <= N / 2; ++i) {
           if (N % i == 0) {
           return false;
        }
    }
    return true;
}
int main(){
	int n,i,j,num,max=0;
	cin>>n;
	vector<int>v;
	for(i=0; i<n; i++){
		int x; cin>>x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for(i=0; i<n; i++){
		int cnt=0;
		if(isPrime(v[i])){
		for(j=i+1; j<n; j++){
			if(v[j]%v[i]==0){
				cnt++;
			}
		}}
		if(cnt>max){
			max=cnt;
			num=v[i];
		}
	}
	cout<<num<<endl;
}
