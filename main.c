#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[50];
    struct Node *child;
    struct Node *sibling;
};

// Create new node
struct Node *createNode(char name[])
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->child = NULL;
    newNode->sibling = NULL;
    return newNode;
}

// Add child category
void addCategory(struct Node *parent, char name[])
{
    struct Node *newNode = createNode(name);

    if (parent->child == NULL)
    {
        parent->child = newNode;
    }
    else
    {
        struct Node *temp = parent->child;
        while (temp->sibling != NULL)
            temp = temp->sibling;
        temp->sibling = newNode;
    }
}

// Display tree
void display(struct Node *root, int level)
{
    if (root == NULL)
        return;

    for (int i = 0; i < level; i++)
        printf("  ");

    printf("- %s\n", root->name);

    display(root->child, level + 1);
    display(root->sibling, level);
}

// Search category
struct Node *search(struct Node *root, char name[])
{
    if (root == NULL)
        return NULL;

    if (strcmp(root->name, name) == 0)
        return root;

    struct Node *res = search(root->child, name);
    if (res != NULL)
        return res;

    return search(root->sibling, name);
}

// Update category
void update(struct Node *root, char oldName[], char newName[])
{
    struct Node *node = search(root, oldName);
    if (node != NULL)
    {
        strcpy(node->name, newName);
        printf("Updated successfully!\n");
    }
    else
    {
        printf("Category not found!\n");
    }
}

// Delete category (simple delete: removes first matching node)
struct Node *deleteNode(struct Node *root, char name[])
{
    if (root == NULL)
        return NULL;

    if (strcmp(root->name, name) == 0)
    {
        free(root);
        return NULL;
    }

    root->child = deleteNode(root->child, name);
    root->sibling = deleteNode(root->sibling, name);

    return root;
}

// Menu
int main()
{
    struct Node *root = createNode("Books");
    int choice;
    char parent[50], name[50], newName[50];

    while (1)
    {
        printf("\n1.Add Category\n2.Delete Category\n3.Update Category\n4.Search\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter parent category: ");
            scanf("%s", parent);
            printf("Enter new category: ");
            scanf("%s", name);

            struct Node *p = search(root, parent);
            if (p != NULL)
            {
                addCategory(p, name);
                printf("Added successfully!\n");
            }
            else
            {
                printf("Parent not found!\n");
            }
            break;

        case 2:
            printf("Enter category to delete: ");
            scanf("%s", name);
            root = deleteNode(root, name);
            printf("Deleted (if existed)\n");
            break;

        case 3:
            printf("Enter old name: ");
            scanf("%s", name);
            printf("Enter new name: ");
            scanf("%s", newName);
            update(root, name, newName);
            break;

        case 4:
            printf("Enter category to search: ");
            scanf("%s", name);
            if (search(root, name))
                printf("Found!\n");
            else
                printf("Not Found!\n");
            break;

        case 5:
            printf("\nCategory Tree:\n");
            display(root, 0);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
}