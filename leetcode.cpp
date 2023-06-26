#include<bits/stdc++.h>
 
using namespace std;
typedef unsigned long long int ll;
ll mod = 1e9+7;
ll DP[2020][2020][2][2];
ll m , d ;
string a , b;

void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
ll Fun(ll pos, ll f1, ll f2,ll modm){
    if(pos==b.size()){
        //cout<<modm;
        return modm==0;
    }

    if(DP[pos][modm][f1][f2]!=-1)return DP[pos][modm][f1][f2];
    ll res = 0;
    ll LIM1,LIM2;
    if(f1)LIM1 = 0;
    else LIM1 = a[pos]-'0';

    if(f2)LIM2 = 9;
    else LIM2 = b[pos]-'0';

    if(!(pos&1)){

        for(int i = LIM1 ; i <= LIM2 ; i++){
            if(i==d)continue;
            int nf1 = (f1 || LIM1!=i);
            int nf2 = (f2 || LIM2!=i);
            res = (res % mod + Fun(pos+1,nf1,nf2,(modm*10+i)%m)%mod)%mod;
        }
    }
    else{
        if(d >= LIM1 and d <= LIM2){
            int nf1 = (f1 || LIM1!=d);
            int nf2 = (f2 || LIM2!=d);
            res = (res % mod + Fun(pos+1,nf1,nf2,(modm*10+d)%m)%mod)%mod;
        }
    }
    return DP[pos][modm][f1][f2] = res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //TakeInput();
    cin >> m >> d;
    
    cin >> a >> b;
    //cout<<a<<" "<<b;
    memset(DP,-1,sizeof(DP));
    cout<<Fun(0,0,0,0);
 
 
}
 
 
 