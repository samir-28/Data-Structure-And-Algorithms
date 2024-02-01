#include <iostream>
#include <stack>
using namespace std;
#define max 5

class StackImplementation
{
public:
    int stack[max];
    int top = -1; /// means stack is empty

    void push(int item) 
    {
        if (top == max - 1) // stack is full
        {
            cout << "Satck Overflow" << endl;
        }
        else
        {
            stack[++top] = item;
            cout << "Item Pushed is:" << endl;
            cout << item << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "stack underflow" << endl;
        }
        else
        {
            top--;
        }
    }

    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Top of the stack is:" << stack[top] << endl;
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Stack Items are:" << endl;
            int i;
            for (i = top; i >= 0; i--)
            {
                cout << stack[i] << endl;
            }
        }
    }
};

int main()
{
    StackImplementation st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.peek();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.display();
    st.push(7);
}
