% Input: una lista di numeri. Creeranno pezzi di n elementi consecutivi
% Occorre trovare le combinazioni per mettere i valori
%

% 104 ?- riga([2,3], Out, 6).
% Out = [3, 3, 3, 2, 2, _] ;
% Out = [3, 3, 3, _, 2, 2] ;
% Out = [_, 3, 3, 3, 2, 2] ;
% Out = [2, 2, 3, 3, 3, _] ;
% Out = [2, 2, _, 3, 3, 3] ;
% Out = [_, 2, 2, 3, 3, 3] ;
% Out = [2, 2, _, _, _, _] ;
% Out = [_, 2, 2, _, _, _] ;
% Out = [_, _, 2, 2, _, _] ;
% Out = [_, _, _, 2, 2, _] ;
% Out = [_, _, _, _, 2, 2] ;
% Out = [3, 3, 3, _, _, _] ;
% Out = [_, 3, 3, 3, _, _] ;
% Out = [_, _, 3, 3, 3, _] ;
% Out = [_, _, _, 3, 3, 3] ;
% Out = [_, _, _, _, _, _].


crea_lista(Char, 1, [Char]) :- !.
crea_lista(Char, Length, [Char|Rest]) :-
  NL is Length - 1,
  crea_lista(Char, NL, Rest).


sottolista(ListaDaCercare, Lista) :-
  append(Mid, _, Lista),
  append(_, ListaDaCercare, Mid).


posizione_pezzo([], _).
posizione_pezzo([H|T], Riga) :-
  crea_lista(H, H, Pezzo),
  posizione_pezzo(T, Riga),
  sottolista(Pezzo, Riga).
posizione_pezzo([_|T], Riga) :-
  posizione_pezzo(T, Riga).


riga(Pezzi, RigaOttenuta, Lunghezza) :-
  length(RigaOttenuta, Lunghezza),
  posizione_pezzo(Pezzi, RigaOttenuta).
