append([], L, L).
append([H|L1], L2, [H|L3]) :-  append(L1, L2, L3).

reverse([],[]).
reverse([H|T],R):- reverse(T,L1), append(L1,[H],R).
