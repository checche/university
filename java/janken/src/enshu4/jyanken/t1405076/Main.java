package enshu4.jyanken.t1405076;


public class Main {


	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		
		User person = new User("hirata");
		CPU com1 = new CPU("CP1");	
		CPU com2 = new CPU("CP2");	
		CPU com3 = new CPU("CP3");	
		JankenGame jg = new JankenGame();
		jg.addPlayer(person);
		jg.addPlayer(com1);
		jg.addPlayer(com2);
		jg.addPlayer(com3);
		Judge jud = new Judge();
		System.out.println("審判を作成しました");
		jg.setJudge(jud);
		System.out.println("審判を登録しました。");
		jg.setNumberOfGames(5);
		System.out.println("じゃんけん回数を"+jg.getNumberOfGames()+"回に設定しました。");
		
		jg.playJanken();

		




	}

}
