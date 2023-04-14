#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;

constexpr auto mxInt = int{ 10000 };

vi list{};
void solve(int m, vi& v) {
	if (list.size() == m) {
		for (const auto& x : list) {
			cout << x << ' ';
		}
		cout << '\n';

		return;
	}

	for (auto i = 0; i <= mxInt; ++i) {
		if (0 < v[i]) {
			list.push_back(i);
			--v[i];

			solve(m, v);

			list.pop_back();
			++v[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	auto v = vi(mxInt + 1, 0);
	for (auto i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++v[x];
	}

	list.reserve(m);
	solve(m, v);

	return 0;
}