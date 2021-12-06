#include<bits/stdc++.h>

using ll = long long;
using namespace std;

#define REP(i, n) for(ll i = 0; (i) < ll(n); (i)++)

template<class T>
bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

ll a[30][30];

ll inf = 1001001001001001001;

int main() {
    ll h, w, k;
    cin >> h >> w >> k;
    REP(i, h) REP(j, w) cin >> a[i][j];

    ll ans = inf;

    REP(x, h) {
        REP(y, w) {
            ll mn = a[x][y];
            vector<vector<vector<ll>>> dp(h, vector<vector<ll>>(w, vector<ll>(k + 2, inf)));

            if (a[0][0] >= mn) dp[0][0][1] = a[0][0];
            if (a[0][0] <= mn) dp[0][0][0] = 0;

            REP(i, h) {
                REP(j, w) {
                    REP(ki, k + 1) {
                        if (i + 1 < h) {
                            if (a[i + 1][j] >= mn) chmin(dp[i + 1][j][ki + 1], dp[i][j][ki] + a[i + 1][j]);
                            if (a[i + 1][j] <= mn) chmin(dp[i + 1][j][ki], dp[i][j][ki]);
                        }
                        if (j + 1 < w) {
                            if (a[i][j + 1] >= mn) chmin(dp[i][j + 1][ki + 1], dp[i][j][ki] + a[i][j + 1]);
                            if (a[i][j + 1] <= mn) chmin(dp[i][j + 1][ki], dp[i][j][ki]);
                        }
                    }
                }
            }

            chmin(ans, dp[h - 1][w - 1][k]);
        }
    }

    cout << ans << endl;
}