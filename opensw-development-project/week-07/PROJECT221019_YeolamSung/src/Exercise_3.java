import java.awt.*;
import javax.swing.*;

public class Exercise_3 extends JFrame {

  public Exercise_3() {
    setTitle("Ten Color Buttons Frame");
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    Container c = getContentPane();
    c.setLayout(new GridLayout(1, 10));

    for (int i = 0; i < 10; i++) {
      c.add(new JButton(Integer.toString(i)));
    }

    setSize(450, 200);
    setVisible(true);
  }

  public static void main(String[] args) {
    new Exercise_3();
  }
}
