/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (x, y), its left and right children will be at positions (x - 1, y - 1) and (x + 1, y - 1) respectively.

The vertical order traversal of a binary tree is a list of non-empty reports for each unique x-coordinate from left to right. Each report is a list of all nodes at a given x-coordinate. The report should be primarily sorted by y-coordinate from highest y-coordinate to lowest. If any two nodes have the same y-coordinate in the report, the node with the smaller value should appear earlier.

Return the vertical order traversal of the binary tree.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation: Without loss of generality, we can assume the root node is at position (0, 0):
The node with value 9 occurs at position (-1, -1).
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2).
The node with value 20 occurs at position (1, -1).
The node with value 7 occurs at position (2, -2).
Example 2:


Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation: The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report [1,5,6], the node with value 5 comes first since 5 is smaller than 6.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 1000
*/




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void fillMap(TreeNode* root, map<int, vector<pair<int, int>>>& xNodes, int x, int y) {
        if (!root) return;
        if (xNodes[x].empty()) xNodes[x].push_back({y, root->val});
        else {
            if (xNodes[x].back().first < y)
                xNodes[x].push_back({y, root->val});
            else {
                vector<pair<int, int>> temp;
                while (!xNodes[x].empty() and (xNodes[x].back().first > y or (xNodes[x].back().first == y and xNodes[x].back().second > root->val))) {
                    temp.push_back(xNodes[x].back());
                    xNodes[x].pop_back();
                }
                xNodes[x].push_back({y, root->val});
                while (!temp.empty()) {
                    xNodes[x].push_back(temp.back());
                    temp.pop_back();
                }
            }
        }
        fillMap(root->left, xNodes, x-1, y+1);
        fillMap(root->right, xNodes, x+1, y+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> xNodes;
        fillMap(root, xNodes, 0, 0);
        vector<vector<int>> verticalOrder;
        for (auto it=xNodes.begin(); it!=xNodes.end(); ++it) {
            vector<int> each;
            for (pair<int, int>& p : it->second)
                each.push_back(p.second);
            verticalOrder.push_back(each);
        }
        return verticalOrder;
    }
};




// Concise implementation with custom sort
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    map<int, vector<pair<int, int>>> mp;
    void traverse(TreeNode* root, int x, int y) {
        if (!root) return;
        mp[x].push_back(make_pair(y, root->val));
        traverse(root->left, x-1, y+1);
        traverse(root->right, x+1, y+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root, 0, 0);
        vector<int> v;
        vector<vector<int>> ans;
        for (auto it=mp.begin(); it!=mp.end(); ++it) {
            sort(it->second.begin(), it->second.end(), [&](pair<int, int> p1, pair<int, int> p2) {
                return p1.first < p2.first or (p1.first == p2.first and p1.second < p2.second);
            });
            for (pair<int, int> p : it->second)
                v.push_back(p.second);
            ans.push_back(move(v));
        }
        return ans;
    }
};

