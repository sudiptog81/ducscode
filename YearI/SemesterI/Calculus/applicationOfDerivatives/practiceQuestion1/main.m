pkg load symbolic

_ = @(x) ( x / ( ( x .^ 2 ) + 1 ) )

syms x

f = _(x) # f(x)

f_dash = simplify(diff(f)) # First Derivative of f(x)
solve(f_dash) # Solutions of f'(x) = 0
critical_points = function_handle(solve(f_dash))(:); # Critical Points
extrema = function_handle(subs(f, critical_points))(:); # Extrema

f_double_dash = simplify(diff(f_dash)) # Second Derivative of f(x)
solve(f_double_dash) # Solutions of f''(x) = 0
inflection_points = function_handle(solve(f_double_dash))(:); # Inflection Pts
inflections = function_handle(subs(f, inflection_points))(:);  # Inflections

fplot(function_handle(f), [-5 +5]) # Plot f(x)
set(findobj(gca, 'type', 'line'), 'LineWidth', 2, 'Color', 'Blue')
hold on
plot(critical_points, extrema, 'r.', ...
     "markersize", 20) # Plot Critical Pts
hold on
plot(inflection_points, inflections, 'm.', ...
		 "markersize", 20) # Plot Inflection Pts
hold on
title("f(x) from -5 to +5")
xlabel("x")
ylabel("f(x)")
hold on
legend("f(x)", "critical", "inflection")
hold on
for i = 1:size(critical_points)(:,1), # Plot Labels
	text(critical_points(i) + 0.3, extrema(i), sprintf("(%0.1f, %0.1f)", ...
	critical_points(i), extrema(i)))
end
hold on
for i = 1:size(inflection_points)(:,1), # Plot Labels
	text(inflection_points(i) + 0.3, inflections(i), sprintf("(%0.1f, %0.1f)", ...
	inflection_points(i), inflections(i)))
end
hold off