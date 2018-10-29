package kadai16;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JPanel;

public class BoardViewer extends JPanel {

    private Board board;

    /**
     * Create the panel.
     */
    public BoardViewer() {
    }
    
    void setBoard(Board board) {
        this.board = board;
    }
 
    public void paintComponent(Graphics g) {
        g.setColor(Color.WHITE);
        g.clearRect(0, 0, this.getWidth(), this.getHeight());
        if(board==null) return;
        for(Circle c: board.circles) {
            c.paint(g, board.getCircleState(c));
        }
        for(Circle c: board.path) {
            c.paint(g, board.getCircleState(c));
        }
    }



}
