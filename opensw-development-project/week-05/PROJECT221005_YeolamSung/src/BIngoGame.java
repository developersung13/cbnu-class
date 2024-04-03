import java.util.Scanner;

class Person {

  private String name;

  public Person(String name) {
    this.name = name;
  }

  public String getName() {
    return name;
  }
}

public class BingoGame {

  public static void main(String args[]) {
    boolean flag = true;
    Scanner sc = new Scanner(System.in);
    Person p[] = new Person[2];
    int randNum[] = new int[3];
    String name;
    for (int k = 0; k < 2; k++) {
      System.out.print(k + 1 + "번째 선수 이름>>");
      name = sc.nextLine();
      p[k] = new Person(name);
    }

    while (true) {
      if (flag) {
        System.out.print("[" + p[0].getName() + "]:" + "<Enter>");
        sc.nextLine();
        for (int k = 0; k < 3; k++) {
          randNum[k] = (int) (Math.random() * 10 % 3 + 1);
          System.out.print("    " + randNum[k]);
        }
        if (randNum[0] == randNum[1] && randNum[1] == randNum[2]) {
          System.out.println("    " + p[0].getName() + "님이 이겼습니다!");
          return;
        } else System.out.println("    아쉽군요!");
        flag = false;
      } else {
        System.out.print("[" + p[1].getName() + "]:" + "<Enter>");
        sc.nextLine();
        for (int k = 0; k < 3; k++) {
          randNum[k] = (int) (Math.random() * 10 % 3 + 1);
          System.out.print("    " + randNum[k]);
        }
        if (randNum[0] == randNum[1] && randNum[1] == randNum[2]) {
          System.out.println("    " + p[1].getName() + "님이 이겼습니다!");
          return;
        } else System.out.println("    아쉽군요!");
        flag = true;
      }
    }
  }
}
