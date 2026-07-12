% verbo(gatto, mangia, cane).
% verbo(cane, mangia, topo).
% verbo(gatto, mangiare, cane).
% verbo(cane, mangiare, topo).
%
% lemma(X, X).
% lemma(mangia, mangiare).
%
% verbo_soggetto_oggetto(VERBO, SOGGETTO, OGGETTO) :-
%   lemma(V_F, VERBO),
%   verbo(SOGGETTO, V_F, OGGETTO), 
%   !.

% ===================================================

% nodo(id, parola)
n(1, il).
n(2, gatto).
n(3, mangia).
n(4, il).
n(5, cane).
n(6, mentre).
n(7, il).
n(8, cane).
n(9, mangia).
n(10, il).
n(11, topo).

lemma(X, X).
lemma(mangia, mangiare).

% ID1 mod ID2
e(1, 2, mod).
e(3, 2, sog).
e(3, 5, ogg).
e(3, 9, mod).
e(5, 4, mod).
e(8, 7, mod).
e(9, 8, sog).
e(9, 11, ogg).
e(9, 6, mod).
e(11, 10, mod).

verbo_soggetto_oggetto(VERBO, SOGGETTO, OGGETTO) :-
  lemma(V_F, VERBO),
  n(ID_V, V_F),
  n(ID_S, SOGGETTO),
  n(ID_O, OGGETTO),
  e(ID_V, ID_S, sog),
  e(ID_V, ID_O, ogg),
  !.
