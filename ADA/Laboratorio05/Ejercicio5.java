// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio05 - Técnicas de Diseño de Algoritmos - Algoritmos Voraces
// Fecha: 01/11/2022

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.StringTokenizer;

public class Ejercicio5 {
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        
        GraphMatrix g = new GraphMatrix(true, 6, false, true);
        g.addEdge(1, 2, 4, true);
        g.addEdge(1, 3, 7, true);
        g.addEdge(1, 6, 3, true);
        g.addEdge(2, 3, 3, true);
        g.addEdge(2, 5, 1, true);
        g.addEdge(3, 4, 1, true);
        g.addEdge(3, 5, 1, true);
        g.addEdge(5, 4, 4, true);
        g.addEdge(6, 5, 3, true);

        System.out.println("Generated Matrix:");
        System.out.println("Matrix Representation:");
        g.showMatrixRepresentation();
        System.out.println("Linking Representation:");
        g.showLinkingRepresentation();
        System.out.println();

        System.out.print("Source Node: ");
        int src = sc.nextInt();
        g.dijkstra(src, true);
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;
    
        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
    
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
    
        int nextInt() { 
            return Integer.parseInt(next()); 
        }
    
        long nextLong() { 
            return Long.parseLong(next()); 
        }
    
        double nextDouble() {
            return Double.parseDouble(next());
        }
    
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }   
}