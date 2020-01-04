#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <cstring>
using namespace std;

struct Node {
	Node *left, *right;
	int l, r;
	int id;
};

Node *build(int l, int r, int id = -1)
{
	Node *root = new Node;
	root->left = root->right = NULL;
	root->l = l;
	root->r = r;
	root->id = id;
	if (root->l < root->r) {
		int mid = (l + r) / 2;
		root->left = build(l, mid, id);
		root->right = build(mid + 1, r, id);
	}
	return root;
}

void add(Node *root, int l, int r, int id)
{
	if (root == NULL)
		return;
	if (l <= root->l && r >= root->r) {
		root->id = id;
		return;
	}
	if (l > root->r || r < root->l)
		return;
	if (root->id != -1) {
		root->left->id = root->id;
		root->right->id = root->id;
	}
	root->id = -1;
	add(root->left, l, r, id);
	add(root->right, l, r, id);
	return;
}

int ls[10000], rs[10000], lrs[20000];
set<int> s;
void cnt(Node *root)
{
	if (root == NULL)
		return;
	if (root->id != -1) {
		if (s.find(root->id) == s.end())
			s.insert(root->id);
		return;
	}
	cnt(root->left);
	cnt(root->right);
	return;
}

int main()
{
	int k;
	cin >> k;
	while (k--) {
		int t;
		cin >> t;
		for (int i = 0; i < t; ++i)
			cin >> ls[i] >> rs[i];
		memcpy(lrs, ls, t * sizeof(int));
		memcpy(lrs + t, rs, t * sizeof(int));
		sort(lrs, lrs + 2 * t);
		map<int, int> m;
		for (int i = 0; i < 2 * t; ++i)
			m[lrs[i]] = i;
		Node *root = build(0, 2 * t - 1);
		for (int i = 0; i < t; ++i)
			add(root, m[ls[i]], m[rs[i]] - 1, i);
		s.clear();
		cnt(root);
		cout << s.size() << endl;
	}
	return 0;
}