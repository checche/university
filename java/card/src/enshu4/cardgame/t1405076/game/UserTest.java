package enshu4.cardgame.t1405076.game;

import enshu4.cardgame.t1405076.card.Card;
import junit.framework.TestCase;

public class UserTest extends TestCase{

private User p;

public void setUp() {
	p = new User("test");
}
   public void tearDown() {
           System.out.println("テスト終了．");
   }
	public void testChooseHand(){
		assertEquals(3,p.chooseCard(5));
		
	}
	
}
