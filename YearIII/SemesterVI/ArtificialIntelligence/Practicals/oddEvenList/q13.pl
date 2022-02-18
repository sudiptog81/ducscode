evenlength([]) :- !.
evenlength([_|T]) :- oddlength(T).
oddlength([_]) :- !.
oddlength([_|T]) :- evenlength(T).
