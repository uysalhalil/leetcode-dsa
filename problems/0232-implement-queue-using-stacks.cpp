// problem: 0232 implement queue using stacks
// difficulty: easy
// studysets: dsa-quest, queue, stack
// url: https://leetcode.com/problems/implement-queue-using-stacks/
// tags: stack, queue, design

#include <vector>
using std::vector;

class MyQueue {
private:
    std::vector<int> _dataPush, _dataPop;

public:
    MyQueue() {}

    void push(int x) {
        _dataPush.push_back(x);
    }

    int pop() {
        int res = peek();
        _dataPop.pop_back();
        return res;
    }

    int peek() {
        if (!_dataPop.size()) {
            while (!_dataPush.empty()) {
                _dataPop.push_back(_dataPush.back());
                _dataPush.pop_back();
            }
        }
        return _dataPop.back();
    }

    bool empty() {
        return _dataPop.empty() && _dataPush.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
