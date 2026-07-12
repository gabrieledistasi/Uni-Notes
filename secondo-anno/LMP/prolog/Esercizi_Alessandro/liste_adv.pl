# intersezione([], L, []).
#
# intersezione([H|T1], [H|T2], [H|I]) :-
#   intersezione(T1, T2, I).
#
# intersezione([H1|T1], [H2|T2], I) :-
#   intersezione(T1, [H2|T2], I).

contenuto(X, [X|_]) :- !.
contenuto(X, [_|T]) :-
  contenuto(X, T).


elemento(X, [X|_]).
elemento(X, [_|T]) :-
  elemento(X, T).


senza_duplicati([], []).
senza_duplicati([H|T], [H|R]) :-
  \+ membro(H, T),
  senza_duplicati(T, R).
senza_duplicati([H|T], R) :-
  membro(H, T),
  senza_duplicati(T, R).


intersezione([], _, []).

intersezione([H|T], L, [H|I]) :-
    membro(H, L),
    \+ membro(H, T),
    intersezione(T, L, I).

intersezione([H|T], L, I) :-
    membro(H, L),
    membro(H, T),
    intersezione(T, L, I).

intersezione([H|T], L, I) :-
    \+ membro(H, L),
    intersezione(T, L, I).


coppia([H|T], H, X) :-
  elemento(X, T),
  write("-----").

coppia([_|T], A, B) :-
  coppia(T, A, B).


sottoinsieme([], []).

sottoinsieme([H|T], [H|X]) :-
  sottoinsieme(T, X).

sottoinsieme([_|T], X) :-
  sottoinsieme(T, X).


concatenata([], L, L).
concatenata([H|T], L, [H|R]) :-
  concatenata(T, L, R).


appiattisci([], []).

appiattisci([[H|T]|L], F) :-
  appiattisci([H|T], F1),
  appiattisci(L, F2),
  concatenata(F1, F2, F).

appiattisci([H|T], [H|F]) :-
  appiattisci(T, F).


contiene(X, L) :-
  concatenata(S, [X|E], L).



% Generazione di lista e posizione degli elementi
% 107 ?- length(A, 5), member(3, A), member(4, A).
% A = [3, 4, _, _, _] ;
% A = [3, _, 4, _, _] ;
% A = [3, _, _, 4, _] ;
% A = [3, _, _, _, 4] ;
% A = [4, 3, _, _, _] ;
% A = [_, 3, 4, _, _] ;
% A = [_, 3, _, 4, _] ;
% A = [_, 3, _, _, 4] ;
% A = [4, _, 3, _, _] ;
% A = [_, 4, 3, _, _] ;
% A = [_, _, 3, 4, _] ;
% A = [_, _, 3, _, 4] ;
% A = [4, _, _, 3, _] ;
% A = [_, 4, _, 3, _] ;
% A = [_, _, 4, 3, _] ;
% A = [_, _, _, 3, 4] ;
% A = [4, _, _, _, 3] ;
% A = [_, 4, _, _, 3] ;
% A = [_, _, 4, _, 3] ;
% A = [_, _, _, 4, 3] ;
