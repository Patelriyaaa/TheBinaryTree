#include<iostream>
#include<string>
#include<windows.h>
#include<queue>
using namespace std;

typedef struct Node // struct node
{
	int data; // varaible for the data
	struct Node *left, *right; // left anf right node
}Node;

bool search(Node *root, int data) // boolean search
{
	if (root == NULL) // checks if the root is null or not
		return false;
	if (root->data == data) // checks if the root of the data is equals to data or not
		return true;

	queue<Node*> q;
	q.push(root); // pushes the root

	while (!q.empty())
	{
		Node *temp = q.front();
		q.pop();

		if (temp->data == data)
			return true;

		if (temp->left)  // checks for assigned left for the object's temp
			q.push(temp->left); 
		if (temp->right) // checks for assigned right for the object's temp
			q.push(temp->right);
	}
	return false;
}

Node *insert(Node *root, int data) // function for inserting
{
	if (root == NULL) // checks for root to equals to null
	{
		Node *temp = new Node(); // creates a new node
		temp->data = data;  //  assigned data for the object's temp to data
		temp->left = NULL; //  assigned left for the object's temp to null
		temp->right = NULL; // assigned right for the object's temp to null
		return temp; // returns temp
	}

	if (data < root->data) // checks if data is less then data assigned for root
		root->left = insert(root->left, data); // returns left assigned for root to new root for left

	if (data>root->data)  // checks if data is less then data assigned for root
		root->right = insert(root->right, data); // returns right assigned for root to new root for right

	return root; // return root
}

Node *getSmallestElementRightSubtree(Node *root) // function get smallest element right subtree
{
	while (root && root->left != NULL) // while loop
		root = root->left;


	return root; // return root
}

Node *delete_node(Node *root, int data) // function delete node
{

	if (root == NULL) // checks for the root to equal to null
		return root; // return root

	if (data < root->data) // checks if the data is less then data assigned to the root
		root->left = delete_node(root->left, data);

	else if (data > root->data) // checks if the data is greater then data assigned to the root
		root->right = delete_node(root->right, data);

	else
	{
		if (root->left == NULL) //If right only presents means - delete the curr node and return right node
		{
			Node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) //If left only presents means - delete the curr node and return let node
		{
			Node *temp = root->left; // puts the temp node to the left assigned to the root
			free(root);
			return temp; // returns the temp
		}
		else
		{
			Node *temp = getSmallestElementRightSubtree(root->right);
			root->data = temp->data; // puts root data to temp data
			root->right = delete_node(root->right, temp->data); // delete node of the right root and temp data
		}

		return root; // return root
	}
}


void inorder(Node *root) // inorder function
{
	if (root != NULL) // checks if the root is equal to null or not
	{
		inorder(root->left); // puts the left to assigned root

		cout << root->data << " "; // prints the data assigned to the root
		inorder(root->right); // puts the right to assigned root
	}
}


void postorder(Node *root) // function postorder
{
	if (root != NULL) // checks if the root is equal to null or not
	{
		inorder(root->left); // puts the left to assigned root
		inorder(root->right);  // puts the right to assigned root
		cout << root->data << " "; // prints the data assigned to the root
	}
}


void preorder(Node *root)
{
	if (root != NULL) // checks if the root is equal to null or not
	{ 
		cout << root->data << " "; // prints the data assigned to the root
		inorder(root->left); // puts the left to assigned root
		inorder(root->right);  // puts the right to assigned root
	}
}
int main()
{
	Node *root = NULL; // Tree Declaration
		int y;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		cout << "\n\t\t\t\t\t Enter the total Number of Input for the tree :";
		cin >> y;
		int i = 1, g;
		while (i != y + 1)
		{
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			cout << "\n\t\t\t\t\t Enter Input number " << i << " : ";
			cin >> g;
			root = insert(root, g);
			i++;
		}


	int n = 0;
	while (n != 6)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << "\n\t\t\t\t\t  _____________________________ ";
		cout << "\n\t\t\t\t\t | 1 - Insert Element          |";
		cout << "\n\t\t\t\t\t | 2 - Remove Element          |";
		cout << "\n\t\t\t\t\t | 3 - Inorder (LNR) Display   |";
		cout << "\n\t\t\t\t\t | 4 - Pre (NLR) Order Display |";
		cout << "\n\t\t\t\t\t | 5 - Post (LRN) Order Display|";
		cout << "\n\t\t\t\t\t | 6 - Quit                    |";
		cout << "\n\t\t\t\t\t |_____________________________|";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		cout << "\n\t\t\t\t\t Choose from the options : ";
		cin >> n;

		switch (n)
		{
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		case 1:
		{
			int k;
			cout << "\n\t\t\t\t\tEnter Element to insert : "; cin >> k;
			root = insert(root, k);
			cout << "\n\t\t\t\t\tElement Sucessfully Inserted !!!!!";
			break;
		}

		case 2:
		{
			int k;
			cout << "\n\t\t\t\t\tEnter Element to Remove : ";
			cin >> k;
			if (search(root, k))
			{
				root = delete_node(root, k);
				cout << "\n\t\t\t\t\tValue Successfully Deleted !!!";
			}
			else
				cout << "\n\t\t\t\t\t********** No Such Element **********";
			break;
		}


		case 3:
		{
			cout << "\n\t\t\t\t\tThe Elements (LNR) are : ";
			inorder(root);
			break;
		}

		case 4:
		{
			cout << "\n\t\t\t\t\tThe Elements (NLR) are : ";
			preorder(root);
			break;
		}
		case 5:
		{
			cout << "\n\t\t\t\t\tThe Elements (LRN) are : ";
			postorder(root);
			break;
		}
		case 6:
		{
			break;
		}
		}
	}
}