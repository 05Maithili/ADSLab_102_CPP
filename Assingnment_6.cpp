#include <iostream>
using namespace std;
void maxof(int a[],int n)
    {
    int maxtotal=a[n-1],profit=0;
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]<maxtotal)
        {

            profit+=(maxtotal-a[i]);
        }
        else
        {

            maxtotal=a[i];
        }
    }
    cout<<"maxprofit: "<<profit<<endl;
    }
int main() 
{
    int n;
    cout<<"enter no of days:";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    maxof(a,n);


    return 0;
}
