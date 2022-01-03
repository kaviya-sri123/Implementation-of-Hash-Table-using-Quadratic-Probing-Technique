#include "hash_header.h"
int Hash::h(int x)
{
    return x%10;
}
int Hash::insert(int x)
{
    if(isFull())
    {
        cout<<"\nHash Table is full.\n\n";
        return -1;
    }
    else
    {
        int pos = h(x);
        if(hash[pos]==-1)
        {
            hash[pos]=x;
            capacity--;
            return 1;
        }
        else
        {
            for(int i=1;i<=10;i++)
            {
                pos=h(x);
                pos=(pos+(i*i))%10;
                if(hash[pos]==-1)
                {
                    hash[pos]=x;
                    capacity--;
                    return 1;
                }
            }
            return 0;
        }
    }
}
int Hash::search()
{
    if(capacity==10)
    {
        cout<<"\nTable is empty.\n\n";
        return 0;
    }
    else
    {
        int e;
        cout<<"Enter the element to search : ";
        cin>>e;
        for(int i=0;i<10;i++)
        {
            if(hash[i]==e)
            {
                cout<<"\nElement found.\n\n";
                return 1;
            }
        }
    }
    cout<<"\nElement not found.\n\n";
    return 0;
}
void Hash::display()
{
    if(capacity==10)
        cout<<"\nTable is empty.\n\n";
    else
    {
        cout<<"Quadratic Probing Hash Table\n\n";
        cout<<"Index\t\t"<<"Element"<<endl;
        for(int i=0;i<10;i++)
            cout<<i<<"\t|\t"<<hash[i]<<endl;
        cout<<"\n\n";
    }
}
bool Hash::isFull()
{
    if(capacity==0)
        return true;
    return false;
}