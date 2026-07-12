% Mossa 1
inversione(Chars1, Chars2, Costo) :-
  append(S1, [X|E11], Chars1),
  append(K, [Y|E12], E11),
  append(S1, [Y|E21], Chars2),
  append(K, [X|E12], E21),
  length(K, LK),
  Costo is 1 + LK.

% Mossa 2
cancellazione(Chars1, Chars2, Costo) :-
  select(_, Chars1, Chars2),
  Costo is 5.

% Mossa 3
inserimento(Chars1, Chars2, Costo) :-
  cancellazione(Chars2, Chars1, Costo).

distanza(Stringa1, Stringa2, MosseDiTrasformazione, CostoTrasformazione) :-
  atom_chars(Stringa1, Chars1),
  atom_chars(Stringa2, Chars2),
  d(Chars1, Chars2, MosseDiTrasformazione, CostoTrasformazione), 
  !.

d(Chars, Chars, [], 0).

d(Chars1, Chars2, [1|Rest], Cost) :-
  inversione(Chars1, X, C2),
  d(X, Chars2, Rest, C1),
  Cost is C1 + C2.

d(Chars1, Chars2, [2|Rest], Cost) :-
  cancellazione(Chars1, X, C2),
  d(X, Chars2, Rest, C1),
  Cost is C1 + C2.

d(Chars1, Chars2, [3|Rest], Cost) :-
  inserimento(Chars1, X, C2),
  d(X, Chars2, Rest, C1),
  Cost is C1 + C2.
