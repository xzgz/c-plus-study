#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <limits>

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
    Node *from;
    Node *to;
    Edge(int w, Node *f, Node *t) {
        weight = w;
        from = f;
        to = t;
    }
};

struct Graph {
    unordered_map<int, Node*> nodes;
    unordered_set<Edge*> edges;
};

Node *GetFromHeadMinDistanceNode(const unordered_map<Node*, int>& dist_map, const unordered_set<Node*>& selected_node) {
    Node *min_node = nullptr;
    int min_dist = numeric_limits<int>::max();
    for (auto dist_pair : dist_map) {
        Node *node = dist_pair.first;
        int dist = dist_pair.second;
        if (selected_node.count(node) == 0 && dist < min_dist) {
            min_node = node;
            min_dist = dist;
        }
    }
    return min_node;
}

unordered_map<Node*, int> Dijkstra1(Node *head) {
    unordered_map<Node*, int> dist_map;
    if (head == nullptr) return dist_map;

    unordered_set<Node*> selected_node;
    dist_map[head] = 0;
    Node *min_node = GetFromHeadMinDistanceNode(dist_map, selected_node);
    while (min_node != nullptr) {
        int dist = dist_map[min_node];
        for (Edge *edge : min_node->edges) {
            Node *to_node = edge->to;
            if (dist_map.count(to_node) == 0) {
                dist_map[to_node] = dist + edge->weight;
            } else {
                dist_map[to_node] = min(dist_map[to_node], dist + edge->weight);
            }
        }
        selected_node.insert(min_node);
        min_node = GetFromHeadMinDistanceNode(dist_map, selected_node);
    }
    return dist_map;
}

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
        Edge *edge = new Edge(weight, from_node, to_node);
        from_node->nexts.push_back(to_node);
        from_node->out++;
        to_node->in++;
        from_node->edges.push_back(edge);
        graph->edges.insert(edge);
    }
    return graph;
}

void DestroyGraph(Graph *graph) {
    for (auto pair : graph->nodes) {
        delete pair.second;
        pair.second = nullptr;
    }
    for (auto edge : graph->edges) {
        delete edge;
        edge = nullptr;
    }
    delete graph;
    graph = nullptr;
}

Graph *GenerateExampleNoCircleGraph() {
    vector<vector<int> > matrix = {
            {7, 'A', 'B'},
            {5, 'D', 'A'},
            {8, 'C', 'B'},
            {7, 'B', 'E'},
            {5, 'C', 'E'},
            {9, 'D', 'B'},
            {15, 'D', 'E'},
            {6, 'F', 'D'},
            {8, 'F', 'E'},
            {11, 'F', 'G'},
            {9, 'G', 'E'},
    };
    return GenerateGraph(matrix);
}

Graph *GenerateExampleGraph() {
    vector<vector<int> > matrix = {
            {7, 'A', 'B'},
            {7, 'B', 'A'},
            {5, 'A', 'D'},
            {5, 'D', 'A'},
            {8, 'B', 'C'},
            {8, 'C', 'B'},
            {7, 'B', 'E'},
            {7, 'E', 'B'},
            {5, 'C', 'E'},
            {5, 'E', 'C'},
            {9, 'B', 'D'},
            {9, 'D', 'B'},
            {15, 'D', 'E'},
            {15, 'E', 'D'},
            {6, 'D', 'F'},
            {6, 'F', 'D'},
            {8, 'F', 'E'},
            {8, 'E', 'F'},
            {11, 'F', 'G'},
            {11, 'G', 'F'},
            {9, 'E', 'G'},
            {9, 'G', 'E'},
    };
    return GenerateGraph(matrix);
}

int main() {
    Graph *graph = GenerateExampleGraph();
    auto iter = graph->nodes.begin();
    Node *head = iter->second;
    unordered_map<Node*, int> dist_map = Dijkstra1(head);
    for (auto dist_pair : dist_map) {
        cout << char(head->value) << "-->" << char(dist_pair.first->value) << ": " << dist_pair.second << endl;
    }
    DestroyGraph(graph);

    return 0;
}
