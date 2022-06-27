#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

typedef struct tree
{
	int tree_value;
	unsigned char height;	
	struct tree* L;
	struct tree* R;
} tree;

tree *add_into_tree(int tree_value)
{
	tree *node = (tree *)malloc(sizeof(tree));
	node->tree_value = tree_value;
	node->height = 1;
	node->L = node->R = NULL;
	return node;
}

unsigned char height(tree* node)
{
	return (node) ? (node->height) : (0);
}

int balance_factor(tree* node)
{
	return height(node->R) - height(node->L);
}

void fix_height(tree* node)
{
	unsigned char hl = height(node->L);
	unsigned char hr = height(node->R);
	node->height = ((hl > hr) ? (hl) : (hr)) + 1;
}

tree* rotateright(tree* node)
{
	tree* node2 = node->L;
	node->L = node2->R;
	node2->R = node;
	fix_height(node);
	fix_height(node2);
	return node2;
}

tree* rotateleft(tree* node2)
{
	tree* node = node2->R;
	node2->R = node->L;
	node->L = node2;
	fix_height(node2);
	fix_height(node);
	return node;
}

tree* balance(tree* node)
{
	fix_height(node);
	if (balance_factor(node) == 2)
	{
		if (balance_factor(node->R) < 0){
			node->R = rotateright(node->R);
		}
		return rotateleft(node);
	}
	if (balance_factor(node) == -2)
	{
		if (balance_factor(node->L) > 0){
			node->L = rotateleft(node->L);
		}
		return rotateright(node);
	}
	return node;
}

tree* insert_into_tree(tree* node, int value)
{
	if (!node){
		return add_into_tree(value);
	}
	if (value < node->tree_value){
		node->L = insert_into_tree(node->L, value);
	}
	else{
		node->R = insert_into_tree(node->R, value);
	}
	return balance(node);
}

void tree_free(tree* node)
{
	if (node == NULL){
		return;
	}
	tree_free(node->L);
	tree_free(node->R);
	free(node);
}


int main()
{
	struct tree *node = NULL;
	int N = 0, value = 0;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &value);
		node = insert_into_tree(node, value);
	}
	printf("%d\n", height(node));
	tree_free(node);
	return 0;
}