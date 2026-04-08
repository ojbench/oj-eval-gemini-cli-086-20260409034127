#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int left;
    int right;
};

vector<Node> tree;
vector<int> inorder_result;

void swap_nodes(int u, int depth, int k) {
    if (u == -1) return;
    if (depth % k == 0) {
        swap(tree[u].left, tree[u].right);
    }
    swap_nodes(tree[u].left, depth + 1, k);
    swap_nodes(tree[u].right, depth + 1, k);
}

void inorder(int u) {
    if (u == -1) return;
    inorder(tree[u].left);
    inorder_result.push_back(u);
    inorder(tree[u].right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    tree.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> tree[i].left >> tree[i].right;
    }
    int t;
    if (!(cin >> t)) return 0;
    for (int i = 0; i < t; ++i) {
        int k;
        cin >> k;
        swap_nodes(1, 1, k);
        inorder_result.clear();
        inorder(1);
        for (int j = 0; j < inorder_result.size(); ++j) {
            cout << inorder_result[j] << (j + 1 == inorder_result.size() ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}

