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
// vector<int> num;
vector<int> num;
int a,b,d,k;
string s;
int dp[11][2][11];

int dpp(int pos,int f,int cnt){
    
    if(pos==s.size()){
        return cnt;
    }

    if(dp[pos][f][cnt]!=-1){
        return dp[pos][f][cnt];
    }
   int lmt;
   int res=0;
    if(f){
      lmt = s[pos]-'0';
    }else{
        lmt = 9;
    }
  
    for(int i=0;i<=lmt;i++){
        int  nf = (f and i==lmt)?1:0;
        if(f and i==lmt) nf = 1;
        int ncnt = (i==1)?cnt+1:cnt;
        res += dpp(pos+1,nf,ncnt);
        
    }
    return dp[pos][f][cnt]= res;
}
// int solve(int a){
// 	num.clear();
// 	while(a>0){
// 		num.push_back(a%10);
// 		a = a/10;
// 	}
// 	reverse(num.begin(),num.end());

// 	memset(dp,-1,sizeof(dp));
// 	int res = dpp(0,1,0);
// 	return res;
// }
int main(){
fastread();
int t;
t=1;
//cin>>t;
while(t--){
    int a;
    cin>>a;
    s = to_string(a);
    cout << dpp(0,1,0);
    
  
}

return 0;
}