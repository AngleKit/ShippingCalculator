# ShippingCalculator
 Calculator for an imaginary shipping sytem to the USA, Canada, and  Australia

Prompt and retrieve the following input from the user (through the console):
    Item name
    Is the item fragile (add in $2.00 if the item is fragile)
    The order total (without shipping)
    The destination to which the item will be shipped (USA, Canada, Australia)  

Then determine the calculations to perform:

    Ship to USA
     less than $50 = $6.00
     $50.01 to $100 = $9.00
     $100.01 to $150 = $12.00
     over $150 = free

    Ship to Canada
     less than $50 = $8.00
     $50.01 to $100 = $12.00
     $100.01 to $150 = $15.00
     over $150 = free

    Ship to Australia
     less than $50 = $10.00
     $50.01 to $100 = $14.00
     $100.01 to $150 = $17.00
     over $150 = free

    If item is labelled "Fragile" then adds $2.00 to total cost

Program also exits out if incorrect imformation is entered for the shipping  desitnation or if the item is fragile. 

Program will print out the item (in uppercase), overall price of shipping, destination (in uppercase), complete cost of item and shipping, and a thank you statment
