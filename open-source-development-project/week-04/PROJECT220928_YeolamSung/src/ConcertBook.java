import java.util.Scanner;

class Book {
    protected static String seatStatus[][] = new String[3][10];
    private static int seatLine;
    public Book() {
        for (int k=0; k < seatStatus.length; k++) {
            for (int z=0; z < seatStatus[0].length; z++) {
                seatStatus[k][z] = "---";
            }
        }
    }
    public void printSeats(int seatNum) {
        switch (seatNum) {
            case 1: System.out.print("S>> "); break;
            case 2: System.out.print("A>> "); break;
            default: System.out.print("B>> "); break;
        }
        seatLine = seatNum;
        for (int k=0; k < seatStatus[0].length; k++) {
            System.out.print(seatStatus[seatNum-1][k] + " ");
        } System.out.println();
    }

    public void setSeat(String name, int seatNum) {
        if (!seatStatus[seatLine-1][seatNum-1].equals("---")) {
            System.out.println("이미 예약된 좌석입니다. 다시 확인해 주세요.");
            return;
        }
        seatStatus[seatLine-1][seatNum-1] = name;
    }
}

class Search extends Book {
    public void printAllSeats() {
        for (int k=0; k < seatStatus.length; k++) {
            for (int z=0; z < seatStatus[0].length; z++) {
                System.out.print(seatStatus[k][z] + " ");
            } System.out.println();
        }
    }
}

class CancelBook extends Book {
    public void cancelSeat(String name, int seatNum) {
        for (int k=0; k < seatStatus[0].length; k++) {
            if (seatStatus[seatNum-1][k].equals(name)) {
                seatStatus[seatNum-1][k] = "---";
                return;
            }
        } System.out.println("해당 이름으로 등록된 예약이 없습니다. 다시 입력해 주세요.");
    }
}

public class ConcertBook {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Book book = new Book();
        Search search = new Search();
        CancelBook cancelBook = new CancelBook();

        int choose, seatNum;
        String name;

        System.out.println("명품콘서트홀 예약 시스템입니다.");
        while(true) {
            System.out.print("예약: 1, 조회: 2, 취소: 3, 끝내기: 4 >>");
            choose = sc.nextInt();
            switch(choose) {
                case 1: {
                    System.out.print("좌석구분 S(1), A(2), B(3)>>");
                    seatNum = sc.nextInt();
                    if (seatNum <= 0 || seatNum >= 4) {
                        System.out.println("좌석은 1~3 사이의 값을 입력해 주세요.");
                        continue;
                    }
                    book.printSeats(seatNum);
                    System.out.print("이름>>");
                    name = sc.next();
                    System.out.print("번호>>");
                    seatNum = sc.nextInt();
                    if (seatNum <= 0 || seatNum >= 11) {
                        System.out.println("좌석은 1~10 사이의 값을 입력해 주세요.");
                        continue;
                    }
                    book.setSeat(name, seatNum);
                    break;  
                } 
                case 2: {
                    search.printAllSeats();
                    break;  
                } 
                case 3: {
                    System.out.print("좌석 S:1, A:2, B:3>>");
                    seatNum = sc.nextInt();
                    if (seatNum <= 0 || seatNum >= 4) {
                        System.out.println("좌석은 1~3 사이의 값을 입력해 주세요.");
                        continue;
                    }
                    System.out.print("이름>>");
                    name = sc.next();
                    cancelBook.cancelSeat(name, seatNum);
                    break;
                }
                case 4: return;
                default:
                    System.out.println("1~4 사이의 값을 입력해 주세요.");
            }
        }
    }
}
