import java.util.Scanner;

public class AlphabetHistogram {

  static int alphabet[] = new int['Z' - 'A' + 1];

  static String readString() {
    StringBuffer sb = new StringBuffer();
    Scanner sc = new Scanner(System.in);
    while (true) {
      String line = sc.nextLine();
      if (line.equals(";")) break;
      sb.append(line);
    }
    return sb.toString();
  }

  public static void main(String[] args) throws Exception {
    System.out.println("영문 텍스트를 입력하고 세미콜론을 입력하세요.");
    String inputStr = readString().toUpperCase();
    for (int k = 0; k < inputStr.length(); k++) {
      if (
        inputStr.charAt(k) >= 'A' && inputStr.charAt(k) <= 'Z'
      ) alphabet[inputStr.charAt(k) - 'A']++;
    }

    System.out.println("\n히스토그램을 그립니다.");
    for (int k = 0; k <= 'Z' - 'A'; k++) {
      System.out.print((char) ('A' + k));
      for (int z = 0; z < alphabet[k]; z++) {
        System.out.print("-");
      }
      System.out.println();
    }
  }
}
