#include<bits/stdc++.h>
using namespace std ;

struct product
{
    char name[10];
    double weight;
    double profit;
    double ratio;
};

int main ()
{
    int n;
    cout<<"Enter number of product: ";
    cin>>n;

    struct product p[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the name of product "<<i+1<<": ";
        cin>>p[i].name;
        cout<<"Enter the weight of product "<<i+1<<": ";
        cin>>p[i].weight;
        cout<<"Enter the profit of product "<<i+1<<": ";
        cin>>p[i].profit;
        p[i].ratio= p[i].profit/p[i].weight;

    }

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(p[i].ratio<p[j].ratio)
            {
                product temp = p [i];
                p[i]=p[j];
                p[j]=temp;

            }
        }
    }
    double capacity;
    cout<<"Enter capacity: ";
    cin>>capacity;
    cout<<endl;
    double maxprofit=0;
    cout<<"Selected product: ";
    for(int i=0; i<n; i++)
    {
        if(capacity<=0)
        {
            break;
        }
        else if (p[i].weight<=capacity)
        {
            cout<<p[i].name<<" ";
            maxprofit=maxprofit+p[i].profit;
            capacity =capacity-p[i].weight;

        }
        else
        {
            cout<<p[i].name;
            maxprofit+=p[i].ratio*capacity;
            capacity =0;
        }
    }
    cout<<endl<<"max profit:"<<fixed<<setprecision(2)<<maxprofit;
}
