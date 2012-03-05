
#include "stdio.h"

typedef struct node 
{
	struct node *left;
	struct node *right;
	int val;
} *treeNode;

StackNode myStackNode = NULL;

//print the perimeter of a tree.

//when left or right are 1 it means we are at the corresponding perimeter.
void traverse( treeNode node, int left = 0, int right = 0)
{
	if( left == 1 )
		printf( "%d", node->val);
	else if( right == 1)
// incase we want just an arbitary print of perimeter u can add a print line here. For orderly print we need to employ this function.
// function adds values to a stack.
		addToStack(node->val);
	else if( left == 0 && right == 0 && (node->left == NULL || node->right == NULL)
	{
		printf( "%d", node->val);
	}

	if( node-> left == NULL && node -> right != NULL)
	{
		traverse(node-> right, 0, right );
	}
	else if( node -> right == NULL && node-> left != NULL )
	{
		traverse( node-> left, left, 0 );
	}
	else
	{
		traverse(node->left, left, 0);
		traverse(node->right, 0, right);
	}

	
}

int _tmain(int argc, _TCHAR* argv[])
{
	treeNode myNode; //assume some populated tree root is given here.
	traverse( myNode, 1, 0);
	traverse( myNode, 0, 1);
	// prints values in a stack.
	print_Stack();
	return 0;
}

