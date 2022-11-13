// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio05 - Técnicas de Diseño de Algoritmos - Algoritmos Voraces
// Fecha: 01/11/2022

public class Ejercicio2 {
    public static void main(final String[] args) {
        GraphMatrix g = new GraphMatrix(false, 9, false, true);
        g.addEdge(1, 2, 4, true);
        g.addEdge(1, 8, 9, true);
        g.addEdge(2, 3, 9, true);
        g.addEdge(2, 8, 11, true);
        g.addEdge(3, 4, 7, true);
        g.addEdge(3, 6, 4, true);
        g.addEdge(3, 9, 2, true);
        g.addEdge(4, 5, 10, true);
        g.addEdge(4, 6, 15, true);
        g.addEdge(5, 6, 11, true);
        g.addEdge(6, 7, 2, true);
        g.addEdge(7, 8, 1, true);
        g.addEdge(7, 9, 6, true);
        g.addEdge(8, 9, 7, true);

        System.out.println("Generated Matrix:");
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
}