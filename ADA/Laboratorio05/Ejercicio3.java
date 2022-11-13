// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio05 - Técnicas de Diseño de Algoritmos - Algoritmos Voraces
// Fecha: 01/11/2022

public class Ejercicio3 {
    public static void main(final String[] args) {
        GraphMatrix g = new GraphMatrix(false, 7, true, false);
        g.addEdge('A', 'B', 7);
        g.addEdge('A', 'D', 5);
        g.addEdge('B', 'C', 8);
        g.addEdge('B', 'D', 9);
        g.addEdge('B', 'E', 7);
        g.addEdge('C', 'E', 5);
        g.addEdge('D', 'E', 15);
        g.addEdge('D', 'F', 6);
        g.addEdge('E', 'F', 8);
        g.addEdge('E', 'G', 9);
        g.addEdge('F', 'G', 11);

        System.out.println("Generated Matrix:");
        System.out.println("Matrix Representation:");
        g.showMatrixRepresentation();
        System.out.println("Linking Representation:");
        g.showLinkingRepresentation();

        GraphMatrix MST = g.prim();
        System.out.println("Minimum Spanning Tree (MST):");
        System.out.println("Matrix Representation:");
        MST.showMatrixRepresentation();
        System.out.println("Linking Representation:");
        MST.showLinkingRepresentation();
        System.out.println();
        System.out.print("Minimum Cost Possible: "+MST.getAccumulatedWeight());
    }
}