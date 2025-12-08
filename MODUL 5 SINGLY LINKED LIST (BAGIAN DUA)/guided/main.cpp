#include "listBuah.h"

#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = NIL;
    createList(List);

    dataBuah dtbuah;

nodeA = alokasi("jeruk", 100, 3000);
nodeB = alokasi("apel", 75, 4000);
nodeC = alokasi("pir", 87, 5000);
nodeD = alokasi("semangka", 43, 11500);
nodeE = alokasi("durian", 15, 31450);

insertFirst(List, nodeA);
insertLast(List, nodeB);
insertAfter(List, nodeC, nodeA);
insertAfter(List, nodeD, nodeC);
insertLast(List, nodeE);

cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" <<endl;
printList(List);
cout << "jumlah node : " << nbList(List) << endl;
cout << endl;

updateFirst(List);
updateLast(List);
updateAfter(List, nodeD);

cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
printList(List);
cout << "jumlah node : " <<nbList(List) << endl;
cout << endl;

FindNodeByData(List, "kalpa");
FindNodeByAddress(List, nodeC);
FindNodeByRange(List, 50, 1000);

delFirst(List);
delLast(List);
delAfter(List, nodeD, nodeE);


cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
printList(List);
cout << "jumlah node ; " << nbList(List) << endl;
cout << endl;

deleteList(List);
cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
printList(List);
cout << "jumlah Node: " <<nbList(List) << endl;
return 0;
}