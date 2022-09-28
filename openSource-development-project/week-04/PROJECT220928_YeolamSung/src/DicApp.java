import java.util.Scanner;

class Dictionary {
    private static String kor[] = { "사랑", "아기", "돈", "미래", "희망" };
    private static String eng[] = { "love", "baby", "money", "future", "hope" };
    public static String kor2Eng(String word) {
        for (int k=0; k < kor.length; k++) {
            if (word.equals(kor[k])) {
                return word + "은(는) " + eng[k];
            }
        } return "";
    }
    
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Dictionary d = new Dictionary();
        String kor, ans;;

        System.out.println("한영 단어 검색 프로그램입니다.");
        while(true) {
            System.out.print("한글 단어?");
            kor = sc.next();
            if (kor.equals("그만")) break;
            ans = d.kor2Eng(kor);
            if (ans.equals("")) {
                System.out.println(kor + "은(는) 저의 사전에 없습니다.");
                continue;
            }
            System.out.println(ans);
        }
    }
}