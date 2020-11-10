#include<iostream>
#include"B.h"
using namespace std;
int main(){
     SortList<int> int_list;
     SortList<char> char_list;

     for(int i=0;i<5;i++){
          int_list.insert(i);
          char_list.insert('a'+i);
     }
     int_list.print();
     char_list.print();
     cout<<int_list.Kth(3)<<endl;
     cout<<char_list.Kth(4)<<endl;
     return 0;
}
