#include "binary_trees.h"
/**
* enqueue_item_3 - Adds an item to a queue.
* @queue_h: A pointer to the queue's head.
* @queue_t: A pointer to the queue's tail.* @n: A pointer to the queue's size value.
* @item: The item to add to the queue.
*/
void enqueue_item_3(heap_t **queue_h, heap_t **queue_t, int *n, void *item)
{
	heap_t *new_node;
	heap_t *node = (heap_t *)item;

	if ((queue_h != NULL) && (queue_t != NULL))
	{
		new_node = malloc(sizeof(heap_t));
		if (new_node == NULL)
			return;
		new_node->left = *queue_t;
		new_node->right = NULL;
		new_node->n = (node != NULL ? node->n : -1);
		new_node->parent = node;
		if (*queue_h == NULL)
			*queue_h = new_node;
		if (*queue_t != NULL)
			(*queue_t)->right = new_node;
		*queue_t = new_node;
		if (n != NULL)
			(*n)++;
	}
}
/**
* dequeue_item_3 - Removes an item from a queue.
* @queue_h: A pointer to the queue's head.
* @queue_t: A pointer to the queue's tail.
* @n: A pointer to the queue's size value.
*
* Return: The value of the removed queue.
*/
heap_t *dequeue_item_3(heap_t **queue_h, heap_t **queue_t, int *n)
{
	heap_t *tmp_0;
	heap_t *tmp_1;
	heap_t *node = NULL;

	if ((queue_h != NULL) && (queue_t != NULL))
	{
		tmp_0 = *queue_h;
		if (tmp_0 != NULL)
		{
			node = tmp_0->parent;
			if (tmp_0->right != NULL)
			{
				tmp_1 = tmp_0->right;
				tmp_1->left = NULL;
				*queue_h = tmp_1;
				free(tmp_0);
			}
			else
			{
				free(tmp_0);
				*queue_h = NULL;
				*queue_t = NULL;
			}
			if (n != NULL)
				(*n)--;
		}
	}

	return (node);
}
/**
* get_insert_position - Gets the next available insertion position \
* for a node in a max binary heap tree.
* @root: The root of the max binary heap tree.
*
* Return: The insertion position, otherwise NULL.
*/
heap_t *get_insert_position(const heap_t *root)
{
	heap_t *head = NULL, *tail = NULL;
	heap_t *parent_node = NULL, *current = NULL;
	int n = 0;

	if (root != NULL)
	{
		enqueue_item_3(&head, &tail, &n, (void *)root);
		while (n > 0)
		{
			current = head;
			if (current->parent != NULL)
			{
				if (current->parent->left != NULL)
				{
					enqueue_item_3(&head, &tail, &n, (void *)(current->parent->left));
				if (current->parent->right != NULL)
				{
					enqueue_item_3(&head, &tail, &n, (void *)(current->parent->right));
				}
				else
				{
					parent_node = current->parent;
					break;
				}
			}
			else
			{
				parent_node = current->parent;
				break;
			}
			}
		dequeue_item_3(&head, &tail, &n);
		}
	while (n > 0)
		dequeue_item_3(&head, &tail, &n);
		}
	return (parent_node);
}
/**
* swap_tree_node_with_parent - Swaps a node in a \
* max binary heap tree with its parent.
* @node: A pointer to the node's address.
* @root: A pointer to the root of the tree.
*/
void swap_tree_node_with_parent(heap_t **node, heap_t **root)
{
	heap_t *node_cpy, *k, *tmp_0, *n, *r;

	if ((node != NULL) && ((*node)->parent != NULL) && (root != NULL))
	{
		k = (*node)->parent, node_cpy = *node, tmp_0 = (*node)->parent->parent;
		n = (*node)->left, r = (*node)->right;
		if ((*node)->parent->left != *node) /* swap from the right */
		{
			if ((tmp_0 != NULL) && (tmp_0->left == (*node)->parent))
				tmp_0->left = *node;
			if ((tmp_0 != NULL) && (tmp_0->right == (*node)->parent))
				tmp_0->right = *node;
			if ((*node)->parent->left != NULL)
				(*node)->parent->left->parent = node_cpy;
			(*node)->parent = tmp_0, (*node)->left = p->left, (*node)->right = k;
			k->parent = node_cpy, k->left = n, k->right = r;
		}
		else /* swap from the left */
		{
			if ((tmp_0 != NULL) && (tmp_0->left == k))
				tmp_0->left = *node;
			if ((tmp_0 != NULL) && (tmp_0->right == k))
				tmp_0->right = *node;
			if ((*node)->parent->right != NULL)
				(*node)->parent->right->parent = *node
			(*node)->parent = tmp_0, (*node)->right = k->right, (*node)->left = k;
			k->parent = node_cpy, k->left = n, k->right = r;
		}
		if (n != NULL)
			n->parent = k;
		if (r != NULL)
			r->parent = k;
		if (tmp_0 == NULL)
			*root = node_cpy;
	}
}
/**
* heap_insert - Inserts a value into a max binary heap tree.
* @root: A pointer to the root of the tree.
* @value: The value to insert.
*
* Return: A pointer to the inserted node.
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL, *parent = NULL;

	if (root != NULL)
	{
		parent = get_insert_position(*root);
		new_node = malloc(sizeof(heap_t));

		if (new_node == NULL)
			return (new_node);
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->parent = parent;
		new_node->n = value;
		if (parent == NULL)
		{
			*root = new_node;
		}
		else
		{
			if (parent->left == NULL)
				parent->left = new_node;
			else
				parent->right = new_node;
			while (new_node->parent != NULL)
			{
				if (new_node->n > new_node->parent->n)
					swap_tree_node_with_parent(&new_node, root);
				else
					break;
			}
		}
	}
	return (new_node);
}
