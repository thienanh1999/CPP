#include <bits/stdc++.h>
using namespace std;

struct Node {
	int value;
	Node* leftChild;
	Node* rightChild;

	Node(int value) {
		this->value = value;
		this->leftChild = nullptr;
		this->rightChild = nullptr;
	}
};

deque<int> input() {
	ifstream fi;
	fi.open("tree.inp");
	int n, node;
	deque<int> nodes;
	fi >> n;
	for (int i = 0; i < n; ++i) {
		fi >> node;
		nodes.push_back(node);
	}
	fi.close();
	return nodes;
}

Node* buildtree(deque<int>* nodes) {
	if (nodes->size() == 0) return nullptr;
	if (nodes->at(0) == -1) {
		nodes->pop_front();
		return nullptr;
	}
	Node* root = new Node(nodes->at(0));
	nodes->pop_front();
	root->leftChild = buildtree(nodes);
	root->rightChild = buildtree(nodes);
	return root;
}

//inorder: left pa right
vector<int> readtree(Node* root) {
	vector<int> result;
	stack<Node*> mynodes;
	Node* curr = root;

	while (curr != nullptr || !mynodes.empty()) {
		while (curr != nullptr) {
			mynodes.push(curr);
			curr = curr->leftChild;
		}
		curr = mynodes.top();
		mynodes.pop();
		result.push_back(curr->value);
		curr = curr->rightChild;
	}

	return result;
}

int main() 
{
	deque<int> nodes = input();
	Node* root = buildtree(&nodes);
	vector<int> result = readtree(root);
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << " ";
	}
}