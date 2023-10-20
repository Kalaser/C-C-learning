#include<stack>
#include<stdio.h>
#include<queue>
#include<iostream>
class MinStack
{
	public:MinStack()
	{

	}
	void push(int x)
	{
		_data.push(x);//将数据压入数据栈
        if(_min.empty())
        {
            _min.push(x);
        }//如果最小值栈空，直接将数据压入栈
        else
        {
            if(x>_min.top())
            {
                x=_min.top();
            }
            _min.push(x);
        }

	}//比较当前数据与最小值栈顶数据大小，选择较小的压入最小值栈
	void pop()//数据栈与最小之前栈同时弹出
	{
		_data.pop();
		_min.pop();
	}
	int top()//获取数据栈栈顶
	{
		return _data.top();
	}
	int getMin() //获取最小值栈栈顶
    {
        return _min.top();
    }
	private:
	std::stack<int> _data;//数据栈
    std::stack<int> _min;//最小值栈
    
};
int main()
{
	MinStack MinStack;
    MinStack.push(-2);
    printf("top=[%d]\n",MinStack.top());
    printf("min=[%d]\n\n",MinStack.getMin());
    MinStack.push(0);
    printf("top=[%d]\n",MinStack.top());
    printf("min=[%d]\n\n",MinStack.getMin());
    MinStack.push(-5);
    printf("top=[%d]\n",MinStack.getMin());
    printf("min=[%d]\n\n",MinStack.getMin());
    MinStack.pop();
    printf("top=[%d]\n",MinStack.top());
    printf("min=[%d]\n\n",MinStack.getMin());
	return 0;
}
