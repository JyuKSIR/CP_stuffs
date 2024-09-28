package Education_system;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.FileWriter;
import java.io.IOException;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class system_signuppage {
    public system_signuppage() {

        JFrame frm1 = new JFrame("Signup");
        frm1.setSize(800, 600);
        frm1.getContentPane().setBackground(Color.decode("#5b9bd5"));
        frm1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frm1.setLocationRelativeTo(null);
        frm1.setResizable(false);
        frm1.setLayout(null);
        
        JLabel slb = new JLabel("Education System");
        slb.setBounds(280, 40, 270, 50);
        slb.setFont(new Font("Times New Roman", Font.BOLD, 25));
        slb.setForeground(Color.white);
        
        JLabel sel = new JLabel("Email");
        sel.setBounds(270, 150, 100, 9);
        sel.setFont(new Font("Times New Roman", Font.BOLD, 12));
        sel.setForeground(Color.white);
        
        JTextField setf = new JTextField();
        setf.setBounds(270, 175, 270, 35);
        setf.setFont(new Font("Times New Roman", Font.BOLD, 15));

        JLabel sul = new JLabel("Username");
        sul.setBounds(270, 230, 100, 9);
        sul.setFont(new Font("Times New Roman", Font.BOLD, 12));
        sul.setForeground(Color.white);

        JTextField sutf = new JTextField();
        sutf.setBounds(270, 255, 270, 35);
        sutf.setFont(new Font("Times New Roman", Font.BOLD, 15));

        JLabel spl = new JLabel("Password");
        spl.setBounds(270, 310, 100, 9);
        spl.setFont(new Font("Times New Roman", Font.BOLD, 12));
        spl.setForeground(Color.white);

        JPasswordField spf = new JPasswordField();
        spf.setBounds(270, 335, 270, 35);
        spf.setFont(new Font("Times New Roman", Font.BOLD, 15));
        spf.setEchoChar('*');

        JButton sjb = new JButton("Sign Up");
        sjb.setBounds(360, 400, 110, 30);
        sjb.setFont(new Font("Ariel", Font.BOLD, 12));
        sjb.setForeground(Color.WHITE);
        sjb.setBackground(Color.BLACK);
        sjb.setFocusable(false);

        ActionListener actionListener = e -> {
            if (e.getSource() == sjb) {
                String email = setf.getText();
                String uname = sutf.getText();
                String pass = new String(spf.getPassword());
                if (email.isEmpty() || uname.isEmpty() || pass.isEmpty()) {
                    JOptionPane.showMessageDialog(frm1, "All fields must be filled", "Error", JOptionPane.ERROR_MESSAGE);
                } else {
                    try {
                        FileWriter file1 = new FileWriter("Username&Password.txt", true);
                        file1.write(uname + "\t" + pass + "\n");
                        file1.close();

                        FileWriter file2 = new FileWriter("student_information.txt", true);
                        file2.write(email + "\t" + uname + "\n");
                        file2.close();

                        JOptionPane.showMessageDialog(frm1, "You've Successfully Signed Up", "Sign Up", JOptionPane.INFORMATION_MESSAGE);
                        frm1.dispose();
                        new system_loginpage();
                    } 
                    catch (IOException e1) {
                        e1.printStackTrace();
                    }
                }
            }
        };
        sjb.addActionListener(actionListener);

        JLabel sem = new JLabel("Already have an account? ");
        sem.setBounds(275, 460, 200, 15);
        sem.setFont(new Font("Ariel", Font.BOLD, 12));
        sem.setForeground(Color.white);

        JLabel sem2 = new JLabel("<html><u>Log In</u></html>");
        sem2.setBounds(460, 460, 200, 15);
        sem2.setFont(new Font("Ariel", Font.BOLD, 14));
        sem2.setForeground(new Color(204, 0, 0));

        sem2.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                frm1.dispose();
                new system_loginpage();
            }
        });

        frm1.add(slb);
        frm1.add(sel);
        frm1.add(setf);
        frm1.add(sul);
        frm1.add(sutf);
        frm1.add(spl);
        frm1.add(spf);
        frm1.add(sjb);
        frm1.add(sem);
        frm1.add(sem2);
        frm1.setVisible(true);
    }

    // public static void main(String[] args) {
    //     new system_signuppage();
    // }
}
