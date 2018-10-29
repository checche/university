package enshu4.jyanken.t1405076;

import java.util.ArrayList;

public class Judge {

	public Result judge(ArrayList<Player> players){
		int g=0;
		int c=0;
		int p=0;
		Result res = new Result();
		for(int i=0;i<players.size(); i++){
			if(players.get(i).getHand() ==0)g++;
			if(players.get(i).getHand() ==1)c++;
			if(players.get(i).getHand() ==2)p++;
		}
		if(g>0 && c>0 && p==0){
			//System.out.println("勝ち手はグー");
			res.setWinnerHand(0);
			for(int i=0;i<players.size(); i++){
				if(players.get(i).getHand()==0)
					res.addWinners(players.get(i));
				if(players.get(i).getHand()==1)
					res.addLosers(players.get(i));
			}
		}
		if(g==0 && c>0 && p>0){
			//System.out.println("勝ち手はチョキ");
			res.setWinnerHand(1);
			for(int i=0;i<players.size(); i++){
				if(players.get(i).getHand()==1)
					res.addWinners(players.get(i));
				if(players.get(i).getHand()==2)
					res.addLosers(players.get(i));
			}
		}
		if(g>0 && c==0 && p>0){
			//System.out.println("勝ち手はパー");
			res.setWinnerHand(2);
			for(int i=0;i<players.size(); i++){
				if(players.get(i).getHand()==2)
					res.addWinners(players.get(i));
				if(players.get(i).getHand()==0)
					res.addLosers(players.get(i));
			}

		}
		if((g>0 && c>0 && p>0) 
				|| (g>0 && c==0 &&p==0)
				||(g==0 && c>0 &&p==0)
				||(g==0 && c==0 &&p>0)){
			//System.out.println("引き分け");
			res.setWinnerHand(-1);
		}
		
		return res;
	}
	
}
