%dato un elemento e una lista, scrivero un predicato che è vero se l'elemento è l'ultimo elemento di una lista

ultimo(X, [X]). %possibile altro caso base ultimo([H, H|[]])

ultimo(X, [_|T]):-
    ultimo(X, T).