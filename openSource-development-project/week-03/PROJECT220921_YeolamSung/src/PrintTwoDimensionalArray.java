public class PrintTwoDimensionalArray {
    public static void main(String args[]) {
        int n[][] = {{1}, {1, 2, 3}, {1}, {1, 2, 3, 4}, {1, 2}};
        for (int k=0; k < n.length; k++) {
            for (int z=0; z < n[k].length; z++) {
                System.out.print(n[k][z] + " ");
            }
            System.out.println("");
        }
    }
}