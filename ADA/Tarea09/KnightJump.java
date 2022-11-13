import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

public class KnightJump {
    public static final int[] xAxis = {-1, -2, -2, -1, 1, 2, 2, 1};
    public static final int[] yAxis = {-2, -1, 1, 2, 2, 1, -1, -2};
    public static boolean success = false;

    public static void main(final String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Amount of Rows: ");
        final int m = Integer.parseInt(br.readLine());
        System.out.print("Amount of Columns: ");
        final int n = Integer.parseInt(br.readLine());
        int[][] board = new int[m][n];

        board[0][0] = 1;
        move(board, 2, 0, 0);
        if(success) {
            System.out.println("Solution:");
            showBoard(board);
        } else {
            System.out.println("There is no a Solution!");
        }
    }

    public static boolean inRange(int value, int low, int high) {
        return low <= value && value <= high;
    }

    public static boolean inTable(int value, int dimension) {
        return inRange(value, 0, dimension - 1);
    }

    public static void move(int[][] board, int i, int posX, int posY) {
        final int m = board.length;
        final int n = board[0].length;
        int u, v;
        int k = 0;
        success = false;

        do {
            u = posX + xAxis[k];
            v = posY + yAxis[k];

            if(inTable(u, m) && inTable(v, n)) {
                if(board[u][v] == 0) {
                    board[u][v] = i;

                    if(i < m*n) {
                        move(board, i+1, u, v);
                        if(!success) {
                            board[u][v] = 0;
                        }
                    } else {
                        success = true;
                    }
                }
            }
            k++;
        } while(!success && k < 8);
    }

    public static void showBoard(int[][] board) {
        for(int i = 0; i < board.length; i++) {
            for(int j = 0; j < board[0].length; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }
}