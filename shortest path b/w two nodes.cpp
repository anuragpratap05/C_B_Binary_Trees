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
	if (k == 0)
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

node* build_from_array(int a[], int start, int end)
{
	if (start > end)
	{
		return NULL;
	}
	int mid = (start + end) / 2;
	node* n = new node(a[mid]);

	n->left = build_from_array(a, start, mid - 1);
	n->right = build_from_array(a, mid + 1, end);
	return n;
}
node* createTreeFromTrav(int *in, int *pre, int s, int e) {
	static int i = 0;
	//Base Case
	if (s > e) {
		return NULL;
	}
	//Rec Case
	node *root = new node(pre[i]);

	int index = -1;
	for (int j = s; s <= e; j++) {
		if (in[j] == pre[i]) {
			index = j;
			break;
		}
	}

	i++;
	root->left = createTreeFromTrav(in, pre, s, index - 1);
	root->right = createTreeFromTrav(in, pre, index + 1, e);
	return root;
}

void rightview(node* root, int level , int &maxlevel)
{
	if (root == NULL)
	{
		return;
	}
	if (maxlevel < level)
	{
		cout << root->data << " ";
		maxlevel = level;
	}
	rightview(root->right, level + 1, maxlevel);
	rightview(root->left, level + 1, maxlevel);

}
int print_at_distance_k(node* root, node* target, int k)
{
	if (root == NULL)
	{
		return -1;
	}
	if (root == target)
	{
		print_kth_level(target, k);
		return 0;
	}
	int dl = print_at_distance_k(root->left, target, k);
	if (dl != -1)
	{
		if (dl + 1 == k)
		{
			cout << root->data << " ";
		}
		else
		{
			print_kth_level(root->right, k - 2 - dl);
		}
		return dl + 1;
	}
	int dr = print_at_distance_k(root->right, target, k);
	if (dr != -1)
	{
		if (dr + 1 == k)
		{
			cout << root->data << " ";
		}
		else
		{
			print_kth_level(root->left, k - 2 - dr);
		}
		return dr + 1;
	}
	return -1;
}
node* lca(node* root, int a, int b)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == a or root->data == b)
	{
		return root;
	}
	node* leftans = lca(root->left, a, b);
	node* rightans = lca(root->right, a, b);
	if (leftans != NULL and rightans != NULL)
	{
		return root;
	}
	if (leftans != NULL)
	{
		return leftans;
	}
	return rightans;
}

class sumpair
{
public:
	int maxsum;
	int branchsum;
	sumpair()
	{
		maxsum = 0;
		branchsum = 0;
	}
};
sumpair max_sum_path(node* root)
{
	sumpair p;
	if (root == NULL)
	{
		return p;
	}

	sumpair leftans = max_sum_path(root->left);
	sumpair rightans = max_sum_path(root->right);

	int op1 = root->data;
	int op2 = leftans.branchsum + root->data;
	int op3 = rightans.branchsum + root->data;
	int op4 = leftans.branchsum + rightans.branchsum + root->data;

	int cur_ans_through_root = max(op1, max(op2, max(op3, op4)));

	p.branchsum = max(leftans.branchsum, max(rightans.branchsum, 0)) + root->data;
	p.maxsum = max(leftans.maxsum, max(rightans.maxsum, cur_ans_through_root));
	return p;
}

int search(node* root, int key, int level)
{
	if (root == NULL)
	{
		return -1;
	}

	if (root->data == key)
	{
		return level;
	}

	int left = search(root->left, key, level + 1);
	if (left != -1)
	{
		return left;
	}
	return  search(root->right, key, level + 1);



}
int shortest_distance(node* root, int a, int b)
{
	node* rootnode = lca(root, a, b);
	int dl = search(rootnode, a, 0);
	int dr = search(rootnode, b, 0);
	return dl + dr;
}

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//node* root=NULL;
	node* root = buildtree();

	//print(root);
	cout << endl;
	//printin(root);
	//cout << endl;
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
	//cout << endl;
	//replacesum(root);
	//cout << endl;
	//bfs(root);
	/*Hbpair ans = isbalnce(root);
	cout << ans.height << endl;
	if (ans.balance)
	{
		cout << "balanced" << endl;
		//cout << ans.height << endl;
	}
	else
	{
		cout << "not balanced" << endl;
	}*/
	/*int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
	int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
	int n = sizeof(in) / sizeof(int);

	node*root = createTreeFromTrav(in, pre, 0, n - 1);
	bfs(root);*/
	//int maxlevel = -1;
	//rightview(root, 0, maxlevel);
	//node* target = root->left->left;
	//print_kth_level(target, 3);
	//print_at_distance_k(root, target, 3);
	//cout << lca(root, 9, 13)->data;
	//cout << max_sum_path(root).maxsum;
	cout << shortest_distance(root, 6, 14);

}
