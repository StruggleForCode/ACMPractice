#include<iostream>
#include<queue>
#include <algorithm>
#define Max 50000 + 5
using namespace std;

int A[Max], B[Max];

struct Node {
	int x, y, sum;
	bool operator <(const  Node b) const {
		return sum > b.sum;
	}
};

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int j = 0; j < n; j++) {
		cin >> B[j];
	}
	sort(A, A + n);
	sort(B, B + n);
	priority_queue<Node> que;
	for (int i = 0; i < n; i++) {
		Node node;
		node.x = i;
		node.y = 0;
		node.sum = A[node.x] + B[node.y];
		que.push(node);
	}

	for (int i = 0; i < n; i++) {
		cout << que.top().sum << (i == n - 1 ? '\n' : ' ');
		Node node;
		node.y = que.top().y + 1;
		node.x = que.top().x;
		node.sum = A[node.x] + B[node.y];
		que.pop();
		que.push(node);
	}
	return 0;
	
}