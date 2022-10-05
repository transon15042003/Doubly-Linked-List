#include "IntDLinkedList.h"

int main()
{
    IntDLinkedList list;
    int size = 10;
    for(int index = 0; index < size; index++){
        list.add(index);
    }
    // cout << list.removeAt(5) << endl;
    // cout << list.removeItem(7) << endl;
    // cout << list.size() << endl;
    // cout << list.get(2) << endl;
    // list.set(0, 10);
    // cout << list.indexOf(10) << endl;
    // list.add(5, 11);
    list.dump();

    // IntDLinkedList list;
    // cout << list.empty() << endl;
    // int values[] = {10, 15, 2, 6, 4, 7, 40, 8};
    // int index[] = {0, 0, 1, 3, 2, 3, 5, 0};
    // for (int idx = 0; idx < 8; idx++)
    // {
    //     list.add(index[idx], values[idx]);
    // }

    // try
    // {
    //     list.add(-1, 16);
    // }
    // catch (std::out_of_range e)
    // {
    //     cout << "Index is out of range" << endl;
    // }

    // try
    // {
    //     list.add(42, 16);
    // }
    // catch (std::out_of_range e)
    // {
    //     cout << "Index is out of range" << endl;
    // }

    // cout << list.empty() << endl;
    // list.dump();
}