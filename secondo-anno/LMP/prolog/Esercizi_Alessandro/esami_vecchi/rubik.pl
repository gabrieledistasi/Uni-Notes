% [
% Front [TopLeft, TopRight, BottomLeft, BottomRight],
% Back [TopLeft, TopRight, BottomLeft, BottomRight],
% Top [TopLeft, TopRight, BottomLeft, BottomRight],
% Bottom [TopLeft, TopRight, BottomLeft, BottomRight],
% Left [TopLeft, TopRight, BottomLeft, BottomRight],
% Right[TopLeft, TopRight, BottomLeft, BottomRight] 
% ]

% [[Giallo, Giallo, Giallo, Giallo],
% [Bianco, Bianco, Bianco, Bianco],
% [Blu, Blu, Blu, Blu],
% [Verde, Verde, Verde, Verde],
% [Rosso, Rosso, Rosso, Rosso],
% [Arancio, Arancio, Arancio, Arancio]]


configurazione_base(Front, Back, Top, Bottom, Left, Right) :-
  Front = [Giallo, Giallo, Giallo, Giallo],
  Back = [Bianco, Bianco, Bianco, Bianco],
  Top = [Blu, Blu, Blu, Blu],
  Bottom = [Verde, Verde, Verde, Verde],
  Left = [Rosso, Rosso, Rosso, Rosso],
  Right = [Arancio, Arancio, Arancio, Arancio].


risolto(Stato) :-
  orientamento(Stato, [Front, Back, Top, Bottom, Left, Right]),
  configurazione_base(Front, Back, Top, Bottom, Left, Right).


ruota_x(cubo(F, R, S, I, Sin, D), cubo(S, I, R, F, Sin, D)).
ruota_y(cubo(F, R, S, I, Sin, D), cubo(D, Sin, S, I, F, R)).
ruota_z(cubo(F, R, S, I, Sin, D), cubo(F, R, Sin, D, I, S)).

inv_ruota_x(C, R) :- ruota_x(C, C1), ruota_x(C1, C2), ruota_x(C2, R).
inv_ruota_y(C, R) :- ruota_y(C, C1), ruota_y(C1, C2), ruota_y(C2, R).
inv_ruota_z(C, R) :- ruota_z(C, C1), ruota_z(C1, C2), ruota_z(C2, R).


orientamento(Cubo, Cubo).
orientamento(Cubo, Risultato) :-
  ruota_x(Cubo, Next),
  orientamento(Next, Risultato).
orientamento(Cubo, Risultato) :-
  ruota_y(Cubo, Next),
  orientamento(Next, Risultato).
orientamento(Cubo, Risultato) :-
  ruota_z(Cubo, Next),
  orientamento(Next, Risultato).


% TOP, BASE PER TUTTI
rotazione_top_orario(
[
  [Front_TL, Front_TR, Front_BR, Front_BL],
  [Back_TL, Back_TR, Back_BR, Back_BL],
  [Top_TL, Top_TR, Top_BR, Top_BL],
  [Bottom_TL, Bottom_TR, Bottom_BR, Bottom_BL],
  [Left_TL, Left_TR, Left_BR, Left_BL],
  [Right_TL, Right_TR, Right_BR, Right_BL]
],
[
  [Right_TL, Right_TR, Front_BR, Front_BL],
  [Left_TL, Left_TR, Back_BR, Back_BL],
  [Top_BL, Top_TL, Top_TR, Top_BR],
  [Bottom_TL, Bottom_TR, Bottom_BR, Bottom_BL],
  [Front_TL, Front_TR, Left_BR, Left_BL],
  [Back_TL, Back_TR, Right_BR, Right_BL]
]
).

rotazione_top_antiorario(CuboIn, CuboOut) :-
  rotazione_top_orario(CuboOut, CuboIn).

% FRONT
rotazione_front_orario(C, R) :- ruota_x(C, C1), rotazione_top_orario(C1, C2), inv_ruota_x(C2, R).
rotazione_front_antiorario(C, R) :- ruota_x(C, C1), rotazione_top_antiorario(C1, C2), inv_ruota_x(C2, R).

% BACK
rotazione_back_orario(C, R) :- ruota_x(C, C1), ruota_x(C1, C2), rotazione_top_orario(C2, C3), inv_ruota_x(C3, C4), inv_ruota_x(C4, R).
rotazione_back_antiorario(C, R) :- ruota_x(C, C1), ruota_x(C1, C2), rotazione_top_antiorario(C2, C3), inv_ruota_x(C3, C4), inv_ruota_x(C4, R).

% LEFT
rotazione_left_orario(C, R) :- ruota_y(C, C1), rotazione_top_orario(C1, C2), inv_ruota_y(C2, R).
rotazione_left_antiorario(C, R) :- ruota_y(C, C1), rotazione_top_antiorario(C1, C2), inv_ruota_y(C2, R).

% RIGHT
rotazione_right_orario(C, R) :- inv_ruota_y(C, C1), rotazione_top_orario(C1, C2), ruota_y(C2, R).
rotazione_right_antiorario(C, R) :- inv_ruota_y(C, C1), rotazione_top_antiorario(C1, C2), ruota_y(C2, R).

% BOTTOM
rotazione_bottom_orario(C, R) :- inv_ruota_x(C, C1), rotazione_top_orario(C1, C2), ruota_x(C2, R).
rotazione_bottom_antiorario(C, R) :- inv_ruota_x(C, C1), rotazione_top_antiorario(C1, C2), ruota_x(C2, R).
