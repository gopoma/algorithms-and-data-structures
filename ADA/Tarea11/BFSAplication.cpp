#include "CGraphMatrix.h"

int main() {
    CGraphMatrix *g = new CGraphMatrix(6, false);
    g->addEdge(0, 1, 11);
    g->addEdge(0, 2, 12);
    g->addEdge(0, 4, 13);
    g->addEdge(0, 5, 14);
    g->addEdge(1, 2, 15);
    g->addEdge(2, 3, 16);
    g->addEdge(2, 4, 17);
    g->addEdge(3, 4, 18);
    g->addEdge(4, 5, 19);

    cout << "Iterative BFS Graph's Traversing:" << endl;
    showVector<size_t>(g->BFSTraverse());

    delete g;
    g = nullptr;

    return 0;
}