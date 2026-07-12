split(L, L1, L2) :-
  append(L1, L2, L),
  length(L1, LEN),
  length(L2, LEN).

split([H|T], [H|L1], L2) :-
  split(T, L1, L2).


merge(X, [], X).
merge([], X, X).

merge([H1|T1], [H2|T2], [H1|L]) :-
  H1 < H2,
  merge(T1, [H2|T2], L).

merge([H1|T1], [H2|T2], [H2|L]) :-
  merge([H1|T1], T2, L).
 

merge_sort([X], [X]).

merge_sort(L, LO) :-
  split(L, L1, L2),
  merge_sort(L1, LO1),
  merge_sort(L2, LO2),
  merge(LO1, LO2, LO),
  !. 
