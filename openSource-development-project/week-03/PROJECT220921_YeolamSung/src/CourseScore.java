import java.util.Scanner;

public class CourseScore {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String course[] = {"Java", "C++", "HTML5", "컴퓨터구조", "안드로이드"};
        String userInput;
        int score[] = {95, 88, 76, 62, 55};
        boolean tf;

        while (true) {
            tf = false;
            System.out.print("과목이름>>");
            userInput = sc.next();
            if (userInput.equals("그만")) break;
            for (int k=0; k < course.length; k++) {
                if (userInput.equals(course[k])) {
                    System.out.println(course[k] + "의 점수는 " + score[k]);
                    tf = true;
                    break;
                }
            } if (!tf) {
                System.out.println("없는 과목입니다.");
            }
        }
    }
}
