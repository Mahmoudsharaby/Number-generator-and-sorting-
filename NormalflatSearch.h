#ifndef NORMALFLATSEARCH_H
#define NORMALFLATSEARCH_H
class normalsearch
{
public:
    bool search(int arr[],int size, int value)
    {
        int x=0;
        for(int i=0;i<size;i++)
        {
            if(arr[i]==value)
            {
                x=1;
                return x;
            }
        }
        return x;
    }
};

#endif // NORMALFLATSEARCH_H
