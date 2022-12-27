#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
void dfs_rec(int src, vector<vector<int>>& grr, bool visted[]) {
		if (!visted[src]) {
			cout << src << " ";
			visted[src] = true;
		}
		for (int j = 0; j < grr[src].size(); j++) {
			if(!visted[grr[src][j]])
				dfs_rec(grr[src][j], grr, visted);
		}
}
void dfs_stack(int src, vector<vector<int>>& grr, bool visted[]) {
	cout << endl << "**************** DFS USING STACK ***************" << endl;
	stack<int> i_love_stack;
	i_love_stack.push(src);
	while (!i_love_stack.empty()) {
		if (!visted[i_love_stack.top()]) {
			cout << i_love_stack.top() << " ";
			visted[i_love_stack.top()] = true;
			int src = i_love_stack.top();
			for (int i = 0; i < grr[src].size(); i++)
				i_love_stack.push(grr[src][i]);
		}
		else
			i_love_stack.pop();
	}
}
void empt_visted(bool visted[],int n) {
	for (int i = 1; i <= n; i++)
		visted[i] = false;
}
void bfs_queue(int src, vector<vector<int>>& grr, bool visted[]) {
	cout << endl << "**************** BFS USING QUEUE ***************" << endl;
	queue<int> i_hate_queue;
	i_hate_queue.push(src);
	while (!i_hate_queue.empty()) {
		if (!visted[i_hate_queue.front()]) {
			cout << i_hate_queue.front() << " ";
			visted[i_hate_queue.front()] = true;
			for (int i = 0; i < grr[i_hate_queue.front()].size(); i++) {
				if (!visted[grr[i_hate_queue.front()][i]]) {
					i_hate_queue.push(grr[i_hate_queue.front()][i]);
				}
			}
			i_hate_queue.pop();
		}
		else
			i_hate_queue.pop();
	}
	cout << endl;
}
void print_graph(int src, vector<vector<int>>& grr,int n) {
	cout << endl << "**************** GRAPH ***************" << endl;
	for (int i = 1; i <= n; i++) {
		cout << i << " : ";
		for (int j = 0; j < grr[i].size(); j++)
			cout << grr[i][j] << " ";
		cout << endl;
	}
}

void bfs_rec(int src, vector<vector<int>>& grr, bool visted[]) {
	/*
	* for (int i = 0; i < grr[src].size(); i++) {
		if (!visted[src]) {
			visted[src] = true;
			cout << src << " ";
		}
		if (!visted[grr[src][i]]) {
			visted[grr[src][i]] = true;
			cout << grr[src][i] << " ";
		}
	}
	for (int i = 0; i < grr[src].size(); i++)
		if (!visted[grr[src][i]])
			bfs_rec(grr[src][i], grr, visted);
	*/
	cout << "hahaha just kiding go away!" << endl;
}
void print_shortest_path(int shortest_path[], int n) {
	cout << "**************** SHORTEST PATH TO ALL NODES ***************" << endl;
	for (int i = 1; i <= n; i++)
		cout << i << " : " << shortest_path[i] << endl;
	cout << endl;
}
void sho_pas(int src,int shortest_path[], vector<vector<int>>& grr,bool visited[]) {
	queue<int> q;
	q.push(src);
	shortest_path[src] = 0;
	for (int i = 0; i < grr.size(); i++)
		shortest_path[i] = 0;
	visited[src] = true;
	while (!q.empty()) {
		int src = q.front();
		q.pop();
		for (int i = 0; i < grr[src].size(); i++) {
			if (!visited[grr[src][i]]) {
				q.push(grr[src][i]);
				visited[grr[src][i]] = true;
				shortest_path[grr[src][i]] += shortest_path[src] + 1;
			}
		}
	}
}
int main() {
	int n, m, src;
	cin >> n >> m >> src;
	vector<vector<int>> grr(n+1);
	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		grr[n1].push_back(n2);
		grr[n2].push_back(n1);
	}

	bool *visted = new bool[n + 1];
	int* shortest_path = new int[n + 1];
	print_graph(src, grr, n); 
	empt_visted(visted, n);
	cout << "**************** DFS USING RECURSION ***************" << endl;
	dfs_rec(src, grr, visted);
	empt_visted(visted, n);
	dfs_stack(src, grr, visted);
	empt_visted(visted, n);
	bfs_queue(src, grr, visted);
	empt_visted(visted, n);
	cout << "**************** BFS USING RECURSION ***************" << endl;
	bfs_rec(src, grr, visted);
	empt_visted(visted, n);
	sho_pas(src, shortest_path, grr, visted);
	empt_visted(visted, n);
	print_shortest_path(shortest_path, n);
	delete[] visted, shortest_path;
}
/*
 7 7 1
 1 2
 2 4
 3 1
 3 6
 2 5
 3 7
 5 6
			 1
		  /    \
		 2      3
		/ \    / \
	   4   5  6   7


*/
