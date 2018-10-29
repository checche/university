package enshu4.cardgame.t1405076.game;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class User extends Player{

	/**名前を決めるコンストラクタ*/
	public User(String name) {
		super(name);
		// TODO 自動生成されたコンストラクター・スタブ
	}
/**引く札を決める*/
	public int chooseCard(int d){
		System.out.println("1~"+d+"番目のうちどのカードを引きますか?");
		BufferedReader br =
				new BufferedReader(new InputStreamReader(System.in));
		
		int k=0;
		try {
			k = Integer.parseInt(br.readLine());
		} catch (NumberFormatException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}
		
		return k;
	}
	
}
