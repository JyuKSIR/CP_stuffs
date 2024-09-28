package Education_system;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class Admin_loginPage{

    public Admin_loginPage() {

        JFrame frm8 = new JFrame("Admin login");
        frm8.setSize(800, 600);
        frm8.getContentPane().setBackground(Color.decode("#5b9bd5"));
        frm8.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frm8.setLocationRelativeTo(null);
        frm8.setResizable(false);
        frm8.setLayout(null);

        JLabel lb8 = new JLabel("Education System");
        lb8.setBounds(280,40, 270, 50);
        lb8.setFont(new Font("Times New Roman", Font.BOLD, 25));
        lb8.setForeground(Color.white);

        JLabel lb9 = new JLabel("Hello Sir!!");
        lb9.setBounds(340,120, 270, 50);
        lb9.setFont(new Font("Times New Roman", Font.BOLD, 20));
        lb9.setForeground(Color.white);

        JLabel ul2 = new JLabel("Username");
        ul2.setBounds(270, 180, 100, 9);
        ul2.setFont(new Font("Times New Roman", Font.BOLD, 12));
        ul2.setForeground(Color.white);

        JTextField utf2 = new JTextField();
        utf2.setBounds(270, 205, 270, 35);
        utf2.setFont(new Font("Times New Roman", Font.BOLD, 15));

        JLabel pl2 = new JLabel("Password");
        pl2.setBounds(270, 260, 100, 9);
        pl2.setFont(new Font("Times New Roman", Font.BOLD, 12));
        pl2.setForeground(Color.white);

        JPasswordField pf2 = new JPasswordField();
        pf2.setBounds(270, 285, 270, 35);
        pf2.setFont(new Font("Times New Roman", Font.BOLD, 15));
        pf2.setEchoChar('*');

        JButton jb2 = new JButton("Enter");
        jb2.setBounds(360, 360, 110, 30);
        jb2.setFont(new Font("Ariel", Font.BOLD, 12));
        jb2.setForeground(Color.WHITE);
        jb2.setBackground(Color.BLACK);
        jb2.setFocusable(false);

        ActionListener actionListener8 = e8 -> {
            if (e8.getSource() == jb2) {
                String uname = utf2.getText();
                String pass = new String(pf2.getPassword());

                if (uname.isEmpty() || pass.isEmpty()) {
                    JOptionPane.showMessageDialog(frm8, "Username or Password cannot be empty", "Error", JOptionPane.ERROR_MESSAGE);
                } 
                else {
                    boolean match = false;
                    try {
                        FileReader fr = new FileReader("AdminUsername&Password.txt");
                        BufferedReader br = new BufferedReader(fr);
                        String line;
                        while ((line = br.readLine()) != null) {
                            if (line.equals(uname + "\t" + pass)) {
                                match = true;
                                break;
                            }
                        }
                        br.close();
                        if (match) {
                            frm8.dispose();
                            new AdminPage(uname);
                        } else {
                            JOptionPane.showMessageDialog(frm8, "You're no Sir!!", "Login Error", JOptionPane.ERROR_MESSAGE);
                        }
                    } catch (IOException e1) {
                        e1.printStackTrace();
                    }
                }
            }
        };
        jb2.addActionListener(actionListener8);

        JLabel em4 = new JLabel("You are not the Admin? ");
        em4.setBounds(275, 425, 200, 15);
        em4.setFont(new Font("Ariel", Font.BOLD, 12));
        em4.setForeground(Color.white);

        JLabel em5 = new JLabel("<html><u>Log In</u></html>");
        em5.setBounds(445, 425, 200, 15);
        em5.setFont(new Font("Ariel", Font.BOLD, 14));
        em5.setForeground(new Color(204, 0, 0));

        em5.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                frm8.dispose();
                new system_loginpage();
            }
        });

        
        frm8.add(lb8);
        frm8.add(ul2);
        frm8.add(utf2);
        frm8.add(pl2);
        frm8.add(pf2);
        frm8.add(jb2);
        frm8.add(lb9);
        frm8.add(em4);
        frm8.add(em5);
        frm8.setVisible(true);
    }

    // public static void main(String[] args) {
    //     new Admin_loginPage();
    // }
}

