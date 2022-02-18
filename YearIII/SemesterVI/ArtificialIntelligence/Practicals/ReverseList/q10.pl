/**
 * Q10. WAP to impl reverse(L, R) where list L is the original and R is the reversed list.
 * Written by Sudipto Ghosh (19/78003) 
 */

conc([], L, L) :- !.                       % base case
conc([H|T], L2, [H|R]) :- conc(T, L2, R).  % recursive case

reverse([], []) :- !.                      % base case
reverse([H|T], R) :- reverse(T, RT),       % recursive case
                     conc(RT, [H], R). 
