package enshu4.jyanken.t1405076;



import java.util.Random;

public class CPU extends Player {
/**コンストラクタ
 * @param name ユーザー名
 */
	Random rand = new Random();
	public CPU(String name){
		super(name);
	}
	/**手を選ぶ*/
	public void chooseHand(){
		System.out.println(this.getName()+"が手を決めています。");
		hand = rand.nextInt(3);
	}
}
