#include "IntDLinkedList.h"

int main(){
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

    list.dump();
}