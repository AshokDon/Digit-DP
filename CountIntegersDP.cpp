//Problime Link :  https://leetcode.com/problems/count-of-integers/

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
ll mod = 1e9+7;
ll DP[23][401][2];
void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
ll Fun(string n2,ll m1,ll m2, ll pos, ll dig_sum, ll f){
	if(pos == n2.size()){
		if(m1 <= dig_sum and dig_sum <= m2)return 1;
		else return 0;
	}
	if(dig_sum > m2)return 0;
	if(DP[pos][dig_sum][f]!=-1)return DP[pos][dig_sum][f];
	ll res = 0;
	ll LIM;

	if(f==0){
		LIM = n2[pos]-'0';
	}
	else{
		LIM = 9;
	}
	//cout<<LIM<<" ";
	for(int i = 0 ; i <= LIM ; i++){
		ll nf = f;
		ll nsum = dig_sum;
		if(f == 0 and i < LIM)nf = 1;
		nsum+=i;
		//cout<<i<<" ";
		res=(res + Fun(n2,m1,m2,pos+1,nsum,nf))%mod;
	}
	return DP[pos][dig_sum][f]=res;
}
int main(){
	TakeInput();
	string n1, n2;
	ll  m1,m2;
	cin >> n1 >> n2;
	cin >> m1 >> m2;
	string s1="0";
	//cout<<n2[0];
	memset(DP,-1,sizeof(DP));
	ll res = Fun(n2,m1,m2,0,0,0);
	memset(DP,-1,sizeof(DP));
	ll res1 = Fun(n1,m1,m2,0,0,0);
	cout<<res-res1;

}
