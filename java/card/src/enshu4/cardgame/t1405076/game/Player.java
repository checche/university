package enshu4.cardgame.t1405076.game;

import enshu4.cardgame.t1405076.card.CardDeck;

public abstract class Player {
/**名前*/
	private String name;
	/**手札*/
	private CardDeck hand = new CardDeck();
	/**勝ちかどうか*/
	private int win;
	
/**名前をつけるコンストラクタ*/
	public Player(String name){
		this.name=name;
		System.out.println(name+"がプレイヤーとして登録されました。");
	}
	
	/**名前を取得する*/
	public String getName() {
		return name;
	}

/**手札を取得する*/
	public CardDeck getHand() {
		return hand;
	}

/**引く札を選ぶ*/
	public abstract int chooseCard(int d);
/**winを取得する*/
	public int getWin() {
		return win;
	}
/**winの値を決める。0→負け。1→勝ち。*/
	public void setWin(int win) {
		this.win = win;
	}
	
	
}
