#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define rep(i, n) for(ll i = 0; i < (ll)n; ++i)
#define rep2(i, s, n) for(ll i = (ll)s; i < (ll)n; ++i)
#define rrep(i, n) for(ll i = (ll)n-1; i >= 0; --i)


int main() {
    string s;
    cin >> s;

    set<string> st;
    sort(s.begin(), s.end());
    do {
        st.insert(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << st.size() << endl;
}
