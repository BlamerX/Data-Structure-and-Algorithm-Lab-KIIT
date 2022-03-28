// 1.	WAP Write the following menu driven program for the binary search tree
// ----------------------------------------
// Binary Search Tree Menu
// ----------------------------------------
// 0. Quit
// 1. Create
// 2. In-Order Traversal
// 3. Pre-Order Traversal
// 4. Post-Order traversal
// 5. Search
// 6. Find Smallest Element
// 7. Find Largest Element
// 8. Deletion of Tree
// ----------------------------------------

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
} *root = NULL;

void insert(int val)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if (root == NULL)
    {
        root = ptr;
        return;
    }
    struct node *current = root;
    while (current != NULL)
    {
        if (val < current->data)
        {
            if (current->left == NULL)
            {
                current->left = ptr;
                return;
            }
            current = current->left;
        }
        else
        {
            if (current->right == NULL)
            {
                current->right = ptr;
                return;
            }
            current = current->right;
        }
    }
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void search(struct node *root, int data)
{
    if (root == NULL)
    {
        printf("Element not found\n");
        return;
    }
    if (root->data == data)
    {
        printf("Element found\n");
        return;
    }
    if (data < root->data)
        search(root->left, data);
    else
        search(root->right, data);
}

void findSmallest(struct node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    while (root->left != NULL)
        root = root->left;
    printf("Smallest element is %d\n", root->data);
}

void findLargest(struct node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    while (root->right != NULL)
        root = root->right;
    printf("Largest element is %d\n", root->data);
}

void deleteTree(struct node *root)
{
    if (root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

int main()
{
    int ch, data;
    while (1)
    {
        printf("----------------------------------------\nBinary Search Tree Menu\n----------------------------------------\n");
        printf("0. Quit\n");
        printf("1. Create\n");
        printf("2. In-Order Traversal\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. Post-Order traversal\n");
        printf("5. Search\n");
        printf("6. Find Smallest Element\n");
        printf("7. Find Largest Element\n");
        printf("8. Deletion of Tree\n----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            exit(0);
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            printf("In-Order Traversal: ");
            inorder(root);
            break;
        case 3:
            printf("Pre-Order Traversal: ");
            preorder(root);
            break;
        case 4:
            printf("Post-Order traversal: ");
            postorder(root);
            break;
        case 5:
            printf("Enter the element to be searched: ");
            scanf("%d", &data);
            search(root, data);
            break;
        case 6:
            findSmallest(root);
            break;
        case 7:
            findLargest(root);
            break;
        case 8:
            deleteTree(root);
            root = NULL;
            break;
        default:
            printf("Wrong choice\n");
        }
        printf("\n");
    }
    return 0;
}