#include "Tests.h"


int main() {

    Unidirectional_list_test();
    //Time_Unidirectional_list_test();
    cout << "\n--------------------------------\n";
    bdListTest();
    //Time_bdListTest();
    cout << "\n--------------------------------\n";
    Ring_buf_test();


    return 0;
}
