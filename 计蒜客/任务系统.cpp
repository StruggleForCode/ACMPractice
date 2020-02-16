#include <iostream>
#include <queue>
#include <string>
using namespace std;


struct Node {
	int id;
	int period;
	int time;
	Node(int _id, int _period, int _time) :id(_id), period(_period), time(_time) {}
	bool operator < (const Node b) const {
		if (time == b.time)
			return id > b.id;
		else return time > b.time;
	}
};

int main() {

	int n, k;
	cin >> n >> k;
	priority_queue<Node> que;
	while (n--) {
		string s;
		int num, period;
		cin >> s >> num >> period;
		que.push(Node(num, period, period));
	}

	while (k--) {
		Node now = que.top();
		cout << now.id << endl;
		que.pop();
		now.time += now.period;
		que.push(now);
	}

	return 0;
}