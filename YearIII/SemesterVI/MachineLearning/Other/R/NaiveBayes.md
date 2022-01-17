Naive Bayes Classifier
================

### Importing Libraries

``` r
library(caret)
library(e1071)
library(caTools)
```

### Preprocessing

``` r
df <- read.csv('https://raw.githubusercontent.com/codebasics/py/master/ML/14_naive_bayes/titanic.csv')
head(df)
```

    ##   PassengerId                                                Name Pclass    Sex Age SibSp
    ## 1           1                             Braund, Mr. Owen Harris      3   male  22     1
    ## 2           2 Cumings, Mrs. John Bradley (Florence Briggs Thayer)      1 female  38     1
    ## 3           3                              Heikkinen, Miss. Laina      3 female  26     0
    ## 4           4        Futrelle, Mrs. Jacques Heath (Lily May Peel)      1 female  35     1
    ## 5           5                            Allen, Mr. William Henry      3   male  35     0
    ## 6           6                                    Moran, Mr. James      3   male  NA     0
    ##   Parch           Ticket    Fare Cabin Embarked Survived
    ## 1     0        A/5 21171  7.2500              S        0
    ## 2     0         PC 17599 71.2833   C85        C        1
    ## 3     0 STON/O2. 3101282  7.9250              S        1
    ## 4     0           113803 53.1000  C123        S        1
    ## 5     0           373450  8.0500              S        0
    ## 6     0           330877  8.4583              Q        0

``` r
summary(df)
```

    ##   PassengerId        Name               Pclass          Sex                 Age       
    ##  Min.   :  1.0   Length:891         Min.   :1.000   Length:891         Min.   : 0.42  
    ##  1st Qu.:223.5   Class :character   1st Qu.:2.000   Class :character   1st Qu.:20.12  
    ##  Median :446.0   Mode  :character   Median :3.000   Mode  :character   Median :28.00  
    ##  Mean   :446.0                      Mean   :2.309                      Mean   :29.70  
    ##  3rd Qu.:668.5                      3rd Qu.:3.000                      3rd Qu.:38.00  
    ##  Max.   :891.0                      Max.   :3.000                      Max.   :80.00  
    ##                                                                        NA's   :177    
    ##      SibSp           Parch           Ticket               Fare           Cabin          
    ##  Min.   :0.000   Min.   :0.0000   Length:891         Min.   :  0.00   Length:891        
    ##  1st Qu.:0.000   1st Qu.:0.0000   Class :character   1st Qu.:  7.91   Class :character  
    ##  Median :0.000   Median :0.0000   Mode  :character   Median : 14.45   Mode  :character  
    ##  Mean   :0.523   Mean   :0.3816                      Mean   : 32.20                     
    ##  3rd Qu.:1.000   3rd Qu.:0.0000                      3rd Qu.: 31.00                     
    ##  Max.   :8.000   Max.   :6.0000                      Max.   :512.33                     
    ##                                                                                         
    ##    Embarked            Survived     
    ##  Length:891         Min.   :0.0000  
    ##  Class :character   1st Qu.:0.0000  
    ##  Mode  :character   Median :0.0000  
    ##                     Mean   :0.3838  
    ##                     3rd Qu.:1.0000  
    ##                     Max.   :1.0000  
    ## 

``` r
df <- df[c('Pclass', 'Sex', 'Age', 'Fare', 'Survived')]
head(df)
```

    ##   Pclass    Sex Age    Fare Survived
    ## 1      3   male  22  7.2500        0
    ## 2      1 female  38 71.2833        1
    ## 3      3 female  26  7.9250        1
    ## 4      1 female  35 53.1000        1
    ## 5      3   male  35  8.0500        0
    ## 6      3   male  NA  8.4583        0

``` r
colSums(is.na(df))
```

    ##   Pclass      Sex      Age     Fare Survived 
    ##        0        0      177        0        0

``` r
df$Age[is.na(df$Age)] <- mean(df$Age, na.rm = TRUE)
colSums(is.na(df))
```

    ##   Pclass      Sex      Age     Fare Survived 
    ##        0        0        0        0        0

``` r
summary(df)
```

    ##      Pclass          Sex                 Age             Fare           Survived     
    ##  Min.   :1.000   Length:891         Min.   : 0.42   Min.   :  0.00   Min.   :0.0000  
    ##  1st Qu.:2.000   Class :character   1st Qu.:22.00   1st Qu.:  7.91   1st Qu.:0.0000  
    ##  Median :3.000   Mode  :character   Median :29.70   Median : 14.45   Median :0.0000  
    ##  Mean   :2.309                      Mean   :29.70   Mean   : 32.20   Mean   :0.3838  
    ##  3rd Qu.:3.000                      3rd Qu.:35.00   3rd Qu.: 31.00   3rd Qu.:1.0000  
    ##  Max.   :3.000                      Max.   :80.00   Max.   :512.33   Max.   :1.0000

``` r
df$Sex <- as.factor(df$Sex)
summary(df)
```

    ##      Pclass          Sex           Age             Fare           Survived     
    ##  Min.   :1.000   female:314   Min.   : 0.42   Min.   :  0.00   Min.   :0.0000  
    ##  1st Qu.:2.000   male  :577   1st Qu.:22.00   1st Qu.:  7.91   1st Qu.:0.0000  
    ##  Median :3.000                Median :29.70   Median : 14.45   Median :0.0000  
    ##  Mean   :2.309                Mean   :29.70   Mean   : 32.20   Mean   :0.3838  
    ##  3rd Qu.:3.000                3rd Qu.:35.00   3rd Qu.: 31.00   3rd Qu.:1.0000  
    ##  Max.   :3.000                Max.   :80.00   Max.   :512.33   Max.   :1.0000

### Modelling

``` r
split <- sample.split(df, SplitRatio = 0.7)
train_nb <- subset(df, split == TRUE)
test_nb <- subset(df, split == FALSE)
```

``` r
model_nb <- naiveBayes(as.factor(Survived) ~ ., train_nb)
model_nb
```

    ## 
    ## Naive Bayes Classifier for Discrete Predictors
    ## 
    ## Call:
    ## naiveBayes.default(x = X, y = Y, laplace = laplace)
    ## 
    ## A-priori probabilities:
    ## Y
    ##         0         1 
    ## 0.6168224 0.3831776 
    ## 
    ## Conditional probabilities:
    ##    Pclass
    ## Y       [,1]      [,2]
    ##   0 2.578788 0.7112887
    ##   1 1.931707 0.8373742
    ## 
    ##    Sex
    ## Y      female      male
    ##   0 0.1151515 0.8848485
    ##   1 0.7170732 0.2829268
    ## 
    ##    Age
    ## Y       [,1]     [,2]
    ##   0 30.35705 11.94543
    ##   1 28.39388 14.50010
    ## 
    ##    Fare
    ## Y       [,1]     [,2]
    ##   0 20.48918 27.21366
    ##   1 48.98927 61.47364

``` r
y_pred <- predict(model_nb, test_nb)
cm <- table(test_nb$Survived, y_pred)
confusionMatrix(cm)
```

    ## Confusion Matrix and Statistics
    ## 
    ##    y_pred
    ##       0   1
    ##   0 185  34
    ##   1  70  67
    ##                                           
    ##                Accuracy : 0.7079          
    ##                  95% CI : (0.6576, 0.7546)
    ##     No Information Rate : 0.7163          
    ##     P-Value [Acc > NIR] : 0.6621910       
    ##                                           
    ##                   Kappa : 0.3511          
    ##                                           
    ##  Mcnemar's Test P-Value : 0.0005991       
    ##                                           
    ##             Sensitivity : 0.7255          
    ##             Specificity : 0.6634          
    ##          Pos Pred Value : 0.8447          
    ##          Neg Pred Value : 0.4891          
    ##              Prevalence : 0.7163          
    ##          Detection Rate : 0.5197          
    ##    Detection Prevalence : 0.6152          
    ##       Balanced Accuracy : 0.6944          
    ##                                           
    ##        'Positive' Class : 0               
    ## 
