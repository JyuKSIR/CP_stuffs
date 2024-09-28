package Education_system;

import java.awt.Color;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import javax.swing.Timer;

import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JRadioButton;

public class ExamPage {
    
    private int currentQuestionIndex = 0;
    private int score = 0;
    private List<Question> questions = new ArrayList<>();
    private JRadioButton[] options;
    private ButtonGroup group;
    private JLabel qlb6, tl;
    private JFrame frm6;
    private Timer timer;
    private int timeRemaining = 15;
    
    public ExamPage(String name, int student_class, String subject){

        JFrame frm6 = new JFrame("Subject Page");
        frm6.setSize(900, 700);
        frm6.getContentPane().setBackground(Color.decode("#5b9bd5"));
        frm6.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frm6.setLocationRelativeTo(null);
        frm6.setResizable(false);
        frm6.setLayout(null);

        JLabel lb4 = new JLabel("Education System");
        lb4.setBounds(320,20, 270, 50);
        lb4.setFont(new Font("Times New Roman", Font.BOLD, 25));
        lb4.setForeground(Color.white);

        JLabel lb5 = new JLabel("<html>Hello there! <u>" + name + "</u></html>");
        lb5.setBounds(690, 50, 250, 50);
        lb5.setFont(new Font("Times New Roman", Font.BOLD, 12));
        lb5.setForeground(Color.white);

        JLabel ul2 = new JLabel(subject + " Exam");
        ul2.setBounds(350, 90, 250, 19);
        ul2.setFont(new Font("Times New Roman", Font.BOLD, 17));
        ul2.setForeground(Color.WHITE);

        JPanel qp = new JPanel(new GridLayout(5, 1));
        qp.setBounds(100, 150, 700, 250);
        qp.setBackground(Color.decode("#5b9bd5"));

        qlb6 = new JLabel();
        qlb6.setFont(new Font("Times New Roman", Font.PLAIN, 16));
        qp.add(qlb6);
        
        options = new JRadioButton[4];
        group = new ButtonGroup();
        
        for (int i = 0; i < options.length; i++) {
            options[i] = new JRadioButton();
            options[i].setBackground(Color.decode("#5b9bd5"));
            options[i].setForeground(Color.black);
            group.add(options[i]);
            qp.add(options[i]);
        }
         
        tl = new JLabel("Time remaining: 15 seconds");
        tl.setBounds(290, 420, 300, 30);
        tl.setFont(new Font("Times New Roman", Font.BOLD, 18));
        tl.setBackground(Color.white);

        JButton sb = new JButton("Submit");
        sb.setBounds(350, 480, 150, 40);
        sb.setFont(new Font("Ariel", Font.BOLD, 12));
        sb.setForeground(Color.WHITE);
        sb.setBackground(Color.BLACK);
        sb.setFocusable(false);
        
        ActionListener actionListener6 = e6 -> {
            if(e6.getSource() == sb){
                timer.stop();
                checkAnswer();

                if (currentQuestionIndex < questions.size() - 1) {
                    currentQuestionIndex++;
                    displayQuestion(currentQuestionIndex);
                } else {
                    writeScoreToFile(name, student_class, subject, score);
                    JOptionPane.showMessageDialog(frm6, "Test complete!");
                    frm6.dispose();
                    new ScoreBoardPage(name, student_class, score);
                }
            }
        };
        sb.addActionListener(actionListener6);
        
        ShowQuestionsFromFile("MCQ.txt");

        if (!questions.isEmpty()) {
            displayQuestion(currentQuestionIndex);
        }
       
        frm6.add(lb4);
        frm6.add(lb5);
        frm6.add(ul2);
        frm6.add(qp);
        frm6.add(tl);
        frm6.add(sb);
        frm6.setVisible(true);
    }


    private void ShowQuestionsFromFile(String filename) {
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                if (line.isEmpty()) continue;
                String question = line;
                String[] options = new String[4];
                for (int i = 0; i < 4; i++) {
                    options[i] = br.readLine().substring(3);
                }
                String answer = br.readLine().split(": ")[1];
                br.readLine();
                questions.add(new Question(question, options, answer));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    private void displayQuestion(int index) {
        Question q = questions.get(index);
        qlb6.setText(q.question);
        qlb6.setFont(new Font("Times New Roman", Font.BOLD, 14));
        qlb6.setForeground(Color.BLACK);
        for (int i = 0; i < options.length; i++) {
            options[i].setText(q.options[i]);
            group.clearSelection();
        }

        timeRemaining = 15;
        tl.setText("Time remaining: " + timeRemaining + " seconds");

        if (timer != null) {
            timer.stop();
        }
        timer = new Timer(1000, new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                timeRemaining--;
                tl.setText("Time remaining: " + timeRemaining + " seconds");
                tl.setForeground(Color.white);
                if (timeRemaining <= 0) {
                    timer.stop();
                    checkAnswer();
                    if (currentQuestionIndex < questions.size() - 1) {
                        currentQuestionIndex++;
                        displayQuestion(currentQuestionIndex);
                    } else {
                        JOptionPane.showMessageDialog(frm6, "Test complete! Your score: " + score);
                    }
                }
            }
        });
        timer.start();
    }

    private void checkAnswer() {
        Question q = questions.get(currentQuestionIndex); 
        for (int i = 0; i < options.length; i++) {
            if (options[i].isSelected()) {
                if (options[i].getText().equals(q.correctAnswer)) {
                    score++;
                }
                break; 
            }
        }
    }

    private void writeScoreToFile(String name, int studentClass, String subject, int score) {
        List<String> lines = new ArrayList<>();
        boolean updated = false;
        
        try (BufferedReader reader = new BufferedReader(new FileReader("scores.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                if (line.contains(name) && line.contains(String.valueOf(studentClass)) && line.contains(subject)) {
                    line = name + "\t" + studentClass + "\t" + subject + "\t" + score;
                    updated = true;
                }
                lines.add(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    
        if (!updated) {
            lines.add(name + "\t" + studentClass + "\t" + subject + "\t" + score);
        }
    
        try (FileWriter writer = new FileWriter("scores.txt")) {
            for (String line : lines) {
                writer.write(line + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // public static void main(String[] args) {
    //     new ExamPage("Junaed", 10, "Chemistry");
    // }

}
