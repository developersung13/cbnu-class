import java.awt.*;
import javax.swing.*;

public class Center extends JPanel {

  public Center() {
    setLayout(new GridLayout(4, 4, 4, 4));
    for (int i = 0; i < 10; i++) {
      add(new JButton(Integer.toString(i)));
    }
    add(new JButton("CE"));
    add(new JButton("계산"));

    JButton[] bList = new JButton[] {
      new JButton("+"),
      new JButton("-"),
      new JButton("x"),
      new JButton("/"),
    };
    for (int i = 0; i < 4; i++) {
      bList[i].setBackground(Color.CYAN);
      add(bList[i]);
    }
  }
}
