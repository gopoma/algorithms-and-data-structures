// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio05 - Técnicas de Diseño de Algoritmos - Algoritmos Voraces
// Fecha: 01/11/2022

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.StringTokenizer;

class Product {
    private double weight;
    private double benefit;
    private double production;

    public Product(double w, double b) {
        setWeight(w);
        setBenefit(b);
    }

    public void setWeight(double w) {
        weight = w;
        setProduction();
    }
    public double getWeight() {
        return weight;
    }
    public void setBenefit(double b) {
        benefit = b;
        setProduction();
    }
    public double getBenefit() {
        return benefit;
    }
    public void setProduction() {
        production = getBenefit()/getWeight();
    }
    public double getProduction() {
        return production;
    }
}

public class Ejercicio6 {
    public static FastScanner sc = new FastScanner();

    public static void main(final String[] args) {

        System.out.print("Amount of Products: ");
        int N = sc.nextInt();
        Product[] products = new Product[N];

        for(int i = 0; i < N; i++) {
            double w, b;

            System.out.println("Product #" + (i + 1) + ":");
            System.out.print("Weight [kg]: ");
            w = sc.nextDouble();
            System.out.print("Benefit: ");
            b = sc.nextDouble();
            
            products[i] = new Product(w, b);
            System.out.println();
        }

        System.out.print("Backpack's Capacity [kg]: ");
        double M = sc.nextDouble();
        System.out.println();

        System.out.println("Solution:");
        backpack(M, products);
    }

    public static void printBackPackSolution(double[] solution, Product[] products) {
        double maximumBenefit = 0; 
        System.out.println("Selection \t\t Amount");
        for(int i = 0; i < solution.length; i++) {
            if(solution[i] != 0) {
                System.out.println("Product #" + (i + 1) + " \t\t " + solution[i]);
                maximumBenefit += products[i].getBenefit() * solution[i];
            }
        }
        System.out.println();
        System.out.println("Maximum Benefit: " + maximumBenefit);
    }

    public static void backpack(double M, Product[] products) {
        double[] solution = new double[products.length];
        solution = backpack(M, products, solution);
        printBackPackSolution(solution, products);
    }

    public static double[] backpack(double M, Product[] products, double[] solution) {
        double current = 0;
        boolean[] selected = new boolean[products.length];
        
        while(current < M) {
            int max_index = -1;
            double max = -1;
            for(int i = 0; i < products.length; i++) {
                if(!selected[i] && (products[i].getProduction() > max)) {
                    max = products[i].getProduction();
                    max_index = i;
                }
            }            

            if(max_index == -1) {
                break;
            }
            selected[max_index] = true;

            if(current + products[max_index].getWeight() <= M) {
                solution[max_index] = 1;
                current += products[max_index].getWeight();
            } else {
                if(current == 0) {
                    current = M;
                }
                solution[max_index] = (M - current) / products[max_index].getWeight();
                current = M;
            }
        }
        return solution;
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