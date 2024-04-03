import java.util.*;

class Word {

  private String english;
  private String korean;

  public Word(String english, String korean) {
    this.english = english;
    this.korean = korean;
  }

  public String getEnglish() {
    return english;
  }

  public String getKorean() {
    return korean;
  }
}

public class Practice_12 {

  private String name; // 퀴즈 프로그램의 이름
  private Vector<Word> v;
  private Scanner scanner;

  public Practice_12(String name) {
    this.name = name;
    v = new Vector<Word>();
    scanner = new Scanner(System.in);
    v.add(new Word("love", "사랑"));
    v.add(new Word("animal", "동물"));
    v.add(new Word("emotion", "감정"));
    v.add(new Word("human", "인간"));
    v.add(new Word("stock", "주식"));
    v.add(new Word("trade", "거래"));
    v.add(new Word("society", "사회"));
    v.add(new Word("baby", "아기"));
    v.add(new Word("honey", "꿀"));
    v.add(new Word("dall", "인형"));
    v.add(new Word("bear", "곰"));
    v.add(new Word("picture", "사진"));
    v.add(new Word("painting", "그림"));
    v.add(new Word("fault", "오류"));
    v.add(new Word("example", "보기"));
    v.add(new Word("eye", "눈"));
    v.add(new Word("statue", "조각상"));
  }

  private int makeExample(int ex[], int answerIndex) {
    int n[] = { -1, -1, -1, -1 }; // -1로 초기화
    int index;
    for (int i = 0; i < n.length; i++) {
      do {
        index = (int) (Math.random() * v.size());
      } while (index == answerIndex || exists(n, index)); // 다시 시도
      n[i] = index;
    }

    for (int i = 0; i < n.length; i++) ex[i] = n[i];
    return (int) (Math.random() * n.length); // ex[] 배열 내의 임의의 위치 리턴. 이곳에 정답을 심는다.
  }

  private boolean exists(int n[], int index) {
    for (int i = 0; i < n.length; i++) {
      if (n[i] == index) return true;
    }
    return false;
  }

  private void test() {
    System.out.println(
      "현재 " +
      v.size() +
      "개의 단어가 들어 있습니다. -1을 입력하면 종료합니다."
    );
    while (true) {
      int answerIndex = (int) (Math.random() * v.size()); // 정답이 들어 있는 벡터 항목의 인덱스
      String eng = v.get(answerIndex).getEnglish(); // 문제로 주어질 영어 단어

      // 4개의 보기를 만들 벡터의 index 배열
      int example[] = new int[4];

      int answerLoc = makeExample(example, answerIndex); // 정답이 있는 보기 번호
      example[answerLoc] = answerIndex; // 보기에 정답 인덱스 저장

      // 문제를 출력합니다.
      System.out.println(eng + "?");
      for (int i = 0; i < example.length; i++) System.out.print(
        "(" + (i + 1) + ")" + v.get(example[i]).getKorean() + " "
      ); // 보기 출력

      System.out.print(":>"); // 프롬프트
      try {
        int in = scanner.nextInt(); // 사용자의 정답 입력
        if (in == -1) {
          break; // 프로그램 종료
        }

        // 사용자가 1~4 사이의 정답 입력
        in--; // 1~4를 0~3의 인덱스로 바꿈
        if (in == answerLoc) System.out.println(
          "Excellent !!"
        ); else System.out.println("No. !!");
      } catch (InputMismatchException e) {
        scanner.next(); // 현재 스트림 버퍼에 입력되어 있는 입력을 읽어서 제거함
        System.out.println("숫자를 입력하세요 !!");
        // while 문으로 다시 반복
      }
    }
  }

  public void run() {
    boolean flag = true;
    System.out.println(
      "**** 영어 단어 테스트 프로그램" + "\"" + name + "\"" + "입니다."
    );
    while (flag) {
      System.out.print("단어 테스트:1, 단어 삽입:2, 종료:3>> ");
      int select = scanner.nextInt();
      switch (select) {
        case 1:
          this.test();
          break;
        case 2:
          System.out.println("영어 단어에 그만을 입력하면 입력을 종료합니다.");
          while (true) {
            System.out.print("영어 한글 입력 >> ");
            String english = scanner.next();
            if (english.equals("그만")) {
              break;
            }
            String korean = scanner.next();
            v.add(new Word(english, korean));
          }
          break;
        case 3:
          System.out.print("\"" + name + "\"를 종료합니다...");
          flag = false;
          scanner.close();
          break;
        default:
          System.out.println("잘못입력했습니다.");
          break;
      }
    }
  }

  public static void main(String[] args) {
    Practice_12 quiz = new Practice_12("명품영어");
    quiz.run();
  }
}
