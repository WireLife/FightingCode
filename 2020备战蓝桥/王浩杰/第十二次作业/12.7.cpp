#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;


int main() {
	int T;
	cin >> T;
	while (T--) {
		queue<int> qu;
		priority_queue<int> pq;
		int n, m, cur;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			qu.push(t);
			pq.push(t);
		}
		cur = 0;
		for (;;) {
			if (pq.top() == qu.front()) {
				if (m == cur) {
					cout << n - pq.size() + 1 << endl;
					break;
				}
				else {
					pq.pop();
					qu.pop();
					cur++;
				}
			}
			else {
				int temp = qu.front();
				qu.pop();
				qu.push(temp);
				if (m == cur) {
					m = pq.size() - 1;
					cur = 0;
				}
				else {
					cur++;
				}
			}
		}
	}
	system("pause");
	return 0;
}
