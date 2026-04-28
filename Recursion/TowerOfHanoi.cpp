#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void tower(int src,int help,int dest,int n,int &count)
{
    count++;
    if(n==1)
    {
        cout << "Moving " << n << " from " << src << " to " << dest << endl;
        return;
    }

    tower(src,dest,help,n-1,count);
    cout << "Moving " << n << " from " << src << " to " << dest << endl;
    tower(help,src,dest,n-1,count);

    return;
}

int main()
{
    int n = 4;
    int src=1,help=2,dest=3,count=0;
    tower(src,help,dest,n,count);

    cout<<"Total steps are : "<<count<<endl;


    return 0;
}