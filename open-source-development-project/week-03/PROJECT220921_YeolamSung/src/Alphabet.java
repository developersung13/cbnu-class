import java.util.Scanner;

public class Alphabet {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("소문자 알파벳 하나를 입력하시오>>");
        char alphabet = sc.next().charAt(0);
        char tmp = alphabet;
        
        for (int k=0; k <= tmp - 'a'; k++, alphabet--) {
            for (int z=0; z <= alphabet - 'a'; z++) {
                System.out.print((char)('a'+z));
            }
            System.out.println();
        }
    }
}
