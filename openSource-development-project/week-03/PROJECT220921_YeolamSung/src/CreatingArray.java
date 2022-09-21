import java.util.Random;
import java.util.Scanner;

public class CreatingArray {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Random r = new Random();
        System.out.print("정수 몇 개?");
        int arrSize = sc.nextInt();
        int arr[] = new int[arrSize];

        for (int k=0; k < arrSize; k++) {
            arr[k] = r.nextInt(100) + 1;
            System.out.print(arr[k] + " ");
            if ((k+1) % 10 == 0) System.out.println();
        }
    }
}