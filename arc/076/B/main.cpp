#include <bits/stdc++.h>
using namespace std;

// {{{

// clang-format off
#define rep(i, n) for (int i = 0; i < (int)(n); i += 1)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; i -= 1)
#define range(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1 )
#define rrange(i, l, r) for ( int i = (int)(r)-1; i >= (int)(l); (i) -= 1 )
#define debug(...) debug_func(#__VA_ARGS__, __VA_ARGS__)
template <typename T, typename... T2> void debug_func(string_view name, const T &a, T2 &&...rest) { stack<char> bs; string_view lbs = "({[<"; string_view rbs = ")}]>"; int end = name.size(); for ( int i = 0; i < (int)name.size(); i++ ) { if ( lbs.find(name[i]) != string::npos ) { bs.push(name[i]); } if ( rbs.find(name[i]) != string::npos ) { if ( !bs.empty() ) { bs.pop(); } } if ( name[i] == ',' && bs.empty() ) { end = i; break; } } cerr << name.substr(0, end) << ":" << a; if constexpr ( sizeof...(rest) == 0 ) { cerr << endl; } else { cerr << ' '; debug_func(name.substr(name.find_first_not_of(' ', end + 1)), forward<T2>(rest)...); } }
template <typename T> vector<T> make_vector(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a, make_vector(ts...)); }
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << p.first << ' ' << p.second; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { for ( pair<T1, T2> x : v ) { os << x << "\n"; } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> v) { if(!v.empty()) { os << v.front(); v.pop(); } while (!v.empty()) { os << " " << v.front(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> v) { if(!v.empty()) { os << v.top(); v.pop(); } while (!v.empty()) { os << " " << v.top(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T> void operator+=(vector<T> &vs, T x) { for ( T &v : vs ) v += x; }
template <typename T> void operator-=(vector<T> &vs, T x) { for ( T &v : vs ) v -= x; }
template <typename T> void operator*=(vector<T> &vs, T x) { for ( T &v : vs ) v *= x; }
template <typename T> void operator/=(vector<T> &vs, T x) { for ( T &v : vs ) v /= x; }
template <typename T> void operator%=(vector<T> &vs, T x) { for ( T &v : vs ) v %= x; }
template <typename T> vector<T> operator+(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v += x; return res; }
template <typename T> vector<T> operator-(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v -= x; return res; }
template <typename T> vector<T> operator*(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v *= x; return res; }
template <typename T> vector<T> operator/(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v /= x; return res; }
template <typename T> vector<T> operator%(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v %= x; return res; }
using ull = unsigned long long;
using ll = long long;
using Pll = pair<ll, ll>;
using P = pair<int, int>;
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr int dy[] = { 0, -1, 1, 0, -1, 1, -1, 1 };
constexpr int dx[] = { -1, 0, 0, 1, -1, -1, 1, 1 };
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = (int)1e9 + 7;
constexpr char newl = '\n';
// clang-format on

// }}}


struct union_find {
	int cnt;
	vector<int> siz, par;
	union_find(int N) : cnt(N), siz(N, 1), par(N) {
		iota(par.begin(), par.end(), 0);
	}

	int root(int x) {
		if ( x == par[x] ) return x;
		return par[x] = root(par[x]);
	}

	int group_count() { return cnt; }

	int size(int x) { return siz[root(x)]; }

	bool same(int x, int y) { return root(x) == root(y); }

	void merge(int x, int y) {
		x = root(x);
		y = root(y);
		if ( x == y ) return;
		if ( siz[x] < siz[y] ) swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
		cnt--;
	}

	// Θ(NlogN)
	// 2つのunion_findでi番目の頂点と同じ連結成分であるものの個数(i番目の頂点を含む)
	vector<int> connect_count(union_find tree) {
		map<pair<int, int>, int> mp;

		int N = par.size();
		for ( int i = 0; i < N; i++ ) {
			pair<int, int> p = make_pair(root(i), tree.root(i));
			mp[p]++;
		}

		vector<int> res(N);
		for ( int i = 0; i < N; i++ ) {
			pair<int, int> p = make_pair(root(i), tree.root(i));
			res[i] = mp[p];
		}
		return res;
	}
};


int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin>>n;
	vector<P> xs(n),ys(n);
	rep(i,n){
		auto &[x,x_i]=xs[i];
		auto &[y,y_i]=ys[i];
		cin>>x>>y;
		x_i=y_i=i;
	}

	sort(xs.begin(),xs.end());
	sort(ys.begin(),ys.end());

	vector<pair<int,P>> edges;

	range(i,1,n){
		auto [px,px_i]=xs[i-1];
		auto [x,x_i]=xs[i];
		edges.emplace_back(abs(px-x),make_pair(px_i,x_i));
	}
	range(i,1,n){
		auto [py,py_i]=ys[i-1];
		auto [y,y_i]=ys[i];
		edges.emplace_back(abs(py-y),make_pair(py_i,y_i));
	}

	union_find uf(n);
	sort(edges.begin(),edges.end());
	ll ans=0;
	for(auto [cost, edge]:edges){
		auto [from,to]=edge;
		if(uf.same(from,to)) continue;
		uf.merge(from,to);
		ans+=cost;
	}
	cout<<ans<<endl;
}