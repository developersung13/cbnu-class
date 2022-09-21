import java.util.Random;

public class CreatingTwoDimensionalArray {
    public static void main(String args[]) {
        Random r = new Random();
        int arr[][] = new int[4][4];
        int randIdx[][] = new int[10][2];
        boolean tf;

        for (int k=0; k < randIdx.length; k++) {
            tf = false;
            randIdx[k][0] = r.nextInt(4);
            randIdx[k][1] = r.nextInt(4);
            for (int z=0; z < k; z++) {
                if (randIdx[k][0] == randIdx[z][0] && randIdx[k][1] == randIdx[z][1]) {
                    tf = true;
                    break;
                }
            } if (tf) {
                k--;
                continue;
            }
            arr[randIdx[k][0]][randIdx[k][1]] = r.nextInt(10) + 1;
        }

        for (int k=0; k < arr.length; k++) {
            for (int z=0; z < arr[0].length; z++) {
                System.out.print(arr[k][z] + "\t");
            } System.out.println();
        }
    }
}
