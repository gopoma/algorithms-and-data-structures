// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio04 - Técnicas de Diseño de Algoritmos – Algoritmo de Strassen
// Fecha: 23/10/2022

public class StrassenAplication {
    public static void showMtx(double[][] mtx) {
        for(int i = 0; i < mtx.length; i++) {
            for(int j = 0; j < mtx[0].length; j++) {
                if((long)mtx[i][j] == mtx[i][j]) {
                    System.out.print((long)mtx[i][j] + " ");
                } else {
                    System.out.print(mtx[i][j] + " ");
                }
            }
            System.out.println();
        }
        System.out.println();
    }
    
    // iDifferential, jDifferential: 0 || (n/2)
    public static void split(double[][] composed, double[][] target, int iDifferential, int jDifferential) {
        final int tDimension = target.length; // composed: nxn -> target: (n/2)x(n/2)
        for(int i = 0; i < tDimension; i++) {
            for(int j = 0; j < tDimension; j++) {
                target[i][j] = composed[i + iDifferential][j + jDifferential]; 
            }
        }
    }

    public static double[][] sub(double[][] A, double[][] B) {
        final int rDimension = A.length;
        double[][] R = new double[rDimension][rDimension];
        for(int i = 0; i < rDimension; i++) {
            for(int j = 0; j < rDimension; j++) {
                R[i][j] = A[i][j] - B[i][j];
            }
        }
        return R;
    }

    public static double[][] sum(double[][] A, double[][] B) {
        final int rDimension = A.length;
        double[][] R = new double[rDimension][rDimension];
        for(int i = 0; i < rDimension; i++) {
            for(int j = 0; j < rDimension; j++) {
                R[i][j] = A[i][j] + B[i][j];
            }
        }
        return R;
    }

    public static void join(double[][] result, double[][] target, int iDifferential, int jDifferential) {
        final int tDimension = target.length;
        for(int i = 0; i < tDimension; i++) {
            for(int j = 0; j < tDimension; j++) {
                result[i + iDifferential][j + jDifferential] = target[i][j];
            }
        }
    }

    public static int getNextPowerOfTwo(int num) {
        int count = 0;
 
        if (num > 0 && (num & (num - 1)) == 0) {
            return num;
        }
 
        while(num != 0) {
            num >>= 1;
            count += 1;
        }
 
        return 1 << count;
    }

    public static double[][] getNormalized(double[][] mtx, int normalizedDimension) {
        double[][] result = new double[normalizedDimension][normalizedDimension];
        for(int i = 0; i < mtx.length; i++) {
            for(int j = 0; j < mtx[0].length; j++) {
                result[i][j] = mtx[i][j];
            }
        }
        return result;
    }

    public static double[][] multiply(double[][] A, double[][] B) throws Exception {
        final int p = A.length;
        final int q = A[0].length;
        final int r = B.length;
        final int s = B[0].length;
        if(q != r) {
            throw new Exception("Can't multiply because they doesn't satisfy the Dimension Constraint!");
        }

        final int normalizedDimension = getNextPowerOfTwo(Math.max(Math.max(p, s), q));
        double[][] ANormalized = getNormalized(A, normalizedDimension);
        double[][] BNormalized = getNormalized(B, normalizedDimension);
        // We can ensure that the inputs are gonna be 2^i*2^i
        double[][] partialResult = multiplyRecursively(ANormalized, BNormalized);
        // Result is just the left upper part of partialResult
        double[][] result = new double[p][s];
        for(int i = 0; i < p; i++) {
            for(int j = 0; j < s; j++) {
                result[i][j] = partialResult[i][j];
            }
        }

        return result;
    }

    public static double[][] multiplyRecursively(double[][] A, double[][] B) {
        final int n = A.length; // As A and B are Square Ones
        double[][] C = new double[n][n];
        
        // Base Case
        if(n == 1) { // 23 -> 12 -> 6 -> 3 -> 1
            C[0][0] = A[0][0] * B[0][0]; // As each one just have one element
        } else {
            double[][] A11 = new double[n/2][n/2];
            double[][] A12 = new double[n/2][n/2];
            double[][] A21 = new double[n/2][n/2];
            double[][] A22 = new double[n/2][n/2];
            double[][] B11 = new double[n/2][n/2];
            double[][] B12 = new double[n/2][n/2];
            double[][] B21 = new double[n/2][n/2];
            double[][] B22 = new double[n/2][n/2];
            
            split(A, A11, 0, 0);
            split(A, A12, 0, n/2);
            split(A, A21, n/2, 0);
            split(A, A22, n/2, n/2);
            split(B, B11, 0, 0);
            split(B, B12, 0, n/2);
            split(B, B21, n/2, 0);
            split(B, B22, n/2, n/2);

            double[][] M1 = multiplyRecursively(A11, sub(B12, B22));
            double[][] M2 = multiplyRecursively(sum(A11, A12), B22);
            double[][] M3 = multiplyRecursively(sum(A21, A22), B11);
            double[][] M4 = multiplyRecursively(A22, sub(B21, B11));
            double[][] M5 = multiplyRecursively(sum(A11, A22), sum(B11, B22));
            double[][] M6 = multiplyRecursively(sub(A12, A22), sum(B21, B22));
            double[][] M7 = multiplyRecursively(sub(A11, A21), sum(B11, B12));

            double[][] C11 = sum(M5, sum(sub(M4, M2), M6));
            double[][] C12 = sum(M1, M2);
            double[][] C21 = sum(M3, M4);
            double[][] C22 = sum(M5, sub(sub(M1, M3), M7));        

            join(C, C11, 0, 0);
            join(C, C12, 0, n/2);
            join(C, C21, n/2, 0);
            join(C, C22, n/2, n/2);
        }
    
        return C;
    }
    
    public static void main(final String[] args) {
        try {
            double[][] A = {
                {1, 2, 3},
                {4, 5, 6}
            };

            double[][] B = {
                {1, 2, 7},
                {3, 4, 8},
                {5, 6, 9}
            };

            showMtx(multiply(A, B));
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
