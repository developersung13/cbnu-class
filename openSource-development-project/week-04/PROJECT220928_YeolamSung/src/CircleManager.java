import java.util.Scanner;

class Circle {
    double x, y;
    int radius;
    public Circle(double x, double y, int radius) {
        this.x = x;
        this.y = y;
        this.radius = radius;
    }

    public double getCircleArea() {
        return 3.14 * radius * radius;
    }
}

public class CircleManager {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        double x, y;
        int radius, tmpIdx=0;
        Circle c[] = new Circle[3];
        for (int k=0; k < c.length; k++) {
            System.out.print("x, y, radius >> ");
            x = sc.nextDouble();
            y = sc.nextDouble();
            radius = sc.nextInt();
            c[k] = new Circle(x, y, radius);
        }

        double maxArea = c[0].getCircleArea();
        for (int k=1; k < c.length; k++) {
            if (maxArea < c[k].getCircleArea()) {
                maxArea = c[k].getCircleArea();
                tmpIdx = k;
            }
        } System.out.println("가장 면적이 큰 원은 (" + c[tmpIdx].x + "," + c[tmpIdx].y + ")" + c[tmpIdx].radius);
    }
}
