#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;
struct Node;
struct Edge;

struct Node {
    int value;
    int in;
    int out;
    vector<Node*> nexts;
    vector<Edge*> edges;
    Node(int v) {
        value = v;
        in = 0;
        out = 0;
    }
};

struct Edge {
    int weight;
    Node from = Node(0);
    Node to = Node(0);
    Edge(int w, Node f, Node t) {
        weight = w;
        from = f;
        to = t;
    }
};

struct Graph {
    unordered_map<int, Node*> nodes;
//    unordered_set<Edge> edges;  //error: no match for call to (const std::hash<Edge>) (const Edge&)
    unordered_set<Edge*> edges;
};

Graph *GenerateGraph(vector<vector<int> > matrix) {
    Graph *graph = new Graph();
    for (int i = 0; i < matrix.size(); ++i) {
        int weight =  matrix[i][0];
        int from = matrix[i][1];
        int to = matrix[i][2];
        if (graph->nodes.count(from) == 0) {
            graph->nodes[from] = new Node(from);
        }
        if (graph->nodes.count(to) == 0) {
            graph->nodes[to] = new Node(to);
        }
        Node *from_node = graph->nodes[from];
        Node *to_node = graph->nodes[to];
        Edge *edge = new Edge(weight, *from_node, *to_node);
        from_node->nexts.push_back(to_node);
        from_node->out++;
        to_node->in++;
        from_node->edges.push_back(edge);
        graph->edges.insert(edge);
    }
    return graph;
}

void BFS(Node *node) {
    if (node == nullptr) return;
    queue<Node*> q;
    unordered_set<Node*> s;
    q.push(node);
    s.insert(node);
    while (!q.empty()) {
        Node *cur = q.front();
        q.pop();
        cout << cur->value << endl;
        for (Node *next : cur->nexts) {
            if (s.count(next) == 0) {
                q.push(next);
                s.insert(next);
            }
        }
    }
}

void DFS(Node *node) {
    if (node == nullptr) return;
    stack<Node*> stack;
    unordered_set<Node*> set;
    stack.push(node);
    set.insert(node);
    cout << node->value << endl;
    while (!stack.empty()) {
        Node *cur = stack.top();
        stack.pop();
        for (Node *next : cur->nexts) {
            if (set.count(next) == 0) {
                stack.push(cur);
                stack.push(next);
                set.insert(next);
                cout << next->value << endl;
                break;
            }
        }
    }
}

vector<Node*> TopologySort(Graph *graph) {
    unordered_map<Node*, int> in_map;
    queue<Node*> zero_in_queue;
    for (unordered_map<int, Node*>::iterator iter = graph->nodes.begin(); iter != graph->nodes.end(); ++iter) {
        Node *node = iter->second;
        in_map[node] = node->in;
        if (node->in == 0) {
            zero_in_queue.push(node);
        }
    }

    vector<Node*> result;
    while (!zero_in_queue.empty()) {
        Node *cur = zero_in_queue.front();
        zero_in_queue.pop();
        result.push_back(cur);
        for (Node *next : cur->nexts) {
            in_map[next]--;
            if (in_map[next] == 0) {
                zero_in_queue.push(next);
            }
        }
    }
    return result;
}




int main() {
    unordered_map<Node*, int> in_map;
    Node *n = new Node(6);
    in_map[n] = 10;
    cout << in_map[n] << endl;

    vector<int> arr;
}
