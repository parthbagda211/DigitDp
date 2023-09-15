#include <bits/stdc++.h>
using namespace std;
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define ll long long
#define P  cout <<
#define S  cin >>
#define en  << endl
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<vector<int>>
#define ff first
#define ss second
#define pb push_back
//****************************************************
#define inVll(vec, n) for(ll & i:vec){cin>>i;} 
#define inVli(vec, n) for(int & i:vec){cin>>i;}
//****************************************************

/*
QUESTIONS:
Majid quickly answered, and his teacher made him another challenge. He asked Majid to calculate the sum of the digits of numbers 1 through n.

*/


//*****************************************************
#define $  >>
vector<int> num;
int a,b,d,k;
int dp[10000][2][10000];

int dpp(int pos,int f,int sum){
    
    if(pos==num.size()){
        return sum;
    }

    if(dp[pos][f][sum]!=-1){
        return dp[pos][f][sum];
    }
   int lmt;
   int res=0;
    if(f==0){
      lmt = num[pos];
    }else{
        lmt = 9;
    }
   int nf;
    for(int i=0;i<=lmt;i++){
        nf = f;
        if(f==0 and i<lmt) nf = 1;

        res += dpp(pos+1,nf,sum+i);
        
    }
    return dp[pos][f][sum]= res;
}
int solve(int a){
	num.clear();
	while(a>0){
		num.push_back(a%10);
		a = a/10;
	}
	reverse(num.begin(),num.end());

	memset(dp,-1,sizeof(dp));
	int res = dpp(0,0,0);
	return res;
}
int main(){
fastread();
int t;
t=1;
//cin>>t;
while(t--){
    int a,b;cin>>a>>b;
    if(a==-1 and b==-1){
        break;
    }
    int res = solve(b)-solve(a-1);
    cout << res <<endl;
  
}

return 0;
}