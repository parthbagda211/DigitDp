#include <iostream>
#include <cstring>
using namespace std;

int call(int pos, int cnt, int f, int n, string &num, int dp[12][12][2]) {
    if (pos == num.size()) {
        return (cnt > 0 && cnt % n == 0) ? 1 : 0;
    }

    if (dp[pos][cnt][f] != -1) {
        return dp[pos][cnt][f];
    }

    int res = 0;
    int lmt;
    if (f) {
        lmt = num[pos] - '0';
    } else {
        lmt = 9;
    }

    for (int i = 0; i <= lmt; i++) {
        int nf = f;
        int ncnt = cnt;
        if (f == 0 && i < lmt) {
            nf = 1;
        }
        ncnt += (i != 0 && i % n == 0);
        res += call(pos + 1, ncnt, nf, n, num, dp);
    }

    return dp[pos][cnt][f] = res;
}

int countDivisibles(int A, int B, int M)
{
   
    // Add 1 explicitly as A is divisible by M
    if (A % M == 0)
        return (B / M) - (A / M) + 1;
 
    // A is not divisible by M
    return (B / M) - (A / M);
}

int main() {
    int a,b,n;cin>>a>>b>>n;
    int count = countDivisibles(a,b, n);

    cout << count << endl;

    return 0;
}
