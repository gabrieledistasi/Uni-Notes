a(a,b).
a(a, e).
a(f, e).
a(c, d).
a(b, c).
a(d, e).

path(X, Y):-
    a(X, Y).

path(X, Y):-
	a(X, Z),
    path(Z, Y).