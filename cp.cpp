#include<bits/stdc++.h>
using namespace std;
#define endl "\n" 
const int mod = 1e9 + 7;
#define ll long long 
// #define int long long 
#define fi(var, strt, end) for (int var = int(strt); var < int(end); var++)
#define fd(var, strt, end) for (int var = int(strt); var >= int(end); var--)
#define all(x) (x).begin(), (x).end() 
#define allr(x) (x).rbegin(), (x).rend() 
#define inp(x) int x; cin>>x;
#define sinp(x) string x; cin>>x;
#define out(x) cout<<x<<endl;
#define outv(x) for (auto &it : x) {cout<<it<<" ";} {cout<<endl;}
#define ter(x, y, z) cout << (x ? y : z) << endl;
#ifndef ONLINE_JUDGE
    void dbg_out() { cerr << endl; }
    template<typename Head, typename... Tail>
    void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#endif


void solve () {
    vector<vector<int>> arr= {
        {9, 1, 8, 6, 4, 7},
        {8, 1, 1, 1, 5, 4}
    };

    int m= arr.size();  //row
int n= arr[0].size();  //col

for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = j - 1; k >= 0; k--) {  //left
                cout<<arr[i][k]<<" ";
            }
            cout<<endl; 
            for (int k = j+1; k < n; k++) {    //right
                cout<<arr[i][k]<<" ";
            }
            cout<<endl;
            for (int k = i - 1; k >= 0; k--) {   //up
                cout<<arr[k][j]<<" ";
            }
            cout<<endl;
            for (int k = i+1; k < m; k++) {   //dwn
                cout<<arr[k][j]<<" ";
            }        
            cout<<endl;
            for (int ki = i-1, kj = j-1; ki >= 0 && kj >= 0; ki--, kj--) {    //left up diagonal
                cout<<arr[ki][kj]<<" ";
            }
            cout<<endl;
            for (int ki = i+1, kj = j-1; ki < m && kj >= 0; ki++, kj--) {    //left down diagonal
                cout<<arr[ki][kj]<<" ";
            }
            cout<<endl;
            for (int ki = i-1, kj = j+1; ki >= 0 && kj < n; ki--, kj++) {    //right up diagonal
                cout<<arr[ki][kj]<<" ";
            }
            cout<<endl;
            for (int ki = i+1, kj = j+1; ki < m && kj < n; ki++, kj++) {    //right down diagonal
                cout<<arr[ki][kj]<<" ";
            }
            cout<<endl;
        }
}

    return;

}


signed main(){
    ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
#else
  cin.tie(0);cout.tie(0);
#endif
    int t;
    t=1;
    // cin>>t;
    while(t--)solve();return 0;}









//binary to string conversion and string to binary conversion....
int btoi(string& binaryString) {
    bitset<32> binset(binaryString);
    return static_cast<int>(binset.to_ullong());
}
 
string itob(int number) {
    bitset<32> binset(number);
    string str= binset.to_string();
    // str.erase(0, str.find_first_not_of('0'));     //for without leading zeroes...
    return str;
}









    //custom_hash for unordered map....
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};







//modular arithmetic....
long long add(long long a, long long b, long long mod) {return (((a + mod) % mod + (b + mod) % mod) % mod);}
// long long sub(long long a, long long b, long long mod) {return (((a + mod) % mod + ((-b) + mod) % mod) % mod);}
long long sub(long long a, long long b, long long mod) {return ((a % mod - b % mod + mod) % mod);}
long long mul(long long a, long long b, long long mod) {return ((a % mod * b % mod) % mod);}
// long long binpow(long long a, long long b, long long m) {a %= m;long long res = 1;while (b > 0) {if ((b & 1) != 0)res = mul(res, a);a = mul(a, a);b /= 2;}return res;}
long long binpow(long long a, long long b, long long mod) {if (b==0) return 1;a%= mod;long long half_power= binpow (a, b/2, mod);if (b%2 ==0){return (half_power% mod * half_power % mod) % mod;}else {return (half_power% mod * half_power % mod * a% mod) % mod;}}
long long inv(long long x, long long mod) {return binpow(x, mod - 2, mod);}
long long divi(long long x, long long y, long long mod) {return mul(x, inv(y, mod), mod);}








//Dearrangements....
int dearrangements (int n, vector<int>& dp) {
    if (n<= 1) return 0;
    if (n== 2) return 1;

    if (dp[n]!= -1) return dp[n];

    return dp[n]= mul((n-1) , (add(dearrangements(n-2, dp), dearrangements(n-1, dp), mod)), mod);
}





class PrefixSum {
public:
    vector<int> psum;
    PrefixSum(vector<int> &a) {
        int n = a.size();
        psum.resize(n, 0);
        psum[0] = a[0];
        for (int i = 1; i < n; i++)
            psum[i] = psum[i - 1] + a[i];
    }
    int query(int l, int r) {
        if (l < 0) l = 0;
        if (r >= psum.size()) r = psum.size() - 1;
        if (l > r) return 0;
        int sum = psum[r];
        if (l - 1 >= 0)
            sum -= psum[l - 1];
        return sum;
    }
};









class Hash
{
    const int MOD = 1e9 + 7, BASE1 = 5689, BASE2 = 8861;
    vector<pair<int, int>> hashes, Pow;

public:
    Hash(string s)
    {
        hashes.assign(s.size() + 1, {0, 0});
        Pow.assign(s.size() + 1, {1, 1});
        for (int i = 0; i < s.size(); i++)
        {
            hashes[i + 1] = {(1ll * hashes[i].first * BASE1 + (s[i] - 'a' + 1)) % MOD,
                             (1ll * hashes[i].second * BASE2 + (s[i] - 'a' + 1)) % MOD};
            Pow[i + 1] = {(1ll * Pow[i].first * BASE1) % MOD,
                          (1ll * Pow[i].second * BASE2) % MOD};
        }
    }
    pair<int, int> get(int l, int r)
    {
        l++, r++;
        int hash1 = (hashes[r].first - (1ll * hashes[l - 1].first * Pow[r - l + 1].first) % MOD + MOD) % MOD;
        int hash2 = (hashes[r].second - (1ll * hashes[l - 1].second * Pow[r - l + 1].second) % MOD + MOD) % MOD;
        return {hash1, hash2};
    }
};