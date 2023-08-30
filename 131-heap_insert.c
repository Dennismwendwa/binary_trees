#include "binary_trees.h"

void traverse_and_insert(heap_t *root, heap_t *created);

void swap_max_heap(int *n, int *nn);

/**
 * heap_insert -  function that inserts a value in Max Binary Heap
 * @root: a double pointer to the root node of the Heap to insert the value
 * @value:  value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *created, *max_heap;

	created = malloc(sizeof(heap_t));
	if (created == NULL)
		return (NULL);

	created->n = value;
	created->parent = NULL;
	created->right = NULL;
	created->left = NULL;

	if (*root == NULL)
	{
		*root = created;
		return (created);
	}

	traverse_and_insert(*root, created);
	
	max_heap = created;
	while (max_heap->parent != NULL && max_heap->n > max_heap->parent->n)
	{
		swap_max_heap(&(max_heap->n), &(max_heap->parent->n));
		max_heap =  max_heap->parent;
	}

	return (created);

}

/**
 * traverse_and_insert - insert
 * @root: node
 * @create: node
 */
void traverse_and_insert(heap_t *root, heap_t *created)
{
	heap_t *trav[1024];
	int i = 0, j = 0;

	trav[i++] = root;
	while (i != j)
	{
		heap_t *position;

		position = trav[j++];

		if (position->left == NULL)
		{
			position->left = created;
			created->parent = position;
			break;
		}
		else
			trav[i++] = position->left;


		if (position->right == NULL)
		{
			position->right = created;
			created->parent = position;
			break;
		}
		else
			trav[i++] = position->right;
	}
}

/**
 * swap_max_heap - heapify
 * @n: node pointer to swap
 * @nn: node pointer to swap
 */
void swap_max_heap(int *n, int *nn)
{
	int move_it;

	move_it = *n;
	*n = *nn;
	*nn = move_it;
}
