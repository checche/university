package kadai16;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;
import java.awt.geom.Line2D.Double;

public class Circle extends Ellipse2D.Double {

    /**
     * 円の選択状態を表すための enum.
     *
     */
    public enum State { OnPath, Current, Reachable, Others };

    /**
     * 円の色
     */
    public Color color;
    /**
     * 円の半径
     */
    public double radius;
    /**
     * 円の中心
     */
    public Point center;


    /**
     * コンストラクタ。
     * 中心 center, 半径 radius, 色 color な Circle を作成
     * @param center
     * @param radius
     * @param color
     */
    public Circle(Point center, double radius, Color color) {
        super(center.x-radius, center.y-radius, radius*2, radius*2);
        this.center = center;
        this.color = color;
        this.radius = radius;
    }

    /**
     * this と c が接続可能かどうか判定。盤面情報は board から取得可能。
     * @param c
     * @param board
     * @return
     */
    public boolean connected(Circle c, Board board) {
        // TODO 他円の中心と直線の距離、同じ色かどうか
    	if(this.color == c.color){
    		for(Circle c1: board.circles){
    			if(c == c1 || this == c1)
    				;
    			else{
    				Line2D.Double d = new Line2D.Double(this.center, c.center);
    				double dis = d.ptSegDist(c1.center);
    				if(dis > c1.radius)
    					;
    				else return false;
    			}
    		}
    		return true;
    	}
    	else return false;
    }
    
    		
    		
    /**
     * 以下描画用補助メソッド
     */
    private void fill(Graphics g, double r0, Color color) {
        int r = (int)r0;
        g.setColor(color);
        g.fillOval(center.x-r, center.y-r, r*2, r*2);
    }
    private void draw(Graphics g, double r0, Color color) {
        int r = (int)r0;
        g.setColor(color);
        g.drawOval(center.x-r, center.y-r, r*2, r*2);
    }

    /**
     * 描画用メソッド。Circle の選択状態に応じて、表示を変える。
     * @param g 描画対象 Graphics(実体はGraphics2Dと思ってもらってOK)
     * @param s 円の選択状態
     */
    public void paint(Graphics g, State s) {
        switch(s) {
        case OnPath:
            draw(g, radius, this.color);
            break;
        case Current:
            fill(g, radius, this.color);
            fill(g, radius*2/3, Color.WHITE);
            break;
        case Reachable:
            fill(g, radius, this.color);
            fill(g, radius*1/3, Color.WHITE);
            break;
        case Others:
            fill(g, radius, this.color);
            break;
        }
    }
    /**
     * Circle の情報(中心、半径、色）などを表示してください。
     **/
    public String toString() {
        // TODO ダミー実装
        return "Circle("+"c:"+this.center.x+","+this.center.y+", "+"r:"+this.radius+", "+this.color.toString()+")";
    }
  
}
