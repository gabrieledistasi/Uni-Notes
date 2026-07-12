:- dynamic fatto/1.

lunghezza([], 0).
lunghezza([H|T], N) :-
  lunghezza(T, N1),
  N is 1 + N1.

num_argomenti(P, N) :-
  P =.. [H|T],
  lunghezza(T, N).


funtore(P, F) :-
  P =.. [F|_].


liste_uguali([], []).
liste_uguali([H|T1], [H|T2]) :-
  liste_uguali(T1, T2).

argomenti(P, L) :-
  P =.. [H|T],
  liste_uguali(T, L).
