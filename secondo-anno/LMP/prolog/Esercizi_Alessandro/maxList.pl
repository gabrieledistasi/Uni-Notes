maxList([H], H).

maxList([H|T], M) :-
  maxList(T, M1),
  (H > M1 -> M = H ; M = M1).
