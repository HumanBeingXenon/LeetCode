#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H
#define null 0

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::queue;
using std::string;
using std::to_string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

//----ListNode---------------------------------------------------------------------

//A simple data structure that forms a singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    //~ListNode() { delete next; }
};

void print_list(ListNode *head);
ListNode *init_list(int arr[], int len, bool has_sentinel = false);
ListNode *init_list(vector<int> v, bool has_sentinel = false);
vector<int> list_to_vector(ListNode *head);
void destroy_list(ListNode *head, bool show_info = false);

//----TreeNode---------------------------------------------------------------------

//A simple data structure that forms a binary tree.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    //~TreeNode() { delete left; delete right; }
};

void print_tree(TreeNode *root, string prefix = "", bool is_left = true);
TreeNode *init_tree(int arr[], int len);
TreeNode *init_tree(vector<int> v);
vector<int> tree_to_vector(TreeNode *root);
void destroy_tree(TreeNode *root, bool show_info = false);

//----GraphNode--------------------------------------------------------------------

//A simple data structure that forms a graph.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node() : val(0), neighbors(vector<Node *>()) {}
    Node(int val) : val(val), neighbors(vector<Node *>()) {}
    Node(int val, vector<Node *> neighbors) : val(val), neighbors(neighbors) {}
};

void print_bfs(Node *node);
//Node* init_graph(int **arr, int len);
Node *init_graph(vector<vector<int>> vertices);
vector<vector<int>> graph_to_vector(Node *node);
void destroy_graph(Node *node, bool show_info = false);

//----vector-----------------------------------------------------------------------

template <typename T>
void print_vector(vector<T> v);
template <typename T>
void print_vector(vector<T> v, int size);

//----ListNode functions-----------------------------------------------------------

//Print out the whole linked list.
void print_list(ListNode *head)
{
    for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << "->";
    cout << "null" << endl;
}

//Initialize a linked list with an int type array.
ListNode *init_list(int arr[], int len, bool has_sentinel)
{
    ListNode *head = new ListNode(0), *ptr = head;
    for (int i = 0; i < len; i++)
    {
        ListNode *node = new ListNode(arr[i]);
        ptr->next = node;
        ptr = ptr->next;
    }
    if (has_sentinel)
        return head;
    else
        return head->next;
}

//Initialize a linked list with an int type vector.
ListNode *init_list(vector<int> v, bool has_sentinel)
{
    ListNode *head = new ListNode(0), *ptr = head;
    for (int val : v)
    {
        ListNode *node = new ListNode(val);
        ptr->next = node;
        ptr = ptr->next;
    }
    if (has_sentinel)
        return head;
    else
        return head->next;
}

//Convert a linked list to a vector.
vector<int> list_to_vector(ListNode *head)
{
    vector<int> vector_output;
    if (head == nullptr)
        return vector_output;

    for (ListNode *ptr = head; ptr; ptr = ptr->next)
        vector_output.emplace_back(ptr->val);

    return vector_output;
}

//Manually destroy a linked list.
void destroy_list(ListNode *head, bool show_info)
{
    if (head == nullptr)
    {
        cout << "Empty linked list, delete failed." << endl;
        return;
    }

    if (show_info)
        cout << "Deleting linked list..." << endl;
    ListNode *cur = head, *next = head->next;
    while (cur != nullptr)
    {
        if (show_info)
            cout << (cur != head ? " " : "") << cur->val;
        delete cur;
        cur = next;
        if (next)
            next = next->next;
    }
    if (show_info)
        cout << endl;
    cout << "Linked List deletion completed." << endl;
}

//----TreeNode functions-----------------------------------------------------------

//Print out the whole binary tree.
void print_tree(TreeNode *root, string prefix, bool is_left)
{
    if (root == nullptr)
    {
        cout << "Empty tree" << endl;
        return;
    }
    if (root->right != nullptr)
        print_tree(root->right, prefix + (is_left ? "│   " : "    "), false);

    cout << prefix + (is_left ? "└── " : "┌── ") + to_string(root->val) << endl;

    if (root->left != nullptr)
        print_tree(root->left, prefix + (is_left ? "    " : "│   "), true);
}

//Initialize a binary tree from an int type array.
TreeNode *init_tree(int arr[], int len)
{
    if (arr == nullptr)
        return nullptr;
    queue<TreeNode *> queue_treenode;
    TreeNode *root = new TreeNode(arr[0]);
    queue_treenode.push(root);
    for (int i = 1; i < len;)
    {
        TreeNode *ptr = queue_treenode.front();
        queue_treenode.pop();
        if (arr[i] != null)
        {
            ptr->left = new TreeNode(arr[i]);
            queue_treenode.push(ptr->left);
        }
        i++;
        if (i < len && arr[i] != null)
        {
            ptr->right = new TreeNode(arr[i]);
            queue_treenode.push(ptr->right);
        }
        i++;
    }
    return root;
}

//Initialize a binary tree from an int type vector using queue.
TreeNode *init_tree(vector<int> v)
{
    if (v.empty())
        return nullptr;

    int size = v.size();
    queue<TreeNode *> queue_treenode;
    TreeNode *root = new TreeNode(v[0]);
    queue_treenode.push(root);
    for (int i = 1; i < size;)
    {
        TreeNode *ptr = queue_treenode.front();
        queue_treenode.pop();
        if (v[i] != null)
        {
            ptr->left = new TreeNode(v[i]);
            queue_treenode.push(ptr->left);
        }
        i++;
        if (i < size && v[i] != null)
        {
            ptr->right = new TreeNode(v[i]);
            queue_treenode.push(ptr->right);
        }
        i++;
    }
    return root;
}

//Another implementation of initializing a binary tree from an int type array using vector.
TreeNode *init_tree2(vector<int> v)
{
    int size = v.size();
    vector<TreeNode *> vector_treenode(size);
    for (int i = 0; i < size; i++)
        vector_treenode[i] = v[i] != null ? new TreeNode(v[i]) : nullptr;
    TreeNode *root = vector_treenode[0];
    int idx = 1;
    for (TreeNode *node : vector_treenode)
    {
        if (node != nullptr)
        {
            if (idx < size)
                node->left = vector_treenode[idx++];
            if (idx < size)
                node->right = vector_treenode[idx++];
        }
    }
    return root;
}

//Convert a binary tree to a vector
vector<int> tree_to_vector(TreeNode *root)
{
    vector<int> vector_output;
    if (root == nullptr)
        return vector_output;

    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        TreeNode *ptr = queue.front();
        queue.pop();
        if (ptr == nullptr)
        {
            vector_output.emplace_back(null);
            continue;
        }
        vector_output.emplace_back(ptr->val);
        queue.push(ptr->left);
        queue.push(ptr->right);
    }
    return vector_output;
}

//Manually destroy a binary tree.
void destroy_tree(TreeNode *head, bool show_info)
{
    if (head == nullptr)
    {
        cout << "Empty tree, delete failed." << endl;
        return;
    }

    if (show_info)
        cout << "Deleting tree..." << endl;

    queue<TreeNode *> queue;
    queue.push(head);

    while (!queue.empty())
    {
        int level_size = queue.size();
        for (int i = 0; i < level_size; i++)
        {
            TreeNode *node = queue.front();
            queue.pop();
            if (show_info)
                cout << (i ? " " : "") << node->val;
            if (node->left)
                queue.push(node->left);
            if (node->right)
                queue.push(node->right);
            delete node;
        }
        if (show_info)
            cout << endl;
    }

    cout << "Binary tree deletion completed." << endl;
}

//----GraphNode functions---------------------------------------------------------

//Print out a the breadth first search start from node.
void print_bfs(Node *node)
{
    if (node == nullptr)
    {
        cout << "Empty graph" << endl;
        return;
    }

    unordered_set<Node *> set;
    queue<Node *> queue;
    set.insert(node);
    queue.push(node);
    while (!queue.empty())
    {
        string node_info = "";
        Node *front = queue.front();
        queue.pop();
        node_info += "Node id: " + to_string(front->val) + ", " + (front->neighbors.size() ? "Neighbor(s): " : "No neighbor");
        for (int i = 0; i < front->neighbors.size(); i++)
        {
            Node *neighbor = front->neighbors[i];
            node_info += (i ? ", " : "") + to_string(neighbor->val);
            if (set.find(neighbor) == set.end())
            {
                set.insert(neighbor);
                queue.push(neighbor);
            }
        }
        cout << node_info << endl;
    }
}

//Initialize a directed/undirected graph with vector<int>.
Node *init_graph(vector<vector<int>> vertices)
{
    if (vertices.empty())
        return nullptr;

    unordered_map<int, Node *> map;
    for (int i = 0; i < vertices.size(); i++)
    {
        int id = i + 1;
        if (map.find(id) == map.end())
            map[id] = new Node(id);
        Node *ptr = map[id];
        for (int j = 0; j < vertices[i].size(); j++)
        {
            int nid = vertices[i][j];
            if (map.find(nid) == map.end())
                map[nid] = new Node(nid);
            ptr->neighbors.emplace_back(map[nid]);
        }
    }
    return map[1];
}

//
vector<vector<int>> graph_to_vector(Node *node)
{
    
}

//Manually destroy a graph.
void destroy_graph(Node *node, bool show_info)
{
    if (node == nullptr)
    {
        cout << "Empty graph, delete failed." << endl;
        return;
    }

    if (show_info)
        cout << "Deleting graph..." << endl;

    unordered_set<Node *> set;
    queue<Node *> queue;
    set.insert(node);
    queue.push(node);
    while (!queue.empty())
    {
        Node *front = queue.front();
        queue.pop();
        for (int i = 0; i < front->neighbors.size(); i++)
        {
            Node *neighbor = front->neighbors[i];
            if (set.find(neighbor) == set.end())
            {
                set.insert(neighbor);
                queue.push(neighbor);
            }
        }
        if (show_info)
            cout << front->val << " ";
        delete front;
    }
    if (show_info)
        cout << endl;
    cout << "Graph deletion completed." << endl;
}

//----vector functions------------------------------------------------------------

//Print out the whole vector.
template <typename T>
void print_vector(vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << (i != v.size() - 1 ? " " : "\n");
    }
}

//Print out specific length of vector.
template <typename T>
void print_vector(vector<T> v, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << (i != size - 1 ? " " : "\n");
    }
}

#endif