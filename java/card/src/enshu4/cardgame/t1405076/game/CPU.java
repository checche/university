package enshu4.cardgame.t1405076.game;
import java.util.Random;

public class CPU extends Player{

	/**名前を決めるコンストラクタ*/
	public CPU(String name) {
		super(name);
		// TODO 自動生成されたコンストラクター・スタブ
	}
/**引く札を決める*/
	public int chooseCard(int d){
		int k=0;
		Random rand = new Random();
		k = rand.nextInt(d)+1;
		return k;
	}
}
