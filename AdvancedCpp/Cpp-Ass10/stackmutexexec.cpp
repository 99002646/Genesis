/*Implementation of Stack using Mutual Exclusion and 
Synchronization (mutex, condition variables)*/ 

#include<bits/stdc++.h>
using namespace std;

#define str(i) std::to_string(i)

class Stack {

    int *m_arr,maxlen,m_ptr;
    mutex mut1;
    
    public:
    Stack(int len):maxlen(len),m_ptr(-1)
    { m_arr = new int[len];}

    ~Stack() {
        if(m_arr!=nullptr)
            delete[] m_arr;
    }

    void push(int val) {
        cout<<"TA"<<endl;
        mut1.lock();
        cout<< "Push:" << val << std::endl; 
        m_arr[++m_ptr]=val;
        mut1.unlock();
    } 

    int pop() {
        cout<<"TB"<<endl;
        mut1.lock();
        int val=m_arr[m_ptr--];
        mut1.unlock();
        return val;
    }

    bool isFull() const { return m_ptr==maxlen-1; }
    bool isEmpty()  const { return m_ptr==-1; }

    void display(){
        cout<<"Elements";
        for(int i=maxlen-1;i>=0;i--)
            cout<<m_arr[i];
    }
  
};

int main(){
    cout<<"---------Start---------"<<endl;
    Stack s1(2);
    Stack *stackPtr = &s1;
    
    
     std::thread t1(std::bind(&Stack::push,stackPtr,2));
    std::future<int> result = std::async(&Stack::pop,stackPtr);
    t1.join();
    cout<<"pop:"+str(result.get())<<endl;
    cout<<"----------END----------"<<endl;

  return 0;
}
