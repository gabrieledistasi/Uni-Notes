% Scrittura alternativa
% s(A1) --> x(A1, A2), y, {prova(A1, A2)}.
% x --> [a, b, c].
% y --> [a].


% 'S'--> 'B'.
% 'S' --> 'A', 'S'.
% 'A' --> [a].
% 'B' --> [b].


% Count A and B
% 'S'(NA, NB) --> 'B'(NA, NB).
% 'S'(NA, NB) --> 'A'(NA_A, NB_A), 'S'(NA_S, NB_S), {NA is NA_A + NA_S, NB is NB_A + NB_S}.
% 'A'(1, 0) --> [a].
% 'B'(0, 1) --> [b].


'S' --> [a], [b].
'S' --> [a], 'S', [b], 'A'.
'A' --> [c], [d].
'A' --> [c], 'A', [d].
