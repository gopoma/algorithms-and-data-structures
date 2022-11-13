#ifndef ADA_TEORIA_CGRAPHMATRIX_H
#define ADA_TEORIA_CGRAPHMATRIX_H

#include "CGraph.h"
#include "CMatrix.h"
#include "CMatrix.cpp"

class CGraphMatrix: public CGraph {
    private:
        i64 **adjacency = nullptr;
    public:
        CGraphMatrix(size_t aV, bool d);
        ~CGraphMatrix();

        bool vertexDoesExist(size_t aVertex);
        bool addEdge(size_t from, size_t to, i64 weight) override;
        bool removeEdge(size_t from, size_t to) override;
        vector<size_t> DFSTraverse() override;
        void DFSTraverse(size_t v, bool visited[], vector<size_t> &result) override;
        vector<size_t> RDFSTraverse() override;
        void RDFSTraverse(size_t v, bool visited[], vector<size_t> &result) override;
        vector<size_t> BFSTraverse() override;
        void BFSTraverse(size_t v, bool visited[], vector<size_t> &result) override;
        vector<size_t> DFSVisit(size_t src) override;
        void DFSVisit(size_t src, bool visited[], vector<size_t> &result) override;
        size_t countConnectedComponents() override;
};

#endif