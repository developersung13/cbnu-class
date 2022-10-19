import java.awt.*;
import javax.swing.*;

public class South extends JPanel {

  public South() {
    setBackground(Color.YELLOW);
    setLayout(new FlowLayout());
    add(new JLabel("계산 결과"));
    add(new JTextField(18));
  }
}
