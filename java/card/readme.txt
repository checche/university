card:トランプの基本動作を行うためのもの
game:ババ抜きを行うプログラムで、cardで作成したクラスなども利用する。

ババ抜きプレイヤーのクラス(Player)とそのユーザーとCPUのサブクラス(User)、(CPU)を作る。また、ゲームの動作を行うクラス(Babanuki)がある。Playerには手札をCardDeckクラスとして持たせる。～ルール～ジョーカー1枚とフルデッキを用意する。(makeDeck)山札の上から順にプレイヤーにカードを配る。(distribute)カードを手にする度に同じ数字のカードを捨てる。(throw)その後同じ数字のカードを捨てる。順番の人がその次の人のカードを引く。選び方はプレイヤーのメソッド(chooseCard)で決める。その後同じ数字のカードを捨てる。これを繰り返し、最後にカードを持っていた人が負け。プレイヤーの勝ち判定フィールド(win)が1の場合勝ち。0の場合負けである。順番はユーザーとCPU2人、順番はユーザー→CPU1→CPU2→ユーザー→…とする。