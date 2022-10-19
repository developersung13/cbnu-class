import java.awt.*;
import javax.swing.*;

public class Exercise_7 extends JFrame {

  public Exercise_7() {
    setTitle("Random Labels");
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    Container c = getContentPane();
    c.setLayout(new BorderLayout());

    c.add(new North(), BorderLayout.NORTH);
    c.add(new Center(), BorderLayout.CENTER);
    c.add(new South(), BorderLayout.SOUTH);

    setSize(300, 300);
    setVisible(true);
  }

  public static void main(String[] args) {
    new Exercise_7();
  }
}
