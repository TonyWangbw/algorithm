#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int maxn = 1e6 + 2;
typedef long long ll;
ll p;
ll disx[maxn], disy[maxn]; 
bool vis[maxn];
int n=0;
int x[100];
int cv=0;
int cw=0;
int w[100];
int bestp=0;
int bestx[100];
int c=0;
int v[100];

struct node {
    ll v, k;
};

void backtrack(int k)
{
   if(k>n){
     if(cv>bestp){
        bestp = cv;
        for(int i=1; i<=n; i++)
            bestx[i] = x[i];
        }
    }
   else{
     for(int i=0; i<=1; i++){
        x[k]=i;
        if(i==0){
            backtrack(k+1);
        }
        else{
           if((cw+w[k])<=c){
             cw += w[k];
             cv += v[k];
             backtrack(k+1);
             cw -= w[k];
             cv -= v[k];
           }
        }
     }
  }
}
 

int bfs(ll x, ll y) {
    queue<node> q;
    q.push({x, 0});
    memset(vis, false, sizeof(vis));
    vis[x] = true;

    while (!q.empty()) {
        ll v = q.front().v;
        ll k = q.front().k;
        disx[v] = k;
        if (v == y) break;
        q.pop();
        if (!vis[(v + 2) % p]) {
            vis[(v + 2) % p] = true;
            q.push({(v + 2) % p, k + 1});
        }
        if (!vis[v * 2 % p]) {
            vis[v * 2 % p] = true;
            q.push({v * 2 % p, k + 1});
        }
        ll t;
        t = v * v % p;
        if (!vis[t]) {
            vis[t] = true;
            q.push({t, k + 1});
        }
    }

    memset(vis, false, sizeof(vis));
    while (!q.empty()) q.pop();
    q.push({y, 0});
    vis[y] = true;

    while (!q.empty()) {
        ll v = q.front().v;
        ll k = q.front().k;
        disy[v] = k;
        if (v == x) break;
        q.pop();
        if (!vis[(v + 2) % p]) {
            vis[(v + 2) % p] = true;
            q.push({(v + 2) % p, k + 1});
        }
        if (!vis[v * 2 % p]) {
            vis[v * 2 % p] = true;
            q.push({v * 2 % p, k + 1});
        }
        ll t;
        t = 1LL * v * v % p;
        if (!vis[t]) {
            vis[t] = true;
            q.push({t, k + 1});
        }
    }
    ll ans = INT_MAX;
    for (int i = 1; i < p; i++)
        if (disx[i] >= 0 && disy[i] >= 0) ans = min(ans, disx[i] + disy[i]);

    return ans;
}

int main() {
    memset(disx, -1, sizeof(disx));
    memset(disy, -1, sizeof(disy));

    ll x, y;
    cin >> x >> y >> p;
	backtrack(10); 
    cout << bfs(x, y) << endl;
    system("pause");
    return 0;
}


