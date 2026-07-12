mossa(2, 1).  mossa(2, -1). mossa(-2, 1). mossa(-2, -1).
mossa(1, 2).  mossa(1, -2). mossa(-1, 2). mossa(-1, -2).

valida(X, Y) :-
    X > 0, X < 9,
    Y > 0, Y < 9.

prossima_mossa([X, Y], Visitati, [NX, NY]) :-
    mossa(DX, DY),
    NX is X + DX,
    NY is Y + DY,
    valida(NX, NY),
    \+ member([NX, NY], Visitati).

% Conta quante mosse "valide" ha la posizione attuale
conta_mosse(Pos, Visitati, Conteggio) :-
    findall(M, prossima_mossa(Pos, Visitati, M), Mosse),
    length(Mosse, Conteggio).

% Ordina le mosse in ordine decrescente di mosse possibili
ordina_mosse(Pos, Visitati, MosseOrdinate) :-
    findall(C-M, (prossima_mossa(Pos, Visitati, M), conta_mosse(M, [M|Visitati], C)), ListaPesata),
    keysort(ListaPesata, ListaOrdinata),
    pairs_values(ListaOrdinata, MosseOrdinate).

path_with_acc(_, ACC, P) :-
    length(ACC, 64),
    !,
    P = ACC.

path_with_acc(Pos, ACC, P) :-
    ordina_mosse(Pos, ACC, [MiglioreMossa|_]), % Prende la mossa con meno opzioni
    path_with_acc(MiglioreMossa, [MiglioreMossa|ACC], P).

% cammino([1,1], P).
cammino([X, Y], S_F) :-
    path_with_acc([X, Y], [[X, Y]], Res),
    reverse(Res, P),
    format(P, P_F),
    atomic_list_concat(P_F, ', ', A_F),
    atom_string(A_F, S_F).

lettera(1, "A"). lettera(2, "B").
lettera(3, "C"). lettera(4, "D").
lettera(5, "E"). lettera(6, "F").
lettera(7, "G"). lettera(8, "H").

format([], []).
format([[X, Y]|T], [C_F|T_F]) :-
    lettera(X, X_F),
    atomic_list_concat([X_F, Y], C_F),
    format(T, T_F).
