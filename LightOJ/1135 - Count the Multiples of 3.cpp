#include<bits/stdc++.h>
using namespace std;
#define inf 1<<29
#define vi vector<int>

class ST{
   vi lazy,tree,tree1,tree2;
   int n;
   int left(int p)
   {
       return p<<1;
   }
   int right(int p)
   {
       return (p<<1)+1;
   }
   void build(int p, int L, int R)
   {
       if(L==R)
       {
           tree[p]=1;
           return;
       }
       build(left(p),L,(L+R)>>1);
       build(right(p),((L+R)>>1)+1,R);
       tree[p] = tree[left(p)]+tree[right(p)];
   }

   void update(int p, int L,int R, int i, int j)
   {
       if(L > j || R < i)
        return;
       if(L>=i && R<=j)
       {
           lazy[p]+=1;
           swap(tree[p],tree1[p]);
           swap(tree2[p],tree[p]);
           return;
       }
       update(left(p),L,(L+R)>>1,i,j);
       update(right(p),((L+R)>>1) +1, R,i,j);
       tree[p] = tree[left(p)] + tree[right(p)];
       tree1[p] = tree1[left(p)] + tree1[right(p)];
       tree2[p] = tree2[left(p)] + tree2[right(p)];

       if(lazy[p]%3 == 1)
       {
           swap(tree[p],tree1[p]);
           swap(tree2[p],tree[p]);
       }
       else if(lazy[p]%3 == 2)
       {
           swap(tree[p],tree1[p]);
           swap(tree1[p],tree2[p]);
       }
   }

   int query(int p, int L, int R, int i, int j, int prop)
   {
      if(L > j || R < i)
        return 0;
      if(L >=i && R <=j)
      {
          if(prop%3==0)
            return tree[p];
          else if(prop%3==1)
            return tree2[p];
          else
            return tree1[p];
      }
      return query(left(p),L, (L+R)>>1,i,j,prop+lazy[p]) + query(right(p),((L+R)>>1)+1,R,i,j,prop+lazy[p]);
   }
   public:
       ST(int a)
       {
           n=a;
           lazy.assign(4*n,0);
           tree.assign(4*n,0);
           tree1.assign(4*n,0);
           tree2.assign(4*n,0);
           build(1,0,n-1);
       }

       void update(int i, int j)
       {
           update(1,0,n-1,i,j);
       }
       int query(int i, int j)
       {
           return query(1,0,n-1,i,j,0);
       }
};



int main()
{
    int t,tc=1,n,q;
    scanf("%d",&t);
    while(tc<=t)
    {
        printf("Case %d:\n",tc);
        scanf("%d %d",&n,&q);
        int a,b,c;
        ST st(n);
        for(int i=0; i<q; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(a==0)
            {
                st.update(b,c);
            }
            else
                printf("%d\n",st.query(b,c));
        }
        tc++;
    }
    return 0;
}
