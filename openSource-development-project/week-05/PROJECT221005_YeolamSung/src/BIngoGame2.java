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

public class BIngoGame2 {

  public static void main(String args[]) {
    boolean flag = true;
    Scanner sc = new Scanner(System.in);
    int personNum;
    int randNum[] = new int[3];
    String name;
    System.out.print("겜블링 게임에 참여할 선수 숫자>>");
    personNum = sc.nextInt();
    Person p[] = new Person[personNum];
    for (int k = 0; k < personNum; k++) {
      System.out.print(k + 1 + "번째 선수 이름>>");
      name = sc.next();
      p[k] = new Person(name);
    }
    name = sc.nextLine();

    while (true) {
      for (int k = 0; k < personNum; k++) {
        flag = false;
        System.out.print("[" + p[k].getName().substring(0, 1) + "]:<Enter>");
        sc.nextLine();
        for (int z = 0; z < 3; z++) {
          randNum[z] = (int) (Math.random() * 10 % 3 + 1);
          System.out.print("    " + randNum[z]);
        }
        for (int g = 1; g < 3; g++) {
          if (randNum[g - 1] != randNum[g]) {
            flag = true;
            break;
          }
        }
        if (!flag) {
          System.out.println("    " + p[0].getName() + "님이 이겼습니다!");
          return;
        } else System.out.println("    아쉽군요!");
      }
    }
  }
}
