Training = c('d1','d2','d3','d4','d5','d6','d7')
fever = c('no', 'average','high','high','average','no','average')
Vomiting = c('no','no','no','yes','no','yes','yes')
Diarrhea = c('no','no','no','yes','yes','yes','yes')
Shivering = c('no','no','yes','no','no','no','no')
Classification = c('healthy(H)','influenza(I)','influenza(I)','Salmonella poisoning (S)','Salmonella poisoning (S)','Bowel inflammation (B)','Bowel inflammation (B)')

DataSet = data.frame(Training, fever, Vomiting, Diarrhea, Shivering, Classification)
DataSet

str(DataSet)
summary(DataSet)
is.na(DataSet)
(DataSet[!complete.cases(DataSet),])

# DATA CLEANING AND PREPARATION

data=DataSet
{
  count=0
  for(i in 1:ncol(data))
  {
    if((class(data[,i])=='numeric')||(class(data[,i])=='integer'))
    {
      if((min(data[,i],na.rm=T))==quantile(data[,i],0.25,na.rm=T)||quantile(data[,i],0.25,na.rm=T)==quantile(data[,i],0.5,na.rm=T)||quantile(data[,i],0.5,na.rm=T)==quantile(data[,i],0.75,na.rm=T)||quantile(data[,i],0.75,na.rm=T)==quantile(data[,i],1,na.rm=T))
      {
        data[,i]=factor(data[,i])
        print(paste(names(data[i]),": CHANGED TO FACTOR"))
        count=count+1
      }else{
        data[,i]=data[,i]
        print(paste(names(data[i]),": IS REAL NUMBER"))
      }
    }else if((class(data[,i])=='factor')){
      print("ALREADY IN FACTOR")
    }else{
      print("NOT NUMERIC")
    }
  }
  print(paste("**** NO. OF ATTRIBUTES ARE COVERTED TO FACTOR:",count ,"****"))
}
DataSet=data
summary(DataSet)


MODEL=rpart(Training~.,data=DataSet,method = "class")

