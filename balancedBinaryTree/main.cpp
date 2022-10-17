//
//  main.cpp
//  balancedBinaryTree
//
//  Created by Shrikrishna Bhat on 10/16/22.
//

#include <iostream>
using namespace std;

class Node {
public:
	int data;
	int rcount,lcount;
	Node *left;
	Node *right;
	
	~Node()
	{
		cout << "Tree Object Deleted " << endl;
	}
};

bool isPBT(int count);
Node* newNode(int data);
Node* insert(Node* root,int data);
void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);

int main(int argc, const char * argv[]) {
	// insert code here...
	//std::cout << "Hello, World!\n";
	
	int size;
	cout << "Enter the size of the Array " << endl;
	cin >> size;
	
	int array[size];
	Node *root = NULL;
	
	for(int i=0;i<size;i++){
		cout << "Enter " << i << "th elements to insert in the tree " << endl;
		cin >> array[i];
	}
	
	for(int i=0;i<size;i++){
		root = insert(root,array[i]);
	}
	
	
	cout << "Preorder Traversal " << endl;
	preorder(root);
	cout << endl;
	
	cout << "Inorder Traversal " << endl;
	inorder(root);
	cout << endl;
	
	cout << "Postorder Traversal " << endl;
	postorder(root);
	cout << endl;
	
	delete root;
	return 0;
}

bool isPBT(int count)
{
	count = count + 1;
	
	while(count % 2 == 0)
		count = count / 2;
	
	if(count == 1)
		return true;
	else
		return false;
}

Node *newNode(int data)
{
	Node* temp = new Node();
	
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	temp->rcount = 0;
	temp->lcount = 0;
	
	return temp;
}

Node *insert(Node *root,int data)
{
	if(root == NULL){
		Node *n = newNode(data);
		return n;
	}
	
	if(root->rcount == root->lcount){
		root->left = insert(root->left, data);
		root->lcount ++;
	}
	
	else if (root->rcount < root->lcount){
		
		if(isPBT(root->lcount)){
			root->right = insert(root->right, data);
			root->rcount ++;
		}
		else{
			root->left = insert(root->left, data);
			root->lcount ++;
		}
	}
	return root;
}

void inorder(Node *root)
{
	if(root != NULL){
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

void preorder(Node *root)
{
	if(root){
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Node *root)
{
	if(root){
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
}
