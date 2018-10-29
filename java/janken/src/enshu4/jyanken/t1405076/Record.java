package enshu4.jyanken.t1405076;

/**
 * プレイヤークラスの戦績を表すフィールド、Recordに関することが書かれている。
 * @author Ta-kun
 *
 */
public class Record {
	/**勝数*/
	private int winCount;
	/**負け数*/
	private int loseCount;
	/**引き分け数*/
	private int drawCount;

	/**コンストラクタ*/
	public Record(){
		winCount = 0;
		loseCount = 0;
		drawCount = 0;
	}

	/**
	 * 勝数を取得
	 * @return 勝数
	 * */
	public int getWinCount() {
		return winCount;
	}
	
	/**
	 * 勝数をセット
	 * @param winCount 勝数
	 * */
	public void setWinCount(int winCount) {
		this.winCount = winCount;
	}
	
	/**
	 * 負け数を取得
	 * @return 負け数
	 * */
	public int getLoseCount() {
		return loseCount;
	}
	
	/**
	 * 負け数をセット
	 * @param loseCount 負け数
	 * */
	public void setLoseCount(int loseCount) {
		this.loseCount = loseCount;
	}
	
	/**
	 * 引き分け数を取得
	 * @return 引き分け数
	 * */
	public int getDrawCount() {
		return drawCount;
	}
	
	/**
	 * 引き分け数をセット
	 * @param drawCount 引き分け数
	 * */
	public void setDrawCount(int drawCount) {
		this.drawCount = drawCount;
	}



}
