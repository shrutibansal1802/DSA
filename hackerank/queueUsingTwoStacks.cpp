#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

class StackQueue{
private:   
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int printpop();
    void pop();
}; 

void StackQueue :: push(int x)
 {
        s1.push(x);
 }

int StackQueue :: printpop()
{
    if(s2.empty() && s1.empty())
        return -1;
        
        if(s2.empty())
        { while(!s1.empty())
            { s2.push(s1.top());
                s1.pop();
            }
        }
       
        int temp=s2.top();
       return temp;
       
}
void StackQueue :: pop()
{
    // if(s2.empty() && s1.empty())
    //     return ;
        
        if(s2.empty())
        { while(!s1.empty())
            { s2.push(s1.top());
                s1.pop();
            }
        } 
       s2.pop();      
}
int main() {
    StackQueue *sq=new StackQueue();
   int q;
   cin>>q;
   while(q--)
   {
       int query;
       cin >>query;

       if(query==1)
       {
            int x;
            cin>>x;
            sq->push(x);
       }
       else if(query==2)
       {
           sq->pop();
       }
       else
       {
          cout<<sq->printpop()<<endl; 
       }
   }  
    return 0;
}
