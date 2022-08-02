#include <iostream>
#include <algorithm>
using namespace std;

int segment_tree[(1 << 18)]; //segmenttree의 크기는 4*n으로 하는게 무난

int init(int node, int nodeLeft, int nodeRight) { //segment_tree의 생성

	if (nodeLeft == nodeRight)
		return segment_tree[node] = 1;

	int mid = (nodeLeft + nodeRight) / 2; 

	return segment_tree[node] = init(2 * node, nodeLeft, mid) + init(2 * node + 1, mid + 1, nodeRight);
}

int query(int node, int nodeLeft, int nodeRight, int order) // segment_tree의 번호 반환
{
	if (nodeLeft ==  nodeRight)
		return nodeLeft; // start 와 end 의 위치가 일치하면 번호를 반환한다.

	int mid = (nodeLeft + nodeRight) / 2;

	if (order <= segment_tree[2 * node])
		return query(2 * node, nodeLeft, mid, order);
	else
		return query(2 * node + 1, mid + 1, nodeRight, order - segment_tree[2 * node]);

}


int update(int index, int node, int nodeLeft, int nodeRight) { //index는 지우려는 segment_tree의 번호

	segment_tree[node]--;

	if (nodeLeft == nodeRight)
		return 0;

	int mid = (nodeLeft + nodeRight) / 2;

	if (index <= mid)
		return update(index, node * 2, nodeLeft, mid);
	else
		return update(index, node * 2 + 1, mid + 1, nodeRight);

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie();

	int pp_num, od_num;

	cin >> pp_num >> od_num;

	init(1, 1, pp_num);

	int order_index = 1;

	cout << "<";
	
	for (int i = 0; i < pp_num; i++) {
		int size = pp_num - i; //사람 수 5
		order_index = (order_index + od_num - 1) % size;

		if (order_index == 0)
			order_index = size;

		int num = query(1, 1, pp_num, order_index);

		update(num, 1, 1, pp_num);

		if (i == pp_num - 1)
			cout << num;
		else
			cout << num << ", ";
	}
	cout << ">";
}
