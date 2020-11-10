#include<iostream>
using namespace std;

 void merge(int *data,int start,int end,int *result)
{
    int left_length = (end - start + 1) / 2 + 1;//�󲿷����������Ԫ�صĸ���
    int left_index = start;
    int right_index = start + left_length;
    int result_index = start;
    while(left_index < start + left_length && right_index < end+1)
    {
        //�Էֱ��Ѿ��ź�������������������кϲ�
        if(data[left_index] <= data[right_index])
            result[result_index++] = data[left_index++];
        else
            result[result_index++] = data[right_index++];
    }
    while(left_index < start + left_length)
        result[result_index++] = data[left_index++];
    while(right_index < end+1)
        result[result_index++] = data[right_index++];
}

void merge_sort(int *data, int start, int end, int *result)
{
    if(1 == end - start)//���������ֻ������Ԫ�أ����������Ԫ�ؽ�������
    {
        if(data[start] > data[end])
        {
            int temp  = data[start];
            data[start] = data[end];
            data[end] = temp;
        }
        return;
    }
    else if(0 == end - start)//���ֻ��һ��Ԫ�أ���������
        return;
    else
    {
        //�������������䣬�ֱ�������������������
        merge_sort(data,start,(end-start+1)/2+start,result);
        merge_sort(data,(end-start+1)/2+start+1,end,result);
        //��ʼ�鲢�Ѿ��ź����start��end֮�������
        merge(data,start,end,result);
        //���������������ݸ��Ƶ�ԭʼ������ȥ
        for(int i = start;i <= end;++i)
            data[i] = result[i];
    }
}

int main()
{

    int t;cin>>t;
    for(int k=0;k<t;k++){
    int n;
    cin>>n;
    int *a,*result;
    a=new int[n];
    result=new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    merge_sort(a,0,n-1,result);
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
        cout<<endl;}
    return 0;
}