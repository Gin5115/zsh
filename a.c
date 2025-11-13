#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (top < 0) {
        return -1;
    }
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

void display() {
    if (top < 0) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    printf("Popped: %d\n", pop());
    display();
    printf("Top element: %d\n", peek());
    return 0;
}

=====================================

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear >= MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    int x = queue[front++];
    if (front > rear) {
        front = rear = -1;
    }
    return x;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("Dequeued: %d\n", dequeue());
    display();
    return 0;
}

=====================================

#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}

=====================================

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1)
        arr[k++] = L[i++];
    
    while (j < n2)
        arr[k++] = R[j++];
    
    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    mergeSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}

=====================================

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;
    
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL)
        return;
    
    prev->next = temp->next;
    free(temp);
}

void search(Node* head, int key) {
    Node* temp = head;
    int pos = 0;
    
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found\n", key);
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);
    
    printf("Linked List: ");
    printList(head);
    
    deleteNode(&head, 20);
    printf("After deleting 20: ");
    printList(head);
    
    search(head, 10);
    
    return 0;
}

=====================================

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    
    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(Node** head, int key) {
    Node* temp = *head;
    
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    
    if (temp == NULL)
        return;
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    free(temp);
}

void printList(Node* head) {
    Node* temp = head;
    printf("NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void printReverse(Node* head) {
    if (head == NULL)
        return;
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    printf("NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);
    
    printf("Doubly Linked List: ");
    printList(head);
    
    printf("Reverse: ");
    printReverse(head);
    
    deleteNode(&head, 20);
    printf("After deleting 20: ");
    printList(head);
    
    return 0;
}

=====================================

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    
    if (key < root->data) {
        return search(root->left, key);
    }
    
    return search(root->right, key);
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    
    Node* found = search(root, 40);
    if (found != NULL) {
        printf("Found: %d\n", found->data);
    }
    
    root = deleteNode(root, 20);
    printf("After deleting 20, Inorder: ");
    inorder(root);
    printf("\n");
    
    return 0;
}

=====================================

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void levelOrder(Node* root) {
    if (root == NULL)
        return;
    
    Node* queue[100];
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    
    while (front < rear) {
        Node* current = queue[front++];
        printf("%d ", current->data);
        
        if (current->left != NULL)
            queue[rear++] = current->left;
        
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    
    printf("Level Order: ");
    levelOrder(root);
    printf("\n");
    
    return 0;
}

=====================================

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    
    return y;
}

int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Node* insert(Node* node, int data) {
    if (node == NULL)
        return createNode(data);
    
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;
    
    node->height = 1 + max(height(node->left), height(node->right));
    
    int balance = getBalance(node);
    
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL)
        return root;
    
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;
            
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            
            free(temp);
        } else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    
    if (root == NULL)
        return root;
    
    root->height = 1 + max(height(root->left), height(root->right));
    
    int balance = getBalance(root);
    
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}

void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    
    root = deleteNode(root, 40);
    
    printf("After deleting 40: ");
    preorder(root);
    printf("\n");
    
    return 0;
}

=====================================

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int V;
    int** adj;
} Graph;

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adj = (int**)malloc(V * sizeof(int*));
    
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int*)calloc(V, sizeof(int));
    }
    
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1;
}

void DFSUtil(Graph* graph, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);
    
    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[v][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

void DFS(Graph* graph, int start) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    
    printf("DFS traversal starting from vertex %d: ", start);
    DFSUtil(graph, start, visited);
    printf("\n");
    
    free(visited);
}

void BFS(Graph* graph, int start) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    int queue[MAX];
    int front = 0, rear = 0;
    
    visited[start] = 1;
    queue[rear++] = start;
    
    printf("BFS traversal starting from vertex %d: ", start);
    
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        
        for (int i = 0; i < graph->V; i++) {
            if (graph->adj[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
    
    free(visited);
}

int main() {
    Graph* graph = createGraph(6);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);
    
    DFS(graph, 0);
    BFS(graph, 0);
    
    return 0;
}

=====================================

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int src, dest, weight;
} Edge;

typedef struct {
    int parent;
    int rank;
} Subset;

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void* a, const void* b) {
    Edge* edge1 = (Edge*)a;
    Edge* edge2 = (Edge*)b;
    return edge1->weight - edge2->weight;
}

void kruskalMST(Edge edges[], int V, int E) {
    Edge result[V];
    int e = 0;
    int i = 0;
    
    qsort(edges, E, sizeof(edges[0]), compareEdges);
    
    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));
    
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    
    while (e < V - 1 && i < E) {
        Edge next_edge = edges[i++];
        
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        
        if (x != y) {
            result[e++] = next_edge;
            unionSets(subsets, x, y);
        }
    }
    
    printf("Edges in MST (Kruskal's):\n");
    int totalWeight = 0;
    for (i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("Total weight: %d\n", totalWeight);
    
    free(subsets);
}

int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    
    return min_index;
}

void primMST(int** graph, int V) {
    int parent[V];
    int key[V];
    int mstSet[V];
    
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    
    key[0] = 0;
    parent[0] = -1;
    
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;
        
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    printf("\nEdges in MST (Prim's):\n");
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        printf("%d -- %d == %d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total weight: %d\n", totalWeight);
}

int main() {
    int V = 4;
    int E = 5;
    
    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    
    kruskalMST(edges, V, E);
    
    int** graph = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph[i] = (int*)calloc(V, sizeof(int));
    }
    
    graph[0][1] = graph[1][0] = 10;
    graph[0][2] = graph[2][0] = 6;
    graph[0][3] = graph[3][0] = 5;
    graph[1][3] = graph[3][1] = 15;
    graph[2][3] = graph[3][2] = 4;
    
    primMST(graph, V);
    
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);
    
    return 0;
}