library(data.table)
ad <- fread('https://raw.githubusercontent.com/dataprofessor/data/master/weather-nominal-weka.csv')
ad
parent_p_0_t <- length(which(ad$play == 'no')) / length(ad$play)
parent_p_1_t <- length(which(ad$play == 'yes')) / length(ad$play)
gini_parent <- 1 - parent_p_0_t^2 - parent_p_1_t^2

library(tidyverse)
ad %>% count(outlook)
outlook_sunny <- subset(ad, outlook == 'sunny')
sunny_p_0_t <- length(which(outlook_sunny$play == 'no')) / length(outlook_sunny$play)
sunny_p_1_t <- length(which(outlook_sunny$play == 'yes')) / length(outlook_sunny$play)
gini_sunny <- 1 - sunny_p_0_t^2 - sunny_p_1_t^2
