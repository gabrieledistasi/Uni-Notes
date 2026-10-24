persona("alessio").
persona("gabriele"). 
persona("dario").

figlio("alessio", "dario").
figlio("gabriele", "dario").
figlio("dario", "filippo").

fratello(X, Y):-
    persona(X),
    figlio(X, L),
    figlio(Y, L).