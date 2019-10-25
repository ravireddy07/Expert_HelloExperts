taxRate = 0.2
standardDeduction = 10000
dependentDeduction = 2000
try: income = raw_input("Enter your Income: ")
except NameError: pass
if income<2000:
  print("Income tax is not payable on income.")
else :
  try: dependents = raw_input("Enter number of dependants: ")
  except NameError: pass
  rawIncome = income-standardDeduction-(dependentDeduction*dependents)
  incomeTax = rawIncome*taxRate
  grossIncome = income-incomeTax
  print("Income tax: ${}".format(incomeTax))
  print("The Gross Income after Tax: ${}".format(grossIncome))
