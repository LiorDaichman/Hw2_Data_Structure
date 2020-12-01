#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "BinaryTree.h"

//#include "BinaryTree.h"


node* NewNode(int value)
{
	node* p = (node*)malloc(sizeof(node));
	p->data = value;
	p->left = NULL;
	p->right = NULL;
	return p;
}

node* Left(node* root)
{
	return root->left;
}

node* Right(node* root)
{
	return root->right;
}

node* randomInsertInto(node* root, int value)
{
	if (root == NULL)
		root = NewNode(value);
	else if (rand() % 2 == 0)
		root->left = randomInsertInto(root->left, value);
	else
		root->right = randomInsertInto(root->right, value);
	return root;
}

node* randomTree()
{
	node* root = NULL;
	int size = 1 + rand() % 15;
	printf("\nsize=%d\n", size);
	int i;
	for (i = 1; i <= size; i++)
		root = randomInsertInto(root, 1 +rand() % 50);
	return root;
}


void deleteTree(node* root)
{
	if (root == NULL)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
}

int height(node* root)
{
	int Lh, Rh;
	if (root == NULL)
		return -1;
	Lh = height(root->left);
	Rh = height(root->right);
	if (Lh > Rh)
		return Lh + 1;
	else
		return Rh + 1;
}
void PrintGivenLevel(node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d  ", root->data);
	else if (level > 1)
	{
		PrintGivenLevel(root->left, level - 1);
		PrintGivenLevel(root->right, level - 1);
	}
}
void PrintLevelOrder(node* root)
{
	int h = height(root);
	int i;
	for (i = 0; i <= h + 1; i++)
	{
		PrintGivenLevel(root, i);
		printf("\n");
	}
}

void pre_order_traversal(node* root)
{
	if (root != NULL)
	{
		printf("%d  ", root->data);
		pre_order_traversal(root->left);
		pre_order_traversal(root->right);
	}
}

void in_order_traversal(node* root)
{
	if (root != NULL)
	{
		in_order_traversal(root->left);
		printf("%d  ", root->data);
		in_order_traversal(root->right);
	}
}



//ex1
//function to check if the root is empty or not.
int IsEmptyTree(struct Node* root1) {

	if (root1 == NULL)//
		return 1;
	else
		return 0;


}

//ex2
//func to print all the leaves of the tree from left to right
void printLeaves(node* root2) {
	if (!IsEmptyTree(root2))
	{
		printLeaves(root2->left);
		printLeaves(root2->right);
		if (IsEmptyTree(root2->left) && IsEmptyTree(root2->right))
		printf("%d ", root2->data);
	}

}
//ex3
//function to search a specific value in the tree
int contains(node*root3, int key)
{	
	if (!root3)
		return 0;
	return (root3->data == key) || (contains(root3->left, key)) || (contains(root3->right, key));

}


//ex4
//function that count the number of nodes in the tree
int countNodes(node* root4) {
	
	if (!root4) {
		return 0;
	}
	return countNodes(root4->left) + countNodes(root4->right)+1;

}

//ex5
//function to calculate the sum of all node in the tree
int sumOfKeys(node* root5) {
	if (!root5) {
		return 0;
	}
	return sumOfKeys(root5->left) + sumOfKeys(root5->right) + root5->data;
}

//ex6
//funcion to help "levelStatistics" to count the node in the level
int countNodeInLevel(node* root6, int numlevel) {

	if (!root6)
		return 0;
	if (numlevel == 1)
		return 1;
	else if (numlevel > 1)
		return countNodeInLevel(root6->left, numlevel - 1) + countNodeInLevel(root6->right, numlevel - 1);

}

//function to count the number of node in specific level of the tree, and print them
void levelStatistics(node* root6, int level) {
	
	printf("the keys of the level %d are: ", level);
	level++;
	PrintGivenLevel(root6, level);
	int sum = countNodeInLevel(root6, level);
	printf("\n the number of all keys in this level are: %d", sum);

}
//func to clculate power of 2 in exponnent
int TwoPower(int exponent) {
	int two = 1;
	for (int i = 0; i < exponent; i++)
	{
		two = 2 * two;
	}
	return two;
}

//function to check a perfet tree by furmula (2^h) -1
int perfectTree(node* root7) {

	int furmula = TwoPower(height(root7))-1;
	if (countNodes(root7) == furmula) {
		return 1;
	}
	else
		return 0;

}