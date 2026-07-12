ins('FIU', 1).
ins('FIT', 1).
ins('CS', 1).
ins('BB', 1).
ins('BU', 2).
ins('CE', 2).
ins('SI', 2).
ins('OP', 2).
ins('NNO', 3).
ins('RE', 3).

conta_elemento(_, [], 0).
conta_elemento(E, [E|T], C) :-
  conta_elemento(E, T, C1),
  C is 1 + C1,
  !.
conta_elemento(E, [_|T], C) :-
  conta_elemento(E, T, C),
  !.

stesso_anno(X, Y) :-
  ins(X, ANNO),
  ins(Y, ANNO).

collisione(Aula1, Aula2) :-
  append(Start1, [Insegnamento1|End1], Aula1),
  append(Start2, [Insegnamento2|End2], Aula2),
  length(Start1, LS),
  length(Start2, LS),
  length(End1, LE),
  length(End2, LE),
  ins(Insegnamento1, ANNO),
  ins(Insegnamento2, ANNO).

genera_lezioni(I1, I2):-
  ins(I1, A1),
  ins(I2, A2),
  I1 \= I2,
  A1 \= A2.

genera_aule([], []).
genera_aule([I1|T1], [I2|T2]) :-
  genera_lezioni(I1, I2),
  genera_aule(T1, T2),

  conta_elemento(I1, T1, X1),
  conta_elemento(I1, T2, X2),
  conta_elemento(I2, T1, Y1),
  conta_elemento(I2, T2, Y2),
  
  Total1 is X1 + X2,
  Total1 < 4,
  Total2 is Y1 + Y2,
  Total2 < 4.
