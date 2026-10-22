#include "DLL.h"

int main() {
    List L;
    infotype H;
    address Elm;

    createList(L);
    printList(L);

    cin >> H.title >> H.url >> H.timestamp >> H.visitcount;
    Elm = createElemen(H);
    insertAscending(L, Elm);
    printList(L);

    cin >> H.title >> H.url >> H.timestamp >> H.visitcount;
    Elm = createElemen(H);
    insertAscending(L, Elm);
    printList(L);

    cin >> H.title >> H.url >> H.timestamp >> H.visitcount;
    Elm = createElemen(H);
    insertAscending(L, Elm);
    printList(L);

    if (findElemen(L, "OpenAI")) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    cout << moreThanOnce(L) << endl;

    return 0;
}
