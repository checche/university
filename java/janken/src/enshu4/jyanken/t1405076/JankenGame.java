package enshu4.jyanken.t1405076;

import java.util.ArrayList;

public class JankenGame {

	ArrayList<Player> players = new ArrayList<Player>();
	private Judge judge;
	private int numberOfGames;
	
	public void addPlayer(Player player){
	players.add(player);
	System.out.println("新しいユーザー「"+player.getName()+"」を作成し、ゲームに追加しました。");
	}


	public int getNumberOfGames() {
		return numberOfGames;
	}


	public void setJudge(Judge judge) {
		this.judge = judge;
	}


	public void setNumberOfGames(int numberOfGames) {
		this.numberOfGames = numberOfGames;
	}

	public void playJanken(){
		for(int j =0; j<numberOfGames; j++){
			System.out.println("--------第"+(j+1)+"回戦--------");
			for(int i = 0; i<players.size(); i++){
				players.get(i).chooseHand();	
			}
			System.out.println("#######じゃんけんぽん!!!!!!#########");
			for(int i = 0; i<players.size(); i++){
				players.get(i).showHand();
			}
		
			Result r = new Result();
			r=judge.judge(players);
			if(r.getWinnerHand()>=0){
				if(r.getWinnerHand()==0)System.out.println("勝ち手 グー");
				if(r.getWinnerHand()==1)System.out.println("勝ち手 チョキ");
				if(r.getWinnerHand()==2)System.out.println("勝ち手 パー");
				System.out.print("勝ち:");
				for(int i = 0; i<r.winners.size(); i++){
					System.out.print(r.winners.get(i).getName()+" ");
					r.winners.get(i).win();
				}
				System.out.print("\n負け:");
				for(int i = 0; i<r.losers.size(); i++){
					System.out.print(r.losers.get(i).getName()+" ");
					r.losers.get(i).lose();
				}
				System.out.print("\n");
			}
			if(r.getWinnerHand()<0){
				System.out.println("引き分け");
				for(int i = 0; i<players.size(); i++){
					players.get(i).draw();
				}
			}
			
			
		}
		
		System.out.println("--------総合戦績--------");
		for(int i = 0; i<players.size(); i++){
			players.get(i).showRecord();
		}
	}


}
