# C_B_Binary_Trees
#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;

	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildtree()
{
	int d;
	cin >> d;
	if (d == -1)
	{
		return NULL;
	}
	node* ans = new node(d);
	ans->left = buildtree();
	ans->right = buildtree();
	return ans;
}

void print(node* rootnode)
{
	if (rootnode == NULL)
	{
		return;
	}
	cout << rootnode->data << " ";
	print(rootnode->left);
	print(rootnode->right);

}
void printin(node* rootnode)
{
	if (rootnode == NULL)
	{
		return;
	}
	printin(rootnode->left);
	cout << rootnode->data << " ";
	printin(rootnode->right);

}

void printpost(node* rootnode)
{
	if (rootnode == NULL)
	{
		return;
	}
	printpost(rootnode->left);
	printpost(rootnode->right);
	cout << rootnode->data << " ";
}

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	node* root = buildtree();

	print(root);
	cout << endl;
	printin(root);
	cout << endl;
	printpost(root);

}
