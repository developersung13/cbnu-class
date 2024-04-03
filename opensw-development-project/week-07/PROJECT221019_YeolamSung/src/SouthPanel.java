import java.awt.*;
import javax.swing.*;

public class SouthPanel extends JPanel {

  public SouthPanel() {
    setBackground(Color.YELLOW);
    setLayout(new FlowLayout());
    add(new JButton("Word Input"));
    add(new JTextField(15));
  }
}
