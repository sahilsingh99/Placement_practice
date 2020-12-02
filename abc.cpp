// nhi btane ka h bhidu
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define pb(i) push_back(i)
#define f first
#define s second
#define mk(l,r) make_pair(l,r)
#define vi vector<int>
#define vl vector<ll>
#define vch vector<char>
#define all(vc) vc.begin(),vc.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ms(i,j) memset(i,j,sizeof i)
#define w(t) while(t--)
#define len(s) s.length()
#define rall(i,a) for(auto i : a)
#define rep(i,n) for(ll i=0;i<(n);++i)
#define repp(i,n,j) for (ll i=j;i<(n);i++)
#define repa(i,n) for(ll i=n;i>=0;i--)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define PI 3.14159265358979323846
#define el cout<<endl;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
const ll MAX=2e5+10;
const ll INF=2e18;

#define INPUT_OUTPUT {\
    freopen("input.txt","r",stdin);\
    freopen("output.txt","w",stdout);\
}
int res[MAX];
int timer = 0;
int low[MAX];
int tim[MAX];
bool vis[MAX];

void reset() {
    ms(res,0);
    timer = 0;
    ms(low,-1);
    ms(tim,-1);
    ms(vis,false);
}

void dfs(int u, vector<int> gp[], int p = -1) {
    int children = 0;
    vis[u] = true;
    tim[u] = low[u] = timer++;
    for(int v : gp[u]) {
        if(v == p) continue;
        if(vis[v]) low[u] = min(low[u], tim[v]);
        else {
            dfs(v,gp,u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= tim[u] and p != -1) res[u] = 1;
            children++;
        }
    }
    if(p == -1 and children > 1) res[0] = 1;
}

void printAns() {
    int ans = 0;
    for(int u : res) 
        if(u) ans++;
    cout<<ans<<endl;
}

void solve2(int n, int m) {
    vector<int> gp[n + 1];
    for(int i = 0; i < m ; i++) {
        int u,v;
        cin>>u>>v;
        gp[u].pb(v);
        gp[v].pb(u);
    }
    reset();
    dfs(1,gp);
    printAns();
}


// logical code of program starts here.
void solve() {
    while(1) {
        int n, m ;
        cin>>n>>m;
        if(!n and !m ) break;
        else solve2(n,m);
    } 
}


// mian function 
int main() {

    #ifndef ONLINE_JUDGE
    INPUT_OUTPUT;//file handling
    #endif
    fastIO;// fast input output
    clock_t start, end; 
    start = clock();
    int t;
    t=1;
    //cin>>t;
    w(t) solve();
    end = clock();   
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC); 
    clog << "Time taken by program is : " << fixed 
    << time_taken << setprecision(5); 
    clog << " sec " << endl;
    return 0;
}