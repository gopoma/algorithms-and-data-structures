// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio05 - Técnicas de Diseño de Algoritmos - Algoritmos Voraces
// Fecha: 01/11/2022

import java.util.Arrays;

public class GraphMatrix extends Graph {
    private long[][] adjacency;
    private boolean normalizeRepresentation;

    public GraphMatrix(boolean d, int nV, boolean aN, boolean nR) {
        super(d, nV, aN);
        adjacency = new long[nV][nV];
        normalizeRepresentation = nR;
    }

    private boolean vertexDoesExist(int aVertex) {
        return 0 <= aVertex && aVertex < numVertices;
    }

    public boolean addEdge(int from, int to, long weight, boolean normalize) {
        if(normalize) {
            from = normalize(from);
            to = normalize(to);
        }
        if(!vertexDoesExist(from) || !vertexDoesExist(to)) {
            return false;
        }

        adjacency[from][to] = weight;
        if(!directed) {
            adjacency[to][from] = weight;
        }
        accumulatedWeight += weight;
        return true;
    }

    public boolean addEdge(char from, char to, long weight) {
        return addEdge(normalize(from), normalize(to), weight, false);
    }

    public boolean removeEdge(int from, int to, boolean normalize) {
        if(normalize) {
            from = normalize(from);
            to = normalize(to);
        }
        if(!vertexDoesExist(from) || !vertexDoesExist(to)) {
            return false;
        }

        accumulatedWeight -= adjacency[from][to];
        adjacency[from][to] = WITHOUT_LINKING;
        if(!directed) {
            adjacency[to][from] = WITHOUT_LINKING;
        }
        return true;
    }

    public boolean removeEdge(char from, char to) {
        return removeEdge(normalize(from), normalize(to), false);
    }

    private long[][] initializeCost() {
        long[][] cost = new long[numVertices][numVertices];
        for(int i = 0; i < numVertices; i++) {
            for(int j = 0; j < numVertices; j++) {
                cost[i][j] = (adjacency[i][j] == WITHOUT_LINKING)? INFINITY : adjacency[i][j];
            }
        }

        return cost;
    }

    private int find(int i, int[] parent) {
        while(parent[i] != WITHOUT_DEFINITION) {
            i = parent[i];
        }
        return i;
    }

    private boolean union(int i, int j, int[] parent) {
        if(i != j) {
            parent[i] = j;
            return true;
        }
        return false;
    }

    public GraphMatrix kruskal() {
        long[][] cost = initializeCost();
        int[] parent = new int[numVertices];
        Arrays.fill(parent, WITHOUT_DEFINITION);
        int addedEdges = 0;
        GraphMatrix MST = new GraphMatrix(false, numVertices, ASCIINormalization, normalizeRepresentation);
        
        while(addedEdges < numVertices - 1) {
            int a = WITHOUT_DEFINITION, b = WITHOUT_DEFINITION, u = WITHOUT_DEFINITION, v = WITHOUT_DEFINITION;
            boolean generatedCycle = false;
            long min = INFINITY;
            for(int i = 0; i < numVertices; i++) {
                for(int j = 0; j < numVertices; j++) {
                    if(cost[i][j] < min) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }

            u = find(u, parent);
            v = find(v, parent);
            generatedCycle = union(u, v, parent);
            if(generatedCycle) {
                MST.addEdge(a, b, cost[a][b], false);
                addedEdges++;
            }
            cost[a][b] = cost[b][a] = INFINITY;
        }

        return MST;
    }

    private int minKey(long[] key, boolean[] mstSet) {
        long min = INFINITY;
        int min_index = WITHOUT_DEFINITION;

        for(int k = 0; k < numVertices; k++) {
            if(!mstSet[k] && key[k] < min) {
                min = key[k];
                min_index = k;
            }
        }
        return min_index;
    }

    private int[] getPrimConfiguration() {
        int[] parent =  new int[numVertices];
        long[] key = new long[numVertices];
        boolean[] mstSet = new boolean[numVertices];

        for(int i = 0; i < numVertices; i++) {
            key[i] = INFINITY;
        }

        key[0] = 0;
        parent[0] = WITHOUT_DEFINITION;

        for(int counter = 0; counter < numVertices - 1; counter++) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;

            for(int v = 0; v < numVertices; v++) {
                if(adjacency[u][v] != WITHOUT_LINKING && !mstSet[v]
                && adjacency[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjacency[u][v];
                }
            }
        }
        return parent;
    }

    public GraphMatrix prim() {
        GraphMatrix result = new GraphMatrix(false, numVertices, ASCIINormalization, normalizeRepresentation);
        int[] parent = getPrimConfiguration();
        
        for(int i = 1; i < numVertices; i++) {
            result.addEdge(parent[i], i, adjacency[parent[i]][i], false);
        }
        return result;
    }

    private int minDistance(long[] dist, boolean[] sptSet) {
        long min = INFINITY;
        int min_index = WITHOUT_DEFINITION;

        for(int k = 0; k < numVertices; k++) {
            if(!sptSet[k] && dist[k] <= min) {
                min = dist[k];
                min_index = k;
            }
        }
        return min_index;
    }

    public void printDijkstraSolution(long[] dist, boolean normalize) {
        System.out.println("Vertex \t\t Distance from Source");
        for(int i = 0; i < numVertices; i++) {
            String distance = (dist[i] == INFINITY) ? "Not Reached" : Long.toString(dist[i]);
            String v = (normalize)? Integer.toString(i + 1) : Integer.toString(i);
            System.out.println(v + " \t\t " + distance);
        }
    }

    public void dijkstra(int src, boolean normalize) {
        if(normalize) {
            src = normalize(src);
        }
        long[] dist = new long[numVertices];
        boolean[] sptSet = new boolean[numVertices];

        for(int i = 0; i < numVertices; i++) {
            dist[i] = INFINITY;
        }

        dist[src] = 0;
        for(int counter = 0; counter < numVertices - 1; counter++) {
            int u = minDistance(dist, sptSet);
            sptSet[u] = true;

            for(int v = 0; v < numVertices; v++) {
                if(!sptSet[v] && adjacency[u][v] != WITHOUT_LINKING
                && dist[u] != INFINITY && (dist[u] + adjacency[u][v] < dist[v])) {
                    dist[v] = dist[u] + adjacency[u][v];
                }
            }
        }
        printDijkstraSolution(dist, normalize);
    }

    private String getMatrixRepresentation(long[][] mtx) {
        String result = "\t";

        for(int i = 0; i < numVertices; i++) {
            int u = (normalizeRepresentation && !ASCIINormalization)? i + 1 : i;
            if(ASCIINormalization) {
                result += (char)(u+'A') + "\t";
            } else {
                result += Integer.toString(u) + "\t";
            }
        }
        result += "\n";

        for(int i = 0; i < numVertices; i++) {
            int v = (normalizeRepresentation && !ASCIINormalization)? i + 1 : i;
            if(ASCIINormalization) {
                result += (char)(v+'A') + "\t";
            } else {
                result += Integer.toString(v) + "\t";
            }
            for(int j = 0; j < numVertices; j++) {
                result += Long.toString(mtx[i][j]) + "\t";
            }
            result += "\n";
        }

        return result;
    }

    public void showMatrixRepresentation() {
        System.out.println(this);
    }

    public void showLinkingRepresentation() {
        for(int i = 0; i < numVertices; i++) {
            int u = (normalizeRepresentation && !ASCIINormalization)? i + 1 : i;
            if(ASCIINormalization) {
                System.out.print((char)(u+'A') + " -> ");
            } else {
                System.out.print(Integer.toString(u) + " -> ");
            }
            for(int j = 0; j < numVertices; j++) {
                if(adjacency[i][j] != WITHOUT_LINKING) {
                    int v = (normalizeRepresentation && !ASCIINormalization)? j + 1 : j;
                    if(ASCIINormalization) {
                        System.out.print((char)(v+'A') + " ");
                    } else {
                        System.out.print(Integer.toString(v) + " ");
                    }
                }
            }
            System.out.println();
        }        
    }

    public String toString() {
        return getMatrixRepresentation(adjacency);
    }
}
