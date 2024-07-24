import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.io.*;

public class signup {
    
    signup() {

        JFrame fm = new JFrame("Signup Page");
        fm.setSize(350, 450);
        fm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        fm.setLocationRelativeTo(null);
        fm.setResizable(false);
        fm.setLayout(null);
        
        JLabel slb = new JLabel("ShitApp");
        slb.setBounds(130,10,100,40);
        slb.setFont(new Font("Times New Roman", Font.BOLD, 20));
        slb.setForeground(Color.BLACK);

        JLabel sul = new JLabel("Username");
        sul.setBounds(30,60,70,9);
        sul.setFont(new Font("Ariel", Font.BOLD, 12));
        sul.setForeground(Color.BLACK);

        JTextField sutf = new JTextField();
        sutf.setBounds(30, 80, 250, 35);
        sutf.setFont(new Font("Ariel",Font.BOLD,15));

        JLabel el = new JLabel("Email");
        el.setBounds(30,127,70,9);
        el.setFont(new Font("Ariel", Font.BOLD, 12));
        el.setForeground(Color.BLACK);

        JTextField etf = new JTextField();
        etf.setBounds(30, 152, 250, 35);
        etf.setFont(new Font("Ariel",Font.BOLD,15));

        JLabel spl = new JLabel("Password");
        spl.setBounds(30,197,70,9);
        spl.setFont(new Font("Ariel", Font.BOLD, 12));
        spl.setForeground(Color.BLACK);

        JPasswordField spf = new JPasswordField();
        spf.setBounds(30, 220, 250, 35);
        spf.setFont(new Font("Ariel", Font.BOLD, 15));
        spf.setEchoChar('*');

        JButton sjb = new JButton("Sign In");
        sjb.setBounds(90,285,110,30);
        sjb.setFont(new Font("Ariel", Font.BOLD, 12));
        sjb.setForeground(Color.WHITE);
        sjb.setBackground(Color.BLACK);
        sjb.setFocusable(false);

        ActionListener actionListener = e -> {
            if(e.getSource() == sjb ){
                try{
                    FileWriter file = new FileWriter("store.txt",true);
                    file.write(sutf.getText() + "\t" + new String(spf.getPassword()) + "\n");
                    file.close();
                    JOptionPane.showMessageDialog(fm, "You've Successfully Signed Up", "Sign Up", JOptionPane.INFORMATION_MESSAGE);
                    fm.dispose();
                    new loginpage();
                } 
                catch (IOException e1){
                    e1.printStackTrace();
                }
            }
        };
        sjb.addActionListener(actionListener);

        JLabel sem = new JLabel("Already have an account? ");
        sem.setBounds(55,333,200,15);
        sem.setFont(new Font("Ariel", Font.BOLD, 12));
        sem.setForeground(Color.BLACK);

        JLabel sem2 = new JLabel("<html><u>LogIn</u></html>");
        sem2.setBounds(205, 333, 200,15);
        sem2.setFont(new Font("Ariel", Font.BOLD, 14));
        sem2.setForeground(new Color(204,0,0));

        sem2.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                fm.dispose();
                new loginpage();
            }
        });

        fm.add(slb);
        fm.add(sul);
        fm.add(sutf);
        fm.add(el);
        fm.add(etf);
        fm.add(spl);
        fm.add(spf);
        fm.add(sjb);
        fm.add(sem);
        fm.add(sem2);
        fm.setVisible(true);
    }
}

