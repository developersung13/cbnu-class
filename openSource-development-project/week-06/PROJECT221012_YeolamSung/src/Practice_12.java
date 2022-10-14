import java.util.InputMismatchException;
import java.util.Scanner;
import java.util.Vector;

class Word { // 영어 단어와 한글 단어를 쌍으로 가진 하나의 단어 표현

  private String english; // 영어 단어
  private String korean; // 영어 단어에 해당하는 한글 단어

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

  private String name; // WordQuiz 프로그램의 이름
  private Scanner scanner = new Scanner(System.in);
  private Vector<Word> v;

  public Practice_12(String name) {
    this.name = name;
    v = new Vector<Word>();
    v.add(new Word("love", "사랑"));
    v.add(new Word("animal", "동물"));
    v.add(new Word("emotion", "감정"));
    v.add(new Word("human", "인간"));
    v.add(new Word("stock", "주식"));
    v.add(new Word("trade", "거래"));
    v.add(new Word("society", "사회"));
    v.add(new Word("baby", "아기"));
    v.add(new Word("honey", "애인"));
    v.add(new Word("dall", "인형"));
    v.add(new Word("bear", "곰"));
    v.add(new Word("picture", "사진"));
    v.add(new Word("painting", "그림"));
    v.add(new Word("fault", "오류"));
    v.add(new Word("example", "보기"));
    v.add(new Word("eye", "눈"));
    v.add(new Word("statue", "조각상"));
  }

  // ex[] 배열에 4개의 보기를 만든다. 보기는 현재 단어 벡터에 있는 단어를 랜덤하게 4개를 선택하고, 벡터에 대한 인덱스를
  // ex[] 배열에 저장한다.
  // answerIndex는 정답이 있는 벡터의 인덱스이므로, ex []에는 answerIndex 값이 들어가지 않도록 한다.
  // 그러므로 이 메소드가 리턴할 때는 answerIndex가 없는 ex[] 배열이 만들어지며, ex[] 배열에 대한 임의의 인덱스틀
  // 리턴한다. 이 메소드가 끝난 뒤 이 위치에 answerIndex를 심는다.
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

  // 배열 n[]에 index의 값이 존재하면 true, 아니면 false 리턴
  private boolean exists(int n[], int index) {
    for (int i = 0; i < n.length; i++) {
      if (n[i] == index) return true;
    }
    return false;
  }

  public void run() {
    System.out.println(
      "**** 영어 단어 테스트 프로그램 \"" + name + "\" 입니다. ****"
    );
    while (true) {
      System.out.print("단어 테스트:1, 단어 삽입:2. 종료:3>> ");
      try {
        int menu = scanner.nextInt();
        switch (menu) {
          case 1:
            wordQuiz();
            break;
          case 2:
            insertWords();
            break;
          case 3:
            finish();
            return;
          default:
            System.out.println("잘못 입력하였습니다.");
        }
      } catch (InputMismatchException e) { // 사용자가 정수가 아닌 문자나 실수를 입력한 경우 예외 처리
        scanner.next(); // 현재 스트림 버퍼에 입력되어 있는 입력을 읽어서 제거함
        System.out.println("숫자를 입력하세요 !!");
        // 다시 while 문으로 반복
      }
      System.out.println(); // 빈 줄 한 줄 출력
    }
  }

  private void insertWords() {
    System.out.println("영어 단어에 그만을 입력하면 입력을 종료합니다.");
    while (true) {
      System.out.print("영어 한글 입력 >> ");
      String engWord = scanner.next(); // 영어 단어 읽기
      if (engWord.equals("그만")) break;

      String korWord = scanner.next(); // 한글 단어 읽기
      v.add(new Word(engWord, korWord));
    }
  }

  private void finish() {
    System.out.println("\"" + name + "\"를 종료합니다.");
    scanner.close();
  }

  private void wordQuiz() {
    System.out.println(
      "현재 " +
      v.size() +
      "개의 단어가 들어 있습니다. -1을 입력하면 테스트를 종료합니다."
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

      // 보기 모두 출력
      for (int i = 0; i < example.length; i++) System.out.print(
        "(" + (i + 1) + ")" + v.get(example[i]).getKorean() + " "
      ); // 보기 출력

      // 정답을 입력받을 프롬프트 출력
      System.out.print(":>"); // 프롬프트
      try {
        int in = scanner.nextInt(); // 사용자의 정답 입력
        if (in == -1) break; //단어 테스트를 끝내고자 하는 경우

        in--; // 입력된 정수(1~4)에 	1을 빼서 0으로부터 시작하는 인덱스로 바꿈
        if (in == answerLoc) System.out.println(
          "Excellent !!"
        ); else System.out.println("No. !!");
      } catch (InputMismatchException e) {
        scanner.next(); // 현재 스트림 버퍼에 입력되어 있는 입력을 읽어서 제거함
        System.out.println("숫자를 입력하세요 !!");
        // 다시 while 문으로 반복
      }
    }
  }

  public static void main(String[] args) {
    Practice_12 quiz = new Practice_12("명품영어");
    quiz.run();
  }
}
