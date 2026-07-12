% Utilizzo:
% op(priorità, concatenabilità (vedi wiki), nome operatore)
:- op(110, xfx, mangia).
:- op(110, xfx, mangia2).
:- op(100, xfx, con).
:- op(100, xfy, di).


mario mangia panino.
dario mangia panino con mortadella.
giovanni mangia panino di dario.
claudio mangia panino di pane di segale.

% Scritture equivalenti:
% mangia("mario", "panino").
% mangia("dario", "panino con mortadella").
% mangia("giovanni", "panino di dario").

X mangia2 Y :-
  X mangia Y.

X mangia2 Y :-
  X mangia Y con _.

X mangia2 Y :-
  X mangia Y di _.

