/**
 * Q12. WAP to impl sumlist(L, S) so that S is the sum of the given list L.
 * Written by Sudipto Ghosh (19/78003) 
 */

sumlist([], 0).                            % base case
sumlist([H|T], S) :- sumlist(T, S1),       % recursive case
                     S is H + S1.
