swap_first_last(S, S_F_L) :-
  S = [H1|T],
  reverse(T, T_R),
  T_R = [H2|T1],
  reverse(T1, T_T_R),
  append([H2|T_T_R], [H1], S_F_L).


get_reverse_1([], []).
get_reverse_1([H|T], [HR|TR]) :-
  string_chars(H, H_SPLIT),
  reverse(H_SPLIT, HR_C),
  string_chars(HR, HR_C),
  get_reverse_1(T, TR).

get_reverse_2([], []).
get_reverse_2([H|T], [HR|TR]) :-
  string_chars(H, H_SPLIT),
  swap_first_last(H_SPLIT, HR_C),
  string_chars(HR, HR_C),
  get_reverse_2(T, TR).


codificatore(S, S_C) :-
  split_string(S, " ", "", S_SPLIT),
  get_reverse_1(S_SPLIT, S_R_SPLIT), 
  atomic_list_concat(['1)'|S_R_SPLIT], ' ', S_C).

codificatore(S, S_C) :-
  split_string(S, " ", "", S_SPLIT),
  get_reverse_1(S_SPLIT, S_1),
  get_reverse_2(S_1, S_R_SPLIT), 
  atomic_list_concat(['2)'|S_R_SPLIT], ' ', S_C).

codificatore(S, S_C) :-
  split_string(S, " ", "", S_SPLIT),
  get_reverse_1(S_SPLIT, S_1),
  get_reverse_2(S_1, S_R_SPLIT), 
  swap_first_last(S_R_SPLIT, S_R_SWAP),
  atomic_list_concat(['3)'|S_R_SWAP], ' ', S_C).


decodificatore(S, S_D) :-
  codificatore(S, S_D).
