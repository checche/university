package enshu4.cardgame.t1405076.card;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

public class CardDeck {
	ArrayList<Card> cards = new ArrayList<Card>();
	
	public CardDeck(){
		cards.clear();
	}
	//i/13,i%13+1
	public void createFullDeck(){
		System.out.println("フルデッキを作ります。");
		Card[] cs=new Card[52];
		for(int i=0; i<cs.length; i++) { 
			cs[i]=new Card(i/13,i%13+1);
			cards.add(cs[i]);
		}
	}
	
	public void shuffle(){
		System.out.println("シャッフルします。");
		Collections.shuffle(cards);
	}
	
	public void addCard(Card card){
		cards.add(card);
	}
	
	public Card getCard(){
		Card c = new Card(0,0);
		c = this.cards.get(0);
		for(int j=0; j<cards.size()-1;j++){
			cards.set(j,cards.get(j+1));	
		}
		cards.remove(cards.size()-1);
		return c;
		
	}
	
	public Card getCardAt(int i){
		Card c = new Card(0,0);
		c = this.cards.get(i-1);
		for(int j=i-1; j<cards.size()-1;j++){
			cards.set(j,cards.get(j+1));	
		}
		cards.remove(cards.size()-1);
		return c;
	}
	
	public int searchCardWithIndex(int cardIndex){
		int k=0;
		for(int i=0; i<cards.size(); i++){
			if(cardIndex == cards.get(i).toIndex())
				k=i+1;
		}
		return k;
	}
	
	public Card seeCardAt(int i){
		return cards.get(i-1);
	}
	
	public void insertCard(int i, Card card){
		cards.add(i-1,card);
	}
	
	public void showAllCards(){
		System.out.println("現在の山を表示します。");
		if(cards.size()==0)System.out.println("ありません。");
		else{
			for(int i=0; i<cards.size(); i++){
			System.out.print(i+1+"番目のカード:");
			cards.get(i).show();
			}
		}
		
	}
	
	public boolean isEmpty(){
		if(cards.size()==0)
			return true;
		return false;
	}
	
	public Iterator<Card> iterator(){
		return cards.iterator();
	}
	
	public int size(){
		return cards.size();
	}
	
	public Card[] toArray(){
		Card[] c = cards.toArray(new Card[0]);
		return c;
	}
	
	
}
