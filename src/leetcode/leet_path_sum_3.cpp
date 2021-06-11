#if 0

/**
 * https://leetcode.com/problems/path-sum-iii/
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int count = 0;
    void find(TreeNode *root, vector<int> &sum, int target)
    {
        if (!root)
            return;

        int len = sum.size();
        int new_sum = root->val + sum[len - 1];

        sum.push_back(new_sum);
        for (int i = 0; i < len; ++i)
        {
            if ((new_sum - sum[i]) == target)
                count++;
        }

        if (root->left)
            find(root->left, sum, target);
        if (root->right)
            find(root->right, sum, target);
        sum.pop_back();
    }

    void find(TreeNode *root, unordered_map<int, int> &sum_map, int sum, int target)
    {
        if (!root)
            return;

        sum += root->val;
        sum_map[sum] += 1;

        if (sum_map.find(sum - target))
        {
            count += sum_map[sum - target];
        }

        if (root->left)
            find(root->left, sum_map, sum, target);
        if (root->right)
            find(root->right, sum_map, sum, target);
        sum.[sum] -= 1;
    }

    int pathSum(TreeNode *root, int target)
    {
        // vector<int> sum(1,0);
        unordered_map<int, int> sum;
        find(root, sum, target);
        return count;
    }
};
#endif
