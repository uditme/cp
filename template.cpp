#include<bits/stdc++.h>
using namespace std;
#define endl "\n" 
const int mod = 1e9 + 7;
#define ll long long 
// #define int long long 
#define all(x) (x).begin(), (x).end() 
#define allr(x) (x).rbegin(), (x).rend() 
#define inp(x) int x; cin>>x;
#define sinp(x) string x; cin>>x;
#define out(x) cout<<x<<endl;
#define outv(x) for (auto &it : x) {cout<<it<<" ";} {cout<<endl;}
#define out2d(x) for (auto &it : x) outv(it)
#define outmp(x) for (auto &[f, s] : x) {outv(f)cout<<" ---> "<<s<<endl;}
#ifndef ONLINE_JUDGE
    void dbg_out() { cerr << endl; }
    template<typename Head, typename... Tail>
    void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#endif


void solve (int tcase) {
    

    return;

}


signed main(){
    ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
#else
  cin.tie(0);cout.tie(0);
#endif
    int t= 1;
    cin>>t;
    for (int _ = 1; _ <= t; _++) solve(_);return 0;}














int arrsize= 10000;   //O( sqrt(n).log(log(n)) )
// 0 ---> Not Prime
// 1 ---> Prime
vector<bool> sieve(arrsize + 1, 1);
vector<long long> spf(arrsize + 1, 1e18);
void createSieve() {
    sieve[0] = 0; sieve[1] = 0;
    for (long long i = 2; i*i <= arrsize; i++)
        if (sieve[i]) {
            spf[i]= i;
            for (long long j = i*i; j <= arrsize; j+=i) {
                sieve[j] = 0;
                spf[j]= min(spf[j], i);
            }
        }
}

// Do this to find factors of a number---->  (...vector...) = prime_factors (...);   O(log n)
vector<int> prime_factors(int n) {
    vector<int> array_of_factors;
    while (n!= 1) {
        int num= spf[n];
        while (n% num== 0) {
            array_of_factors.push_back(num);
            n/= num;
        }

    }
    return array_of_factors;
}



















//precomputation of fact and ifact (inversefactorial).....  O(fact_n)
int fact_n= 1e7;
vector<long long> fact(fact_n +1, 0), ifact(fact_n +1, 0);
void precompute_factorial() {
    fact[0]= 1;
    for (int i = 1; i <= fact_n; i++) {
        fact[i]= mul(fact[i-1], i, mod);
    }
    ifact[fact_n]= inv(fact[fact_n], mod);           //mod should be prime...
    for (int i = fact_n-1; i >= 0; i--) {
        ifact[i]= mul(ifact[i+1], i+1, mod);
    }
}

//ncr...
long long ncr(long long n, long long r) {
    return mul(fact[n], mul(ifact[r], ifact[n-r], mod), mod);
}


//ncr for once...   O(r)
long long ncr1(int n, int r) {
    if (r > n - r) r = n - r;     //to make O(n/2)...
    long long res = 1;
    for (int i = 0; i < r; ++i) {
        res = mul(res, (n - i), mod);
        res = divi(res, (i + 1), mod);      //mod should be prime...
        //res /= (i + 1);
    }
    return res;
}
