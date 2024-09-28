package Education_system;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class ScoreBoardPage {
    

    public ScoreBoardPage(String name, int student_class,int score){

        JFrame frm7 = new JFrame("Scoreboard Page");
        frm7.setSize(800, 600);
        frm7.getContentPane().setBackground(Color.decode("#5b9bd5"));
        frm7.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frm7.setLocationRelativeTo(null);
        frm7.setResizable(false);
        frm7.setLayout(null);

        JLabel lb7 = new JLabel("Education System");
        lb7.setBounds(280,40, 270, 50);
        lb7.setFont(new Font("Times New Roman", Font.BOLD, 25));
        lb7.setForeground(Color.white);


        JLabel lb8 = new JLabel( name + " your Score is " + score);
        lb8.setBounds(270, 190, 300, 50);
        lb8.setFont(new Font("Times New Roman", Font.BOLD, 22));
        lb8.setForeground(Color.WHITE);

        JLabel lb9 = new JLabel("<html>Hello there! <u>" + name + "</u></html>");
        lb9.setBounds(580, 90, 250, 50);
        lb9.setFont(new Font("Times New Roman", Font.BOLD, 12));
        lb9.setForeground(Color.white);

        if(score < 8){
            JLabel lb10 = new JLabel("Study Hard " + name);
            lb10.setBounds(300, 260, 250, 50);
            lb10.setFont(new Font("Times New Roman", Font.BOLD, 17));
            lb10.setForeground(Color.white);
            frm7.add(lb10);
        }
        else{
            JLabel lb10 = new JLabel("You did great " + name);
            lb10.setBounds(300, 260, 250, 50);
            lb10.setFont(new Font("Times New Roman", Font.BOLD, 17));
            lb10.setForeground(Color.white);
            frm7.add(lb10);
        }

        final JButton cpb = new JButton("Subject Page");
        cpb.setBounds(260, 390, 130, 40);
        cpb.setFont(new Font("Ariel", Font.BOLD, 12));
        cpb.setForeground(Color.WHITE);
        cpb.setBackground(Color.BLACK);
        cpb.setFocusable(false);

        final JButton eb = new JButton("Exit");
        eb.setBounds(400, 390, 130, 40);
        eb.setFont(new Font("Ariel", Font.BOLD, 12));
        eb.setForeground(Color.WHITE);
        eb.setBackground(Color.BLACK);
        eb.setFocusable(false);

        ActionListener actionListener7 = e7 -> {
            if(e7.getSource() == cpb){
                frm7.dispose();
                new Subject_page(name, student_class);
            }
            if(e7.getSource() == eb){
                frm7.dispose();
            }
        };
        cpb.addActionListener(actionListener7);
        eb.addActionListener(actionListener7);

        frm7.add(lb7);
        frm7.add(lb8);
        frm7.add(lb9);
        frm7.add(cpb);
        frm7.add(eb);
        frm7.setVisible(true);
    }

    // public static void main(String[] args) {
    //     new ScoreBoardPage("Junaed", 9, 8);
    // }
}
