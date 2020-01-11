#include<iostream>
using namespace std;

int main()
{
	int a =1025;
	int *p =&a;
	cout<<p<<endl;        // address of a
	cout<<p+1<<endl;      //address of a +4(size of integer)
	cout<<*p<<endl;       //a
	cout<<*p+1<<endl;     //*p =1024 +1 =1025
	cout<<*(p+1)<<endl;   //garbage value
	cout<<endl;
	
	//char pointer
	char *p1;
	p1=(char*)p;
	cout<<*p1<<endl;      // one  byte of 1024 in binary i.e. 1 in char
	printf("%d\n",*p1);   //1
	cout<<endl;
	
	
	//void pointer
	void *p0;
	p0=p;
	cout<<endl;
//	cout<<*p0; gives error ,no rerefrencing allowed for void pointers


//pointer to pointer
    int x=5;
    int *s;
    int **q;            // pointer to pointer
    s=&x;               
    q=&s;
    cout << *s << endl;
    cout << *q << endl;       // & of x
	cout << *(*q) << endl;	  //  x
	cout << **q << endl;      // x
	**q= 10;
	cout << x << endl;        // x=10
	**q = *s+2;
	cout << x << endl;        //x = 12
	cout<<endl;
	
	// array pointer
	int A[5] ={1,4,6,8,5};
	int *z;
	z = A;                    // same as z= &A[0]
	cout<<*z <<endl;          // A[0]
	cout<<*(z+1) <<endl;      //A[1]
	cout<<*z +1 <<endl;       //A[0]+1
}
