nodo(a).
nodo(b).
nodo(c).
nodo(d).

not_nodo(X) :-
  nodo(X),
  !,
  write(X),
  nl,
  fail.

not_nodo(_).

my_not(P) :-
  P,
  !,
  fail.

my_not(_).

my_not2(P) :-
  \+ P.

num_el(_, [], 0).
num_el(X, [X|T], N) :-
  num_el(X, T, N1), 
  N is 1 + N1,
  !.

num_el(X, [H|T], N) :-
  num_el(X, T, N).
