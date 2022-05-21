#include "Tests.h"


void bdListTest() {
    BDList testBDList;
    for (int i = 1; i <= 15; i++)
        testBDList.pushEnd(14 - i);
    cout << "Source list:\n";
    testBDList.print();
    cout << "Count: " << testBDList.getCount() << endl;

    testBDList.quickSort();
    cout << "Sorted list:\n";
    testBDList.print();
    cout << "Count: " << testBDList.getCount() << endl;

    testBDList.insert(35, 5);
    testBDList.print();
    cout << "Count: " << testBDList.getCount() << endl;

    /*BDListIterator testBDListIterator(testBDList.begin());
    cout << "Current node: " << *testBDListIterator << endl;
    testBDListIterator++;
    cout << "Current node: " << *testBDListIterator << endl;*/

    /*testBDListIterator = testBDList.end();
    cout << "Current node: " << *testBDListIterator << endl;
    testBDListIterator--;
    cout << "Current node: " << *testBDListIterator << endl;*/

    for (int i = 0; i < 5; i++)
        testBDList.popEnd();
    testBDList.print();
    cout << "Count: " << testBDList.getCount() << endl;

    testBDList.erase(3);
    testBDList.print();
    cout << "Count: " << testBDList.getCount() << endl;

    /*cout << "Get by head by 3: " << testBDList.getByHead(3) << endl;
    cout << "Get by tail by 3: " << testBDList.getByTail(3) << endl;*/

    BDList testSplit = testBDList.split(7);
    cout << "Split lists\nFirst:\n";
    testBDList.print();
    cout << "Second:\n";
    testSplit.print();

    cout << (testBDList != testSplit) << endl;
}


void Time_bdListTest() {
    cout << "\n----------------------------------" << endl << "Time comparison test between STL list and written Bidirectional_list:" << endl;
    auto written_bdListTest_start = std::chrono::high_resolution_clock::now();

    BDList l1, l2;
    for (int i = 0; i < 20000; i++) {
        l1.pushBegin(rand() % 1000);
    }
    //cout << l1.getCount() << endl;

    for (int i = 0; i < 10000; i++) {
        l1.popBegin();
    }
    //cout << l1.getCount()<<endl;

    for (int i = 0; i < 10; i++) {
        l2.pushBegin(i);
    }
    //cout << l2.getCount() << endl;
    BDListIterator curr = l2.begin();
    BDListIterator stop = l2.end();
    while (curr != stop)
    {
        cout << *curr << " ";
        curr++;
    }cout << *curr << " ";

    l1.delAll();
    for (int i = 0; i < 20000; i++) {
        l1.pushBegin(i);
    }
    cout << endl;
    //cout << endl << l2.getCount() << endl;

    auto written_bdListTest_end = std::chrono::high_resolution_clock::now();
    auto written_bdListTest_res = std::chrono::duration_cast<ms>(written_bdListTest_end - written_bdListTest_start).count();
    cout << "Written Bidirectional_list performance time: " << written_bdListTest_res << " ms" << endl << endl;



    auto STL_list_start = std::chrono::high_resolution_clock::now();
    std::list<int> ll1, ll2;
    for (int i = 0; i <= 20000; i++) {
        ll1.push_front(rand() % 1000);
    }
    //cout << ll1.max_size() << endl;

    for (int i = 0; i < 10000; i++) {
        ll1.pop_front();
    }
    //cout << ll1.max_size() << endl;

    for (int i = 0; i < 10; i++) {
        ll2.push_front(i);
    }
    //cout<<ll2.max_size()<<endl;
    auto current = ll2.begin();
    auto end = ll2.end();
    while (current != end)
    {
        cout << *current << " ";
        current++;
    }

    ll1.clear();
    for (int i = 0; i < 20000; i++) {
        ll1.push_front(i);
    }
    cout << endl;
    //cout << endl << ll2.max_size() << endl;

    auto STL_list_end = std::chrono::high_resolution_clock::now();
    auto STL_list_res = std::chrono::duration_cast<ms>(STL_list_end - STL_list_start).count();
    cout << "STL list performance time: " << STL_list_res << " ms" << endl << endl;
}
//////////////////////////////////////////////////////////////////////



void Unidirectional_list_test() {
    Unidirectional_list testlist;
    for (int i = 1; i <= 15; i++)
        testlist.push(rand()%100);
    cout << "Source list:\n";
    testlist.print();
    cout << "Count: " << testlist.getCount() << endl << endl;

    testlist.Xoar();
    cout << "Sorted list:\n";
    testlist.print();
    cout << "Count: " << testlist.getCount() << endl;

    testlist.insert(35, 3);
    testlist.print();
    cout << "Count: " << testlist.getCount() << endl;

    /*Iterator_uni Iter(testlist.begin());
    cout << "Current node: " << *Iter << endl;
    Iter++;
    cout << "Current node: " << *Iter << endl;*/

    

    for (int i = 0; i < 5; i++)
        cout<<testlist.pop()<<" ";
    cout << endl;
    testlist.print();
    cout << "Count: " << testlist.getCount() << endl;

    testlist.erase(3);
    testlist.print();
    cout << "Count: " << testlist.getCount() << endl;
  
    Unidirectional_list testSplit = testlist.Div_list(50);
    cout << "Current lists:\n First:\n";
    testlist.print();
    cout << " Second:\n";
    testSplit.print();

    cout<<(testlist != testSplit);
}



void Time_Unidirectional_list_test()
{
    cout << "\n----------------------------------" << endl << "Time comparison test between STL forward_list and written Unidirectional_list:" << endl;
    auto written_Unidirectional_list_start = std::chrono::high_resolution_clock::now();

    Unidirectional_list l1, l2;
    for (int i = 0; i < 20000; i++) {
        l1.push_first(rand() % 1000);
    }
    //cout << l1.getCount() << endl;

    for (int i = 0; i < 10000; i++) {
        l1.pop_first();
    }
    //cout << l1.getCount()<<endl;

    for (int i = 0; i < 10; i++) {
        l2.push_first(i);
    }
    //cout << l2.getCount() << endl;
    Iterator_uni curr = l2.begin();
    Iterator_uni stop = l2.end();
    while (curr != stop)
    {
        cout << *curr << " ";
        curr++;
    }cout << *curr << " ";

    l1.delAll();
    for (int i = 0; i < 20000; i++) {
        l1.push_first(i);
    }
    cout << endl;
    //cout << endl << l2.getCount() << endl;

    auto written_Unidirectional_list_end = std::chrono::high_resolution_clock::now();
    auto written_Unidirectional_list_res = std::chrono::duration_cast<ms>(written_Unidirectional_list_end - written_Unidirectional_list_start).count();
    cout << "Written Unidirectional_list performance time: " << written_Unidirectional_list_res << " ms" << endl << endl;



    auto STL_forward_list_start = std::chrono::high_resolution_clock::now();
    std::forward_list<int> ll1, ll2;
    for (int i = 0; i <= 20000; i++) {
        ll1.push_front(rand() % 1000);
    }
    //cout << ll1.max_size() << endl;

    for (int i = 0; i < 10000; i++) {
        ll1.pop_front();
    }
    //cout << ll1.max_size() << endl;

    for (int i = 0; i < 10; i++) {
        ll2.push_front(i);
    }
    //cout<<ll2.max_size()<<endl;
    auto current = ll2.begin();
    auto end = ll2.end();
    while (current != end)
    {
        cout << *current << " ";
        current++;
    }

    ll1.clear();
    for (int i = 0; i < 20000; i++) {
        ll1.push_front(i);
    }
    cout << endl;
    //cout << endl << ll2.max_size() << endl;

    auto STL_forward_list_end = std::chrono::high_resolution_clock::now();
    auto STL_forward_list_res = std::chrono::duration_cast<ms>(STL_forward_list_end - STL_forward_list_start).count();
    cout << "STL forward_list performance time: " << STL_forward_list_res << " ms" << endl << endl;

}



////////////////////////////////////////////////////////////////




void Ring_buf_test() {
    Ring_buf testbuf(16);
    for (int i = 1; i <= 15; i++)
        testbuf.push(rand() % 100);
    cout << "Source list:\n";
    testbuf.show();
    cout << "Count: " << testbuf.count() << endl << endl;

    testbuf.quick_sort();
    cout << "Sorted list:\n";
    testbuf.show();
    cout << "Count: " << testbuf.count() << endl;

    testbuf.insert(35, 3);
    testbuf.show();
    cout << "Count: " << testbuf.count() << endl;

    /*RingIterator Iter(testbuf.begin());
    cout << "Current node: " << *Iter << endl;
    Iter++;
    cout << "Current node: " << *Iter << endl;*/



    for (int i = 0; i < 5; i++)
        cout << testbuf.pop() << " ";
    cout << endl;
    testbuf.show();
    cout << "Count: " << testbuf.count() << endl;

    testbuf.erase(3);
    testbuf.show();
    cout << "Count: " << testbuf.count() << endl;

    Ring_buf test1(15), test2(15);
    testbuf.list_split(test1, test2, 60);
    cout << "Current lists:\n First:\n";
    test1.show();
    cout << " Second:\n";
    test2.show();

    cout << (test1 != test2);
}



//void Time_Ring_buf_test() {
//
//
//}
