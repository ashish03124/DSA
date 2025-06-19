#include<iostream>
#define MAX 100
using namespace std;

class ArrayOperation
{
    int n;
    int a[100];
public:
    ArrayOperation()
    {
        cout<<"Enter the size of array : ";
        cin>>n;
    }
    void create(); // to inser at some element to array
    // Travsal : forward and backward
    void Travsal_Forward();
};
void ArrayOperation::create()
{
    cout<<"Enter the"<<n<<" number of element :"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
}
void ArrayOperation::Travsal_Forward()
{
    cout<<" The Arrays element are "<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<endl;
}
int main()
{
    ArrayOperation t;
    t.create();
    t.Travsal_Forward();
    return 0;
}