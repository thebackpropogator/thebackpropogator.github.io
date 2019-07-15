#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
    /* Basic types */
    typedef long long           ll;
    typedef long double         ld;
    typedef unsigned long long ull;
    /* STL containers */
    typedef vector <int>    vi;
    typedef vector <ll>     vll;
    typedef pair <int, int> pii;
    typedef pair <ll, ll>   pll;
    typedef vector < pii >  vpii;
    typedef vector < pll >  vpll;
    typedef vector <string> vs;
    typedef vector < vi >   vvi;
    typedef vector < vll >  vvll;
    typedef vector < vpii > vvpii;
    typedef set <int>       si;
/* Macros */
    /* Loops */
    #define fl(i, a, b)     for(ll i = (a); i < (b); i ++)
    #define fll(i,n)        fl(i,0,n)
    #define rep(i, n)       fl(i, 1, (n))
    #define loop(i, n)      fl(i, 0, (n) - 1)
    #define rfl(i, a, b)    for(int i(a); i >= (b); i --)
    #define rrep(i, n)      rfl(i, (n), 1)
    /* Algorithmic functions */
    #define srt(v)          sort((v).begin(), (v).end())
    #define rsrt(v)         sort((v).begin(), (v).end(),greater<int>())
    #define rem_duplicate(v) (v).erase(unique((v).begin(), (v).end()), (v).end()) 
    /* STL container methods */
    #define pb              push_back
    #define mp              make_pair
    #define eb              emplace_back
    /* String methods */
    #define dig(i)          (s[i] - '0')
    #define slen(s)         s.length()
    /* Shorthand notations */
    #define fr              first
    #define sc              second
    #define re              return 
    #define sz(x)           ((int) (x).size())
    #define all(x)          (x).begin(), (x).end()
    #define sqr(x)          ((x) * (x))
    #define fill(x, y)      memset(x, y, sizeof(x))
    #define clr(a)          fill(a, 0)
    #define endl            '\n'
    /* Mathematical */
    #define IINF            0x3f3f3f3f
    #define LLINF           1000111000111000111LL
    #define PI              3.14159265358979323
    /* Debugging purpose */
    #define trace1(x)                cerr << #x << ": " << x << endl
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
    /* Fast Input Output */
    #define high_functioning_sociopath                  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
/* Constants */
    const ll MOD = 1000000007LL;
    const ll MAX = 100010LL;
/* Templates */

template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; x %= m; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }

void Sieve(int n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          cout << p << " "; 
} 

ll n, m;
vll v(131075);
vll t(4*131075);

void build(ll node, ll tl, ll tr){
    if(tl == tr){
        t[node] = v[tl];
    }else{
        ll tm = (tl+tr)/2;
        build(node*2,tl,tm);
        build(node*2+1,tm+1,tr);
        ll ht = n - (ll)log2(node);
        if(ht%2) t[node] = t[node*2] | t[node*2+1];
        else t[node] = t[node*2] ^ t[node*2+1];
    }
}

void update(ll node, ll tl, ll tr, ll pos, ll val){
    if(tl == tr){
        t[node] = val;
    }else{
        ll tm = (tl+tr)/2;
        if(pos <= tm){
            update(node*2,tl,tm,pos,val);
        }else{
            update(node*2+1,tm+1,tr,pos,val);
        }
        ll ht = n - (ll)log2(node);
        if(ht%2) t[node] = t[node*2] | t[node*2+1];
        else t[node] = t[node*2] ^ t[node*2+1];
    }
}



int main(){

    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif*/

    high_functioning_sociopath;    
    cin>>n>>m;
    fl(i,0,(ll)(pow(2,n))) cin>>v[i];
    //fl(i,0,(ll)(pow(2,n))) cout<<v[i]<<" ";
    //cout<<"\n";
    //cout<<(ll)(pow(2,n))-1<<"\n";
    build(1,0,(ll)(pow(2,n))-1);
    fll(i,m){
        ll x, y;
        cin>>x>>y;
        //fll(i,(ll)(pow(2,n+1))+1) cout<<t[i]<<" ";
        //cout<<"\n";
        update(1,0,(ll)(pow(2,n))-1,x-1,y);
        cout<<t[1]<<"\n";
    }

    

    return 0;
}
