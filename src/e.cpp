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

int inf = 1001001001;

int main() {
    int n, r;
    cin >> n >> r;
    vector<int> rs(n - 1);
    rep(i, n - 1) cin >> rs[i];
    sort(rs.rbegin(), rs.rend());

    int ans = inf;

    rep2(p, 1, n + 1) {
        // p は r が引いた数
        int ok = n;
        int ng = 0;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;

            // 判定をする
            bool flag = false;
            {
                int num = p * r;
                set<int> unused;
                rep2(pi, 1, n + 1) {
                    unused.insert((int) pi);
                }
                unused.erase(p);

                int cnt = 0;

                rep(i, n - 1) {
                    rep2(pi, 1, n + 1) {
                        if (!unused.count(pi)) continue;
                        if (rs[i] * pi < num) continue;
                        unused.erase(pi);
                        cnt++;
                        break;
                    }
                }

                if (n - 1 - cnt < mid) flag = true;
            }

            if (flag) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        chmin(ans, ok);
    }

    cout << ans << endl;
}