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
int mod = 1e9+7;
long dp[23][2][401];

long dpp(int pos,int f,int sum, const int &min_sum, const int &max_sum,string & num){
    
    if(pos==num.size()){
      return (sum>=min_sum and sum<=max_sum);
    }

    if(dp[pos][f][sum]!=-1){
        return dp[pos][f][sum];
    }
   int lmt;
   long res=0;
    if(f){
      lmt = num[pos]-'0';
    }else{
        lmt = 9;
    }
  
    for(int i=0;i<=lmt;i++){
        int nf = (f and i==lmt)?1:0;
        res = (res + dpp(pos+1,nf,sum+i,min_sum,max_sum,num))%mod;
        
    }
    return dp[pos][f][sum]= res;
}

    int count(string num1, string num2, int min_sum, int max_sum) {

        memset(dp,-1,sizeof(dp));
        long a = dpp(0,1,0,min_sum,max_sum,num2);

        memset(dp,-1,sizeof(dp));
        long b = dpp(0,1,0,min_sum,max_sum,num1);

        int sum=0;
        for(int i=0;i<num1.size();i++){
            sum += num1[i]-'0';
        }

        if(sum>=min_sum and sum<=max_sum){
            b--;
        }


        return ((a-b)+mod)%mod;

        
    }
int main(){
fastread();
int t;
t=1;
//cin>>t;
while(t--){
   string a,b;cin>>a>>b;
   int minSum,maxSum;cin>>minSum>>maxSum;
   int ans = count(a,b,minSum,maxSum);
    

  
}

return 0;
}