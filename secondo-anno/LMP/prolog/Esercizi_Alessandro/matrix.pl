% "e" sta per "emergente"

colonna_e([], [], []).
colonna_e([[H|T]|RM], [H|RC], [T|RMT]) :-
  colonna_e(RM, RC, RMT).


trasposta([[]|_], []).
trasposta(M, [C|MT]) :-
  colonna_e(M, C, MR),
  trasposta(MR, MT).
