/*

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1
NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor.

*/


int i=0,j=0;
vector<int>mn(2000100),st(2000100);
MinStack::MinStack() {
    st.clear(); mn.clear();
    i=-1;j=-1;
}

void MinStack::push(int x) {
    i++;
    st[i]=x;
    if(j>=0 and mn[j]>=x) j++,mn[j]=x;
    else if(j==-1) j++,mn[j]=x;
}

void MinStack::pop() {
    if(i<0) return;
    if(st[i]==mn[j]) j--;
    i--;
}

int MinStack::top() {
    if(i<0) return -1;
    return st[i];
}

int MinStack::getMin() {
    if(j>=0) return mn[j];
    return -1;
}
