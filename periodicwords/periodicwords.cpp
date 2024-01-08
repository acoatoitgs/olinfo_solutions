#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

int N;
string S;
int Q;

vector<long long> prefix;
const long long coeff = 0x3f4f5f6f;
const long long mod = 1000000007;
vector<vector<int>> divs;
vector<long long> basePower;


void precompute()
{
    prefix.resize(N);
    divs.resize(N+1);
    basePower.resize(N);

    long long tmp_coeff = coeff;
    prefix[0] = (long long)(S[0]-'a'+1);
    basePower[0] = 1;

    for(int i = 1; i < N; i++)
    {
        basePower[i] = tmp_coeff;
        prefix[i] = (prefix[i-1] + (long long)(S[i]-'a'+1) * tmp_coeff)%mod;
        tmp_coeff = (tmp_coeff * coeff)%mod;
    }
    
    //Sieve
    for (int i = 1; i <= N/2; ++i) {
        for (int j = 2 * i; j <= N; j += i) {
        divs[j].emplace_back(i);
    }
}
}

inline long long stringHash(int l, int r)
{
    if(l == 0) return prefix[r];
    
    return (prefix[r]-prefix[l-1]+mod)%mod;
}

inline bool compareHash(int l1,int r1, int l2, int r2)
{
    int div = r1-r2;
    
    long long fHash = stringHash(l1, r1);
    long long sHash = stringHash(l2, r2);
    
    if((sHash*basePower[div])%mod == fHash) return true;

    return false;
}

inline string solve(int l, int r)
{
    int lenght = r-l+1;
    for(auto div : divs[lenght])
    {
        if(compareHash(l+div, r, l, r-div))
        {
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    cin >> N >> S >> Q;
    precompute();

    int l,r;
    for(int i = 0; i < Q; i++)
    {
        cin >> l >> r;
        cout <<  solve(l, r) << "\n";
        
    }
}