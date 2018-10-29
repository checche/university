package enshu4.cardgame.t1405076.game;

import java.util.ArrayList;

import enshu4.cardgame.t1405076.card.Card;
import enshu4.cardgame.t1405076.card.CardDeck;

public class Babanuki {
	
	private static Babanuki instance = new Babanuki();
	
	/**はじめに配る山札のフィールド*/
	private CardDeck Deck = new CardDeck();
	/**プレイヤーのリスト*/
	ArrayList<Player> players = new ArrayList<Player>();
	
	private Babanuki(){
	}
	public static Babanuki getInstance() {
        return instance;
}
	
/**はじめに配る山札を作成する*/	
	public void makeDeck(){
		Deck.createFullDeck();
		Card jk = new Card(-1,0);
		Deck.addCard(jk);
		Deck.shuffle();
	}
	/**プレイヤーを追加する*/
	public void addPlayer(Player player){
		players.add(player);	
	}
	
	/**手にしたカードと同じ数字のカードが手札にあるか確認し、あればともに捨てる*/
	public void throwaway(Player p){
		for(int i=0; i<p.getHand().size()-1; i++){
		if(p.getHand().seeCardAt(p.getHand().size()).getNumber()==p.getHand().seeCardAt(i+1).getNumber()){
			p.getHand().getCardAt(i+1);
			p.getHand().getCardAt(p.getHand().size());
		}
		}
	}
	/**山札をプレイヤーに分配する*/
	public void distribute(){
		Card c = new Card(1,1);
		for(int j=0; j<17; j++){

				c = Deck.getCard();
				players.get(0).getHand().addCard(c);
				throwaway(players.get(0));
				c = Deck.getCard();
				players.get(1).getHand().addCard(c);
				throwaway(players.get(1));
				c = Deck.getCard();
				players.get(2).getHand().addCard(c);
				throwaway(players.get(2));
			}
		c = Deck.getCard();
		players.get(0).getHand().addCard(c);
		throwaway(players.get(0));
		c = Deck.getCard();
		players.get(1).getHand().addCard(c);
		throwaway(players.get(1));
		}
		
	
	/**手札の開示*/
	public void showHand(){
		System.out.print("taの");players.get(0).getHand().showAllCards();
		
	}
	
	/**ゲームを行う*/
	public void game(){
		players.get(0).setWin(0);
		players.get(1).setWin(0);
		players.get(2).setWin(0);
		while(true){
		players.get(0).getHand().addCard(players.get(1).getHand().getCardAt(players.get(0).chooseCard(players.get(1).getHand().size())));
		throwaway(players.get(0));
		if(players.get(0).getHand().size()==0||players.get(1).getHand().size()==0||players.get(2).getHand().size()==0)break;
		players.get(1).getHand().addCard(players.get(2).getHand().getCardAt(players.get(1).chooseCard(players.get(2).getHand().size())));
		throwaway(players.get(1));
		if(players.get(0).getHand().size()==0||players.get(1).getHand().size()==0||players.get(2).getHand().size()==0)break;
		players.get(2).getHand().addCard(players.get(0).getHand().getCardAt(players.get(2).chooseCard(players.get(0).getHand().size())));
		throwaway(players.get(2));
		if(players.get(0).getHand().size()==0||players.get(1).getHand().size()==0||players.get(2).getHand().size()==0)break;
		showHand();
		}
		
		if(players.get(0).getHand().size()==0&&players.get(1).getHand().size()!=0&&players.get(2).getHand().size()!=0){
			System.out.println("あなたはあがりました。");
			while(true){
				showHand();
				players.get(1).getHand().addCard(players.get(2).getHand().getCardAt(players.get(1).chooseCard(players.get(2).getHand().size())));
				throwaway(players.get(1));
				if(players.get(1).getHand().size()==0||players.get(2).getHand().size()==0)break;
				players.get(2).getHand().addCard(players.get(1).getHand().getCardAt(players.get(2).chooseCard(players.get(1).getHand().size())));
				throwaway(players.get(2));
				if(players.get(2).getHand().size()==0||players.get(1).getHand().size()==0)break;
				
			}}

		if(players.get(0).getHand().size()!=0&&players.get(1).getHand().size()==0&&players.get(2).getHand().size()!=0){
			System.out.println("CPU1が上がりました。");
			while(true){
				showHand();
				players.get(0).getHand().addCard(players.get(2).getHand().getCardAt(players.get(0).chooseCard(players.get(2).getHand().size())));
				throwaway(players.get(0));
				if(players.get(0).getHand().size()==0||players.get(2).getHand().size()==0)break;
				players.get(2).getHand().addCard(players.get(0).getHand().getCardAt(players.get(2).chooseCard(players.get(0).getHand().size())));
				throwaway(players.get(2));
				if(players.get(2).getHand().size()==0||players.get(0).getHand().size()==0)break;
				
			}}

		if(players.get(0).getHand().size()!=0&&players.get(1).getHand().size()!=0&&players.get(2).getHand().size()==0){
			System.out.println("CPU2があがりました。");
			while(true){
				showHand();
				players.get(0).getHand().addCard(players.get(1).getHand().getCardAt(players.get(0).chooseCard(players.get(1).getHand().size())));
				throwaway(players.get(0));
				if(players.get(0).getHand().size()==0||players.get(1).getHand().size()==0)break;
				players.get(1).getHand().addCard(players.get(0).getHand().getCardAt(players.get(1).chooseCard(players.get(0).getHand().size())));
				throwaway(players.get(1));
				if(players.get(1).getHand().size()==0||players.get(0).getHand().size()==0)break;
				
			}}
		
		System.out.println("Finish!!!");
		showHand();
		for(int i=0; i<3; i++){
			if(players.get(i).getHand().size()==0)players.get(i).setWin(1);
		}
		for(int i=0; i<3; i++){
		if(players.get(i).getWin()==1)System.out.println(players.get(i).getName()+" win!");
		
		}

		for(int i=0; i<3; i++){
		if(players.get(i).getWin()==0)System.out.println(players.get(i).getName()+" lose...");
		}
	}
}
	

