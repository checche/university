package enshu4.cardgame.t1405076.card;

public class Main {

	public static void main(String[] args) {
		CardDeck cd = new CardDeck();
		cd.createFullDeck();
		System.out.println("ジョーカーも追加します。");
		Card jk = new Card(-1,0);
		cd.addCard(jk);
		cd.shuffle();
		cd.showAllCards();
		System.out.println("\n上から何枚か取ります。");
		cd.getCard().show();
		cd.getCard().show();
		cd.getCard().show();
		cd.getCard().show();
		System.out.println("現在のデッキ枚数は"+cd.size()+"枚です。");
		System.out.print("上から3番目のカードは");cd.seeCardAt(3).show();
		cd.showAllCards();
	}

}
