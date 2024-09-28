package Education_system;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;


public class Subject_page {

    public Subject_page(String name, int student_class){

        JFrame frm4 = new JFrame("Subject Page");
        frm4.setSize(800, 600);
        frm4.getContentPane().setBackground(Color.decode("#5b9bd5"));
        frm4.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frm4.setLocationRelativeTo(null);
        frm4.setResizable(false);
        frm4.setLayout(null);

        JLabel lb2 = new JLabel("Education System");
        lb2.setBounds(280,40, 270, 50);
        lb2.setFont(new Font("Times New Roman", Font.BOLD, 25));
        lb2.setForeground(Color.white);

        JLabel lb3 = new JLabel("<html>Hello there! <u>" + name + "</u></html>");
        lb3.setBounds(580, 90, 250, 50);
        lb3.setFont(new Font("Times New Roman", Font.BOLD, 12));
        lb3.setForeground(Color.white);

        JLabel ul2 = new JLabel("You've choosen class  " + student_class);
        ul2.setBounds(285, 150, 250, 13);
        ul2.setFont(new Font("Times New Roman", Font.BOLD, 17));
        ul2.setForeground(Color.white);

        final JButton jbc = new JButton("Chemistry");
        jbc.setBounds(350, 200, 130, 40);
        jbc.setFont(new Font("Ariel", Font.BOLD, 12));
        jbc.setForeground(Color.WHITE);
        jbc.setBackground(Color.BLACK);
        jbc.setFocusable(false);

        final JButton jbp = new JButton("Physics");
        jbp.setBounds(350, 260, 130, 40);
        jbp.setFont(new Font("Ariel", Font.BOLD, 12));
        jbp.setForeground(Color.WHITE);
        jbp.setBackground(Color.BLACK);
        jbp.setFocusable(false);

        final JButton jbb = new JButton("Biology");
        jbb.setBounds(350, 320, 130, 40);
        jbb.setFont(new Font("Ariel", Font.BOLD, 12));
        jbb.setForeground(Color.WHITE);
        jbb.setBackground(Color.BLACK);
        jbb.setFocusable(false);

        final JButton jbm = new JButton("Math");
        jbm.setBounds(350, 380, 130, 40);
        jbm.setFont(new Font("Ariel", Font.BOLD, 12));
        jbm.setForeground(Color.WHITE);
        jbm.setBackground(Color.BLACK);
        jbm.setFocusable(false);

        final JButton pb = new JButton("Prev. Page");
        pb.setBounds(60, 480, 110, 25);
        pb.setFont(new Font("Ariel", Font.BOLD, 12));
        pb.setForeground(Color.white);
        pb.setBackground(Color.black);
        pb.setFocusable(false);

        ActionListener actionListener4 = e4 -> {
            if (e4.getSource() == jbc) {
                frm4.dispose();
                new ContentDisplayPage(name,student_class, "Chemistry");
            }
            if(e4.getSource() == jbp){
                frm4.dispose();
                new ContentDisplayPage(name, student_class, "Physics");
            }
            if(e4.getSource() == jbb){
                frm4.dispose();
                new ContentDisplayPage(name, student_class , "Biology");
            }
            if(e4.getSource() == jbm){
                frm4.dispose();
                new ContentDisplayPage(name, student_class , "Math");
            }
            if(e4.getSource() == pb){
                frm4.dispose();
                new ClassPage(name);
            }
        };
        jbc.addActionListener(actionListener4);
        jbp.addActionListener(actionListener4);
        jbb.addActionListener(actionListener4);
        jbm.addActionListener(actionListener4);
        pb.addActionListener(actionListener4);

        frm4.add(lb2);
        frm4.add(lb3);
        frm4.add(ul2);
        frm4.add(jbc);
        frm4.add(jbp);
        frm4.add(jbb);
        frm4.add(jbm);
        frm4.add(pb);
        frm4.setVisible(true);
    }

    // public static void main(String[] args) {
    //     new Subject_page("junaed",10);
    // }
}
