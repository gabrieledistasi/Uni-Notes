%Scrivi intersezione(L1, L2, R), dove R contiene 
%gli elementi della prima lista che compaiono anche nella seconda.


concatena([], X, X).  %caso base: l ultimo passaggio dell induzione, se tutto vero fino al penultimo momento, controllo l ultimo momento, 

concatena([H|T],B,[H|T1] ):- %ho 3 liste, per prima cosa non mi interessa della seconda lista, ma controllo se la prima coincide con la terza (quella che deve essere concatenata) 
    concatena(T, B, T1). 


intersezione([], L2, []).

intersezione([H|T], L2, R):-
    concatena(_, [H|_], L2), 
    intersezione(T, L2, R1), 
    concatena([H], R1, R).

intersezione([H|T], L2, R):- 
    \+ concatena(_, [H|_], L2), 
    intersezione(T, L2, R).






%come deve essere fatta la soluzione?
% A = [1, 3, 5, 7, 2, 2, 6, 15, 11] e B = [1, 2, 2, 3, 4, 5, 6, 7, 8, 9], R = 