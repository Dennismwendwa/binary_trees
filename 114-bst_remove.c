#include "binary_trees.h"

static bst_t *bst_looksmall(bst_t *head);


/**
 * bst_remove - function that removes nodes
 * @root:- pointer to the root of the node
 * @value:- value of node to remove
 * Return:- Always 0
 */

bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (root->right == NULL)
		{
			bst_t *tmp = root->left;
			free(root);
			return (tmp);
		}

		bst_t *tmp = bst_looksmall(root->right);
		root->n = tmp->n;
		root->right = bst_remove(root->right, tmp->n);
	}

	return (root);

}



/**
 * bst_looksmall - function that search for the smallest value
 * @head:- pointer to the node to start searching from
 * Return:- Always 0
 */

static bst_t *bst_looksmall(bst_t *head)
{
	while (head->left != NULL)
	{
		head = head->left;
	}

	return (head);
}
