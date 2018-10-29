package enshu4.jyanken.t1405076;


/**
 * プレイヤーに関することがある。
 * @author Ta-kun
 *
 */

public abstract class Player {
	/**ユーザー名*/
	private String name;
	/**手*/
	protected int hand;
	/**戦績*/
	private Record record= new Record();
	
	/**名前を設定するコンストラクタ
	 * @param name ユーザー名
	 * */
	public Player(String name) {
		this.name = name;
	}
	/**名前を取得する
	 * @return 名前
	 * */
	public String getName() {
		return name;
	}
	/**手を取得する
	 * @return 手
	 * */
	public int getHand() {
		return hand;
	}
	/**手を表示する*/
	public void showHand() {
		if(this.hand==0)
			System.out.println(name+"の手はグー");
		if(this.hand==1)
			System.out.println(name+"の手はチョキ");
		if(this.hand==2)
			System.out.println(name+"の手はパー");
	}
	/**手を選ぶ抽象メソッド*/
	public abstract void chooseHand();
	
	/**戦績を取得する
	 * @return 戦績
	 * */
	public Record getRecord() {
		return record;
	}
	/**戦績を表示する*/
	public void showRecord() {
		System.out.println(name+"さんの戦績 勝ち"+this.record.getWinCount()+" 負け"
							+this.record.getLoseCount()+" 引き分け"
							+this.record.getDrawCount());
	}
	/**勝数を1増やす*/
	public void win(){
		record.setWinCount(record.getWinCount()+1);
	}
	/**負け数を1増やす*/
	public void lose(){
		record.setLoseCount(record.getLoseCount()+1);
	}
	/**引き分け数を1増やす*/
	public void draw(){
		record.setDrawCount(record.getDrawCount()+1);
	}

}
