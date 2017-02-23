#include <iostream>
#include <stack>

class MyQueue
{
private:
  std::stack<int> in_stack;
  std::stack<int> out_stack;
public:
  /** Initialize your data structure here. */
  MyQueue()
  {

  }

  /** Push element x to the back of queue. */
  void push(int x)
  {
    in_stack.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop(void)
  {
    int value = peek();
    out_stack.pop();
    return value;
  }

  /** Get the front element. */
  int peek(void)
  {
    if (out_stack.empty())
    {
      while (in_stack.size() > 0)
      {
        out_stack.push(in_stack.top());
        in_stack.pop();
      }
    }
    return out_stack.top();
  }

  /** Returns whether the queue is empty. */
  bool empty(void)
  {
    return (in_stack.empty() && out_stack.empty());
  }
};

int main()
{
  // Your MyQueue object will be instantiated and called as such:
  MyQueue my_queue;
  my_queue.push(1);
  std::cout << my_queue.peek() << std::endl;
  std::cout << my_queue.pop() << std::endl;
  std::cout << my_queue.empty() << std::endl;
  return EXIT_SUCCESS;
}
