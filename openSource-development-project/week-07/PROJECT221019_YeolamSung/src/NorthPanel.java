import java.awt.*;
import javax.swing.*;

public class NorthPanel extends JPanel {

  public NorthPanel() {
    setBackground(Color.LIGHT_GRAY);
    setLayout(new FlowLayout());
    add(new JButton("열기"));
    add(new JButton("닫기"));
    add(new JButton("나가기"));
  }
}
