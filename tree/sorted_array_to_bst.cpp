#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> input() {
	ifstream fi;
	fi.open("sorted_array.inp");

	int n, num;
	vector<int> nums;
	
	fi >> n;
	for (int i = 0; i < n; ++i) {
		fi >> num;
		nums.push_back(num);
	}
	
	fi.close();
	return nums;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	TreeNode* root = new TreeNode(1);
	return root;
}

int main()
{
	vector<int> nums = input();
	sortedArrayToBST(nums);
}