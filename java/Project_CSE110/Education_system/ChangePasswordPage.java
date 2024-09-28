package Education_system;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class ChangePasswordPage extends ChangePassword {

    private JFrame frm11;
    private JTextField cutf;
    private JPasswordField cpf,cpf2;

    public ChangePasswordPage(String filename){

        super(filename);

        frm11 = new JFrame("Change Password");
        frm11.setSize(800, 600);
        frm11.getContentPane().setBackground(Color.decode("#5b9bd5"));
        frm11.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frm11.setLocationRelativeTo(null);
        frm11.setResizable(false);
        frm11.setLayout(null);
        
        JLabel clb = new JLabel("Education System");
        clb.setBounds(280, 40, 270, 50);
        clb.setFont(new Font("Times New Roman", Font.BOLD, 25));
        clb.setForeground(Color.white);
        
        JLabel cul = new JLabel("Username");
        cul.setBounds(270, 130, 100, 9);
        cul.setFont(new Font("Times New Roman", Font.BOLD, 12));
        cul.setForeground(Color.white);

        cutf = new JTextField();
        cutf.setBounds(270, 155, 270, 35);
        cutf.setFont(new Font("Times New Roman", Font.BOLD, 15));

        JLabel cpl = new JLabel("Old Password");
        cpl.setBounds(270, 210, 100, 9);
        cpl.setFont(new Font("Times New Roman", Font.BOLD, 12));
        cpl.setForeground(Color.white);

        cpf = new JPasswordField();
        cpf.setBounds(270, 235, 270, 35);
        cpf.setFont(new Font("Times New Roman", Font.BOLD, 15));
        cpf.setEchoChar('*');

        JLabel cpl2 = new JLabel("New Password");
        cpl2.setBounds(270, 290, 120, 9);
        cpl2.setFont(new Font("Times New Roman", Font.BOLD, 12));
        cpl2.setForeground(Color.white);

        cpf2 = new JPasswordField();
        cpf2.setBounds(270, 315, 270, 35);
        cpf2.setFont(new Font("Times New Roman", Font.BOLD, 15));
        cpf2.setEchoChar('*');

        JButton sjb3 = new JButton("Change Password");
        sjb3.setBounds(315, 390, 170, 40);
        sjb3.setFont(new Font("Ariel", Font.BOLD, 12));
        sjb3.setForeground(Color.WHITE);
        sjb3.setBackground(Color.BLACK);
        sjb3.setFocusable(false);

        ActionListener actionListener11 = e11 -> {
            if (e11.getSource() == sjb3) {
                changePassword("Username&Password.txt");
            }
        };
        sjb3.addActionListener(actionListener11);

        JLabel cem = new JLabel("Go back to ");
        cem.setBounds(340, 460, 200, 15);
        cem.setFont(new Font("Ariel", Font.BOLD, 12));
        cem.setForeground(Color.white);

        JLabel cem2 = new JLabel("<html><u>Log In</u></html>");
        cem2.setBounds(420, 460, 200, 15);
        cem2.setFont(new Font("Ariel", Font.BOLD, 14));
        cem2.setForeground(new Color(204, 0, 0));

        cem2.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                frm11.dispose();
                new system_loginpage();
            }
        });

        frm11.add(clb);
        frm11.add(cul);
        frm11.add(cutf);
        frm11.add(cpl);
        frm11.add(cpf);
        frm11.add(cpl2);
        frm11.add(cpf2);
        frm11.add(sjb3);
        frm11.add(cem);
        frm11.add(cem2);
        frm11.setVisible(true);

        
    }

    @Override
    public void changePassword(String file) {
    String username = cutf.getText();
    String oldPassword = new String(cpf.getPassword()); 
    String newPassword = new String(cpf2.getPassword());

    List<String> lines = new ArrayList<>();
    boolean userFound = false;

    try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
        String line;
        while ((line = reader.readLine()) != null) {
            String[] parts = line.split("\t");
            if (parts[0].equals(username) && parts[1].equals(oldPassword)) {
                userFound = true;
                lines.add(username + "\t" + newPassword);
            } else {
                lines.add(line);
            }
        }
    } catch (IOException e) {
        JOptionPane.showMessageDialog(frm11, "Error reading the file: " + e.getMessage());
        return;
    }

    if (userFound) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(file))) {
            for (String updatedLine : lines) {
                writer.write(updatedLine);
                writer.newLine();
            }
            JOptionPane.showMessageDialog(frm11, "Password updated successfully for user '" + username + "'.");
            frm11.dispose();
            new system_loginpage();
        } catch (IOException e) {
            JOptionPane.showMessageDialog(frm11, "Error writing to the file: " + e.getMessage());
        }
    } else {
        JOptionPane.showMessageDialog(frm11, "Invalid username or password.","Changing Password Error", JOptionPane.ERROR_MESSAGE);
    }
}

    // public static void main(String[] args) {
    //     new ChangePasswordPage("Username&Password.txt");
    // }
}
