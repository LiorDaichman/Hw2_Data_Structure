#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"BinaryTree.h"

/*
Home work 2
data structure
student 1:313276859
student 2 :316005347
campus beer sheva
*/

int main()
{
	srand(time(NULL));
	node* root;
	int H, num, NumToSearch;
	root = randomTree();
	H = height(root);
	printf("\n\nHeight of tree is %d\n", H);
	printf("\nLevels of Bynary Tree:\n");
	PrintLevelOrder(root);

	printf("\ntest print leaves\n");
	printLeaves(root);

	int bdika = -1;
	
	printf("\ndoes %d exsist?\n",bdika);
	//scanf_s("%d", &bdika);
	int contest=contains(root, bdika);
	printf(" tset conteains ???? %d\n", contest);

	printf("checking count nodes\n");
	int Nodecount = countNodes(root);
	printf("%d", Nodecount);
	//5
	printf("\nchacking sum of all nodes   ");
	int sumtest = sumOfKeys(root);
	printf("%d\n", sumtest);
	//6
	levelStatistics(root,H);
	

	//7
	printf("\npower %d\n", TwoPower(5));

	printf("\nPrefect tree   ");
	int tree = perfectTree(root);
	printf("%d",tree);


	printf("\nPreorder Traversal tree\n");
	pre_order_traversal(root);
	printf("\n\nIn_order Traversal tree\n");
	in_order_traversal(root);

	deleteTree(root);
	printf("\nTree deleted\n");
	printf("\nis empty ? %d", IsEmptyTree(root));
	return 0;

}