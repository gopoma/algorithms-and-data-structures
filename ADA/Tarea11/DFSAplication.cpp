#include "CGraphMatrix.h"

int main() {
    CGraphMatrix *g = new CGraphMatrix(7, false);
    g->addEdge(0, 1, 12);
    g->addEdge(0, 2, 25);
    g->addEdge(1, 3, 37);
    g->addEdge(2, 3, 79);
    g->addEdge(4, 5, 125);

    cout << "Iterative DFS Graph's Traversing:" << endl;
    showVector<size_t>(g->DFSTraverse());
    cout << "Recursive DFS Graph's Traversing:" << endl;
    showVector<size_t>(g->RDFSTraverse());
    cout << "Amount of Connected Components: " << g->countConnectedComponents() << endl;

    delete g;
    g = nullptr;

    return 0;
}