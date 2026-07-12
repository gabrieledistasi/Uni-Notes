lunghezza([], 0).
lunghezza([_|T], L) :- 
  lunghezza(T, L1),
  L is L1 + 1.

membro(X, [X|T]).
membro(X, [_|T]):-
  membro(X, T).

% NON FAREEEEEEEE!!!
appartiene(E, [H|T]) :-
  E == H;
  appartiene(E, T).

ultimo([H|[]], H).
ultimo([H|T], L) :-
  ultimo(T, L).

inverti([], []).
inverti([H|T], L) :-
  inverti(T, R),
  concatenata(R, [H], L).

palindroma([]).
palindroma([_]).
palindroma(L) :-
  inverti(L, L).

somma_lista([X], X).
somma_lista([H|T], R) :-
  somma_lista(T, R1),
  R is H + R1.

massimo([X], X).
massimo([H|T], H) :-
  massimo(T, M),
  H >= M.
massimo([H|T], M) :-
  massimo(T, M),
  H < M.

num_elemento(X, [X], 1).
num_elemento(X, [], 0).

num_elemento(X, [X|T], N) :-
  num_elemento(X, T, N1),
  N is 1 + N1.

num_elemento(X, [H|T], N) :-
  num_elemento(X, T, N).


concatenata([], L, L).
concatenata([H|T], L2, [H|R]) :-
    concatenata(T, L2, R). 


permutazione([X], [X]).

permutazione(P, [H|T]) :-
  concatenata(Left, [H|Right], P),
  concatenata(Left, Right, TP),
  permutazione(TP, T).


minimo([X], X).
minimo([H|T], H) :-
  minimo(T, M),
  H < M.
minimo([H|T], M) :-
  minimo(T, M),
  H >= M.


ordinata([X], [X]).
ordinata(L, [M|T_O]) :-
  minimo(L, M),
  concatenata(S, [M|E], L),
  concatenata(S, E, T),
  ordinata(T, T_O).


uguali([X], [X]).
uguali([H|T1], [H|T2]) :-
  uguali(T1, T2).


permutazione2(L, P) :-
  ordinata(L, L1),
  ordinata(P, P1),
  uguali(L1, P1).
