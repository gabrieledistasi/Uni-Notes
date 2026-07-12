% Versione dalla documentazione di swipl
%
% :- use_module(library(clpfd)).
%
% n_queens(N, Qs) :-
%         length(Qs, N),
%         Qs ins 1..N,
%         safe_queens(Qs).
%
% safe_queens([]).
% safe_queens([Q|Qs]) :- safe_queens(Qs, Q, 1), safe_queens(Qs).
%
% safe_queens([], _, _).
% safe_queens([Q|Qs], Q0, D0) :-
%         Q0 #\= Q,
%         abs(Q0 - Q) #\= D0,
%         D1 #= D0 + 1,
%         safe_queens(Qs, Q0, D1).


% Genera una lista con valori da 1 a N
range(N, N, [N]).
range(I, N, [I|Ns]) :-
    I < N,
    I1 is I + 1,
    range(I1, N, Ns).


queens([], []).
% queens([regina corrente | regine disponibili], colonne disponibili)
queens([Q|Qs], Ns) :-
    % Select toglie Q dalla lista Ns, mettendo il risultato in Rest
    select(Q, Ns, Rest),
    queens(Qs, Rest),
    % Controlla se la regina Q non viene mangiata dalle regine in Qs
    safe(Q, Qs, 1).


% Controlla se una regina è al sicuro
safe(_, [], _).
% safe(regina corrente, [regina da confrontare | altre regine], distanza in righe)
safe(Q, [Q1|Qs], D) :-
    abs(Q - Q1) =\= D, % Non su stessa diagonale
    D1 is D + 1, % Incrementa distanza da verificare
    safe(Q, Qs, D1).


n_queens(N, Qs) :-
    range(1, N, Ns),
    queens(Qs, Ns).
