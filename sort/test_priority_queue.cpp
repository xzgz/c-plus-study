#include <iostream>
#include <queue>

using namespace std;

void TestPriorityQueue() {
    cout << "TestPriorityQueue():" << endl;
    priority_queue<int> p;
    p.push(1);
    p.push(2);
    p.push(8);
    p.push(5);
    p.push(43);
    for(int i = 0; i < 5; ++i) {
        cout << p.top() << endl;
        p.pop();
    }
}

void TestSmallPrioritizeQueue() {
    cout << "TestSmallPrioritizeQueue():" << endl;
    priority_queue<int, vector<int>, less<int> > p;
    p.push(1);
    p.push(2);
    p.push(8);
    p.push(5);
    p.push(43);
    for(int i = 0; i < 5; ++i) {
        cout << p.top() << endl;
        p.pop();
    }
}

void TestBigPrioritizeQueue() {
    cout << "TestBigPrioritizeQueue():" << endl;
    priority_queue<int, vector<int>, greater<int> > p;
    p.push(1);
    p.push(2);
    p.push(8);
    p.push(5);
    p.push(43);
    for(int i = 0; i < 5; ++i) {
        cout << p.top() << endl;
        p.pop();
    }
}

struct Node {
    int x;
    int y;
    Node(int x0, int y0) {
        x = x0;
        y = y0;
    }
};
struct Cmp {
    bool operator()(Node a, Node b) {
        if(a.x == b.x) {
            return a.y > b.y;
        } else {
            return a.x > b.x;
        }
    }
};
bool CmpFun1(Node a, Node b) {
    if(a.x == b.x) {
        return a.y > b.y;
    } else {
        return a.x > b.x;
    }
}
auto CmpFun2 = [](Node a, Node b) {
    if(a.x == b.x) {
        return a.y > b.y;
    } else {
        return a.x > b.x;
    }
};

void TestCustomPrioritizeQueue() {
    cout << "TestCustomPrioritizeQueue():" << endl;
    unsigned int seed = time(nullptr);
    srand(seed);
//    priority_queue<Node, vector<Node>, Cmp> p;
    priority_queue<Node, vector<Node>, decltype(CmpFun2)> p(CmpFun2);
    for (int i = 0; i < 10; ++i) {
        p.push(Node(rand(), rand()));
    }
    while (!p.empty()) {
        cout << p.top().x << "\t" << p.top().y << endl;
        p.pop();
    }
}

int main() {
    TestPriorityQueue();
    TestSmallPrioritizeQueue();
    TestBigPrioritizeQueue();
    TestCustomPrioritizeQueue();

    return 0;
}
