% Fatti

maschio(alessandro).
maschio(thomas).
maschio(stefano).

femmina(lula).
femmina(alessia).
femmina(luana).

genitore(stefano, alessandro).
genitore(luana, alessandro).
genitore(stefano, thomas).
genitore(fiorello, stefano).
genitore(anselmo, luana).


% Predicati

figlio(X, Y) :-
  genitore(Y, X).

nonno(X, Y) :-
  genitore(X, Z), genitore(Z, Y).

fratello(X, Y) :-
  genitore(Z, X), genitore(Z, Y), X \= Y.
