import java.util.Scanner;

public class StringLotate {

  public static void main(String args[]) {
    int tmpIdx;
    Scanner sc = new Scanner(System.in);
    System.out.println(
      "문자열을 입력하세요. 빈칸이 있어도 되고 영어 한글 모두 됩니다."
    );
    String inputStr = sc.nextLine();
    for (int k = 0; k < inputStr.length(); k++) {
      tmpIdx = k + 1;
      for (int z = 0; z < inputStr.length(); z++) {
        if (tmpIdx == inputStr.length()) tmpIdx = 0;
        System.out.print(inputStr.charAt(tmpIdx++));
      }
      System.out.println();
    }
  }
}
