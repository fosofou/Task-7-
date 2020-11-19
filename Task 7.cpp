// Task 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#include <iostream>
#include "SLList.h"

using namespace std;
int main()
{
    setlocale(0, "");
    std::cout.setf(std::ios_base::boolalpha);
    SLList* list = SLList::genSLList();
    cout << "Сгенерированный список"<<endl;
    PrintSLList(list);
    DeleteDuplicate(list);
    cout <<endl<< "Список без дубликатов"<<endl;
    PrintSLList(list);
    cout << endl << "Элемент с конца: ";
    int index;
    cin >> index;
    cout<<SearchElem(index, list);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
