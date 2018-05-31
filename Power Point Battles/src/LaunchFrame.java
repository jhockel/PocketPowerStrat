import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

public class LaunchFrame extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = -1214924041690131553L;
	private JPanel contentPane;
	private static BufferedImage board_4;
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					LaunchFrame frame = new LaunchFrame();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public LaunchFrame() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 850, 620);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		
		try {
			board_4 = ImageIO.read(new File("src/Board_4.jpg"));
			System.out.println("resources loaded");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			System.out.println("resources failed to load");
			e.printStackTrace();
		}
		JLabel picLabel = new JLabel(new ImageIcon(board_4));
		picLabel.setSize(813, 560);
		picLabel.setLocation(10, 10);
		add(picLabel);
		
		JLabel hp = new JLabel();
		hp.setText("HP: 5000");
		hp.setSize(90, 15);
		hp.setLocation(15, 295);
		picLabel.add(hp);
		
	}
	
	public void drawCluster(int x, int y) {
		
		
		
	}

}