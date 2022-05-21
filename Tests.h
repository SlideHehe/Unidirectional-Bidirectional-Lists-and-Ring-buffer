#ifndef TESTS_H
#define TESTS_H

#include <chrono>
using ms = std::chrono::milliseconds;

#include "Unidirectional_list.h"
#include<forward_list>

#include "BDList.h"
#include<list>

#include "Ring_buf.h"
//#include<circular_buffer>

void Unidirectional_list_test();
void Time_Unidirectional_list_test();

void bdListTest();
void Time_bdListTest();


void Ring_buf_test();
//void Time_Ring_buf_test();

#endif //TESTS_H
