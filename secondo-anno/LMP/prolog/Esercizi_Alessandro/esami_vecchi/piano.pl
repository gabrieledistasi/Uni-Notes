lista_uguale(_, 0, []) :- !.
lista_uguale(X, L, [X|T]) :-
  L1 is L - 1,
  lista_uguale(X, L1, T).

trova_sequenza(N, L, H) :-
  L = [H|_],
  lista_uguale(H, N, LU),
  append(LU, _, L).
trova_sequenza(N, [_|T], S) :-
  trova_sequenza(N, T, S).

lineaOrizzontaleInUnPianoFattaDi(A, Lunghezza, [Row|_]) :-
  trova_sequenza(Lunghezza, Row, A).

lineaOrizzontaleInUnPianoFattaDi(A, Lunghezza, [_|Rest]) :-
  lineaOrizzontaleInUnPianoFattaDi(A, Lunghezza, Rest).


% NON FUNZIONANTE!
%
% quadratoInUnPianoFattoDi(A, LunghezzaLato, Piano) :-
%   controlla_righe_consecutive(A, LunghezzaLato, Piano), !.
%
% quadratoInUnPianoFattoDi(A, LunghezzaLato, [_|RestoPiano]) :-
%   quadratoInUnPianoFattoDi(A, LunghezzaLato, RestoPiano).
%
%
% controlla_righe_consecutive(_, 0, _) :- !.
% controlla_righe_consecutive(A, N, [Row|RestoPiano]) :-
%   N > 0,
%   trova_sequenza(N, Row, A), 
%   NuovoN is N - 1,
%   controlla_righe_consecutive(A, NuovoN, RestoPiano).
