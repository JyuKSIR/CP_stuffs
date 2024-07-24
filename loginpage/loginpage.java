import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;

public class loginpage {

    loginpage () {

        JFrame frm = new JFrame("Login Page");
        frm.setSize(350, 450);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frm.setLocationRelativeTo(null);
        frm.setResizable(false);
        frm.setLayout(null);

        JLabel lb = new JLabel("ShitApp");
        lb.setBounds(130,10,100,40);
        lb.setFont(new Font("Times New Roman", Font.BOLD, 20));
        lb.setForeground(Color.BLACK);

        JLabel ul = new JLabel("Username");
        ul.setBounds(30,60,70,9);
        ul.setFont(new Font("Ariel", Font.BOLD, 12));
        ul.setForeground(Color.BLACK);

        JTextField utf = new JTextField();
        utf.setBounds(30, 80, 250, 35);
        utf.setFont(new Font("Ariel",Font.BOLD,15));
        
        JLabel pl = new JLabel("Password");
        pl.setBounds(30,145,70,9);
        pl.setFont(new Font("Ariel", Font.BOLD, 12));
        pl.setForeground(Color.BLACK);
        
        JPasswordField pf = new JPasswordField();
        pf.setBounds(30, 165, 250, 35);
        pf.setFont(new Font("Ariel", Font.BOLD, 15));
        pf.setEchoChar('*');

        JCheckBox cb = new JCheckBox();
        cb.setBounds(27, 210, 20, 20);

        JLabel rl = new JLabel("Remember me");
        rl.setBounds(52,215,110,9);
        rl.setFont(new Font("Ariel", Font.BOLD, 12));
        rl.setForeground(Color.BLACK);

        JButton jb = new JButton("Login");
        jb.setBounds(90,250,110,30);
        jb.setFont(new Font("Ariel", Font.BOLD, 12));
        jb.setForeground(Color.WHITE);
        jb.setBackground(Color.BLACK);
        jb.setFocusable(false);

        ActionListener actionListener2 = e2 -> {
            if(e2.getSource() == jb ) {
                boolean match = false;
                String uname = utf.getText();
                String pass = new String(pf.getPassword());

                try{
                    FileReader fr = new FileReader("store.txt");
                    BufferedReader br = new BufferedReader(fr);
                    String line;
                    while((line = br.readLine()) != null){
                        if(line.equals(uname + "\t" + pass)){
                            match = true;
                            break;
                        }
                    }
                    br.close();
                    if(match){
                        JOptionPane.showMessageDialog(frm, "You've Successfully Logged in");
                    }
                    else{
                        JOptionPane.showMessageDialog(frm, "Wrong Password");
                    }
                }
                catch(IOException e1){
                    e1.printStackTrace();
                }
            }
        };
        jb.addActionListener(actionListener2);
        
        JLabel em = new JLabel("Don't have an account? ");
        em.setBounds(55,300,200,15);
        em.setFont(new Font("Ariel", Font.BOLD, 12));
        em.setForeground(Color.BLACK);
        
        JLabel em2 = new JLabel("<html><u>Sign Up</u></html>");
        em2.setBounds(190, 300, 200,15);
        em2.setFont(new Font("Ariel", Font.BOLD, 14));
        em2.setForeground(new Color(204,0,0));
        
        em2.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                frm.dispose();
                new signup();
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
        frm.setVisible(true);
    }
    
}
