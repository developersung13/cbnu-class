// Scanner를 이용한 키 입력 연습 프로그램 코드

import java.util.Scanner;

public class ScannerEx {
    public static void main(String args[]) {
        System.out.println("이름, 도시, 나이, 체중, 독신 여부를 빈칸으로 분리하여 입력하세요");
        Scanner scanner = new Scanner(System.in);
        String name = scanner.next();
        System.out.print("이름은 " + name + ", ");
        String city = scanner.next();
        System.out.print("도시는 " + city + ", ");
        int age = scanner.nextInt();
        System.out.print("나이는 " + age + "살, ");
        double weight = scanner.nextDouble();
        System.out.print("체중은 " + weight + "kg, ");
        boolean single = scanner.nextBoolean();
        System.out.println("독신 여부는 " + single + "입니다.");
        scanner.close();
    }
}