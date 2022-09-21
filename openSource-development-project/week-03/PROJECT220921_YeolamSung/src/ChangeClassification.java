import java.util.Scanner;

public class ChangeClassification {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int unit[] = {50000, 10000, 1000, 500, 100, 50, 10, 1};
        int calculatedBalance, balance;

        System.out.print("금액을 입력하시오>>");
        balance = sc.nextInt();

        for (int k=0; k < unit.length; k++) {
            calculatedBalance = balance / unit[k];
            if (calculatedBalance == 0) continue;
            System.out.println(unit[k]+"원 짜리 : " + calculatedBalance + "개");
            balance %= unit[k];
        }
    }
}