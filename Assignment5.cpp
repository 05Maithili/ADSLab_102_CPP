#include<iostream>
using namespace std;

// structure to store shop start and end times
struct shop{
    int start;
    int end;
};

void sortByEndTime(shop shops[], int N)
{
    for(int i=0; i<N-1; i++)
    {
        for(int j=0; j<N-i-1; i++)
        {
            if(shops[j].end>shops[j+1].end)
            {
                shop temp = shops[j];
                shops[j] = shops[j+1];
                shops[j+1] = temp;
            }
        }
    }
}

int maxShops(int S[], int E[], int N, int K)
{
    shop shops[10];
    for(int i= 0; i<N ; i++)
    {
        shops[i].start= S[i];
        shops[i].end = E[i];
    }

    sortByEndTime(shops, N);

    int personEndTime[10];
    for(int i = 0; i < K;i++ )
    {
        personEndTime[i]=-99;
    }
    
    int count = 0;
     
    for(int i = 0 ; i< N; i++)
    {
        for(int p =0 ; p< K; p++)
        {
            if(personEndTime[p] <= shops[i].start)
            {
                personEndTime[p]=shops[i].end;
            }
            count++;
            break;
        }
    }
    return count;
}

int main()
{
    int N = 6 , K=2;
    int S[]={1,3,0,5,8,5};
    int E[]={2,4,6,7,9,9};
    cout<<"\nMax Shop visted:"<<maxShops(S, E, N , K);
    return 0;
}
