import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;

class Location {

  private String city;
  private double longitude; // 경도
  private double latitude; // 위도

  public Location(String city, double longitude, double latitude) {
    this.city = city;
    this.longitude = longitude;
    this.latitude = latitude;
  }

  public void setCity(String city) {
    this.city = city;
  }

  public String getCity() {
    return city;
  }

  public void setLogitude(double longitude) {
    this.longitude = longitude;
  }

  public double getLongitude() {
    return longitude;
  }

  public void setLatitude(double latitude) {
    this.latitude = latitude;
  }

  public double getLatitude() {
    return latitude;
  }
}

public class Practice_6 {

  private Scanner scanner = new Scanner(System.in);
  private HashMap<String, Location> dept = new HashMap<String, Location>();

  private void read() {
    System.out.println("도시,경도,위도를 입력하세요.");
    for (int i = 0; i < 4; i++) {
      System.out.print(">> ");
      String text = scanner.nextLine();
      StringTokenizer st = new StringTokenizer(text, ",");
      String city = st.nextToken().trim();
      double logitude = Double.parseDouble(st.nextToken().trim());
      double latitude = Double.parseDouble(st.nextToken().trim());

      Location loc = new Location(city, logitude, latitude);
      dept.put(city, loc); //해시맵에 저장
    }
  }

  private void printAll() {
    Set<String> key = dept.keySet();
    Iterator<String> it = key.iterator();
    System.out.println("---------------------------");
    while (it.hasNext()) {
      String city = it.next(); // 도시 이름 알아냄
      Location loc = dept.get(city); // 도시 이름을 키로하여 해시맵에서 Locaiton 객체 얻어냄

      System.out.print(loc.getCity() + "\t");
      System.out.print(loc.getLongitude() + "\t");
      System.out.println(loc.getLatitude());
    }
    System.out.println("---------------------------");
  }

  private void processQuery() {
    while (true) {
      System.out.print("도시 이름 >> ");
      String city = scanner.nextLine(); // 도시 이름 입력
      if (city.equals("그만")) return; // 종료

      Location loc = dept.get(city); // 해시맵에서 도시를 키로 검색
      if (loc == null) { // 도시가 해시맵에 없다면
        System.out.println(city + "는 없습니다.");
      } else { // 해시맵에서 검색된  Student 객체
        System.out.print(loc.getCity() + "\t");
        System.out.print(loc.getLongitude() + "\t");
        System.out.println(loc.getLatitude());
      }
    }
  }

  public void run() {
    read();
    printAll();
    processQuery();
  }

  public static void main(String[] args) {
    Practice_6 man = new Practice_6();
    man.run();
  }
}
