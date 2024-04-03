import java.util.Scanner;

class Phone {
    private String name;
    private String tel;
    public Phone(String name, String tel) {
        this.name = name;
        this.tel = tel;
    }

    public String getUserTel(String name) {
        if (this.name.equals(name)) return this.tel;
        return "";
    }
}

public class PhoneBook {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("인원수>>");
        int pNum = sc.nextInt();
        Phone pArr[] = new Phone[pNum];
        String name, tel, searchName, ans="";
        
        for (int k=0; k < pNum; k++) {
            System.out.print("이름과 전화번호(이름과 번호는 빈 칸 없이 입력)>>");
            name = sc.next();
            tel = sc.next();
            pArr[k] = new Phone(name, tel);
        } System.out.println("저장되었습니다...");
        sc.nextLine();
        while(true) {
            System.out.print("검색할 이름>>");
            searchName = sc.next();
            if (searchName.equals("그만")) break;
            for (int k=0; k < pNum; k++) {
                ans = pArr[k].getUserTel(searchName);
                if (!ans.equals("")) break;
            }

            if (ans.equals(""))
                System.out.println(searchName + "이 없습니다.");
            else
                System.out.println(searchName + "의 번호는 " + ans + "입니다.");
        }
        sc.close();
    }
}