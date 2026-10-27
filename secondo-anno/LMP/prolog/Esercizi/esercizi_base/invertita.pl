invertita([],[]). 

invertita([H|T], [H1|T1]):- 
    concatena(Y, [H], [H1|T1]), 
    invertita(Y, T), 
    !.