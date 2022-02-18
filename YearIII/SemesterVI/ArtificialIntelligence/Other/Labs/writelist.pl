writelist([]).
writelist([H|T]) :- write(H), nl, writelist(T).

writerevlist([]).
writerevlist([H|T]) :- writerevlist(T), write(H), nl.