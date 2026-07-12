% Prendi i soli elementi duplicati di una lista
duplicati([], []).

duplicati([H|T], L) :-
  member(H, T),
  !,
  duplicati(T, R),
  de_dup([H|R], L).

duplicati([_|T], LD) :-
  duplicati(T, L),
  de_dup(L, LD).

% Rimuovi i duplicati da una lista
de_dup([], []).

de_dup([H|T], LD) :-
  member(H, T),
  !,
  de_dup(T, LD).

de_dup([H|T], [H|LD]) :-
  de_dup(T, LD).

% Stile sliding-window contigua
% Tutte le sottoliste di lunghezza N di L (N minore di len(L))

% sottolista(_, 0, []).
%
% sottolista([H|T1], N, [H|T2]) :-
%   N > 0,
%   NT is N - 1,
%   sottolista(T1, NT, T2).
%
% sottolista([_|T1], N, T2) :-
%   N > 0,
%   sottolista(T1, N, T2).


get_first_n(_, 0, []).

get_first_n([H|T1], N, [H|T2]) :-
  N > 0,
  NT is N - 1,
  get_first_n(T1, NT, T2).

sottolista(L, N, L1) :-
  get_first_n(L, N, L1).

sottolista([_|T], N, L) :-
  sottolista(T, N, L).

% Palindroma, controllare se una lista lo è
my_reverse([], []).
my_reverse([H|T], R) :-
  my_reverse(T, TR),
  append(TR, [H], R).

palindroma([]).

palindroma(L) :-
  % reverse(L, L). BUILT IN
  my_reverse(L, L).

% Generare un anagramma
word(["p","a","l","l","a"]).
word(["c","a","n","e"]).
word(["g","a","t","t","o"]).
word(["c","a","s","a"]).
word(["l","i","b","r","o"]).
word(["m","a","r","e"]).
word(["s","o","l","e"]).
word(["l","u","n","a"]).
word(["f","i","o","r","e"]).
word(["p","o","r","t","a"]).

perm([X], [X]).

perm(P, [H|T]) :-
  append(Left, [H|Right], P),
  append(Left, Right, TP),
  perm(TP, T).

anagramma(P, A) :-
  perm(P, A),
  word(A),
  !.
