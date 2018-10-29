package enshu4.jyanken.t1405076;

import java.util.ArrayList;

public class Result {

	private int winnerHand;
	ArrayList<Player> winners = new ArrayList<Player>();
	ArrayList<Player> losers = new ArrayList<Player>();
	public int getWinnerHand() {
		return winnerHand;
	}
	public void setWinnerHand(int winnerHand) {
		this.winnerHand = winnerHand;
	}

	public void addWinners(Player winner) {
		 winners.add(winner);
	}

	public void addLosers(Player loser) {
		losers.add(loser);
	}
	
	
	
}
