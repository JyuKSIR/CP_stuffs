package Education_system;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class ContentDisplayPage {

    
    public ContentDisplayPage(String name, int student_class, String subject){

        JFrame frm5 = new JFrame("Subject Page");
        frm5.setSize(900, 700);
        frm5.getContentPane().setBackground(Color.decode("#5b9bd5"));
        frm5.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frm5.setLocationRelativeTo(null);
        frm5.setResizable(false);
        frm5.setLayout(null);

        JLabel lb3 = new JLabel("Education System");
        lb3.setBounds(320,20, 270, 50);
        lb3.setFont(new Font("Times New Roman", Font.BOLD, 25));
        lb3.setForeground(Color.white);

        JLabel lb4 = new JLabel("<html>Hello there! <u>" + name + "</u></html>");
        lb4.setBounds(690, 50, 250, 50);
        lb4.setFont(new Font("Times New Roman", Font.BOLD, 12));
        lb4.setForeground(Color.white);

        JLabel ul3 = new JLabel("You've chosen subject " + subject);
        ul3.setBounds(310, 90, 400, 20);
        ul3.setFont(new Font("Times New Roman", Font.BOLD, 17));
        ul3.setForeground(Color.white);

        JTextArea jta = new JTextArea();
        jta.setLineWrap(true);
        jta.setWrapStyleWord(true);
        jta.setBackground(Color.decode("#5b9bd5"));
        jta.setForeground(Color.black);
        jta.setEditable(false);

        // for giving example

        if(subject == "Chemistry"){
            try {
                BufferedReader reader = new BufferedReader(new FileReader("Chemistry.txt"));
                String line;
                while ((line = reader.readLine()) != null) {
                    jta.append(line + "\n");
                }
                reader.close();
            } catch (IOException e) {
                jta.append("Error reading file: " + e.getMessage());
            }
        }

        if(subject == "Physics"){
            try {
                BufferedReader reader = new BufferedReader(new FileReader("Physics.txt"));
                String line;
                while ((line = reader.readLine()) != null) {
                    jta.append(line + "\n");
                }
                reader.close();
            } catch (IOException e) {
                jta.append("Error reading file: " + e.getMessage());
            }
        }

        if(subject == "Biology"){
            try {
                BufferedReader reader = new BufferedReader(new FileReader("Biology.txt"));
                String line;
                while ((line = reader.readLine()) != null) {
                    jta.append(line + "\n");
                }
                reader.close();
            } catch (IOException e) {
                jta.append("Error reading file: " + e.getMessage());
            }
        }

        if(subject == "Math"){
            try {
                BufferedReader reader = new BufferedReader(new FileReader("Math.txt"));
                String line;
                while ((line = reader.readLine()) != null) {
                    jta.append(line + "\n");
                }
                reader.close();
            } catch (IOException e) {
                jta.append("Error reading file: " + e.getMessage());
            }
        }

        // // for class 9

        // if(subject == "Chemistry" && student_class == 9){
        //     try {
        //         BufferedReader reader = new BufferedReader(new FileReader("Chemistry.txt"));
        //         String line;
        //         while ((line = reader.readLine()) != null) {
        //             jta.append(line + "\n");
        //         }
        //         reader.close();
        //     } catch (IOException e) {
        //         jta.append("Error reading file: " + e.getMessage());
        //     }
        // }

        // if(subject == "Physics" && student_class == 9){
        //     try {
        //         BufferedReader reader = new BufferedReader(new FileReader("Physics.txt"));
        //         String line;
        //         while ((line = reader.readLine()) != null) {
        //             jta.append(line + "\n");
        //         }
        //         reader.close();
        //     } catch (IOException e) {
        //         jta.append("Error reading file: " + e.getMessage());
        //     }
        // }

        // if(subject == "Biology" && student_class == 9){
        //     try {
        //         BufferedReader reader = new BufferedReader(new FileReader("Biology.txt"));
        //         String line;
        //         while ((line = reader.readLine()) != null) {
        //             jta.append(line + "\n");
        //         }
        //         reader.close();
        //     } catch (IOException e) {
        //         jta.append("Error reading file: " + e.getMessage());
        //     }
        // }

        // if(subject == "Math" && student_class == 9){
        //     try {
        //         BufferedReader reader = new BufferedReader(new FileReader("Math.txt"));
        //         String line;
        //         while ((line = reader.readLine()) != null) {
        //             jta.append(line + "\n");
        //         }
        //         reader.close();
        //     } catch (IOException e) {
        //         jta.append("Error reading file: " + e.getMessage());
        //     }
        // }

        // //for class 10

        // if(subject == "Chemistry" && student_class == 10){
        //     try {
        //         BufferedReader reader = new BufferedReader(new FileReader("Chemistry.txt"));
        //         String line;
        //         while ((line = reader.readLine()) != null) {
        //             jta.append(line + "\n");
        //         }
        //         reader.close();
        //     } catch (IOException e) {
        //         jta.append("Error reading file: " + e.getMessage());
        //     }
        // }

        // if(subject == "Physics" && student_class == 10){
        //     try {
        //         BufferedReader reader = new BufferedReader(new FileReader("Physics.txt"));
        //         String line;
        //         while ((line = reader.readLine()) != null) {
        //             jta.append(line + "\n");
        //         }
        //         reader.close();
        //     } catch (IOException e) {
        //         jta.append("Error reading file: " + e.getMessage());
        //     }
        // }

        // if(subject == "Biology" && student_class == 10){
        //     try {
        //         BufferedReader reader = new BufferedReader(new FileReader("Biology.txt"));
        //         String line;
        //         while ((line = reader.readLine()) != null) {
        //             jta.append(line + "\n");
        //         }
        //         reader.close();
        //     } catch (IOException e) {
        //         jta.append("Error reading file: " + e.getMessage());
        //     }
        // }

        // if(subject == "Math" && student_class == 10){
        //     try {
        //         BufferedReader reader = new BufferedReader(new FileReader("Math.txt"));
        //         String line;
        //         while ((line = reader.readLine()) != null) {
        //             jta.append(line + "\n");
        //         }
        //         reader.close();
        //     } catch (IOException e) {
        //         jta.append("Error reading file: " + e.getMessage());
        //     }
        // }

        // // for class 11

        // if(subject == "Chemistry" && student_class == 11){
        //     try {
        //         BufferedReader reader = new BufferedReader(new FileReader("Chemistry.txt"));
        //         String line;
        //         while ((line = reader.readLine()) != null) {
        //             jta.append(line + "\n");
        //         }
        //         reader.close();
        //     } catch (IOException e) {
        //         jta.append("Error reading file: " + e.getMessage());
        //     }
        // }

        // if(subject == "Physics" && student_class == 11){
        //     try {
        //         BufferedReader reader = new BufferedReader(new FileReader("Physics.txt"));
        //         String line;
        //         while ((line = reader.readLine()) != null) {
        //             jta.append(line + "\n");
        //         }
        //         reader.close();
        //     } catch (IOException e) {
        //         jta.append("Error reading file: " + e.getMessage());
        //     }
        // }

        // if(subject == "Biology" && student_class == 11){
        //     try {
        //         BufferedReader reader = new BufferedReader(new FileReader("Biology.txt"));
        //         String line;
        //         while ((line = reader.readLine()) != null) {
        //             jta.append(line + "\n");
        //         }
        //         reader.close();
        //     } catch (IOException e) {
        //         jta.append("Error reading file: " + e.getMessage());
        //     }
        // }

        // if(subject == "Math" && student_class == 11){
        //     try {
        //         BufferedReader reader = new BufferedReader(new FileReader("Math.txt"));
        //         String line;
        //         while ((line = reader.readLine()) != null) {
        //             jta.append(line + "\n");
        //         }
        //         reader.close();
        //     } catch (IOException e) {
        //         jta.append("Error reading file: " + e.getMessage());
        //     }
        // }
        
        // //for class 12

        // if(subject == "Chemistry" && student_class == 12){
        //     try {
        //         BufferedReader reader = new BufferedReader(new FileReader("Chemistry.txt"));
        //         String line;
        //         while ((line = reader.readLine()) != null) {
        //             jta.append(line + "\n");
        //         }
        //         reader.close();
        //     } catch (IOException e) {
        //         jta.append("Error reading file: " + e.getMessage());
        //     }
        // }

        // if(subject == "Physics" && student_class == 12){
        //     try {
        //         BufferedReader reader = new BufferedReader(new FileReader("Physics.txt"));
        //         String line;
        //         while ((line = reader.readLine()) != null) {
        //             jta.append(line + "\n");
        //         }
        //         reader.close();
        //     } catch (IOException e) {
        //         jta.append("Error reading file: " + e.getMessage());
        //     }
        // }

        // if(subject == "Biology" && student_class == 12){
        //     try {
        //         BufferedReader reader = new BufferedReader(new FileReader("Biology.txt"));
        //         String line;
        //         while ((line = reader.readLine()) != null) {
        //             jta.append(line + "\n");
        //         }
        //         reader.close();
        //     } catch (IOException e) {
        //         jta.append("Error reading file: " + e.getMessage());
        //     }
        // }

        // if(subject == "Math" && student_class == 12){
        //     try {
        //         BufferedReader reader = new BufferedReader(new FileReader("Math.txt"));
        //         String line;
        //         while ((line = reader.readLine()) != null) {
        //             jta.append(line + "\n");
        //         }
        //         reader.close();
        //     } catch (IOException e) {
        //         jta.append("Error reading file: " + e.getMessage());
        //     }
        // }

        
        
        JScrollPane sp = new JScrollPane(jta, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
        sp.setBounds(50, 120, 810, 450); 

        final JButton exb = new JButton("Try Yourself");
        exb.setBounds(450, 592, 130, 40);
        exb.setFont(new Font("Ariel", Font.BOLD, 12));
        exb.setForeground(Color.WHITE);
        exb.setBackground(Color.BLACK);
        exb.setFocusable(false);

        final JButton ppb = new JButton("Prev. Page");
        ppb.setBounds(300, 592, 130, 40);
        ppb.setFont(new Font("Ariel", Font.BOLD, 12));
        ppb.setForeground(Color.WHITE);
        ppb.setBackground(Color.BLACK);
        ppb.setFocusable(false);
        
        ActionListener actionListener5 = e5 ->{
            if(e5.getSource() == exb){
                frm5.dispose();
                new ExamPage(name, student_class, subject);
            }

            if(e5.getSource() == ppb){
                frm5.dispose();
                new Subject_page(name, student_class);
            }
        };

        exb.addActionListener(actionListener5);
        ppb.addActionListener(actionListener5);


        frm5.add(lb3);
        frm5.add(lb4);
        frm5.add(ul3);
        frm5.add(sp); 
        frm5.add(exb);
        frm5.add(ppb);
        frm5.setVisible(true);
    }
    
    // public static void main(String[] args) {
    //     new ContentDisplayPage("junaed",9, "Chemistry");
    // }

}
