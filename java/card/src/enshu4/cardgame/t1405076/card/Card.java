package enshu4.cardgame.t1405076.card;

public class Card {
	private int suit;
	private int number;

	public Card(int suit, int number){
		this.suit = suit;
		this.number = number;
	}

	public int getSuit() {
		return suit;
	}
	
	public int getNumber() {
		return number;
	}

	public int toIndex(){
		if(this.suit == -1)return -1;
		else {return (this.suit*13) + this.number - 1;}
		
	}
	
	public String toString(){
		String s = null;
		String n = null;
		if(this.suit == 0){
			s = "スペード";
		}
		if(this.suit == 1){
			s = "ダイヤ";
		}
		if(this.suit == 2){
			s = "ハート";
		}
		if(this.suit == 3){
			s = "クラブ";
		}
		if(this.suit == -1){
			s = "ジョーカー";
		}

		if(this.number == 1){
			n ="A";
		}
		else if(this.number == 11){
			n ="J";
		}
		else if(this.number == 12){
			n ="Q";
		}
		else if(this.number == 13){
			n ="K";
		}
		else if(this.number == 0){
			n ="";
		}
		else {
			n=String.valueOf(this.number);
		}
		return s+n;
	}
	
	public void show(){
		System.out.println(this.toString());
	}
	
	public static int getIndex(int suit, int number){
		if(suit == -1)return -1;
		return (suit*13) + number -1;
	}
	
}
