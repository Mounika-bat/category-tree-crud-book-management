
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int numVertices;
    struct Node *adjLists[MAX];
    char names[MAX][50];
};

// Create node
struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Initialize graph
void initGraph(struct Graph *graph)
{
    graph->numVertices = 0;
    for (int i = 0; i < MAX; i++)
    {
        graph->adjLists[i] = NULL;
        strcpy(graph->names[i], ""); // IMPORTANT FIX
    }
}

// Validate ID
int isValidID(int id)
{
    return (id >= 0 && id < MAX);
}

// Add task
void addTask(struct Graph *graph)
{
    int id;

    printf("Enter Task ID (0-%d): ", MAX - 1);
    scanf("%d", &id);

    if (!isValidID(id))
    {
        printf("Invalid ID!\n");
        return;
    }

    if (strlen(graph->names[id]) > 0)
    {
        printf("Task already exists!\n");
        return;
    }

    printf("Enter Task Name: ");
    scanf(" %[^\n]", graph->names[id]);

    graph->numVertices++;
    printf("Task added successfully!\n");
}

// Add dependency
void addDependency(struct Graph *graph)
{
    int src, dest;

    printf("Enter Source Task ID: ");
    scanf("%d", &src);

    printf("Enter Destination Task ID: ");
    scanf("%d", &dest);

    if (!isValidID(src) || !isValidID(dest) ||
        strlen(graph->names[src]) == 0 ||
        strlen(graph->names[dest]) == 0)
    {
        printf("Invalid task IDs!\n");
        return;
    }

    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    printf("Dependency added: %d -> %d\n", src, dest);
}

// Display graph
void displayGraph(struct Graph *graph)
{
    printf("\nCampaign Dependency Graph:\n");

    for (int i = 0; i < MAX; i++)
    {
        if (strlen(graph->names[i]) > 0)
        {
            printf("%d (%s) -> ", i, graph->names[i]);

            struct Node *temp = graph->adjLists[i];
            while (temp)
            {
                printf("%d ", temp->vertex);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

// Search
void searchTask(struct Graph *graph)
{
    int id;
    printf("Enter Task ID to search: ");
    scanf("%d", &id);

    if (isValidID(id) && strlen(graph->names[id]) > 0)
        printf("Found: %s\n", graph->names[id]);
    else
        printf("Task not found\n");
}

// Update
void updateTask(struct Graph *graph)
{
    int id;
    printf("Enter Task ID to update: ");
    scanf("%d", &id);

    if (isValidID(id) && strlen(graph->names[id]) > 0)
    {
        printf("Enter new name: ");
        scanf(" %[^\n]", graph->names[id]);
        printf("Updated successfully!\n");
    }
    else
    {
        printf("Task not found\n");
    }
}

// Delete task
void deleteTask(struct Graph *graph)
{
    int id;
    printf("Enter Task ID to delete: ");
    scanf("%d", &id);

    if (!isValidID(id) || strlen(graph->names[id]) == 0)
    {
        printf("Task not found\n");
        return;
    }

    // Free outgoing edges
    struct Node *temp = graph->adjLists[id];
    while (temp)
    {
        struct Node *t = temp;
        temp = temp->next;
        free(t);
    }
    graph->adjLists[id] = NULL;

    // Remove ALL incoming edges
    for (int i = 0; i < MAX; i++)
    {
        struct Node *curr = graph->adjLists[i];
        struct Node *prev = NULL;

        while (curr)
        {
            if (curr->vertex == id)
            {
                if (prev)
                    prev->next = curr->next;
                else
                    graph->adjLists[i] = curr->next;

                struct Node *del = curr;
                curr = curr->next;
                free(del);
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    strcpy(graph->names[id], "");
    graph->numVertices--;

    printf("Task deleted successfully!\n");
}

// DFS for topo
void topoDFS(struct Graph *graph, int v, int visited[], int stack[], int *top)
{
    visited[v] = 1;

    struct Node *temp = graph->adjLists[v];
    while (temp)
    {
        if (!visited[temp->vertex])
            topoDFS(graph, temp->vertex, visited, stack, top);
        temp = temp->next;
    }

    stack[++(*top)] = v;
}

// Topological sort
void topologicalSort(struct Graph *graph)
{
    int visited[MAX] = {0};
    int stack[MAX];
    int top = -1;

    for (int i = 0; i < MAX; i++)
    {
        if (strlen(graph->names[i]) > 0 && !visited[i])
        {
            topoDFS(graph, i, visited, stack, &top);
        }
    }

    printf("\nExecution Order:\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%s -> ", graph->names[stack[i]]);
    }
    printf("END\n");
}

// Main
int main()
{
    struct Graph graph;
    initGraph(&graph);

    int choice;

    while (1)
    {
        printf("\n--- Advertising Campaign DAG ---\n");
        printf("1. Add Campaign Task\n");
        printf("2. Add Dependency\n");
        printf("3. Delete Task\n");
        printf("4. Update Task\n");
        printf("5. Search Task\n");
        printf("6. Display Graph\n");
        printf("7. Show Execution Order\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addTask(&graph);
            break;
        case 2:
            addDependency(&graph);
            break;
        case 3:
            deleteTask(&graph);
            break;
        case 4:
            updateTask(&graph);
            break;
        case 5:
            searchTask(&graph);
            break;
        case 6:
            displayGraph(&graph);
            break;
        case 7:
            topologicalSort(&graph);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
