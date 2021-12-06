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
    int h, w, n;
    cin >> h >> w >> n;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    vector<pair<int, int>> rc(n);
    rep(i, n) {
        int r, c;
        cin >> r >> c;
        r--, c--;
        rc[i] = {r, c};
    }

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(h, vector<int>(w, inf)));
    rep(k, n) {
        int r = rc[k].first;
        int c = rc[k].second;
        dp[k][r][c] = 0;
        deque<pair<int, int>> que;
        que.emplace_back(r, c);
        while (!que.empty()) {
            pair<int, int> p = que.front();
            que.pop_front();
            int i = p.first;
            int j = p.second;
            rep(t, 4) {
                int ii = i + dx[t];
                int jj = j + dy[t];

                if (ii < 0 || ii >= h || jj < 0 || jj >= w) continue;
                if (s[ii][jj] == '#') continue;
                if (s[ii][jj] == '@') {
                    if (chmin(dp[k][ii][jj], dp[k][i][j] + 1)) que.emplace_back(ii, jj);
                }
                if (s[ii][jj] == '.') {
                    if (chmin(dp[k][ii][jj], dp[k][i][j])) que.emplace_front(ii, jj);
                }
            }
        }
    }

    vector<vector<int>> mx(h, vector<int>(w, -1));
    rep(k, n) {
        rep(i, h) {
            rep(j, w) {
                chmax(mx[i][j], dp[k][i][j]);
            }
        }
    }

    int ans_i = -2;
    int ans_j = -2;
    int mn = inf;
    rep(i, h) {
        rep(j, w) {
            if (mn > mx[i][j] && s[i][j] == '.') {
                ans_i = i;
                ans_j = j;
                mn = mx[i][j];
            }
        }
    }

    cout << (ans_i + 1) << ' ' << (ans_j + 1) << endl;
}