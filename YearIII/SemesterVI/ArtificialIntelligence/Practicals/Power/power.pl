power(0, Power, 0) :- Power > 0.
power(Num, 0, 1) :- Num > 0.
power(Num, Power, Ans) :- Num > 0, Power > 0,
                          P1 is Power - 1,
                          power(Num, P1, A1),
                          Ans is A1 * Num.
