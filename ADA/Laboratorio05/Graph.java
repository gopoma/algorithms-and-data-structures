// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio05 - Técnicas de Diseño de Algoritmos - Algoritmos Voraces
// Fecha: 01/11/2022

public abstract class Graph {
    protected static long INFINITY = Long.MAX_VALUE;
    protected static short WITHOUT_LINKING = 0; 
    protected static short WITHOUT_DEFINITION = -1;
    protected boolean directed;
    protected int numVertices;
    protected boolean ASCIINormalization;
    protected long accumulatedWeight;

    protected Graph(boolean d, int nV, boolean aN) {
        directed = d;
        numVertices = nV;
        ASCIINormalization = aN;
        accumulatedWeight = 0;
    }

    public boolean isDirected() {
        return directed;
    }
    public int getNumVertices() {
        return numVertices;
    }
    public long getAccumulatedWeight() {
        return accumulatedWeight;
    }

    protected static int normalize(int i) {
        return i - 1;
    }

    protected static int normalize(char c) {
        return c - 'A';
    }

    public abstract boolean addEdge(int from, int to, long weight, boolean normalize);
    public abstract boolean removeEdge(int from, int to, boolean normalize);
    public abstract Graph kruskal();
    public abstract Graph prim();
    public abstract void dijkstra(int src, boolean normalize);
    public abstract void showLinkingRepresentation();
}