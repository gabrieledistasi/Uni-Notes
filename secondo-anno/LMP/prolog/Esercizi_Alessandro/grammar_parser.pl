% NON FUNZIONA, PRENDE LE OPZIONI IN ORDINE!

prod("S", ["a", "b"]).
% prod("S", ["a", "S"]).
prod("S", ["a", "S", "b", "A"]).
prod("A", ["c", "d"]).
prod("A", ["c", "A", "d"]).

not_terminal(C) :- prod(C, _).

parser([], []) :- !.

parser([H|T], OUT) :-
  not_terminal(H),
  !,
  prod(H, X),
  append(X, T, W),
  parser(W, OUT).

parser([H|T], [H|R]) :-
  parser(T, R).
