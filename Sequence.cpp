#include <algorithm>
#include<iostream>
#define MaxSize 50
using namespace std;
typedef struct{
    int data[MaxSize];
    int length;
}SeqList;
//插入
bool ListInsert(SeqList &L,int i,int e){
    if(i<1||i>L.length+1)
        return false;
    if(L.length>=MaxSize)
        return false;
    for(int j=L.length;j>=i;j--)
        L.data[j]=L.data[j-1];
    L.data[i-1]=e;
    L.length++;
    return true;
}
//删除
bool ListDelete(SeqList &L,int i,int &e)
{
    if(i<1||i>L.length)
        return false;
    e=L.data[i-1];
    for(int j=i;j<L.length;j++)
        L.data[j-1]=L.data[j];
    L.length--;
    return true;
}
//定位
int ListLocate(SeqList &L,int e){
    for(int i=0;i<L.length;i++)
        if(L.data[i]==e)
            return i+1;
    return 0;
}
//P18 二 1
bool LocateMinest(SeqList &L,int &e)
{
    if(L.length==0)
        return false;
    int minIndex=0;
    for(int i=1;i<L.length;i++)
        if(L.data[minIndex]>L.data[i])
            minIndex=i;
    e=L.data[minIndex];
    L.data[minIndex]=L.data[L.length-1];
    L.length--;
    return true;
}
//P18 二 2
void Revese(SeqList &L)
{
    int temp;
    for(int i=0,j=L.length-1;i<j;i++,j--)
    {
        temp=L.data[i];
        L.data[i]=L.data[j];
        L.data[j]=temp;
    }
}
//P18 二 3
void DeleteAll(SeqList &L,int e)
{
    int index=0;
    for(int i=0;i<L.length;i++)
        if(L.data[i]==e)
            continue;
        else
            L.data[index++]=L.data[i];
    L.length=index;
}
//P18 二 4
bool DeleteScaleAll(SeqList &L,int start,int end)
{
    int i,j;
    if(start>=end||L.length==0)
        return false;
    for(i=0;i<L.length&&L.data[i]<start;i++);
    if(i>=L.length)
        return false;
    for(j=i;j<L.length&&L.data[j]<=end;j++);
    for(;j<L.length;i++,j++)
        L.data[i]=L.data[j];
    L.length=i;
    return true;
}
//P18 二 5
bool DeleteScaleAll2(SeqList &L,int start,int end)
{
    if(start>=end||L.length==0)
        return false;
    int index=0;
    for(int i=0;i<L.length;i++)
    {
        if(!(L.data[i]>start&&L.data[i]<end))
            L.data[index++]=L.data[i];
    }
    L.length=index;
    return true;
}
//P18 二 6
bool DeleteSameAll(SeqList &L)
{
    if(L.length==0)
        return false;
    int index=0;
    for(int i=1;i<L.length;i++)
    {
        if(L.data[i]!=L.data[index])
            L.data[++index]=L.data[i];
    }
    L.length=index+1;
    return true;
}
void ListPrint(SeqList &L){
    for(int i=0;i<L.length;i++)
        cout<<L.data[i]<<"\t";
    cout<<endl;
}
int main()
{
    SeqList seqList;
    int e;
    seqList.length=0;
    ListInsert(seqList,1,9);
    ListInsert(seqList,1,9);
    ListInsert(seqList,1,9);
    ListInsert(seqList,1,7);
    ListInsert(seqList,1,6);
    ListInsert(seqList,1,5);
    ListInsert(seqList,1,4);
    ListInsert(seqList,1,1);
    ListInsert(seqList,1,1);
    ListInsert(seqList,1,1);
    ListPrint(seqList);
    DeleteSameAll(seqList);
    ListPrint(seqList);
}