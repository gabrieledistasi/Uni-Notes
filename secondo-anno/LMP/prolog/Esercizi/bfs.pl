edge(a, b).
edge(a, d).
edge(b, a).
edge(b, c).
edge(d, c).
edge(c, e).

next_frontier_from_node([H|R],NF_N):-
    setof([N,H|R],e(H,N),NF_N).
 
next_frontier([],[]).
next_frontier([H|R],N):-
    next_frontier_from_node(H,NH),
    next_frontier(R,NN),
    append(NH,NN,N).
 
path(A,B,PATH):-
	next_frontier_deep([[A]],B,PATH).
 
next_frontier_deep(F,NodoGoal,[NodoGoal|R]):-    
   next_frontier(F,PATHS),
   member([NodoGoal|R],PATHS).
 
next_frontier_deep(F,NodoGoal,PATH):-    
   next_frontier(F,PATHS),
   next_frontier_deep(PATHS,NodoGoal,PATH).
