#include "Tests.h"

void bdListTest() {
    BDList testBDList;
    for (int i = 0; i < 15; i++)
        testBDList.push(14 - i);
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

    BDListIterator testBDListIterator(testBDList.begin());
    cout << "Current node: " << *testBDListIterator << endl;
    testBDListIterator++;
    cout << "Current node: " << *testBDListIterator << endl;

    testBDListIterator = testBDList.end();
    cout << "Current node: " << *testBDListIterator << endl;
    testBDListIterator--;
    cout << "Current node: " << *testBDListIterator << endl;

    for (int i = 0; i < 5; i++)
        testBDList.pop();
    testBDList.print();
    cout << "Count: " << testBDList.getCount() << endl;

    testBDList.erase(3);
    testBDList.print();
    cout << "Count: " << testBDList.getCount() << endl;

    cout << "Get by head by 3: " << testBDList.getByHead(3) << endl;
    cout << "Get by tail by 3: " << testBDList.getByTail(3) << endl;

    BDList testSplit = testBDList.split(7);
    cout << "Split lists\n First:\n";
    testBDList.print();
    cout << "Second:\n";
    testSplit.print();

    testBDList.delAll();
    testBDList.print();
}