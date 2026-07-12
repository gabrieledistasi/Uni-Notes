find([], X, I) :-
  write(-1).

compare(X, Y) :-
  X = Y.

find([H|T], X, I) :-
  (compare(H, X) -> write(I) ; I1 is I + 1, find(T, X, I1)).
