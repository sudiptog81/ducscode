library(caret)
library(e1071)
library(caTools)

df <- read.csv('https://raw.githubusercontent.com/codebasics/py/master/ML/14_naive_bayes/titanic.csv')
head(df)
summary(df)

df <- df[c('Pclass', 'Sex', 'Age', 'Fare', 'Survived')]
colSums(is.na(df))
df$Age[is.na(df$Age)] <- mean(df$Age, na.rm = TRUE)
colSums(is.na(df))
summary(df)
df$Sex <- as.factor(df$Sex)
summary(df)

head(df)
split <- sample.split(df, SplitRatio = 0.7)
train_nb <- subset(df, split == TRUE)
test_nb <- subset(df, split == FALSE)

model_nb <- naiveBayes(as.factor(Survived) ~ ., train_nb)
y_pred <- predict(model_nb, test_nb)

cm <- table(test_nb$Survived, y_pred)
confusionMatrix(cm)

