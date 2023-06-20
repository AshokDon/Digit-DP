#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, d, k;
vector<ll>nums;
int DP[12][12][12];
void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
ll Fun(ll pos, ll cnt, ll f){
	if(cnt > k)return 0;
	if(pos == nums.size()){

		if(cnt == k)return 1;
		else return 0;
	}

	if(DP[pos][cnt][f]!=-1)return DP[pos][cnt][f];
	ll res = 0;
	int LIM;
	if(f==0){
		LIM = nums[pos];
	}
	else{
		LIM = 9;
	}
	for(int i = 0 ; i <= LIM ; i++){
		ll nf = f;
		//cout<<i;
		ll ncnt = cnt;
		if(f == 0 and i < LIM)nf = 1;
		if(i == d)ncnt++;
		
		if(ncnt <= k)res += Fun(pos+1,ncnt,nf);
	}
	//cout<<"\n";
	return DP[pos][cnt][f]=res;
}
ll solve(ll b){
	nums.clear();
	while(b > 0){
		nums.push_back(b%10);
		b = b / 10;
	}
	reverse(nums.begin(),nums.end());
	memset(DP,-1,sizeof(DP));
	ll res = Fun(0, 0 , 0);
	return res;
}
int main(){
	TakeInput();
	cin >> a >> b >> d >> k;
	//cout<<"hi";
	ll ans = solve(b) - solve(a-1);
	cout<<ans;
}
