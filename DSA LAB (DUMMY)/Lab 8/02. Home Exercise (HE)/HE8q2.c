// Modify program HE8.1 by providing more options as follows:
// a) To count number of leaf nodes in the tree.
// b) To count number of non-leaf nodes in the tree.
// c) To find number of nodes in the binary tree.
// d) To find sum of all nodes of the binary tree.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(struct node *node, int data)
{
    if (node == NULL)
    {
        struct node *temp;
        temp = malloc(sizeof(struct node));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < (node->data))
        node->left = createNode(node->left, data);
    else if (data > node->data)
        node->right = createNode(node->right, data);

    return node;
}

int findMin(struct node *node)
{

    if (node == NULL)
    {
        printf("\nThe tree is Empty");
        return -1;
    }
    if (node->left == NULL)
        return node->data;
    else
        findMin(node->left);
}

int findMax(struct node *node)
{
    if (node == NULL)
    {
        printf("\nThe tree is Empty");
        return -1;
    }
    if (node->right == NULL)
        return node->data;
    else
        findMax(node->right);
}

struct node *findMinimum(struct node *node)
{

    if (node == NULL)
        return NULL;
    if (node->left)
        return findMinimum(node->left);
    else
        return node;
}

struct node *del(struct node *node, int data)
{

    struct node *temp;

    if (node == NULL)
        printf("\nElement not found");

    else if (data < node->data)
        node->left = del(node->left, data);

    else if (data > node->data)
        node->right = del(node->right, data);

    else
    {
        if (node->right && node->left)
        {
            temp = findMinimum(node->right);
            node->data = temp->data;
            node->right = del(node->right, temp->data);
        }
        else
        {
            temp = node;
            if (node->left == NULL)
                node = node->right;
            else if (node->right == NULL)
                node = node->left;
            free(temp);
        }
    }
    return node;
}

void inorder(struct node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void preorder(struct node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(struct node *node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

int getLeafCount(struct node *node)
{
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return (getLeafCount(node->left) + getLeafCount(node->right));
}

int nonleaf(struct node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return 0;
    }
    return 1 + nonleaf(root->left) + nonleaf(root->right);
}

int count(struct node *tree)
{
    int c = 0;

    if (tree == NULL)
        return 0;

    else
    {
        c += count(tree->left);
        c += count(tree->right);
        return c;
    }
}

int SumOfBinaryTree(struct node *root)
{
    if (root == NULL)
        return 0;
    return (root->data + SumOfBinaryTree(root->left) + SumOfBinaryTree(root->right));
}

int main()
{
    struct node *root = NULL;
    int data, ch, n, sw;

    while (1)
    {
        printf("\n----------------------------------------\n");
        printf("Binary Search Tree Menu\n");
        printf("----------------------------------------\n");
        printf("0. Quit \n1. Create \n2. In - Order Traversal \n3. Pre - Order Traversal \n4. Post - Order traversal \n5. Find Smallest Element \n6. Find Largest Element \n7. Insert an element \n8. Delete an element \n9. Modification of TREE\n");
        printf("----------------------------------------\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        p:
        case 0:
            exit(0);
        case 1:
            printf("\nEnter no of nodes: ");
            scanf("%d", &n);
            printf("Enter %d nodes: ", n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &data);
                root = createNode(root, data);
            }
            break;
        case 2:
            printf("\nInorder Traversal: \n");
            inorder(root);
            break;
        case 3:
            printf("\nPreorder Traversal: \n");
            preorder(root);
            break;
        case 4:
            printf("\nPostorder Traversal: \n");
            postorder(root);
            break;
        case 5:
            printf("\nThe smallest value in the node is: %d", findMin(root));
            break;
        case 6:
            printf("\nThe largest value in the node is: %d", findMax(root));
            break;
        case 7:
            printf("\nEnter the node to insert: ");
            scanf("%d", &data);
            root = createNode(root, data);
            break;
        case 8:
            printf("\nEnter the element to delete: ");
            scanf("%d", &data);
            root = del(root, data);
            break;
        case 9:
            while (1)
            {
                printf("\n1. To count number of leaf nodes in the tree. \n2. To count number of non-leaf nodes in the tree. \n3. To find number of nodes in the binary tree. \n4. To find sum of all nodes of the binary tree.\n5. Exit \nEnter your choice: ");
                scanf("%d", &sw);
                switch (sw)
                {
                case 1:
                    printf("\nLeaf count of the tree is: %d", getLeafCount(root));
                    break;
                case 2:
                    printf("\nNon - Leaf count of the tree is: %d", nonleaf(root));
                    break;
                case 3:
                    printf("\nNo of nodes in the tree is: %d", count(root));
                    break;
                case 4:
                    printf("\nSum of all nodes in the tree is: %d", SumOfBinaryTree(root));
                    break;
                case 5:
                    exit(0);
                default:
                    printf("\nWrong option");
                    break;
                }
            }
        default:
            printf("\nWrong option");
            break;
        }
    }

    return 0;
}