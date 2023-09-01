#include "binary_trees.h"
/**
* binary_tree_size - Measures the size of a binary tree.
* @tree: A pointer to the root node of the tree to measure the size of.
*
* Return: The size of the tree.
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t si_ze = 0;

	if (tree)
	{
		si_ze += 1;
		si_ze += binary_tree_size(tree->left);
		si_ze += binary_tree_size(tree->right);
	}
	return (si_ze);
}
