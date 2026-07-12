% cifra_rip(prima cifra, seconda cifra, riporto in, somma, riporto out)

cifra_rip('0', '0', '0', '0', '0').
cifra_rip('0', '0', '1', '1', '0').

cifra_rip('0', '1', '0', '1', '0').
cifra_rip('0', '1', '1', '2', '0').

cifra_rip('0', '2', '0', '2', '0').
cifra_rip('0', '2', '1', '0', '1').

cifra_rip('1', '0', '0', '1', '0').
cifra_rip('1', '0', '1', '2', '0').

cifra_rip('1', '1', '0', '2', '0').
cifra_rip('1', '1', '1', '0', '1').

cifra_rip('1', '2', '0', '0', '1').
cifra_rip('1', '2', '1', '1', '1').

cifra_rip('2', '0', '0', '2', '0').
cifra_rip('2', '0', '1', '0', '1').

cifra_rip('2', '1', '0', '0', '1').
cifra_rip('2', '1', '1', '1', '1').

cifra_rip('2', '2', '0', '1', '1').
cifra_rip('2', '2', '1', '2', '1').

  
somma_cifre([], [], '0', ACC, ['0'|ACC]).
somma_cifre([], [], '1', ACC, ['1'|ACC]).

somma_cifre([H1|T1], [], RIP_IN, ACC, Z) :-
  cifra_rip(H1, '0', RIP_IN, S, RIP_OUT), 
  somma_cifre(T1, [], RIP_OUT, [S|ACC], Z).

somma_cifre([], [H2|T2], RIP_IN, ACC, Z) :-
  cifra_rip(H2, '0', RIP_IN, S, RIP_OUT), 
  somma_cifre([], T2, RIP_OUT, [S|ACC], Z).

somma_cifre([H1|T1], [H2|T2], RIP_IN, ACC, Z) :-
  cifra_rip(H1, H2, RIP_IN, S, RIP_OUT), 
  somma_cifre(T1, T2, RIP_OUT, [S|ACC], Z).


somma(X, Y, Z) :-
  number_chars(X, CIFRE_PRIMO),
  number_chars(Y, CIFRE_SECONDO),
  reverse(CIFRE_PRIMO, C_1),
  reverse(CIFRE_SECONDO, C_2),
  somma_cifre(C_1, C_2, '0', [], Z_C),
  number_chars(Z, Z_C),
  !.

% La logica del primo ordine non può costruire una logica
% assiomatica dell'algebra, in quanto non c'è niente che
% ci permette di computare.

% LAMBDA ASTRAZIONI! WIIIIIIIIIIIIII
% (λx.f(x) M)
% Es: λx.x+5 3

% Beta riduzioni, prendo le applicazioni di prima e le "risolvo"
% L'argomento della funzione M deve essere sostituita dentro la
% funzione f al posto delle variabili.
%
% Es. di prima: Prendo M e lo metto al posto della X
% (λx f(x) M) = f(M)
% Es: λx.x+5 3 => 3 + 5
%
%
% Esempio di somma
% somma = λx.λy.x(y)
