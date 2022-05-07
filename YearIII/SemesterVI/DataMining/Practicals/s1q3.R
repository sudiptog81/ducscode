# S1 Q3

# install.packages('rattle.data')

standardize = function(x) {
  z <- (x - mean(x)) / sd(x)
  return( z)
}

print_dataframe = function(df) {
  for (attr in colnames(df)) {
    cat("Attribute:", attr)
    cat("\n\tMean:", mean(df[, attr]))
    cat("\n\tStd. Dev.:", sd(df[, attr]))
    cat("\n\n")
  }
}

library(rattle.data)
View(wine)

wine_data <- wine[-c(1, 1)]
wine_data

print_dataframe(wine_data)

wine_data <- apply(wine_data, 2, standardize)

print_dataframe(wine_data)

# On IRIS Dataset
library(datasets)
data(iris)

iris_data <- iris[-c(1, 5)]
iris_data

print_dataframe(iris_data)

iris_data <- apply(iris_data, 2, standardize)

print_dataframe(iris_data)

