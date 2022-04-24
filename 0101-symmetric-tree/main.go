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
	public:
		bool isSymmetric(TreeNode* root) {
			list<TreeNode*> l;
			l.push_back(root);
			while (!l.empty()) {
				list<TreeNode*> newl;
				for (auto& e: l) {
					if (!e) continue;
					newl.push_back(e->left);
					newl.push_back(e->right);
				}
				cout << endl;
				while (!l.empty()) {
					if (l.size() == 1) break;
					if (!l.front() || !l.back()) {
						if (!l.front() && !l.back()) {
							l.pop_front();
							l.pop_back();
							continue;
						}
						return false;
					}
					if (l.front()->val != l.back()->val) {
						return false;
					}
					l.pop_front();
					l.pop_back();
				}
				l = move(newl);
			}
			return true;
		}
	};