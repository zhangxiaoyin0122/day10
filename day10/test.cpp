#include <iosteream>
using namespace std;

class Solution {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k) {
		if (pRoot == nullptr || k <= 0)
			return nullptr;
		stack<TreeNode*> st; //定义一个栈,利用栈实现中序遍历
		TreeNode* cur = pRoot;
		//当栈不为空或根节点存在
		while (cur || !st.empty()) {
			//左节点全部入栈
			while (cur) {
				st.push(cur);
				cur = cur->left;
			}
			TreeNode* node = st.top();
			st.pop();
			k--;
			if (k == 0)
				return node;
			cur = node->right;
		}
		return nullptr;
	}
};

class Solution {
public:
	void LeftRotateStringHelper(string& str) {
		char temp = str[0];
		for (int i = 0; i < str.size() - 1; i++) {
			str[i] = str[i + 1];
		}
		str[str.size() - 1] = temp;
	}
	string LeftRotateString(string str, int n) {
		if (str.size() == 0 || n == 0)
			return str;
		int step = n % str.size();
		while (step--)
			LeftRotateStringHelper(str);
		return str;
	}
};
class Solution {
public:
	void reverse(string& str, int start, int end) {
		while (start < end) {
			char temp = str[start];
			str[start] = str[end];
			str[end] = temp;
			start++;
			end--;
		}
	}
	string LeftRotateString(string str, int n) {
		if (str.length() == 0 || n == 0)
			return str;
		int step = n % str.size();
		reverse(str, 0, step - 1); //逆置前半部分
		reverse(str, step, str.size() - 1); //逆置后半部分
		reverse(str, 0, str.size() - 1); //整体逆置
		return str;
	}
};

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > result;
		if (pRoot == nullptr)
			return result;
		stack<TreeNode*> st; //保存要遍历的节点
		queue<TreeNode*> q; //辅助队列
		st.push(pRoot);
		int dir = 1; //dir == 1,left->right;dir == 2,right->left
		while (!st.empty()) {
			vector<int> v;
			int size = st.size();
			for (int i = 0; i < size; i++) {
				TreeNode* node = st.top();
				v.push_back(node->val);
				st.pop();
				TreeNode* first = (dir == 1) ? node->left : node->right;
				TreeNode* second = (dir == 1) ? node->right : node->left;
				if (first)
					q.push(first);
				if (second)
					q.push(second);
			}
			result.push_back(v);
			//下一轮节点入栈进行逆序
			while (!q.empty()) {
				st.push(q.front());
				q.pop();
			}
			dir = (dir == 1) ? 2 : 1;
		}
		return result;
	}
};