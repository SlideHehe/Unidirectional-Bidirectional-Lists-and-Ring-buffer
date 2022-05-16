#include "Tests.h"

void Bidirectional_list_test() {
    Bidirectional_List test_list;
    for (int i = 0; i < 15; i++)
        test_list.push(i);
    test_list.print();
    cout << "Count: " << test_list.getCount() << endl;

    test_list.insert(35, 5);
    test_list.print();
    cout << "Count: " << test_list.getCount() << endl;

    Iterator test_iterator(test_list.begin());
    cout << "Current node: " << *test_iterator << endl;
    test_iterator++;
    cout << "Current node: " << *test_iterator << endl;

    test_iterator = test_list.end();
    cout << "Current node: " << *test_iterator << endl;
    test_iterator--;
    cout << "Current node: " << *test_iterator << endl;

    for (int i = 0; i < 5; i++)
        test_list.pop();
    test_list.print();
    cout << "Count: " << test_list.getCount() << endl;

    test_list.erase(3);
    test_list.print();
    cout << "Count: " << test_list.getCount() << endl;

    cout << "Get by head by 3: " << test_list.getByHead(3) << endl;
    cout << "Get by tail by 3: " << test_list.getByTail(3) << endl;

    test_list.delAll();
    test_list.print();
}