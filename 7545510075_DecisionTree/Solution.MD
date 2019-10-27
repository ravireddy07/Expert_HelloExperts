
(a). Apply the DT algorithm to the training data provided in the dataset.

     
	1). Entropy of the given dataset data : Entropy(data)
	  
	    = -(1/2 log2(1/7) - 2/7 log2(2/7) − 2/7 log2(2/7) − 2/7 log2(2/7)) 
		
		= 1.950
	
	
	2). Consider attribute x = 'fever',
	
	       Values            H   I   S   B              Entropy
		
		data1(no)            *           *        [1/2, 0, 0, 1/2] -> 1
		data2(average)           *   *   *        [0, 1/3, 1/3, 1/3] -> 1.585
		data3(high)              *   *            [0, 1/2, 1/2, 0] -> 1
		
		-> Entropy(data/fever) = (2/7)*1 + (3/7)*1.585 + (2/7)*1
		                       = 1.251
							
	
	3). Consider attribute x = 'Vomiting',
	
	       Values            H   I   S   B                Entropy
		
		 data1(yes)                  *   **        [0, 0, 1/3, 2/3] -> 0.918
		 data2(no)           *   **  *             [1/4, 2/4, 1/4, 0] -> 1.5
		
		-> Entropy(data/Vomiting) = (3/7)*0.918 + (4/7)*1.5
		                          = 1.251
	
	
	4). Consider attribute x = 'Diarrhea',
	
	       Values            H   I   S   B              Entropy
		
		 data1(yes)                  **  **        [0, 0, 2/4, 2/4] -> 1
		 data2(no)           *   **               [1/3, 2/3, 0, 0] -> 0.918
		
		-> Entropy(data/Diarrhea) = (4/7)*1 + (3/7)*0.918
		                          = 0.965
								  
								  
	5). Consider attribute x = 'Shivering',
	
	       Values            H   I   S   B              Entropy
		
		 data1(yes)              *                   [0, 0, 1, ] -> 0
		 data2(no)           *   *   **  **     [1/6, 1/6, 2/6, 2/6] -> 1.918
		
		-> Entropy(data/Shivering) = (1/7)*0 + (6/7)*1.918
		                           = 1.644
	
	
	
	Choosing the attribute that maximizes the informatation gain,
	
	    1).   Fever:   Gain(data) = Ent(data) − Ent(data|fever) = 1.95 − 1.251 = 0.699
		
		2). Vomiting:  Gain(data) = Ent(data) − Ent(data|Vomiting) = 1.95 − 1.251 = 0.699
		
		3). Diarrhea:  Gain(data) = Ent(data) − Ent(data|Diarrhea) = 1.95 − 0.965 = 0.985
		
		4). Shivering: Gain(data) = Ent(data) − Ent(data|Shivering) = 1.95 − 1.644 = 0.306
		
		
		-> Attribute 'Diarrhea' is the most effective one, maximizing the information gain.
	
	
	Now split the data using attribute 'Diarrhea' and apply the algorithm recursively on subsets.
	

(b). Does the resulting decision tree provide a disjoint definition of the classes ?

    Answer) Yes, the resulting decision tree provides disjoint class definitions.