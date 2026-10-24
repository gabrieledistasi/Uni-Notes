%scrivere un predicato che dato un elemento in una lista vedere se l'elemento appartiene alla lista

appartiene(X, [X|_]).
appartiene(X, [_|T]):-
    appartiene(X, T).

%cut è un punto esclamativo che permette a prolog di dire dove terminare il backtracking:
%appartiene(X, [X|_]):-!.
%appartiene(X, [_|T]):-
%    appartiene(X, T).
% scrivendo il codice in questo modo permette di avere SOLO la prima soluzione 
