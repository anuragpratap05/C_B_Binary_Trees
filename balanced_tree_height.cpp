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
int count(node* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int ans1 = count(root->left);
	int ans2 = count(root->right);
	return  1 + (ans1 + ans2);

}

int sum(node* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int ans1 = sum(root->left);
	int ans2 = sum(root->right);
	return  root->data + (ans1 + ans2);

}

int diameter(node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);
	int op1 = h1 + h2;
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);
	return max(max(op1, op2), op3);
}

class Pair {
public:
	int height;
	int diameter;
};

Pair fastDiameter(node*root) {
	Pair p;
	if (root == NULL) {
		p.diameter = p.height = 0;
		return p;
	}
	//Otherwise
	Pair left = fastDiameter(root->left);
	Pair right = fastDiameter(root->right);

	p.height = max(left.height, right.height) + 1;
	p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
	return p;
}

int replacesum(node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL and root->right == NULL)
	{
		return root->data;
	}

	int leftsum = replacesum(root->left);
	int rightsum = replacesum(root->right);

	int temp = root->data;
	root->data = leftsum + rightsum;
	return temp + root->data;

}

class Hbpair
{
public:
	int height;
	bool balance;
};

Hbpair isbalnce(node* root)
{
	Hbpair p;
	if (root == NULL)
	{
		p.height = 0;
		p.balance = true;
		return p;
	}
	Hbpair left = isbalnce(root->left);
	Hbpair right = isbalnce(root->right);
	p.height = max(left.height , right.height) + 1;

	if (abs(left.height - right.height) <= 1 and left.balance and right.balance)
	{
		p.balance = true;
	}
	else
	{
		p.balance = false;
	}

	return p;
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
	//bfs(root);
	//cout << count(root) << endl;
	//cout << sum(root) << endl;
	//cout << diameter(root) << endl;
	//Pair p = fastDiameter(root);
	//cout << p.height << endl;
	//cout << p.diameter << endl;
	//bfs(root);
	//replacesum(root);
	//cout << endl;
	//bfs(root);
	Hbpair ans = isbalnce(root);
	cout << ans.height << endl;
	if (ans.balance)
	{
		cout << "balanced" << endl;
		//cout << ans.height << endl;
	}
	else
	{
		cout << "not balanced" << endl;
	}

}
