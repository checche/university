package enshu4.cardgame.t1405076.game;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class MainBaba {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		System.out.print("あなたの名前を入力してください。");
		BufferedReader br =
				new BufferedReader(new InputStreamReader(System.in));
		String str = null;
		try {
			str = br.readLine();
		} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}
		
		User u = new User(str);
		CPU c1 = new CPU("CPU1");
		CPU c2 = new CPU("CPU2");
		
		Babanuki bn = Babanuki.getInstance();
		
		bn.addPlayer(u);
		bn.addPlayer(c1);
		bn.addPlayer(c2);
		
		bn.makeDeck();
		
		bn.distribute();
		
		bn.showHand();
		
		bn.game();
	}

}
