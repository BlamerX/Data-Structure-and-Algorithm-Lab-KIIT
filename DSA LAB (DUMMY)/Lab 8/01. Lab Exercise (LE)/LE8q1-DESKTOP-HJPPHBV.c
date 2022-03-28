// WAP to create a binary search tree and traverse the tree with in-order, pre-order and post order by proving suitable menu for the user.
//
// ---------------------------------------
// Binary Search Tree Menu
// ---------------------------------------
// 0. Quit
// 1. Create
// 2. In - Order Traversal
// 3. Pre - Order Traversal
// 4. Post - Order traversal
// ---------------------------------------
// Enter your choice :

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

int main()
{
    struct node *root = NULL;
    int data, ch, n;

    while (1)
    {
        printf("\n----------------------------------------\n");
        printf("Binary Search Tree Menu\n");
        printf("----------------------------------------\n");
        printf("0. Quit \n1. Create \n2. In - Order Traversal \n3. Pre - Order Traversal \n4. Post - Order traversal\n");
        printf("----------------------------------------\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
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
        default:
            printf("\nWrong option");
            break;
        }
    }

    return 0;
}