#include "CGraph.h"

CGraph::CGraph(size_t aV, bool d) {
    setAmountVertices(aV);
    setDirected(d);
}

void CGraph::setAmountVertices(size_t aV) {
    amountVertices = aV;
}

size_t CGraph::getAmountVertices() {
    return amountVertices;
}

void CGraph::setDirected(bool d) {
    directed = d;
}

bool CGraph::isDirected() {
    return directed;
}