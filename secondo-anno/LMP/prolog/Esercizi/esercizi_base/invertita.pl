invertita([], []). %caso base: una lista vuota è uguale se invertita

invertita([H|T], [H1|T1]):-
    concatena(T1, [H], [H1|T1]), 
    invertita(T, [H1|T1]). 

    
 
