%scrivere un predicato che, date due liste, è vero se una è la permutazione dell altra



permutata([], []). %caso base: una lista vuota è permutazione di una lista vuota

permutata([H|T], L):- 

    concatena(Prima,[H], PrimaeH),
    concatena(PrimaeH, Dopo, L),
    concatena(Prima, Dopo, L1),

    permutata(T, L1). 

% [a, b, c, d]
% [b, c, a, d] Lista, parola: a
% [prima, parola, L1] prima


permutata(X, X).

permutata([H|T], L):-
    append(Prima, [H|Dopo], L), 
    append(Prima, Dopo, PT), 
    permutata(T, PT).



