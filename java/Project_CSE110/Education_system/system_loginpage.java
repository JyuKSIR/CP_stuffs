package Education_system;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class system_loginpage {

    public system_loginpage() {

        JFrame frm = new JFrame("login");
        frm.setSize(800, 600);
        frm.getContentPane().setBackground(Color.decode("#5b9bd5"));
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frm.setLocationRelativeTo(null);
        frm.setResizable(false);
        frm.setLayout(null);

        JLabel lb = new JLabel("Education System");
        lb.setBounds(280,40, 270, 50);
        lb.setFont(new Font("Times New Roman", Font.BOLD, 25));
        lb.setForeground(Color.white);

        JLabel em3 = new JLabel("<html><u>Admin</u></html>");
        em3.setBounds(635, 110, 200, 15);
        em3.setFont(new Font("Ariel", Font.BOLD, 14));
        em3.setForeground(Color.BLACK);

        JLabel ul = new JLabel("Username");
        ul.setBounds(270, 150, 100, 9);
        ul.setFont(new Font("Times New Roman", Font.BOLD, 12));
        ul.setForeground(Color.white);

        JTextField utf = new JTextField();
        utf.setBounds(270, 175, 270, 35);
        utf.setFont(new Font("Times New Roman", Font.BOLD, 15));

        JLabel pl = new JLabel("Password");
        pl.setBounds(270, 230, 100, 9);
        pl.setFont(new Font("Times New Roman", Font.BOLD, 12));
        pl.setForeground(Color.white);

        JPasswordField pf = new JPasswordField();
        pf.setBounds(270, 255, 270, 35);
        pf.setFont(new Font("Times New Roman", Font.BOLD, 15));
        pf.setEchoChar('*');

        JCheckBox cb = new JCheckBox();
        cb.setBounds(268, 330, 20, 20);

        JLabel rl = new JLabel("Remember me");
        rl.setBounds(293, 335, 110, 9);
        rl.setFont(new Font("Times New Roman", Font.BOLD, 12));
        rl.setForeground(Color.white);

        JButton jb = new JButton("Login");
        jb.setBounds(360, 370, 110, 30);
        jb.setFont(new Font("Ariel", Font.BOLD, 12));
        jb.setForeground(Color.WHITE);
        jb.setBackground(Color.BLACK);
        jb.setFocusable(false);

        ActionListener actionListener2 = e2 -> {
            if (e2.getSource() == jb) {
                String uname = utf.getText();
                String pass = new String(pf.getPassword());

                if (uname.isEmpty() || pass.isEmpty()) {
                    JOptionPane.showMessageDialog(frm, "Username or Password cannot be empty", "Error", JOptionPane.ERROR_MESSAGE);
                } 
                else {
                    boolean match = false;
                    try {
                        FileReader fr = new FileReader("Username&Password.txt");
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
                            frm.dispose();
                            new ClassPage(uname);
                        } else {
                            JOptionPane.showMessageDialog(frm, "Wrong Username or Password", "Login Error", JOptionPane.ERROR_MESSAGE);
                        }
                    } catch (IOException e1) {
                        e1.printStackTrace();
                    }
                }
            }
        };
        jb.addActionListener(actionListener2);

        JLabel em = new JLabel("Don't have an account? ");
        em.setBounds(275, 420, 200, 15);
        em.setFont(new Font("Ariel", Font.BOLD, 12));
        em.setForeground(Color.white);

        JLabel em2 = new JLabel("<html><u>Sign Up</u></html>");
        em2.setBounds(445, 420, 200, 15);
        em2.setFont(new Font("Ariel", Font.BOLD, 14));
        em2.setForeground(new Color(204, 0, 0));

        JLabel em5 = new JLabel("<html><u>Change Password</u></html>");
        em5.setBounds(425, 300, 200, 15);
        em5.setFont(new Font("Times New Roman", Font.PLAIN, 13));
        em5.setForeground(Color.BLUE);

        em2.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                frm.dispose();
                new system_signuppage();
            }
        });

        em3.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                frm.dispose();
                new Admin_loginPage();
            }
        });

        em5.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                frm.dispose();
                new ChangePasswordPage("Username&Password.txt");
            }
        });

        frm.add(lb);
        frm.add(ul);
        frm.add(utf);
        frm.add(pl);
        frm.add(pf);
        frm.add(cb);
        frm.add(rl);
        frm.add(jb);
        frm.add(em);
        frm.add(em2);
        frm.add(em3);
        frm.add(em5);
        frm.setVisible(true);
    }

    // public static void main(String[] args) {
    //     new system_loginpage();
    // }
}

