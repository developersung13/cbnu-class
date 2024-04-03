import java.awt.*;
import javax.swing.*;

public class North extends JPanel {

  public North() {
    setBackground(Color.LIGHT_GRAY);
    setLayout(new FlowLayout());
    add(new JLabel("수식입력"));
    add(new JTextField(18));
  }
}
