#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

priority_queue<pair<int, pair<pi, pi>>, vector<pair<int, pair<pi, pi>>>, greater<pair<int, pair<pi, pi>>>> q;
int P[2010*2010];
int horizontal[2005], vertical[2005];
int A, B, N, M;


int nd(int r, int c) {
    return r * M + c;
}

int find(int x) {
    return x == P[x] ? x : P[x] = find(P[x]);
}

bool merge(int x, int y) {
    int X = find(x);
    int Y = find(y);
    if (X == Y) return false;
    P[x]=X;
    P[y]=X;
    P[Y]=X;
    return true;
}

int main() {
    setIO("fencedin");
    cin >> A >> B >> N >> M;

    vector<int> VA(N + 1), HA(M + 1);
    for (int i = 0; i < N; i++) {
        cin >> VA[i];
    }
    for (int j = 0; j < M; j++) {
        cin >> HA[j];
    }

    sort(VA.begin(), VA.end());
    for (int i = 0; i < N; i++) {
        VA[i] = VA[i + 1] - VA[i];
    }
    VA[N] = B - VA[N];

    sort(HA.begin(), HA.end());
    for (int i = 0; i < M; i++) {
        HA[i] = HA[i + 1] - HA[i];
    }
    HA[M] = A - HA[M];

    sort(VA.begin(), VA.end());
    sort(HA.begin(), HA.end());
    N++; M++;

    for (int i = 0; i < N * M; i++) {
        P[i] = i;
    }

    long long result = 0;
    for (int vi = 0, hi = 0; vi < N || hi < M; ) {
        if (hi == M || (vi < N && VA[vi] < HA[hi])) {
            for (int i = 0; i + 1 < M; i++) {
                if (merge(nd(vi, i), nd(vi, i + 1))) {
                    result += VA[vi];
                }
            }
            vi++;
        } else {
            for (int i = 0; i + 1 < N; i++) {
                if (merge(nd(i, hi), nd(i + 1, hi))) {
                    result += HA[hi];
                }
            }
            hi++;
        }
    }
    cout<<result<<endl;
    return 0;
}