#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for(ll i = 0; (i) < ll(n); (i)++);

// [0..sqrt(R)), [L..R) の篩を返す
pair<vector<ll>, vector<ll>> sieve(ll l, ll r) {
    ll n = sqrt(r) + 1;
    vector<ll> aux(n, -1);
    vector<ll> res(r - l, -1);
    for (ll i = 2; i * i < n; i++) {
        if (aux[i] != -1) continue;
        for (ll j = i * i; j < n; j += i) aux[j] = i;

        ll start = (l + i - 1) / i * i;
        if (start == i) start *= 2;
        for (ll p = start; p < r; p += i) res[p] = i;
    }
    return {aux, res};
}

int main() {
    ll n, k;
    cin >> n >> k;
    auto[aux, res] = sieve(n - k, n + 1);
}