:- use_module(library(clpfd)).

% ===============================
% ESEMPIO SCHEMA (5x5)
% # = nero
% _ = lettera
% ===============================

schema([
    [#,_,_,_,#],
    [_,_,#,_,_],
    [_,#,_,#, _],
    [_,_,#,_,_],
    [#,_,_,_,#]
]).

% ===============================
% DIZIONARIO
% ===============================

dictionary([
    [p,y,t,h,o,n],
    [d,e,b,u,g],
    [l,i,s,t,a],
    [c,o,d,e],
    [r,u,s,t],
    [j,a,v,a],
    [s,q,l],
    [a,p,i]
]).

% ===============================
% COSTRUZIONE GRIGLIA
% ===============================

build_grid(Grid) :-
    schema(Schema),
    copy_term(Schema, Grid).

% ===============================
% ESTRAZIONE SLOT REALI
% ===============================

slots(Grid, Slots) :-
    horizontal_slots(Grid, H),
    transpose(Grid, T),
    horizontal_slots(T, V),
    append(H, V, Slots).

horizontal_slots([], []).
horizontal_slots([Row|Rows], Slots) :-
    row_slots(Row, RowSlots),
    horizontal_slots(Rows, Rest),
    append(RowSlots, Rest, Slots).

row_slots(Row, Slots) :-
    split_at_hash(Row, Parts),
    include(valid_slot, Parts, Slots).

split_at_hash([], []).
split_at_hash(Row, [Part|Rest]) :-
    append(Part, Tail, Row),
    ( Tail = [#|Remaining] ->
        split_at_hash(Remaining, Rest)
    ; Tail = [] ->
        Rest = []
    ).

valid_slot(Slot) :-
    length(Slot, L),
    L > 1.

% ===============================
% ASSEGNAZIONE CON MRV
% ===============================

solve(Grid) :-
    build_grid(Grid),
    dictionary(Dict),
    slots(Grid, Slots),
    length(Slots, N),

    % una variabile indice per ogni slot
    length(Indices, N),
    Indices ins 1..1000,

    assign_domains(Slots, Dict, Indices),

    all_different(Indices),

    labeling([ff], Indices).

assign_domains([], _, []).
assign_domains([Slot|Slots], Dict, [I|Is]) :-
    findall(Index,
        (nth1(Index, Dict, Word),
         same_length(Slot, Word)),
        Domain),

    list_to_fdset(Domain, Set),
    I in_set Set,

    element(I, Dict, Word),
    Slot = Word,

    assign_domains(Slots, Dict, Is).

% ===============================
% STAMPA
% ===============================

print_grid([]).
print_grid([Row|Rows]) :-
    print_row(Row),
    print_grid(Rows).

print_row([]) :- nl.
print_row([#|T]) :-
    write('# '),
    print_row(T).
print_row([H|T]) :-
    write(H), write(' '),
    print_row(T).
