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
#define $  >>

//****************************************************
int dp[30][2][30];

int dpp(int pos,int f,int prev,string & num){
    
    if(pos==num.size()){
     return 1;
    }

    if(dp[pos][f][prev]!=-1){
        return dp[pos][f][prev];
    }
   int lmt;
   int res=0;
    if(f){
      lmt = num[pos]-'0';
    }else{
        lmt = 1;
    }
  
    for(int i=0;i<=lmt;i++){

       int nf = f;
       if(i<lmt) nf=0;

        if(prev!=1 or i!=1){
         res  += dpp(pos+1,nf,i,num);
        }

       
        
    }
    return dp[pos][f][prev]= res;
}

    int findIntegers(int n) {

        memset(dp,-1,sizeof(dp));

        string s;
        while(n!=0){
            int rem = n%2;
            s += (rem +'0');
            n/=2;
        }
        reverse(s.begin(),s.end());
        return dpp(0,1,0,s);
        
    }


int main(){
fastread();
int t;
t=1;
//cin>>t;
while(t--){
  int a ;cin>>a;
  int ans = findIntegers(a);
  cout << ans;
}

return 0;
}