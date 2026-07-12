% Messaggio di esempio 1: "il gatto sta pensando di mangiare il cane per fame"
% "igspdmicpflateialaea tan n nrm t s g e e o a i       n a       d r       o e"

% Messaggio di esempio 2: "studio per sport"
% "spstepurod ri to"

% Basato sulla struttura della stringa di input:
% 1) Cerca una 'p'
% 2) Cerca la prossima 'e', ricordando i caratteri prima in B_E
% 3) Cerca la prossima 'r', ricordando i caratteri prima in B_R
% 4) Verifica che il numero di caratteri di B_E sia uguale a B_R
% 5) Verifica che la 'p' trovata appartenga all'inizio di una parola
%    (controllando che il numero di caratteri prima della prima 'p'
%    sia minore o uguale al numero di caratteri tra 'p' - 'e' - 'r')
% Teoricamente andrebbe controllato che alla stessa distanza non ci
% siano altri caratteri, cercando uno spazio o in altri modi. Altrimenti
% parole come 'pero' potrebbero dare problemi

% Calcola il numero di parole cercando "per"
lunghezza_messaggio(L, N) :-
  append(B_P, X_P, L),
  append([p], A_P, X_P),
  append(B_E, X_E, A_P),
  append([e], A_E, X_E),
  append(B_R, X_R, A_E),
  append([r], _, X_R),
  length(B_E, NX),
  length(B_R, NX),
  length(B_P, L_B),
  L_B =< NX,
  N is NX + 1.


% Costruisci una stringa prendendo uno ogni N-1 caratteri, incluso il primo
get_string([], _, _, OLD, OLD).

get_string([' '|_], _, 0, OLD, OLD).

get_string([H|T], N, 0, OLD, NEW) :- 
  append(OLD, [H], ACC),
  N1 is N-1,
  get_string(T, N, N1, ACC, NEW).

get_string([_|T], N, N1, OLD, NEW) :- 
  N1 > 0,
  N2 is N1-1,
  get_string(T, N, N2, OLD, NEW).


% Estrai N stringhe di lunghezza N da una stringa come descritto in "get_string"
get_n_strings(_, _, 0, []).

get_n_strings(M_S, N, CURR, M_D) :-
  M_S = [_|T],
  get_string(M_S, N, 0, [], M_H),
  NEXT is CURR - 1,
  get_n_strings(T, N, NEXT, M_T),
  append(M_H, [' '|M_T], M_D).

% Rimuovi l'ultimo carattere (sarà uno spazio, pura estetica)
last_removed([], []).
last_removed(IN, OUT) :-
  reverse(IN, [_|T]),
  reverse(T, OUT).

% Determina il numero di parole, le estrae e ricompone il messaggio in stringa
decodifica_messaggio(M, M_D) :-
  string_chars(M, M_S),
  lunghezza_messaggio(M_S, N),
  get_n_strings(M_S, N, N, M_D_C1),
  last_removed(M_D_C1, M_D_C2),
  string_chars(M_D, M_D_C2),
  !.
