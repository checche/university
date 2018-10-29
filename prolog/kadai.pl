%%% 平成27年度後期 プログラミング言語論演習 課題
%%% 学籍番号:1405076t
%%% 氏名:平田恭嘉
%%% email:1405076t@stu.kobe-u.ac.jp


d(x, 1).
d(Y, 0) :- atomic(Y), Y \== x.
d(Y+Z, DY+DZ) :- d(Y, DY),d(Z, DZ).
d(Y^N, N*Y^N1*DY) :- integer(N), N1 is N-1, d(Y,DY).
d(x, 1).
d(Y, 0) :- atomic(Y), Y \== x.
d(Y+Z, DY+DZ) :- d(Y, DY), d(Z, DZ).
d(Y^N, N*Y^N1*DY) :- integer(N), N1 is N-1, d(Y, DY).
d(-Y, DR) :- d(Y,DY), DR is -1*DY.
d(Y-Z, DY-DZ) :- d(Y, DY),d(Z, DZ).
d(Y*Z, Y*DZ+DY*Z) :- d(Y, DY),d(Z, DZ).
d(sin(Y), cos(Y)*DY) :- d(Y, DY).
d(cos(Y), -sin(Y)*DY) :- d(Y, DY).
d(exp(Y), exp(Y)*DY) :- d(Y, DY).
d(A^Y, A^Y*log(A)*DY) :- d(Y, DY).
d(log(Y), 1/Y*DY) :- d(Y, DY).

s(Y+Z, S) :- s(Y, SY), s(Z, SZ), s1(SY+SZ, S).
s(Y*Z, S) :- s(Y, SY), s(Z, SZ), s1(SY*SZ, S).
s(Y-Z, S) :- s(Y, SY), s(Z, SZ), s1(SY-SZ, S).
s(Y^Z, S) :- s(Y, SY), s(Z, SZ), s1(SY^SZ, S).
s(Y, Y).
s1(0+Z, Z).
s1(Y+0, Y).
s1(1*Z, Z).
s1(Y*1, Y).
s1(Y+Z, S1) :- integer(Y), integer(Z), S1 is Y+Z.
s1(Y-Z, S1) :- integer(Y), integer(Z), S1 is Y-Z.
s1(Y*Z, S1) :- integer(Y), integer(Z), S1 is Y*Z.
s1(Y^Z, S1) :- integer(Y), integer(Z), Z1 is Z -1 , s1(Y^Z1,S2), S1 is S2 * Y.
s1(_*0, 0).
s1(Y-0, Y).
s1(Y^1, Y).
s1(_^0, 1).
s1(1^_, 1).
s1(X*(Y*Z), S1) :- s(X*Y*Z, S1).
s1(Y, Y).


u([], S, S).
u([S | X], Y, Z) :- member(S, Y), !, u(X, Y, Z).
u([S | X], Y, [S | Z]) :- u(X, Y, Z).

i([], _, []).
i([S | X], Y, [S | Z]) :- member(S, Y), !, i(X, Y, Z).
i([_ | X], Y, Z) :- i(X, Y, Z).

di([], _, []).
di([S | X], Y, Z) :- member(S, Y), !, di(X, Y, Z).
di([S | X], Y, [S | Z]) :- di(X, Y, Z).


%%% 問題6 (その1)
% exp(Y)を微分する関数d/2を作成しました．使い方は以下の通りです．
% ?- d(exp(x+2),DY), s(DY,DS).
% DY = exp(x+2)* (1+0),
% DS = exp(x+2) 
%
%%% 問題6 (その2)
% A^Y(Aは定数)の微分をする関数d/2を作成しました．使い方は以下の通りです．
%
% ?- d(3^(x^3+x^2),DY), s(DY,DS).
% DY = 3^ (x^3+x^2)*log(3)* (3*x^2*1+2*x^1*1),
% DS = 3^ (x^3+x^2)*log(3)* (3*x^2+2*x) 
%
%%% 問題6 (その3)
% log(Y)の微分をする関数d/2を作りました．使い方は以下の通りです．
% ?- d(log(x^2+3),DY),s(DY,SY).
% DY = 1/ (x^2+3)* (2*x^1*1+0),
% SY = 1/ (x^2+3)*2*x 
%
%%% 問題7
% 2つのリストの要素の論理和、論理積、論理差を表示する関数u/2, i/2, di/2を作りました。使い方は以下です。
% ?- u([1,2,3,4,5,6,7],[2,3,4,5],X). 
% X = [1, 6, 7, 2, 3, 4, 5].
%
% ?- i([1,2,3,4,5,6,7],[2,3,4,5],X).
% X = [2, 3, 4, 5].
%
% ?- di([1,2,3,4,5,6,7],[2,3,4,5],X).
% X = [1, 6, 7].

