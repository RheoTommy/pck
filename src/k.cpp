#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define rep(i, n) for(ll i = 0; i < (ll)n; ++i)
#define rep2(i, s, n) for(ll i = (ll)s; i < (ll)n; ++i)
#define rrep(i, n) for(ll i = (ll)n-1; i >= 0; --i)

template<class T>
bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
void vecout(const vector<T> &v, char div = '\n') {
    rep(i, v.size()) {
        if (i) cout << div;
        cout << v[i];
    }
    cout << endl;
}

ll inf = 1001001001;

int main() {
    ll n, c, a, s, w;
    cin >> n >> c >> a >> s >> w;
    vector<ll> as(n);
    vector<ll> ss(n);
    vector<ll> ws(n);
    ll sum = a + s + w;
    rep(i, n) {
        ll ai, si, wi;
        cin >> ai >> si >> wi;
        as[i] = ai + 1;
        ss[i] = si + 1;
        ws[i] = wi + 1;
    }

    vector<vector<vector<vector<ll>>>> dp(n + 1,
                                          vector<vector<vector<ll>>>(n + 1,
                                                                     vector<vector<ll>>(101,
                                                                                        vector<ll>(101, inf))));
    dp[0][0][a][s] = 0;
    rep(i, n) {
        rep(j, i + 1) {
            rep(ai, 101) {
                rep(si, 101) {
                    if (dp[i][j][ai][si] > c) continue;

                    chmin(dp[i + 1][j][ai][si], dp[i][j][ai][si]);


                    // a s で勝つ
                    {
                        ll ap = as[i];
                        ll sp = ss[i];
                        if (ap <= ai && sp <= si) chmin(dp[i + 1][j + 1][ai][si], dp[i][j][ai][si]);
                        if (ap > ai && sp > si && ap + sp <= sum)
                            chmin(dp[i + 1][j + 1][ap][sp], dp[i][j][ai][si] + ap + sp - ai - si);
                        if (ap <= ai && sp > si && ap + sp <= sum) {
                            rep(delta, sp - si + 1) {
                                if (sum - (ai - delta) >= sp && ai - delta >= ap)
                                    chmin(dp[i + 1][j + 1][ai - delta][sp], dp[i][j][ai][si] + sp - si);
                            }
                        }
                        if (ap > ai && sp <= si && ap + sp <= sum) {
                            rep(delta, ap - ai + 1) {
                                if (sum - (si - delta) >= ap && si - delta >= sp)
                                    chmin(dp[i + 1][j + 1][ap][si - delta], dp[i][j][ai][si] + ap - ai);
                            }
                        }
                    }

                    // a w で勝つ
                    rep(_, 1) {
                        ll ap = as[i];
                        ll wp = ws[i];
                        if (ai + si > sum) break;
                        ll wi = sum - ai - si;
                        if (ap <= ai && wp <= wi) chmin(dp[i + 1][j + 1][ai][si], dp[i][j][ai][si]);
                        if (ap > ai && wp > wi && ap + wp <= sum)
                            chmin(dp[i + 1][j + 1][ap][si - (ap - ai + wp - wi)], dp[i][j][ai][si] + ap - ai + wp - wi);
                        if (ap <= ai && wp > wi && ap + wp <= sum) {
                            rep(delta, wp - wi + 1) {
                                if (sum - (ai - delta) >= wp && ai - delta >= ap)
                                    chmin(dp[i + 1][j + 1][ai - delta][sum - (ai - delta + wp)],
                                          dp[i][j][ai][si] + wp - wi);
                            }
                        }
                        if (ap > ai && wp <= wi && ap + wp <= sum) {
                            rep(delta, ap - ai + 1) {
                                if (sum - (wi - delta) >= ap && wi - delta >= wp)
                                    chmin(dp[i + 1][j + 1][ap][sum - (ap + wi - delta)], dp[i][j][ai][si] + ap - ai);
                            }
                        }
                    }

                    // s w で勝つ
                    rep(_, 1) {
                        ll sp = ss[i];
                        ll wp = ws[i];
                        if (ai + si > sum) break;
                        ll wi = sum - ai - si;
                        if (sp <= si && wp <= wi) chmin(dp[i + 1][j + 1][ai][si], dp[i][j][ai][si]);
                        if (sp > si && wp > wi && sp + wp <= sum)
                            chmin(dp[i + 1][j + 1][sum - (wp + sp)][sp],
                                  dp[i][j][ai][si] + sp - si + wp - wi);
                        if (sp <= si && wp > wi && sp + wp <= sum) {
                            rep(delta, wp - wi + 1) {
                                if (sum - (si - delta) >= wp && si - delta >= sp)
                                    chmin(dp[i + 1][j + 1][sum - (si - delta + wp)][si - delta],
                                          dp[i][j][ai][si] + wp - wi);
                            }
                        }
                        if (sp > si && wp <= wi && sp + wp <= sum) {
                            rep(delta, sp - si + 1) {
                                if (sum - (wi - delta) >= sp && wi - delta >= wp)
                                    chmin(dp[i + 1][j + 1][sum - (sp + wi - delta)][sp], dp[i][j][ai][si] + sp - si);
                            }
                        }
                    }
                }
            }
        }
    }


    ll ans = -1;

    rrep(k, n + 1) {
        rep(a, 101) {
            rep(s, 101) {
                if (dp[n][k][a][s] <= c) chmax(ans, k);
            }
        }
    }

    cout << ans << endl;
}