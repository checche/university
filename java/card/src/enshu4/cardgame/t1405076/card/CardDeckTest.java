package enshu4.cardgame.t1405076.card;

import junit.framework.TestCase;

public class CardDeckTest extends TestCase{
    // すべてのテストメソッドで用いるカードのインスタンス
    private Card spadeA, diamond10, heartQ, clubK,
            spade5, diamondA, heartA, clubA, joker;
	CardDeck cd = new CardDeck();
	

    /**
     * テストの前処理．カードのインスタンスを生成する．
     */
    public void setUp() {
        //いくつかテスト用のカードインスタンスを作っておく．
        spadeA = new Card(0,1);      //スペードA
        diamond10 = new Card(1,10);  //ダイヤ10
        heartQ = new Card(2,12);     //ハートQ
        clubK = new Card(3,13);      //クラブK

        //他にも作っておく．
        spade5 = new Card(0,5);      //スペード5
        diamondA = new Card(1,1);    //ダイヤA
        heartA = new Card(2,1);      //ハートA
        clubA = new Card(3,1);       //クラブA
        joker = new Card(-1,0);      //ジョーカー
        
        cd.addCard(spadeA);
        cd.addCard(diamond10);
        cd.addCard(heartQ);
        cd.addCard(clubK);
        cd.addCard(spade5);
        cd.addCard(diamondA);
        cd.addCard(heartA);
        cd.addCard(clubA);
        cd.addCard(joker);
}
/**
 *  テストの後処理．
 */
    public void tearDown() {
        System.out.println("テスト終了．");
    }
	
    public void testGetCard(){
    	assertSame(spadeA, cd.getCard());
    }
	
    public void testGetCardAt(){
    	assertSame(spadeA, cd.getCardAt(1));
    }
	
	public void testSearchCardWithIndex(){
		assertEquals(1, cd.searchCardWithIndex(0));
        assertEquals(9, cd.searchCardWithIndex(-1));
	}
	
	public void testSeeCardAt(){
		assertSame(spadeA, cd.seeCardAt(1));
	}
	
	public void testIsEmpty(){
		assertFalse(cd.isEmpty());
	}

	
	public void testSize(){
		assertEquals(9, cd.size());
	}
	
	
	
}
