import java.awt.*;
import javax.swing.*;

public class CenterPanel extends JPanel {

  public CenterPanel() {
    setLayout(null);
    for (int i = 0; i < 10; i++) {
      JLabel jl = new JLabel("*");
      int x = (int) (Math.random() * 250);
      int y = (int) (Math.random() * 150);
      jl.setLocation(x, y);
      jl.setSize(20, 20);
      jl.setForeground(Color.red);
      add(jl);
    }
  }
}
