#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,m,a;
    scanf("%d",&t);
    while(t--)
    {
        deque< pair <int,int> > dq;
        pair<int,int> b;
        int c=0;
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a);
            dq.push_back(make_pair(i,a));
        }
        while(1)
        {
            b = dq.front();
            dq.pop_front();

            bool flag = false;
            for(int i=0; i<dq.size(); i++)
                if(dq[i].second > b.second)
                {
                    dq.push_back(b);
                    flag = true;
                    break;
                }

            if(flag == false)
            {
                c++;
                if(b.first==m)
                    break;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
