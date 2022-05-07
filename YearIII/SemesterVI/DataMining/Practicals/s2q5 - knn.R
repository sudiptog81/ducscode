library(rpart)
library(caret)
library(e1071)
library(class)

breastcancer <- read.csv("D:/ducscode/YearIII/SemesterVI/DataMining/Practicals/data/wdbc.data", header=F)
breastcancer

breastcancer$V2 <- as.factor(breastcancer$V2)

## using 75% train, 25% test

trainIndex <- createDataPartition(breastcancer$V2, p=0.75, list=FALSE)
trainIndex

dataTrain <- breastcancer[trainIndex,]
dataTrain

dataTest  <- breastcancer[-trainIndex,]
dataTest

predictions <- knn(dataTrain[-c(1,2)], dataTest[-c(1,2)], dataTrain$V2, k=5)
confusionMatrix(predictions, dataTest$V2)

acc_75_25 <- confusionMatrix(predictions, dataTest$V2)$overall[1] * 100

## using 66.6% train, 33.3% test

trainIndex <- createDataPartition(breastcancer$V2, p=2/3, list=FALSE)
trainIndex

dataTrain <- breastcancer[trainIndex,]
dataTrain

dataTest  <- breastcancer[-trainIndex,]
dataTest

predictions <- knn(dataTrain[-c(1,2)], dataTest[-c(1,2)], dataTrain$V2, k=5)
confusionMatrix(predictions, dataTest$V2)

acc_66_33 <- confusionMatrix(predictions, dataTest$V2)$overall[1] * 100

## using holdout method

trainIndex <- createDataPartition(breastcancer$V2, p=.8, list=FALSE)
trainIndex

dataTrain <- breastcancer[trainIndex,]
dataTrain

dataTest  <- breastcancer[-trainIndex,]
dataTest

predictions <- knn(dataTrain[-c(1,2)], dataTest[-c(1,2)], dataTrain$V2, k=5)
confusionMatrix(predictions, dataTest$V2)

acc_ho <- confusionMatrix(predictions, dataTest$V2)$overall[1] * 100

## using random subsampling

i <- 300
j <- 1
acc <- c()
for(i in 300:427)
{
  s <- sample(569, i)
  dataTrain <- breastcancer[s,]
  dataTest <- breastcancer[-s,]
  predictions <- knn(dataTrain[-c(1,2)], dataTest[-c(1,2)], dataTrain$V2, k=5)
  acc[j] <- confusionMatrix(predictions, dataTest$V2)$overall[1] * 100
  j <- j + 1
}
acc_rs <- mean(acc)

## using cv

trainIndex <- createDataPartition(breastcancer$V2, p=0.75, list=FALSE)
trainIndex

dataTrain <- breastcancer[trainIndex,]
dataTrain

dataTest  <- breastcancer[-trainIndex,]
dataTest

knnModel = train(V2 ~ .,
                dataTrain,
                method = 'knn',
                preProcess = c("center", "scale"),
                trControl=trainControl(method='cv', number=10))

knnModel$finalModel

predictions <- predict(knnModel, dataTest)
confusionMatrix(predictions, dataTest$V2)

acc_cv <- confusionMatrix(predictions, dataTest$V2)$overall[1] * 100

## standardize dataset

standardize = function(x) {
  z <- (x - mean(x)) / sd(x)
  return( z)
}

breastcancer[-c(1,2)] <- apply(breastcancer[-c(1,2)], 2, standardize)

trainIndex <- createDataPartition(breastcancer$V2, p=0.75, list=FALSE)
trainIndex

dataTrain <- breastcancer[trainIndex,]
dataTrain

dataTest  <- breastcancer[-trainIndex,]
dataTest

predictions <- knn(dataTrain[-c(1,2)], dataTest[-c(1,2)], dataTrain$V2, k=5)
confusionMatrix(predictions, dataTest$V2)

acc_std <- confusionMatrix(predictions, dataTest$V2)$overall[1] * 100

cat("Accuracy with train/test split of 75% and 25% is", acc_75_25, "%\n")
cat("Accuracy with train/test split of 66.6% and 33.3% is", acc_66_33, "%\n")
cat("Accuracy with holdout is", acc_ho, "%\n")
cat("Accuracy with random subsampling is", acc_rs, "%\n")
cat("Accuracy with cross validation is", acc_cv, "%\n")
cat("Accuracy with standardization is", acc_std, "%\n")

