package Education_system;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;


public class AdminPage implements DisplayInformation {
    
    public AdminPage(String name){

        JFrame frm9 = new JFrame("Admin login");
        frm9.setSize(800, 600);
        frm9.getContentPane().setBackground(Color.decode("#5b9bd5"));
        frm9.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frm9.setLocationRelativeTo(null);
        frm9.setResizable(false);
        frm9.setLayout(null);

        JLabel lb9 = new JLabel("Education System");
        lb9.setBounds(280,40, 270, 50);
        lb9.setFont(new Font("Times New Roman", Font.BOLD, 25));
        lb9.setForeground(Color.white);

        JLabel lb10 = new JLabel("Hello " + name + " Sir!!");
        lb10.setBounds(310,120, 270, 50);
        lb10.setFont(new Font("Times New Roman", Font.BOLD, 20));
        lb10.setForeground(Color.white);
        
        JButton jb5 = new JButton("Enrolled students");
        jb5.setBounds(330, 200, 170, 50);
        jb5.setFont(new Font("Ariel", Font.BOLD, 12));
        jb5.setForeground(Color.WHITE);
        jb5.setBackground(Color.BLACK);
        jb5.setFocusable(false);

        JButton jb6 = new JButton("Students results");
        jb6.setBounds(330, 270, 170, 50);
        jb6.setFont(new Font("Ariel", Font.BOLD, 12));
        jb6.setForeground(Color.WHITE);
        jb6.setBackground(Color.BLACK);
        jb6.setFocusable(false);

        JButton jb7 = new JButton("Login Page");
        jb7.setBounds(330, 340, 170, 50);
        jb7.setFont(new Font("Ariel", Font.BOLD, 12));
        jb7.setForeground(Color.WHITE);
        jb7.setBackground(Color.BLACK);
        jb7.setFocusable(false);

        ActionListener actionListener9 = e9 -> {
            if (e9.getSource() == jb5) {
                displayStudentInformation("student_information.txt");
            }
            if (e9.getSource() == jb6) {
                displayStudentResults("scores.txt");
            }
            if (e9.getSource() == jb7) {
                frm9.dispose();
                new system_loginpage();
            }
        };
        jb5.addActionListener(actionListener9);
        jb6.addActionListener(actionListener9);
        jb7.addActionListener(actionListener9);

        frm9.add(lb9);
        frm9.add(lb10);
        frm9.add(jb5);
        frm9.add(jb6);
        frm9.add(jb7);
        frm9.setVisible(true);
    }

    public void displayStudentInformation(String filename) {
        JFrame frm10 = new JFrame("Enrolled Students");
        frm10.setSize(600, 400);
        frm10.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frm10.setLocationRelativeTo(null);
        frm10.setResizable(false);
        
        JTextArea jta2 = new JTextArea();
        jta2.setFont(new Font("Times New Roman", Font.BOLD, 17));
        jta2.setLineWrap(true);
        jta2.setWrapStyleWord(true);
        jta2.setForeground(Color.black);
        jta2.setEditable(false);
        JScrollPane sp2 = new JScrollPane(jta2, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
        
        StringBuilder sbb = new StringBuilder();
        int studentCount = 0;
        
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split("\t");
                if (parts.length >= 2) {
                    sbb.append("Email: ").append(parts[0]).append(" \nName: ").append(parts[1]).append("\n\n"); // Add an extra newline
                    studentCount++;
                } else {
                    sbb.append("Insufficient data in line: ").append(line).append("\n");
                }
            }
        } catch (IOException e) {
            sbb.append("Error reading file: ").append(e.getMessage());
        }
        
        sbb.append("Total Enrolled Students: ").append(studentCount);
        
        jta2.setText(sbb.toString());
        frm10.add(sp2);
        frm10.setVisible(true);
    }

    public void displayStudentResults(String filename) {
        JFrame frm11 = new JFrame("Students Results");
        frm11.setSize(600, 400);
        frm11.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frm11.setLocationRelativeTo(null);
        frm11.setResizable(false);
        
        JTextArea jta3 = new JTextArea();
        jta3.setFont(new Font("Times New Roman", Font.BOLD, 17));
        jta3.setLineWrap(true);
        jta3.setWrapStyleWord(true);
        jta3.setForeground(Color.black);
        jta3.setEditable(false);
        JScrollPane sp2 = new JScrollPane(jta3, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
        
        StringBuilder sb = new StringBuilder();
        
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split("\t");
                if (parts.length >= 4) {
                    sb.append("Student Name: ").append(parts[0])
                           .append("\nStudent Class: ").append(parts[1])
                           .append("\nSubject: ").append(parts[2])
                           .append("\nScore: ").append(parts[3]).append("\n\n");
                } else {
                    sb.append("Insufficient data in line: ").append(line).append("\n");
                }
            }
        } catch (IOException e) {
            sb.append("Error reading file: ").append(e.getMessage());
        }
        
        jta3.setText(sb.toString());
        frm11.add(sp2);
        frm11.setVisible(true);
    }
    // public static void main(String[] args) {
    //     new AdminPage("Junaed");
    // }

}
