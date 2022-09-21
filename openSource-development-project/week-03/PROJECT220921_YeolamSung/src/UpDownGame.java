import java.util.Random;
import java.util.Scanner;

public class UpDownGame {
    public static void main(String args[]) {
        Random r = new Random();
        Scanner sc = new Scanner(System.in);
        int userNum = -1, randNum;
        char playAgainFlag = 'y';

        System.out.println("수를 결정하였습니다. 맞추어 보세요\n0~99");
        
        while (playAgainFlag == 'y') {
            randNum = r.nextInt(100);
            for (int k=1; userNum != randNum;k++) {
                System.out.print(k+">>");
                userNum = sc.nextInt();
                if (userNum > randNum) System.out.println("더 낮게");
                else if (userNum < randNum) System.out.println("더 높게");
            }
            System.out.print("맞았습니다.\n다시 하시겠습니까(y/n)>>");
            playAgainFlag = sc.next().charAt(0);
        }
    }
}