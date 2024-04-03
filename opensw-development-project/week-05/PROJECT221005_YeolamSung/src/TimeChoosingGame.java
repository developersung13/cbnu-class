import java.util.Calendar;
import java.util.Scanner;

public class TimeChoosingGame {

  public static void main(String args[]) {
    int diff;
    int person[] = new int[2];
    Scanner sc = new Scanner(System.in);
    System.out.println("10초에 가까운 사람이 이기는 게임입니다.");
    System.out.print("황기태 시작 <Enter>>");
    sc.nextLine();
    for (int k = 0; k < 2; k++) {
      int currentSec = Calendar.getInstance().get(Calendar.SECOND);
      System.out.println("\t현재 초 시간 = " + currentSec);
      System.out.print("10초 예상 후 <Enter키>>");
      sc.nextLine();
      int choosedSec = Calendar.getInstance().get(Calendar.SECOND);
      System.out.println("\t현재 초 시간 = " + choosedSec);
      if (currentSec > choosedSec) {
        diff = currentSec + 59 - choosedSec;
      } else diff = choosedSec - currentSec;
      person[k] = diff;
      if (k == 1) break;
      System.out.print("이재문 시작 <Enter키>>");
      sc.nextLine();
    }
    if (person[0] < person[1]) {
      System.out.println(
        "황기태의 결과 " +
        person[0] +
        ", 이재문의 결과 " +
        person[1] +
        ", 승자는 황기태"
      );
    } else {
      System.out.println(
        "황기태의 결과 " +
        person[0] +
        ", 이재문의 결과 " +
        person[1] +
        ", 승자는 이재문"
      );
    }
  }
}
