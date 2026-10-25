%scrivere un predicato che, dato un elemento e una lista, è vero se l elemento compare 2 volte nella lista

appartiene(X, [X|_]). 

appartiene(X, [_|T]):-
    appartiene(X, T).



duplicato(X, L):-

	concatena(_, [X|Dopo], L),
    appartiene(X, Dopo).




%2, [1, 3, 2, 2, 5, 6, 7], [1, 2, 3, 2, 5, 6, 7], [1, 2, 2], 
%
