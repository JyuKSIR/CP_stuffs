package Education_system;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionListener;


import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;


public class ClassPage {
    
    
    public ClassPage(String name){
        
        
        JFrame frm3 = new JFrame("Class Page");

        frm3.setSize(800, 600);
        frm3.getContentPane().setBackground(Color.decode("#5b9bd5"));
        frm3.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frm3.setLocationRelativeTo(null);
        frm3.setResizable(false);
        frm3.setLayout(null);

        JLabel lb1 = new JLabel("Education System");
        lb1.setBounds(280,40, 270, 50);
        lb1.setFont(new Font("Times New Roman", Font.BOLD, 25));
        lb1.setForeground(Color.white);

        JLabel lb2 = new JLabel("<html>Hello there! <u>" + name + "</u></html>");
        lb2.setBounds(580, 90, 250, 50);
        lb2.setFont(new Font("Times New Roman", Font.BOLD, 12));
        lb2.setForeground(Color.white);


        JLabel ul1 = new JLabel("Which Class are you in? ");
        ul1.setBounds(300, 150, 250, 17);
        ul1.setFont(new Font("Times New Roman", Font.BOLD, 17));
        ul1.setForeground(Color.white);

        final JButton jbc9 = new JButton("Class 9");
        jbc9.setBounds(350, 200, 130, 40);
        jbc9.setFont(new Font("Ariel", Font.BOLD, 12));
        jbc9.setForeground(Color.WHITE);
        jbc9.setBackground(Color.BLACK);
        jbc9.setFocusable(false);

        final JButton jbc10 = new JButton("Class 10");
        jbc10.setBounds(350, 260, 130, 40);
        jbc10.setFont(new Font("Ariel", Font.BOLD, 12));
        jbc10.setForeground(Color.WHITE);
        jbc10.setBackground(Color.BLACK);
        jbc10.setFocusable(false);

        final JButton jbc11 = new JButton("Class 11");
        jbc11.setBounds(350, 320, 130, 40);
        jbc11.setFont(new Font("Ariel", Font.BOLD, 12));
        jbc11.setForeground(Color.WHITE);
        jbc11.setBackground(Color.BLACK);
        jbc11.setFocusable(false);

        final JButton jbc12 = new JButton("Class 12");
        jbc12.setBounds(350, 380, 130, 40);
        jbc12.setFont(new Font("Ariel", Font.BOLD, 12));
        jbc12.setForeground(Color.WHITE);
        jbc12.setBackground(Color.BLACK);
        jbc12.setFocusable(false);


        ActionListener actionListener3 = e3 -> {
            if (e3.getSource() == jbc9) {
                frm3.dispose();
                new Subject_page(name,9);
            }
            if(e3.getSource() == jbc10){
                frm3.dispose();
                new Subject_page(name,10);
            }
            if(e3.getSource() == jbc11){
                frm3.dispose();
                new Subject_page(name,11);
            }
            if(e3.getSource() == jbc12){
                frm3.dispose();
                new Subject_page(name,12);
            }
        };
        jbc9.addActionListener(actionListener3);
        jbc10.addActionListener(actionListener3);
        jbc11.addActionListener(actionListener3);
        jbc12.addActionListener(actionListener3);
        


        frm3.add(lb1);
        frm3.add(lb2);
        frm3.add(ul1);
        frm3.add(jbc9);
        frm3.add(jbc10);
        frm3.add(jbc11);
        frm3.add(jbc12);
        frm3.setVisible(true);
    }

    // public static void main(String[] args) {
    //     new ClassPage("Junaed");
    // }
}
