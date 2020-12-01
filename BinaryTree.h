#ifndef _BINARY_TREE
#define _BINARY_TREE

typedef struct Node node;
struct Node {
	int data;
	node* left;
	node* right;
};

node* NewNode(int);
node* Left(node*);
node* Right(node*);
node* randomInsertInto(node*, int);
node* randomTree();
void deleteTree(node*);
int height(node*);
void PrintGivenLevel(node*, int);
void PrintLevelOrder(node*);
void pre_order_traversal(node*);
void in_order_traversal(node*);
//ex1
int IsEmptyTree(node*);
//ex2
void printLeaves(node*);
//ex3
int contains(node*, int);
//ex4
int countNodes(node*);
//ex5
int sumOfKeys(node*);
//ex6
int countNodeInLevel(node*, int);
void levelStatistics(node*, int);
//ex7
int TwoPower(int div);
int perfectTree(node*);

#endif
