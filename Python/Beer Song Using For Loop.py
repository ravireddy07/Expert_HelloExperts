for quant in range(99,0,-1):
   if quant >1:
       print(quant,' Bottles of Beer on the Wall,', quant,"Bottles of Beer")
       if quant >2:
           suffix=str(quant)+ "bottles of beer on the wall"
       else:
           suffix=" 1 bottle of beer on the wall"
   elif quant ==1:
       print(" 1 bottle of beer on the Wall, 1 bottle of beer")
       suffix="No more beer on the wall"

   print("Take one more down and pass it around", suffix)
   print("---")
