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
//    Node(const Node& rhs) {
//        x = rhs.x;
//        y = rhs.y;
//    }
    Node(int x0, int y0) {
        x = x0;
        y = y0;
    }
    bool operator < (const Node& rhs) const {
        if(x == rhs.x) {
            return y > rhs.y;
        } else {
            return x > rhs.x;
        }
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
void TestCustomPrioritizeQueue1() {
    cout << "TestCustomPrioritizeQueue1():" << endl;
    unsigned int seed = time(nullptr);
    srand(seed);
    priority_queue<Node, vector<Node>, Cmp> p;
    for (int i = 0; i < 10; ++i) {
        p.push(Node(rand(), rand()));
    }
    while (!p.empty()) {
        cout << p.top().x << "\t" << p.top().y << endl;
        p.pop();
    }
}

// when it is true, the element will move down
auto CmpFun2 = [](Node a, Node b) {
    if(a.x == b.x) {
        return a.y > b.y;
    } else {
        return a.x > b.x;
    }
};
void TestCustomPrioritizeQueue2() {
    cout << "TestCustomPrioritizeQueue2():" << endl;
    unsigned int seed = time(nullptr);
    srand(seed);
//    priority_queue<Node, vector<Node>, decltype(&CmpFun2)> p(CmpFun2);  // error
    priority_queue<Node, vector<Node>, decltype(CmpFun2)> p(CmpFun2);
    for (int i = 0; i < 10; ++i) {
        p.push(Node(rand(), rand()));
    }
    while (!p.empty()) {
        cout << p.top().x << "\t" << p.top().y << endl;
        p.pop();
    }
}

static bool CmpFun1(Node a, Node b) {
    if(a.x == b.x) {
        return a.y > b.y;
    } else {
        return a.x > b.x;
    }
}
void TestCustomPrioritizeQueue3() {
    cout << "TestCustomPrioritizeQueue3():" << endl;
    unsigned int seed = time(nullptr);
    srand(seed);
    priority_queue<Node, vector<Node>, decltype(&CmpFun1)> p(CmpFun1);
//    priority_queue<Node, vector<Node>, decltype(CmpFun1)> p(CmpFun1);  // error
    for (int i = 0; i < 10; ++i) {
        p.push(Node(rand(), rand()));
    }
    while (!p.empty()) {
        cout << p.top().x << "\t" << p.top().y << endl;
        p.pop();
    }
}

void TestCustomPrioritizeQueue4() {
    cout << "TestCustomPrioritizeQueue4():" << endl;
    unsigned int seed = time(nullptr);
    srand(seed);
    priority_queue<Node> p;
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
    TestCustomPrioritizeQueue1();
    TestCustomPrioritizeQueue2();
    TestCustomPrioritizeQueue3();
    TestCustomPrioritizeQueue4();

    return 0;
}
