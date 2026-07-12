    

    % Rappresentare una tabella
% [att1#[val1, val2], att2#[val1, val2], att3#[val1, val2]]

:- op(500, xfx, '#').

% Es. tabella
% [azienda#[acme, pear, hal, macrohard], comunicati#[+, +, -, -], q1#[-, +, +, -], personale#[+, +, -, +], x#[+, +, -, +], tg#[-, +, -, +], andamento#[+, -, +, -]]


project(_, [], []).
project(COL, [COL#_|T], T) :- !.
project(COL, [C|T], [C|TR]) :-
  project(COL, T, TR).


estrai_riga([], [], []) :- !.
estrai_riga([ATTR#[H|T]|Resto], [ATTR#T|Resto_Rem], [ATTR#[H]|Resto_Ris]) :-
  estrai_riga(Resto, Resto_Rem, Resto_Ris).


estrai_tutte_righe([_#[]|_], []) :- !.
estrai_tutte_righe(Data, [R|Res]) :-
  estrai_riga(Data, Data_Res, R),
  estrai_tutte_righe(Data_Res, Res).


contiene_valore(Target, [Target|_]) :- !.
contiene_valore(Target, [_|T]) :- contiene_valore(Target, T).


filtra_righe(_, [], []).
filtra_righe(Target, [Riga|Resto], Risultato) :-
    contiene_valore(Target, Riga), !,
    filtra_righe(Target, Resto, Risultato).
filtra_righe(Target, [Riga|Resto], [Riga|Risultato]) :-
    filtra_righe(Target, Resto, Risultato).


delete(Target, Data, Res) :-
    estrai_tutte_righe(Data, Righe),
    filtra_righe(Target, Righe, Res).
