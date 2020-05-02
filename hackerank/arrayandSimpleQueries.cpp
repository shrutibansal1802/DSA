#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,m;
    cin>>n>>m;
    vector<int>v1;
    for(int i=0;i<n;i++)
    {
        int el;
        cin>>el;
        v1.push_back(el);
    }
    while(m--)
    {
        int q,q1,q2;
        cin>>q>>q1>>q2;
        vector<int>v2;
        
        v2.assign(v1.begin()+q1-1,v1.begin()+q2);
        v1.erase(v1.begin()+q1-1,v1.begin()+q2);
        

        if(q==1)
        {
            v1.insert(v1.begin(),v2.begin(),v2.end());
        }
        else
        {
            v1.insert(v1.end(),v2.begin(),v2.end());
        }
        v2.clear();
    }
    cout<<abs(v1[0]-v1[n-1])<<endl;
      for (int i = 0; i < n; i++) 
        cout << v1[i] << " "; 
    return 0;
}
