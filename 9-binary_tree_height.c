#include "binary_trees.h"
/**
* binary_tree_height - Measures the height of a binary tree.* @tree: A pointer to the root node of the tree to measure the height.
*
* Return: If tree is NULL, your function must return 0, else return height.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t m = 0, f = 0;

		m = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		f = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((m > f) ? m : f);
	}
	return (0);
}
