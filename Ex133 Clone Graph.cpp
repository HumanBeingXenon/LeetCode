#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include "data_structure.hpp"

using namespace std;

Node *cloneGraph(Node *node);

int main(int argc, char const *argv[])
{
    vector<vector<int>> v = {{2, 4}, {1, 3}, {2, 4}, {1, 3}};
    Node *node = init_graph(v), *node2 = cloneGraph(node);
    print_bfs(node);
    print_bfs(node2);
    destroy_graph(node);
    destroy_graph(node2);
    return 0;
}

Node *cloneGraph(Node *node)
{
    if (node == nullptr)
        return nullptr;

    unordered_map<Node *, Node *> map;
    queue<Node *> queue;
    queue.push(node);
    while (!queue.empty())
    {
        Node *cur = queue.front();
        queue.pop();
        if (map.find(cur) == map.end())
            map[cur] = new Node(cur->val);

        for (int i = 0; i < cur->neighbors.size(); i++)
        {
            Node *neighbor = cur->neighbors[i];
            if (map.find(neighbor) == map.end())
            {
                queue.push(neighbor);
                map[neighbor] = new Node(neighbor->val);
            }
            map[cur]->neighbors.emplace_back(map[neighbor]);
        }
    }
    return map[node];
}
