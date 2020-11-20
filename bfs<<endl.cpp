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

int height(node* rootnode)
{
	if (rootnode == NULL)
	{
		return 0;
	}

	int ls = height(rootnode->left);
	int rs = height(rootnode->right);
	return max(ls, rs) + 1;
}

void print_kth_level(node* rootnode, int k)
{
	if (rootnode == NULL)
	{
		return;
	}
	if (k == 1)
	{
		cout << rootnode->data << " ";
		return;
	}

	print_kth_level(rootnode->left, k - 1);
	print_kth_level(rootnode->right, k - 1);
	return;
}

void print_all_levels(node* rootnode)
{
	int H = height(rootnode);
	for (int i = 1; i <= H; i++)
	{
		print_kth_level(rootnode, i);
		cout << endl;
	}
	return;
}

void bfs(node* rootnode)
{
	queue<node*> q;
	q.push(rootnode);
	q.push(NULL);
	while (!q.empty())
	{
		node* f = q.front();
		if (f == NULL)
		{
			cout << endl;
			q.pop();
			if (!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
			cout << f->data << " " ;
			q.pop();
			if (f->left)
			{
				q.push(f->left);
			}
			if (f->right)
			{
				q.push(f->right);
			}
		}
	}
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
	//printin(root);
	cout << endl;
	//printpost(root);
	//cout << height(root) << endl;
	//print_kth_level(root, 3);
	//print_all_levels(root);
	bfs(root);

}
