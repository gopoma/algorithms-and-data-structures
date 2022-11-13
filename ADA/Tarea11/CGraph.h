#ifndef ADA_TEORIA_CGRAPH_H
#define ADA_TEORIA_CGRAPH_H

#include "Definitions.h"

class CGraph {
    private:
        size_t amountVertices;
        bool directed;
    protected:
        CGraph(){};
        CGraph(size_t amountVertices, bool d);
    public:
        void setAmountVertices(size_t aV);
        size_t getAmountVertices();
        void setDirected(bool d);
        bool isDirected();

        virtual bool addEdge(size_t from, size_t to, i64 weight)=0;
        virtual bool removeEdge(size_t from, size_t to)=0;
        virtual vector<size_t> DFSTraverse()=0;
        virtual void DFSTraverse(size_t v, bool visited[], vector<size_t> &result)=0;
        virtual vector<size_t> RDFSTraverse()=0;
        virtual void RDFSTraverse(size_t v, bool visited[], vector<size_t> &result)=0;
        virtual vector<size_t> BFSTraverse()=0;
        virtual void BFSTraverse(size_t v, bool visited[], vector<size_t> &result)=0;
        virtual vector<size_t> DFSVisit(size_t src)=0;
        virtual void DFSVisit(size_t src, bool visited[], vector<size_t> &result)=0;
        virtual size_t countConnectedComponents()=0;
};

#endif