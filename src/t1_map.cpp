#include <iostream>
#include <map>
using namespace std;
int main()
{
    map <string, int> mymap;
    map <string, int>:: iterator it;
    mymap["China"] = 100;
    mymap["English"] = 100;
    mymap["America"] = 100;

    cout << "======遍历======\n";
    for (it = mymap.begin(); it != mymap.end(); it++)
        cout << (*it).first << ":" << (*it).second << endl;
    /*
    通过迭代器可以读取它指向的元素，*迭代器名就表示迭代器指向的元素。通过非常量迭代器还能修改其指向的元素。

    STL 标准库为 map 容器配备的是双向迭代器（bidirectional iterator）。这意味着，map 容器迭代器只能进行 ++p、p++、--p、p--、*p 操作，并且迭代器之间只能使用 == 或者 != 运算符进行比较。
    */

    cout << "=====包含=======\n";
    if (mymap.count("China"))
        cout << "exist China" << endl;
    else
        cout << "No exist China" << endl;

    cout << "=====键值对的第一个、第二个=======\n";
    //c++ 里面的map容器的迭代器里面 有个first 和 second
    //就是键值对的第一个和第二个
    map<string, int> m;
    m["one"] = 1;
    map<string, int>::iterator p = m.begin();
    p->first;    // 这个是 string 值是 "one"
    p->second;   //这个是 int 值是 1
    cout << (*p).first << ":" << (*p).second << endl;

    return 0;
}

/*
//输出结果为
America:300
China:100
English:200
//注：默认情况下，键值对是按键首字母的ascll大小，升序排列
*/

/*
C++ Maps是一种关联式容器，包含“关键字/值”对
begin()          返回指向map头部的迭代器
clear(）         删除所有元素
count()          返回指定元素出现的次数
empty()          如果map为空则返回true
end()            返回指向map末尾的迭代器
equal_range()    返回特殊条目的迭代器对
erase()          删除一个元素
find()           查找一个元素
get_allocator()  返回map的配置器
insert()         插入元素  s
key_comp()       返回比较元素key的函数
lower_bound()    返回键值>=给定元素的第一个位置
max_size()       返回可以容纳的最大元素个数
rbegin()         返回一个指向map尾部的逆向迭代器
rend()           返回一个指向map头部的逆向迭代器
size()           返回map中元素的个数
swap()            交换两个map
upper_bound()     返回键值>给定元素的第一个位置
value_comp()      返回比较元素value的函数
*/