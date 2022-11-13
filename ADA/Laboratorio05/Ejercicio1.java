// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio05 - Técnicas de Diseño de Algoritmos - Algoritmos Voraces
// Fecha: 01/11/2022

public class Ejercicio1 {
    public static void main(final String[] args) {
        GraphMatrix g = new GraphMatrix(false, 7, false, true);
        g.addEdge(1, 2, 5, true);
        g.addEdge(1, 4, 5, true);
        g.addEdge(2, 3, 5, true);
        g.addEdge(2, 4, 5, true);
        g.addEdge(2, 6, 3, true);
        g.addEdge(3, 6, 4, true);
        g.addEdge(3, 7, 2, true);
        g.addEdge(4, 5, 3, true);
        g.addEdge(4, 6, 3, true);
        g.addEdge(5, 6, 1, true);
        g.addEdge(6, 7, 5, true);

        System.out.println("Generated Graph:");
        System.out.println("Matrix Representation:");
        g.showMatrixRepresentation();
        System.out.println("Linking Representation:");
        g.showLinkingRepresentation();
        System.out.println();

        GraphMatrix MST = g.kruskal();
        System.out.println("Minimum Spanning Tree (MST):");
        System.out.println("Matrix Representation:");
        MST.showMatrixRepresentation();
        System.out.println("Linking Representation:");
        MST.showLinkingRepresentation();
        System.out.println();
        System.out.print("Minimum Cost Possible: "+MST.getAccumulatedWeight());
    }

    public static int normalize(int i) {
        return i - 1;
    }
}