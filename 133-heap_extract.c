#include "binary_trees.h"

/**
 * rebuild_heap - heapification
 * @root:  double pointer to the root node of heap
 */
void rebuild_heap(heap_t *root)
{
	heap_t *large_n;
	int smaller;

	if (root == NULL)
		return;

	large_n = root;

	if (root->left != NULL && root->left->n > large_n->n)
		large_n = root->left;
	if (root->right != NULL && root->right->n > large_n->n)
		large_n = root->right;

	if (large_n != root)
	{
		smaller = root->n;
		root->n = large_n->n;
		large_n->n = smaller;
		rebuild_heap(large_n);
	}
}

/**
 * heap_extract - function that extracts the root node of a Max Binary Heap
 * @root:  double pointer to the root node of heap
 * Return: 0 if function fails, extracted node on success
 */
int heap_extract(heap_t **root)
{
	int saved_data;
	heap_t *trav, *before_last_right_node = NULL;

	if ((*root) == NULL)
		return (0);

	saved_data = (*root)->n;
	trav = *root;
	while (trav->right != NULL)
	{
		before_last_right_node = trav;
		trav = trav->right;
	}
	/*free the rightmost node that has replaced the root*/
	if (before_last_right_node != NULL)
	{
		if (before_last_right_node->left == trav)
			before_last_right_node->left = NULL;
		else
			before_last_right_node->right = NULL;
	}
	else
		(*root) = NULL;

	if (trav != (*root))
		(*root)->n = trav->n;
	free(trav);
	rebuild_heap(*root);
	return (saved_data);
}
