library(arules) 
library(arulesViz)

data_trans <- read.transactions("D:/ducscode/YearIII/SemesterVI/DataMining/Practicals/data/bakery/1000-out1.csv",sep=",", cols = 1, rm.duplicates = FALSE) 

id <- c(0:49)
name <- factor(c("Chocolate Cake","Lemon Cake","Casino Cake","Opera Cake","Strawberry Cake","Truffle Cake","Chocolate Eclair","Coffee Eclair","Vanilla Eclair","Napoleon Cake","Almond Tart","Apple Pie","Apple Tart","Apricot Tart","Berry Tart","Blackberry Tart","Blueberry Tart","Chocolate Tart","Cherry Tart","Lemon Tart","Pecan Tart","Ganache Cookie","Gongolals Cookie","Raspberry Cookie","Lemon Cookie","Chocolate Meringue","Vanilla Meringue","Marzipan Cookie","Tuile Cookie","Walnut Cookie","Almond Croissant","Apple Croissant","Apricot Croissant","Cheese Croissant","Chocolate Croissant","Apricot Danish","Apple Dansh","Almond Twist","Almond Bear Claw","Blueberry Danish","Lemonade","Raspberry Lemonade","Orange Juice","Green Tea","Bottled Water","Hot Coffee","Chocolate Coffee","Vanilla Frappucino","Cherry Soda","Single Espresso"))
goods_name <- data.frame(id, name)

data_trans@itemInfo$labels <- goods_name$name[match(data_trans@itemInfo$labels,goods_name$id)] 

itemFrequencyPlot(data_trans,topN=10,type="absolute")

# 4.1
# Set minimum support to 0.005 (50%) and confidence to 75%
rules.all <- apriori(data_trans ,list(supp = 0.005, conf = 0.75)) 
summary(rules.all) 

# Sort the rules by confidence
rules_sort<-sort(rules.all, by="confidence", decreasing=TRUE) 
inspect(rules_sort)
plot(rules.all)

# 4.2
# Set minimum support to 0.006 (60%) and confidence to 60%
rules.all <- apriori(data_trans ,list(supp = 0.006, conf = 0.60)) 
summary(rules.all) 

# Sort the rules by confidence
rules_sort<-sort(rules.all, by="confidence", decreasing=TRUE) 
inspect(rules_sort)
plot(rules.all)
