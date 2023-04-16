#include <iostream>
#include "LinkedList.h"

using namespace std;


int main() {
    LinkedList<double> lst;
    lst.push_back(1.0);
    lst.push_back(2.0);
    lst.push_back(3.0);
    lst.push_back(4.0);

    for (Node<double> *curr = lst.get_head(); curr != NULL; curr = curr->get_next())
        cout << curr->get_value() << " ";
    cout << endl;

    return 0;
}
