#include "CGraphMatrix.h"

CGraphMatrix::CGraphMatrix(size_t aV, bool d):CGraph(aV, d) {
    adjacency = generateSquareMatrix<i64>(aV);
}

CGraphMatrix::~CGraphMatrix() {
    delete[] adjacency;
    adjacency = nullptr;
}

bool CGraphMatrix::vertexDoesExist(size_t aVertex) {
    return 0 <= aVertex && aVertex < getAmountVertices();
}

bool CGraphMatrix::addEdge(size_t from, size_t to, i64 weight) {
    if(!vertexDoesExist(from) || !vertexDoesExist(to)) {
        return false;
    }

    adjacency[from][to] = weight;
    if(!isDirected()) {
        adjacency[to][from] = weight;
    }
    return true;
}

bool CGraphMatrix::removeEdge(size_t from, size_t to) {
    if(!vertexDoesExist(from) || !vertexDoesExist(to)) {
        return false;
    }

    adjacency[from][to] = WITHOUT_LINKING;
    if(!isDirected()) {
        adjacency[to][from] = WITHOUT_LINKING;
    }
    return true;
}

vector<size_t> CGraphMatrix::DFSTraverse() {
    bool visited[getAmountVertices()];
    vector<size_t> result;

    for(size_t i = 0; i < getAmountVertices(); i++) {
        if(!visited[i]) {
            DFSTraverse(i, visited, result);
        }
    }
    return result;
}

void CGraphMatrix::DFSTraverse(size_t v, bool visited[], vector<size_t> &result) {
    stack<size_t> S;
    S.push(v);

    while(!S.empty()) {
        size_t current = S.top();
        S.pop();

        if(!visited[current]) {
            result.push_back(current); // visit
            visited[current] = true;
            for(size_t i = 0; i < getAmountVertices(); i++) {
                if(adjacency[current][i] != WITHOUT_LINKING && !visited[i]) {
                    S.push(i);
                }
            }
        }
    }
}

vector<size_t> CGraphMatrix::RDFSTraverse() {
    bool visited[getAmountVertices()];
    vector<size_t> result;

    for(size_t i = 0; i < getAmountVertices(); i++) {
        if(!visited[i]) {
            RDFSTraverse(i, visited, result);
        }
    }
    return result;
}

void CGraphMatrix::RDFSTraverse(size_t v, bool visited[], vector<size_t> &result) {
    visited[v] = true;
    result.push_back(v); // visit, Prefix variation

    for(size_t i = 0; i < getAmountVertices(); i++) {
        if(adjacency[v][i] != WITHOUT_LINKING && !visited[i]) {
            RDFSTraverse(i, visited, result);
        }
    }
    // move result.push_back(v); [AKA visit] here to have the Postfix variation
}

vector<size_t> CGraphMatrix::BFSTraverse() {
    bool visited[getAmountVertices()];
    vector<size_t> result;

    for(size_t i = 0; i < getAmountVertices(); i++) {
        if(!visited[i]) {
            BFSTraverse(i, visited, result);           
        }
    }
    return result;
}

void CGraphMatrix::BFSTraverse(size_t v, bool visited[], vector<size_t> &result) {
    queue<size_t> Q;
    Q.push(v);

    while(!Q.empty()) {
        size_t current = Q.front();
        Q.pop();

        if(!visited[current]) {
            result.push_back(current);
            visited[current] = true;

            for(size_t i = 0; i < getAmountVertices(); i++) {
                if(adjacency[v][i] != WITHOUT_LINKING && !visited[i]) {
                    Q.push(i);
                }
            }
        }       
    }
}

vector<size_t> CGraphMatrix::DFSVisit(size_t src) {
    bool visited[getAmountVertices()];
    vector<size_t> result;
    DFSVisit(src, visited, result);
    return result;
}

void CGraphMatrix::DFSVisit(size_t src, bool visited[], vector<size_t> &result) {
    result.push_back(src);
    visited[src] = true;

    for(size_t i = 0; i < getAmountVertices(); i++) {
        if(adjacency[src][i] != WITHOUT_LINKING && !visited[i]) {
            DFSVisit(i, visited, result);
        }
    }
}

size_t CGraphMatrix::countConnectedComponents() {
    size_t cc = 0; // Amount of Connected Components
    set<size_t> nV; // Vertices that aren't visited yet
    for(size_t i = 0; i < getAmountVertices(); i++) {
        nV.insert(i);
    }

    while(!nV.empty()) {
        vector<size_t> visited = DFSVisit(*nV.begin());
        for(size_t v: visited) {
            nV.erase(v);
        }
        cc++;
    }
    return cc;
}