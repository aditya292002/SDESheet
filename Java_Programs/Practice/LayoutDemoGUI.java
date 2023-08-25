import javax.swing.*;
import java.awt.*;

public class LayoutDemoGUI extends JFrame {
    private JButton button1;
    private JButton button2;
    private JButton button3;
    private JButton button4;
    private JButton button5;

    public LayoutDemoGUI() {
        setTitle("A Layout Demo");
        setLayout(new BorderLayout());

        // Button 1 occupying the entire width
        button1 = new JButton("Button 1");
        add(button1, BorderLayout.NORTH);

        // Panel for buttons 3, 4, and 5
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(1, 3));

        button3 = new JButton("Button 3");
        buttonPanel.add(button3);

        button4 = new JButton("Button 4");
        buttonPanel.add(button4);

        button5 = new JButton("Button 5");
        buttonPanel.add(button5);

        add(buttonPanel, BorderLayout.CENTER);

        // Button 2 occupying the entire width
        JButton button2 = new JButton("Button 2");
        add(button2, BorderLayout.SOUTH);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 200);
        setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new LayoutDemoGUI());
    }
}
