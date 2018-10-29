package kadai16;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Point;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Stack;

public class Board implements Serializable{

    static boolean debugWithDisplay = true;

    Collection<Circle> circles = new ArrayList<Circle>();
    Stack<Circle> path = new Stack<Circle>();
    Collection<Circle> reachables = new ArrayList<Circle>();
    Stack<Circle> frontier = new Stack<Circle>();

    
  
    public boolean addCircle(Circle next) {
        circles.add(next);
        return true;
    }

    /**
     * 現状の到達可能範囲を返すメソッド。
     * 空の場合は、null ではなく空のCollectionを返しましょう
     * 計算の実体は、calcReachables(Circle)で実現してください。
     * @return
     */
    public Collection<Circle> getReachables() {
        return calcReachables(getCurrent());
    }

    /**
     * 到達可能範囲を計算するメソッド。
     * 頑張って実装してください。
     * @param target 起点となる Circle
     * @return 到達可能な Circle から構成される Collection
     */
    private Collection<Circle> calcReachables(Circle target) {
        if(path.size() == 0 || target == null){
        	reachables.clear();
        	return reachables;
        }
        // TODO 実装しましょう
        reachables.clear();
        frontier.clear();
        
        reachables.add(target);
        
        for(Circle c : circles)
        	if(target.connected(c, this)){
        		reachables.add(c);
        		frontier.push(c);
        	}
			        
        while(frontier.size() != 0){
        	Circle fr =frontier.pop();
        	for(Circle c : circles){
        		if(fr.connected(c, this)){
        			if(reachables.contains(c))
        				;
        			else {
        				reachables.add(c);
        				frontier.push(c);
        			}
        		}				
        	}	
        }
        return reachables;	
    }


    /**
     * 座標をあらわす Point p を含む円を探して、結果を返す。
     * @param p 対象座標
     * @return 結果。ない場合は null を返す
     */
    public Circle getCircle(Point p) {
        //TODO 実装しましょう
    	for(Circle c: circles){
    		if(c.center.distance(p) <= c.radius)
    			return c;
    	}
        return null;
    }
    /**
     * 座標を表すpを含む一筆書き中の円を探して結果を返す。
     * @param p 対象座標
     * @return 結果。無い場合はnull
     */
    public Circle getCircleFromAdd(Point p){
    	for(Circle c: path){
    		if(c.center.distance(p) <= c.radius)
    			return c;
    	}
    	return null;
    }
    
    /**
     * 対象の円 c が一筆書きによって現在選択中の円(Current)か、すでに一筆書きで消しつつある円(OnPath?)か、
     * あるいは現在選択選択されていない円(Reachable)か、それ以外の円(Others)かを判定する。
     * @param c
     * @return
     */
    public Circle.State getCircleState(Circle c) {
    	//TODO 実装しましょう
    	if(c == getCurrent()) return Circle.State.Current;
    	else if(path.contains(c)) return Circle.State.OnPath;
    	else if(reachables.contains(c)) return Circle.State.Reachable;
    	else return Circle.State.Others;
    }


    /**
     * Circle c を path に加える。getCurrent()の値も c に変わり、calc() も行う必要あり。
     * @param next
     */
    public void addPath(Circle next) {
    	//TODO 実装しましょう
    	if(path.size() == 0){
    		path.push(next);
    		circles.remove(next);
    		reachables = getReachables();
    	}
    	else
    		if(getCurrent().connected(next, this)){
    			path.push(next);
    			circles.remove(next);
        		reachables = getReachables();
    		}
    }

    /**
     * 現在選択中の円を返す。一筆書き中でない場合は、null を返す。
     * @return
     */
    public Circle getCurrent() {
        //TODO 実装しましょう
    	if(path.size() == 0) return null;
    	else return path.lastElement();
    }


    /**
     * 一筆書きを完了し、パス上の円を盤面から削除する。
     */
    public void executePath() {
        //TODO 未実装
    	path.clear();
    	reachables = getReachables();
    }

    public void undoPath(){
    	if(path.size() >= 1){
    		Circle c = path.lastElement();
    		circles.add(c);
    		path.remove(c);
    		reachables = getReachables();
    	}
    			
    }

    
    /* (非 Javadoc)
     * @see java.lang.Object#toString()
     *
     * 盤面情報(path, circles)がわかるように再定義してください。
     */
    public String toString() {
        // TODO ダミー実装
        return "Board[path: "+this.path.toString()+", rest:"+this.circles.toString()+"]";
    }

    /**
     * テスト用初期盤面に利用されるCircle群
     */
    public static Circle[] testCircles = new Circle[] {
        new Circle(new Point(39, 29), 8.2, Color.BLUE),
        new Circle(new Point(16, 28), 11.7, Color.RED),
        new Circle(new Point(20, 58), 13.0, Color.ORANGE),
        new Circle(new Point(34, 108), 18.8, Color.BLACK),
        new Circle(new Point(13, 87), 8.2, Color.BLUE),
        new Circle(new Point(62, 72), 23.0, Color.BLACK),
        new Circle(new Point(83, 31), 19.3, Color.ORANGE),
        new Circle(new Point(178, 58), 48.5, Color.RED),
        new Circle(new Point(108, 82), 18.4, Color.BLUE),
        new Circle(new Point(73, 136), 26.0, Color.ORANGE),
        new Circle(new Point(132, 127), 24.5, Color.ORANGE),
        new Circle(new Point(12, 146), 9.0, Color.RED),
        new Circle(new Point(39, 158), 9.4, Color.BLUE),
        new Circle(new Point(17, 182), 15.3, Color.ORANGE),
        new Circle(new Point(17, 215), 11.4, Color.RED),
        new Circle(new Point(40, 229), 12.0, Color.RED),
        new Circle(new Point(55, 198), 18.3, Color.ORANGE),
        new Circle(new Point(123, 185), 30.0, Color.BLUE),
        new Circle(new Point(284, 219), 24.1, Color.BLUE),
        new Circle(new Point(155, 230), 16.1, Color.ORANGE),
        new Circle(new Point(213, 191), 48.1, Color.RED),
        new Circle(new Point(172, 139), 13.4, Color.ORANGE),
        new Circle(new Point(300, 136), 40.0, Color.BLUE),
        new Circle(new Point(271, 52), 37.9, Color.ORANGE),
        new Circle(new Point(361, 44), 39.5, Color.BLACK),
        new Circle(new Point(386, 131), 33.8, Color.ORANGE),
        new Circle(new Point(359, 203), 38.5, Color.RED),
    };

    /**
     * テストデータを追加するメソッド
     */
    public void addTestCircles() {
        for(Circle c: testCircles) addCircle(c);
    }
    /**
     * テスト用メソッド
     */

    public void execTest() {
        addTestCircles();

        System.out.println("Init Board: " + this);
        displayRepaint();   // GUI 表示用メソッド。中身はみなくてもOK

        System.out.println("Test: getCircle");
        System.out.println("getCircle(new Point(70, 130)):" + getCircle(new Point(70,130)));
        System.out.println("getCirlce(new Point(91, 136)):" + getCircle(new Point(91,136)));
        System.out.println("getCirlce(new Point(300, 136)):" + getCircle(new Point(300,136)));

        System.out.println("Test: Circle#connected()");
        Circle c0 = testCircles[9];
        Circle c1 = testCircles[10];
        Circle c2 = testCircles[25];
        Circle c3 = testCircles[16];
        Circle c4 = testCircles[17];
        System.out.println("c0: " + c0);
        System.out.println("c1: " + c1);
        System.out.println("c0.connected(c1, ...) = "+ c0.connected(c1, this));
        System.out.println("c2: " + c2);
        System.out.println("c1.connected(c2, ...) = "+ c1.connected(c2, this));
        System.out.println("c3: " + c3);
        System.out.println("c1.connected(c3, ...) = "+ c1.connected(c3, this));
        System.out.println("c4: " + c4);
        System.out.println("c3.connected(c4, ...) = "+ c3.connected(c4, this));


        System.out.println("Click c0");
        addPath(c0);
        System.out.println("Step1: " + this);
        displayRepaint();  // GUI 表示用メソッド。中身はみなくてもOK

        System.out.println("Click c1");
        addPath(c1);
        System.out.println("Step2: " + this);
        displayRepaint(); // GUI 表示用メソッド。中身はみなくてもOK

        System.out.println("Click c2");
        addPath(c2);
        System.out.println("Step2: " + this);
        displayRepaint(); // GUI 表示用メソッド。中身はみなくてもOK


        System.out.println("Click c3");
        addPath(c3);
        System.out.println("Step3: " + this);
        displayRepaint(); // GUI 表示用メソッド。中身はみなくてもOK

        System.out.println("Click c4");
        addPath(c4);
        System.out.println("Step4: " + this);
        displayRepaint(); // GUI 表示用メソッド。中身はみなくてもOK

        executePath();
        System.out.println("Remove the path:" + this);
        displayRepaint(); // GUI 表示用メソッド。中身はみなくてもOK

    }
    /**
     * main メソッド。
     * @param args
     */
    public static void main(String[] args) {
        // test routines for main
        Board board = new Board();
        if(debugWithDisplay) {//GUI 表示
            board.execTestWithDisplay(); // 内部で execTest()が実行される
        } else {
            board.execTest();
        }
    }

    /*
     * 以下、描画用ルーチン（中身はわからなくてもOK）
     */
    BoardFrame frame = null; // should be accessed only by GUI thread.
    int waitSec = 3;

    public void displayRepaint() {
        if(debugWithDisplay) {
            EventQueue.invokeLater(new Runnable() {
                @Override
                public void run() {
                    if(frame!=null) frame.repaint();
                }
            });
            try {
                Thread.sleep(waitSec * 1000);
            } catch (InterruptedException e) {
                // do nothing
            }
        }
    }
    public void execTestWithDisplay() {
        final Board board = this;
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    BoardFrame frame = new BoardFrame();
                    board.frame = frame;
                    frame.setBoard(board);
                    frame.setTitle("execTestWithDisplay");
                    frame.setVisible(true);
                    new Thread(new Runnable() {
                        @Override
                        public void run() {
                            execTest();
                        }
                    }).start();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }
}
