%Scrivi elimina(X, L, R), dove R è la lista ottenuta 
%eliminando una sola occorrenza di X da L.

elimina(X, L, R):-

    concatena(Prima, [X|Dopo], L), 
    concatena(Prima, Dopo, R). 







% come voglio che sia fatta la soluzione? 
% dato X = 1, L = [1, 2, 3, 4, 5, 6, 7], R = [2, 3, 4, 5, 6, 7]
% oppure, L = [2, 3, 4, 1, 23, 4, 5,56], R = [2, 3, 4, 23, 4, 5, 56]