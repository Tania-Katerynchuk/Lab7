#include <iostream>

using namespace std;

struct Node
{
	int top;
	Node *left, *right;
};

void OutputTree(Node *&tree)
{
	if (tree != NULL&&(tree->left!=NULL||tree->right!=NULL))
	{
		cout << "\t    " << tree->top << endl;
		if (tree->left != NULL) {
			cout << "\t" << tree->left->top;
			if (tree->right != NULL)
				cout << "\t" << tree->right->top;
		}
		else {
			cout << "\t\t" << tree->right->top;
		}
		cout << endl << endl << endl;
		OutputTree(tree->left);
		OutputTree(tree->right);
	}
}

void AddNode(int top, Node *&tree)
{
	if (NULL == tree)
	{
		tree = new Node;
		tree->top = top;
		tree->left = tree->right = NULL;
	}

	if (top<tree->top)
	{
		if (tree->left != NULL) AddNode(top, tree->left);
		else
		{
			tree->left = new Node;
			tree->left->left = tree->left->right = NULL;
			tree->left->top = top;
		}
	}

	if (top>tree->top)
	{
		if (tree->right != NULL) AddNode(top, tree->right);
		else
		{
			tree->right = new Node;
			tree->right->left = tree->right->right = NULL;
			tree->right->top = top;
		}
	}

}

int main()
{
	setlocale(LC_CTYPE, "ukr");
	int nNodeTree, temp;
	cout << "����i�� �i���i��� ����i�: ";
	cin >> nNodeTree;
	Node *tree = NULL;
	for (int i = 0; i < nNodeTree; i++) {
		cout << "����� " << i+1 << " = ";
		cin >> temp;
		AddNode(temp, tree);
	}
	bool choice = true;
	while (choice) {
		OutputTree(tree);
		cout << "1 - ������ ����� �����\n0 - ���i�\n";
		cin >> choice;
		if (!choice)
			return 0;
		
		cout << "����i�� ����� �����: ";
		cin >> temp;
		cout << endl;
		AddNode(temp, tree);
		
	}
	

	system("pause");
	return 0;
}