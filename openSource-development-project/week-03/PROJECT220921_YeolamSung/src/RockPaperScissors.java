import java.util.Random;
import java.util.Scanner;

public class RockPaperScissors {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Random r = new Random();
        String str[] = {"가위", "바위", "보"};
        String user, computer;
        boolean tf = true;

        System.out.println("컴퓨터와 가위 바위 보 게임을 합니다.");
        while(tf) {
            System.out.print("가위 바위 보!>>");
            user = sc.next();
            computer = str[r.nextInt(3)];
                if (user.equals("가위")) {
                    if (computer.equals("가위")) {
                        System.out.println("사용자 " + user + " , 컴퓨터 = " + computer + ", 비겼습니다.");
                    } else if (computer.equals("바위")) {
                        System.out.println("사용자 " + user + " , 컴퓨터 = " + computer + ", 사용자가 졌습니다.");
                    } else {
                        System.out.println("사용자 " + user + " , 컴퓨터 = " + computer + ", 사용자가 이겼습니다.");
                    }
                } else if (user.equals("바위")) {
                    if (computer.equals("가위")) {
                        System.out.println("사용자 " + user + " , 컴퓨터 = " + computer + ", 사용자가 이겼습니다.");
                    } else if (computer.equals("바위")) {
                        System.out.println("사용자 " + user + " , 컴퓨터 = " + computer + ", 비겼습니다.");
                    } else {
                        System.out.println("사용자 " + user + " , 컴퓨터 = " + computer + ", 사용자가 졌습니다.");
                    }
                } else if (user.equals("보")) {
                    if (computer.equals("가위")) {
                        System.out.println("사용자 " + user + " , 컴퓨터 = " + computer + ", 사용자가 졌습니다.");
                    } else if (computer.equals("바위")) {
                        System.out.println("사용자 " + user + " , 컴퓨터 = " + computer + ", 사용자가 이겼습니다.");
                    } else {
                        System.out.println("사용자 " + user + " , 컴퓨터 = " + computer + ", 비겼습니다.");
                    }
                } else if (user.equals("그만")) {
                    System.out.println("게임을 종료합니다...");
                    tf = false;
                }
            }
    }
}
