/**
 * Q9. WAP to impl conc(L1, L2, L3) where L2 is the list to be appended with L1 to get the resulted list L3.
 * Written by Sudipto Ghosh (19/78003) 
 */

conc([], L, L) :- !.                       % base case
conc([H|T], L2, [H|R]) :- conc(T, L2, R).  % recursive case