schedule(Ta, A1, A2, Tb, B1, B2, Td, D1, D2) :- 
	session(Ta, artificial_intelligence, A1, A2),
	session(Tb, bioinformatics, B1, B2),
	session(Td, databases, D1, D2),
	no_conflict(Ta, A1, A2, Tb, B1, B2),
	no_conflict(Ta, A1, A2, Td, D1, D2),
	no_conflict(Tb, B1, B2, Td, D1, D2).

session(Time, Topic, P1, P2) :-
	time(Time),
	expert(Topic, P1),
	expert(Topic, P2),
	P1 \= P2.

no_conflict(Time1, _, _, Time2, _, _) :-
	Time1 \= Time2.

no_conflict(Time, P1, P2, Time, Q1, Q2) :-
	P1 \= Q1, P1 \= Q2,
	P2 \= Q1, P2 \= Q2.

time(morning).
time(afternoon).

expert(bioinformatics, barbara).
expert(bioinformatics, ben).
expert(artificial_intelligence, adam).
expert(artificial_intelligence, ann).
expert(artificial_intelligence, barbara).
expert(databases, adam).
expert(databases, danny).
