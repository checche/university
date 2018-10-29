package enshu4.jyanken.t1405076;

/**
 * Playerのサブクラスである。
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class User extends Player {

	/**コンストラクタ
	 * @param name ユーザー名
	 */
	public User(String name){
		super(name);
	}
	/**手を選ぶ*/
	public void chooseHand(){
		while(true){
		System.out.print(this.getName()+"さんの手を入力してください[0:グー　1:チョキ　2:パー]：");
		BufferedReader br =
				new BufferedReader(new InputStreamReader(System.in));
		String str;
		try {
			str = br.readLine();
			if(Integer.parseInt(str)<0 || Integer.parseInt(str)>2)System.out.println("不適切");
			else{hand = Integer.parseInt(str); break;}
		} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}
		}
	}
}
