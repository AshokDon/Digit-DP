//Problem Link: https://vjudge.net/problem/LightOJ-1068
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a , b , k , t;
vector<ll>nums;
ll DP[11][2][100][100];
void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

ll Fun(int pos,int dig_sum, int f, int n){
	if(pos==nums.size()){
		//cout<<n<<" "<<dig_sum<<endl;
		if(dig_sum==0 and n == 0) return 1;
		else return 0;
	}
	if(DP[pos][f][dig_sum][n]!=-1)return DP[pos][f][dig_sum][n];
	ll res = 0;
	ll LIM;
	
	if(f==0){
		LIM = nums[pos];
	}
	else{
		LIM = 9;
	}
	for(int i = 0 ; i <= LIM ; i++){
		ll nf = f;
		
	
		if(f==0 and i < LIM)nf = 1;
		
		res += Fun(pos+1,(dig_sum+i)%k,nf,(n*10+i)%k);

	}
	return DP[pos][f][dig_sum][n]=res;
}

ll Solve(int n){
	nums.clear();
	memset(DP,-1,sizeof(DP));
	while(n){
		nums.push_back(n%10);
		n/=10;
	}
	reverse(nums.begin(),nums.end());
	//for(auto it:nums)cout<<it<<" ";
	ll res = Fun(0,0,0,0);

	return res;
}
int main(){
	TakeInput();
	cin >>t;
	//int i = 1;
	while(t--){


	
		cin >> a >> b >> k;
		//cout<<a<<b<<k<<endl;;
		
		if(k>=100) cout<<0<<"\n";
		else cout<<Solve(b)-Solve(a-1)<<"\n";
		//i++;
	}
	//cout<<"hi";
}
