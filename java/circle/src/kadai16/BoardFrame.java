package kadai16;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.Point;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import javax.swing.JLabel;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JToggleButton;
import javax.swing.JToolBar;
import javax.swing.JTextPane;

public class BoardFrame extends JFrame {

    private JPanel contentPane;
    public Board board;
    public BoardViewer viewer;
    private JTextField textField;
    /**
     * Launch the application.
     */
    public static void main(String[] args) {
        Board board = new Board();
        board.addTestCircles();
        display(board, "BoardFrame#main()");
    }

    public static void display(final Board board, final String title) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    final BoardFrame frame = new BoardFrame();
                    frame.setBoard(board);
                    frame.setTitle(title);
                    frame.setVisible(true);
                    frame.repaint();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }

    /**
     * Create the frame.
     */
    public BoardFrame() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(100, 100, 482, 396);
        contentPane = new JPanel();

     
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        setContentPane(contentPane);
        viewer = new BoardViewer();
        viewer.setBounds(6, 6, 468, 277);
        viewer.addMouseListener(new MouseAdapter() {
        	@Override
        	public void mouseClicked(MouseEvent e) {
        		int btn = e.getButton();
        		if(btn == MouseEvent.BUTTON1){
        			Point p = new Point();
        			p = e.getPoint();
        			processClick(p);
        		}
        		else if(btn ==MouseEvent.BUTTON3){
        			undo();
        		}
        	}
        });
        contentPane.setLayout(null);
        contentPane.add(viewer);
        
        JButton btnNewButton = new JButton("Save");
        btnNewButton.addMouseListener(new MouseAdapter() {
        	@Override
        	public void mouseClicked(MouseEvent e) {
        		saveBoard(textField.getText());
        	}
        });
        
        textField = new JTextField();
        textField.setBounds(6, 321, 468, 26);
        contentPane.add(textField);
        textField.setColumns(10);
        btnNewButton.setBounds(6, 290, 117, 29);
        contentPane.add(btnNewButton);
        
        JButton btnNewButton_1 = new JButton("Load");
        btnNewButton_1.addMouseListener(new MouseAdapter() {
        	@Override
        	public void mouseClicked(MouseEvent e) {
        		loadBoard(textField.getText());
        	}
        });
        btnNewButton_1.setBounds(119, 290, 117, 29);
        contentPane.add(btnNewButton_1);
    }    
    
    public void saveBoard(String name){
    	try {
    		String filename = (name.length()<1)?"noname" : name;
			ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(filename+".ser"));
			out.writeObject(board);
			out.close();
    	} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}		
    }
	
    public void loadBoard(String name){
    	try {	
    		String filename = (name.length()<1)?"noname" : name;
    		ObjectInputStream in = new ObjectInputStream(new FileInputStream(filename+".ser"));
    		try {
				Object obj = in.readObject();
				board = (Board) obj;
				display(board, "BoardFrame#main()(Loaded)");
				in.close();
			} catch (ClassNotFoundException e) {
				// TODO 自動生成された catch ブロック
				e.printStackTrace();
			}
    	} catch (FileNotFoundException e) {
    		// TODO 自動生成された catch ブロック
    		System.out.println("File not found!");
    		//e.printStackTrace();
    	} catch (IOException e) {
    		// TODO 自動生成された catch ブロック
    		e.printStackTrace();
    	}	
    }
    
    public void setBoard(Board board) {
        this.board = board;
        viewer.setBoard(board);
    }
    
    public void processClick(Point p){
    	Circle c = board.getCircle(p);
    	Circle a = board.getCircleFromAdd(p);
    	if(c != null) board.addPath(c);
    	else if(c == null && a == null)board.executePath();
    	repaint();
    		
    }
    public void undo(){
		board.undoPath();
		repaint();
    }
}
