#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a node in the binary tree
struct Node {
    int left;
    int right;
};

vector<Node> tree;
vector<int> inorder_result;

// Function to swap left and right children of nodes at depths that are multiples of k
void swap_nodes(int u, int depth, int k) {
    if (u == -1) return;
    
    // If the current depth is a multiple of k, swap the left and right children
    if (depth % k == 0) {
        swap(tree[u].left, tree[u].right);
    }
    
    // Recursively process the left and right subtrees
    swap_nodes(tree[u].left, depth + 1, k);
    swap_nodes(tree[u].right, depth + 1, k);
}

// Function to perform an in-order traversal of the tree
void inorder(int u) {
    if (u == -1) return;
    
    inorder(tree[u].left);
    inorder_result.push_back(u);
    inorder(tree[u].right);
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    // Initialize the tree with n + 1 elements (1-based indexing)
    tree.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> tree[i].left >> tree[i].right;
    }
    
    int t;
    if (!(cin >> t)) return 0;
    
    // Process each query
    for (int i = 0; i < t; ++i) {
        int k;
        cin >> k;
        
        // Perform the swap operations starting from the root (node 1) at depth 1
        swap_nodes(1, 1, k);
        
        // Get the in-order traversal of the modified tree
        inorder_result.clear();
        inorder(1);
        
        // Output the result, space-separated
        for (size_t j = 0; j < inorder_result.size(); ++j) {
            cout << inorder_result[j] << (j + 1 == inorder_result.size() ? "" : " ");
        }
        cout << "\n";
    }
    
    return 0;
}