edge(a, b).
edge(a, d).
edge(b, a).
edge(b, c).
edge(d, c).
edge(c, e).


path_prof(A,B,[A,B]):-
    edge(A,B).
path_prof(A,B,[A|P]):-
    e(A,C),
    path(C,B,P),
    ((member(A,P),!,fail);true).


path(A,B,Path) :-
       travel(A,B,[A],Q), 
       reverse(Q,Path).

travel(A,B,P,[B|P]) :- 
       edge(A,B).
travel(A,B,Visited,Path) :-
       edge(A,C),           
       C \== B,
       \+member(C,Visited),
       travel(C,B,[C|Visited],Path).  
