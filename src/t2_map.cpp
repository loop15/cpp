// -------------------------------------------------------------------------
// 文件名 : list1.cpp
// 创建者 : 方煜宽
// 　邮箱 ： fangyukuan@gmail.com
// 创建时间 : 2010-9-19 15:58
// 功能描述 : STL中的list就是一双向链表，可高效地进行插入删除元素。
//
// -------------------------------------------------------------------------
//#include " stdafx.h "
#include <iostream>
#include <list>
using namespace std;

list < int > g_list1;
list < int > g_list2;

//////////////////////////////////////////////////////////////////////// //

// 初始化全局链表
void InitList()
{
// push_back()增加一元素到链表尾
    g_list1.push_back(1);
    g_list1.push_back(2);
    g_list1.push_back(3);

// push_front()增加一元素到链表头
    g_list2.push_front(6);
    g_list2.push_front(5);
    g_list2.push_front(4);
}

// 输出一个链表
void ShowList(list < int > &listTemp)
{
// size()返回链表中元素个数
    cout << listTemp.size() << endl;

    for (list < int > ::iterator it = listTemp.begin(); it != listTemp.end(); ++ it)
    {
        cout << * it << ' ' ;
    }
    cout << endl;
}

//////////////////////////////////////////////////////////////////////// //

// 构造函数，空链表
void constructor_test0()
{
    list < int > listTemp;
    cout << listTemp.size() << endl;
}

// 构造函数，建一个含三个默认值是0的元素的链表
void constructor_test1()
{
    list < int > listTemp(3);
    ShowList(listTemp);
}

// 构造函数，建一个含五个元素的链表，值都是1
void constructor_test2()
{
    list < int > listTemp(5, 1);
    ShowList(listTemp);
}

// 构造函数，建一个g_list1的copy链表
void constructor_test3()
{
    list < int > listTemp(g_list1);
    ShowList(listTemp);
}

// 构造函数，listTemp含g_list1一个区域的元素[_First, _Last)
void constructor_test4()
{
    list < int > listTemp(g_list1.begin(), g_list1.end());
    ShowList(listTemp);
}

// assign()分配值，有两个重载
// template
// void assign ( InputIterator first, InputIterator last );
// void assign ( size_type n, const T& u );
void assign_test()
{
    list < int > listTemp(5, 1);
    ShowList(listTemp);

    listTemp.assign(4, 3);
    ShowList(listTemp);

    listTemp.assign(++ g_list1.begin(), g_list1.end());
    ShowList(listTemp);
}

// operator=
void operator_equality_test()
{
    g_list1 = g_list2;
    ShowList(g_list1);
    ShowList(g_list2);
}

// front()返回第一个元素的引用
void front_test7()
{
    cout << g_list1.front() << endl;
}

// back()返回最后一元素的引用
void back_test()
{
    cout << g_list1.back() << endl;
}

// begin()返回第一个元素的指针(iterator)
void begin_test()
{
    list < int > ::iterator it1 = g_list1.begin();
    cout << *++ it1 << endl;

    list < int > ::const_iterator it2 = g_list1.begin();
    it2 ++ ;
// (*it2)++; // *it2 为const 不用修改
    cout << * it2 << endl;

}

// end()返回 [最后一个元素的下一位置的指针] (list为空时end()= begin())
void end_test()
{
    list < int > ::iterator it = g_list1.end(); // 注意是：最后一个元素的下一位置的指针
    -- it;
    cout << * it << endl;
}

// rbegin()返回链表最后一元素的后向指针
void rbegin_test()
{
    list < int > ::reverse_iterator it = g_list1.rbegin();
    for (; it != g_list1.rend(); ++ it)
    {
        cout << * it << ' ' ;
    }
    cout << endl;
}

// rend()返回链表第一元素的下一位置的后向指针
void rend_test()
{
    list < int > ::reverse_iterator it = g_list1.rend();
    -- it;
    cout << * it << endl;
}

// push_back()增加一元素到链表尾
void push_back_test()
{
    ShowList(g_list1);
    g_list1.push_back(4);
    ShowList(g_list1);
}

// push_front()增加一元素到链表头
void push_front_test()
{
    ShowList(g_list1);
    g_list1.push_front(4);
    ShowList(g_list1);
}

// pop_back()删除链表尾的一个元素
void pop_back_test()
{
    ShowList(g_list1);
    cout << endl;

    g_list1.pop_back();
    ShowList(g_list1);

}

// pop_front()删除链表头的一元素
void pop_front_test()
{
    ShowList(g_list1);
    cout << endl;

    g_list1.pop_front();
    ShowList(g_list1);
}

// clear()删除所有元素
void clear_test()
{
    ShowList(g_list1);
    g_list1.clear();
    ShowList(g_list1);
}

// erase()删除一个元素或一个区域的元素(两个重载函数)
void erase_test()
{
    ShowList(g_list1);
    g_list1.erase(g_list1.begin());
    ShowList(g_list1);

    cout << endl;

    ShowList(g_list2);
    g_list2.erase(++ g_list2.begin(), g_list2.end());
    ShowList(g_list2);
}

// remove()删除链表中匹配值的元素(匹配元素全部删除)
void remove_test()
{
    ShowList(g_list1);
    g_list1.push_back(1);
    ShowList(g_list1);

    g_list1.remove(1);
    ShowList(g_list1);
}

bool myFun(const int &value)
{
    return (value < 2);
}
// remove_if()删除条件满足的元素(会遍历一次链表)
void remove_if_test()
{
    ShowList(g_list1);
    g_list1.remove_if(myFun);
    ShowList(g_list1);
}


// empty()判断是否链表为空
void empty_test()
{
    list < int > listTemp;
    if (listTemp.empty())
        cout << " listTemp为空 " << endl;
    else
        cout << " listTemp不为空 " << endl;
}


// max_size()返回链表最大可能长度:1073741823
void max_size_test()
{
    list < int > ::size_type nMax = g_list1.max_size();
    cout << nMax << endl;
}


// resize()重新定义链表长度(两重载函数)：
void resize_test()
{
    ShowList(g_list1);
    g_list1.resize(9);   // 用默认值填补
    ShowList(g_list1);
    cout << endl;

    ShowList(g_list2);
    g_list2.resize(9, 51);    // 用指定值填补
    ShowList(g_list2);
}

// reverse()反转链表
void reverse_test()
{
    ShowList(g_list1);
    g_list1.reverse();
    ShowList(g_list1);
}


// sort()对链表排序，默认升序(两个重载函数)
void sort_test()
{
    list < int > listTemp;
    listTemp.push_back(9);
    listTemp.push_back(3);
    listTemp.push_back(5);
    listTemp.push_back(1);
    listTemp.push_back(4);
    listTemp.push_back(3);

    ShowList(listTemp);
    listTemp.sort();
    ShowList(listTemp);

    listTemp.sort(greater < int > ());
    ShowList(listTemp);
}

// merge()合并两个升序序链表并使之成为另一个升序.
void merge_test1()
{
    list < int > listTemp2;
    listTemp2.push_back(3);
    listTemp2.push_back(4);

    list < int > listTemp3;
    listTemp3.push_back(9);
    listTemp3.push_back(10);

    ShowList(listTemp2);
    cout << endl;
    ShowList(listTemp3);
    cout << endl;

    listTemp2.merge(listTemp3);
    ShowList(listTemp2);
}


bool myCmp(int first, int second)
{
    return (int (first) > int (second));
}

// merge()合并两个降序链表并使之成为另一个降序.
void merge_test2()
{
    list < int > listTemp2;
    listTemp2.push_back(4);
    listTemp2.push_back(3);

    list < int > listTemp3;
    listTemp3.push_back(10);
    listTemp3.push_back(9);

    ShowList(listTemp2);
    cout << endl;
    ShowList(listTemp3);
    cout << endl;

// listTemp2.merge(listTemp3, greater()); // 第二个参数可以是自己定义的函数如下
    listTemp2.merge(listTemp3, myCmp);
    ShowList(listTemp2);
}

// splice()对两个链表进行结合(三个重载函数),结合后第二个链表清空
// void splice ( iterator position, list& x );
// void splice ( iterator position, list& x, iterator i );
// void splice ( iterator position, list& x, iterator first, iterator last );
void splice_test()
{
    list < int > listTemp1(g_list1);
    list < int > listTemp2(g_list2);

    ShowList(listTemp1);
    ShowList(listTemp2);
    cout << endl;

//
    listTemp1.splice(++ listTemp1.begin(), listTemp2);
    ShowList(listTemp1);
    ShowList(listTemp2);

//
    listTemp1.assign(g_list1.begin(), g_list1.end());
    listTemp2.assign(g_list2.begin(), g_list2.end());
    listTemp1.splice(++ listTemp1.begin(), listTemp2, ++ listTemp2.begin());
    ShowList(listTemp1);
    ShowList(listTemp2);

//
    listTemp1.assign(g_list1.begin(), g_list1.end());
    listTemp2.assign(g_list2.begin(), g_list2.end());
    listTemp1.splice(++ listTemp1.begin(), listTemp2, ++ listTemp2.begin(), listTemp2.end());
    ShowList(listTemp1);
    ShowList(listTemp2);

}

// insert()在指定位置插入一个或多个元素(三个重载函数)
// iterator insert ( iterator position, const T& x );
// void insert ( iterator position, size_type n, const T& x );
// template
// void insert ( iterator position, InputIterator first, InputIterator last );
void insert_test()
{
    list < int > listTemp1(g_list1);
    ShowList(listTemp1);
    listTemp1.insert(listTemp1.begin(), 51);
    ShowList(listTemp1);
    cout << endl;

    list < int > listTemp2(g_list1);
    ShowList(listTemp2);
    listTemp2.insert(listTemp2.begin(), 9, 51);
    ShowList(listTemp2);
    cout << endl;

    list < int > listTemp3(g_list1);
    ShowList(listTemp3);
    listTemp3.insert(listTemp3.begin(), g_list2.begin(), g_list2.end());
    ShowList(listTemp3);

}

// swap()交换两个链表(两个重载)
void swap_test()
{
    ShowList(g_list1);
    ShowList(g_list2);
    cout << endl;

    g_list1.swap(g_list2);
    ShowList(g_list1);
    ShowList(g_list2);
}

bool same_integral_part(double first, double second)
{
    return (int (first) == int (second));
}

// unique()删除相邻重复元素
void unique_test()
{
    list < int > listTemp;
    listTemp.push_back(1);
    listTemp.push_back(1);
    listTemp.push_back(4);
    listTemp.push_back(3);
    listTemp.push_back(5);
    listTemp.push_back(1);
    list < int > listTemp2(listTemp);

    ShowList(listTemp);
    listTemp.unique(); // 不会删除不相邻的相同元素
    ShowList(listTemp);
    cout << endl;

    listTemp.sort();
    ShowList(listTemp);
    listTemp.unique();
    ShowList(listTemp);
    cout << endl;

    listTemp2.sort();
    ShowList(listTemp2);
    listTemp2.unique(same_integral_part);
    ShowList(listTemp2);

}

// 主函数，下面要测试哪个就把那个注释去掉即可
int main(int argc, char *argv[])
{
    InitList();
    ShowList(g_list1);
// ShowList(g_list2);

// constructor_test0();
// constructor_test1();
// constructor_test2();
// constructor_test3();
// constructor_test4();
// assign_test();
// operator_equality_test();
// front_test7();
// back_test();
// begin_test();
// end_test();
// rbegin_test();
// rend_test();
// push_back_test();
// push_front_test();
// pop_back_test();
// pop_front_test();
// clear_test();
// erase_test();
// remove_test();
// remove_if_test();
// empty_test();
// max_size_test();
// resize_test();
// reverse_test();
// sort_test();
// merge_test1();
// merge_test2();
// splice_test();
// insert_test();
// swap_test();
// unique_test();
    return 0 ;
}
