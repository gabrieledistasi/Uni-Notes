% [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],[0, 0, '*', '*', '*', '*', '*', '*', 0, 0],[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]


% [
% [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
% [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
% [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
% [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
% [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
% [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
% [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
% [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
% [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
% [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
% [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
% [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
% [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
% [0, 0, '*', '*', '*', '*', '*', '*', 0, 0],
% [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
% [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
% [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
% [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
% [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
% [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
% ]


lunghezza([], 0).
lunghezza([_|T], Length) :-
  lunghezza(T, LT),
  Length is 1 + LT.


crea_lista(Char, 1, _, [Char]).
crea_lista(Char, Length, Limit, [Char|Rest]) :-
  Limit > 0,
  NewLimit is Limit - 1,
  crea_lista(Char, N_L, NewLimit, Rest),
  Length is N_L + 1,
  Length =< Limit.


check_zero([]).
check_zero([0|_]).


esiste_linea(Char, Left, Length, Row) :-
  lunghezza(Row, LR),
  crea_lista(Char, Length, LR, Sequenza),
  append(Mid, End, Row),
  append(Start, Sequenza, Mid),
  check_zero(End),
  reverse(Start, StartR),
  check_zero(StartR),
  lunghezza(Start, Left).


% Non funziona il trovare i rettangoli

trova_rettangoli(Matrix, [X,Y], Width, Height) :-
    trova_rettangoli(Matrix, 0, [X,Y], Width, Height).


trova_rettangoli([], _, _, _, _) :- fail.

trova_rettangoli([Row|T], Y, [X,Y], Width, Height) :-
    nl,
    esiste_linea('*', X, Width, Row),
    altezza_rettangolo(T, X, Width, 1, Height),
    Width is Width,
    Height is Height,
    X is X,
    Y is Y.

trova_rettangoli([_|T], Y0, Coord, Width, Height) :-
    Y1 is Y0 + 1,
    !,
    trova_rettangoli(T, Y1, Coord, Width, Height).


altezza_rettangolo([], _, _, H, H).

altezza_rettangolo([Row|T], X, Width, Acc, Height) :-
    esiste_linea('*', X, Width, Row),
    NewAcc is Acc + 1,
    altezza_rettangolo(T, X, Width, NewAcc, Height),
    X is X.

altezza_rettangolo(_, _, _, Height, Height).
