// 비교 연산자 및 논리 연산자 사용 프로그램 코드

public class LogicalOperator {
    public static void main(String[] args) {
        System.out.println('a' > 'b');
        System.out.println(3 >= 2);
        System.out.println(-1 < 0);
        System.out.println(3.45 <= 2);
        System.out.println(3 == 2);
        System.out.println(3 != 2);
        System.out.println(!(3 != 2));
        System.out.println((3 > 2) && (3 > 4));
        System.out.println((3 != 2) || (-1 > 0));
        System.out.println((3 != 2) ^ (-1 > 0));
    }
}