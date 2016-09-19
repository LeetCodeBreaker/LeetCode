#include <iostream>
#include <list>

class MinStack {
public:
    std::list<int> l;
    std::list<int> min_l;

    MinStack() {

    }

    void push(int x) {
        l.push_front(x);
        if (min_l.empty()) {
            min_l.push_front(x);
        } else {
            if (x <= min_l.front()) {
                min_l.push_front(x);
            }
        }
        return;
    }

    void pop() {
        if (min_l.front() == l.front()) {
            min_l.pop_front();
        }
        l.pop_front();
    }

    int top() {
        return l.front();
    }

    int getMin() {
        return min_l.front();
    }
};

int main() {
    MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    std::cout << obj.getMin() << std::endl;
    obj.pop();
    std::cout << obj.top() << std::endl;
    std::cout << obj.getMin() << std::endl;

    return 0;
}

