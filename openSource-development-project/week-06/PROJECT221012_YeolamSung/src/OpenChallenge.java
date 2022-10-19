import java.lang.Math;
import java.util.*;

class Word {

  String eng;
  String kor;

  public Word(String eng, String kor) {
    this.eng = eng;
    this.kor = kor;
  }
}

public class OpenChallenge {

  //제 컴퓨터 상 패키지랑 다 varyeun으로 해놔서 어쩔 수가 없었어요
  Vector<Word> v = new Vector<Word>();

  public OpenChallenge() {
    //저자가 이렇게 미리 17개 삽입해 두었다고 책에 나와있어요
    v.add(new Word("love", "사랑"));
    v.add(new Word("animal", "동물"));
    v.add(new Word("painting", "그림"));
    v.add(new Word("bear", "곰"));
    v.add(new Word("eye", "눈"));
    v.add(new Word("picture", "사진"));
    v.add(new Word("society", "사회"));
    v.add(new Word("human", "인간"));
    v.add(new Word("emotion", "감정"));
    v.add(new Word("error", "오류"));
    v.add(new Word("baby", "아기"));
    v.add(new Word("doll", "인형"));
    v.add(new Word("example", "보기"));
    v.add(new Word("deal", "거래"));
    v.add(new Word("statue", "조각상"));
    v.add(new Word("snowman", "눈사람"));
    v.add(new Word("christmas", "크리스마스"));
  }

  void makeexample(int[] ex, int answerindex, int size, int answer) {
    int n[] = { -1, -1, -1, -1 };
    int j;
    for (int i = 0; i < 4; i++) {
      do {
        j = (int) (Math.random() * size);
      } while (j == answerindex || exists(n, j));
      n[i] = j;
    } //n에는 v의 인덱스가 들어가있음
    n[answer - 1] = answerindex; //마지막에 answer에 answerindex 넣음
    for (int i = 0; i < 4; i++) {
      ex[i] = n[i];
    }
  }

  boolean exists(int n[], int j) {
    for (int i = 0; i < n.length; i++) {
      if (n[i] == j) return true;
    } //그니까 이전 보기들 중에 인덱스 겹치는 거 있으면 안되니까 검사함
    return false;
  }

  void run() {
    Scanner scanner = new Scanner(System.in);
    System.out.println(
      "\"명품영어\"의 단어 테스트를 시작합니다. -1을 입력하면 종료합니다."
    );
    System.out.println("현재 " + v.size() + "개의 단어가 들어 있습니다.");
    for (;;) {
      int answerindex = (int) (Math.random() * v.size());
      System.out.println(v.get(answerindex).eng + "?");
      int answer = (int) (Math.random() * 4 + 1);
      int ex[] = new int[4];
      makeexample(ex, answerindex, v.size(), answer);
      //그러면 보기 완성
      for (int i = 0; i < 4; i++) {
        System.out.print("(" + (i + 1) + ")" + v.get(ex[i]).kor + " ");
      }
      System.out.print(":>");
      int your_answer = scanner.nextInt();
      if (your_answer == -1) {
        System.out.println("\"명품영어\"를 종료합니다...");
        return;
      } else if (your_answer == answer) System.out.println(
        "Excellent !!"
      ); else System.out.println("No. !!");
    }
  }

  public static void main(String[] args) {
    OpenChallenge q = new OpenChallenge();
    q.run();
  }
}
