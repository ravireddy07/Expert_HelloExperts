import java.util.*;
import java.util.ArrayList;
import java.util.Scanner;
 
class ShoppingCart {
   private String customerName;
   private String currentDate;
   private ArrayList<ItemToPurchase> cartItems = new ArrayList<>();
 
   /*Default Constructor */
   public ShoppingCart() {
       customerName = "none";
       currentDate = "January 1, 2016";
       cartItems = new ArrayList<>();
   }
   /* Parameterised constructor */
   public ShoppingCart(String customerName, String currentDate) {
       this.customerName = customerName;
       this.currentDate = currentDate;
       cartItems = new ArrayList<>();
   }
   /* Adds @param to the cartItems list */
   public void addItem(ItemToPurchase itemToPurchase) {
       if (cartItems != null) {
           cartItems.add(itemToPurchase);
       }
   }
   /* Removes item with itemName @param from the cartItems list */
   public void removeItem(String itemName) {
       if (cartItems != null) {
           for (ItemToPurchase itemToPurchase : cartItems) {
               if (itemToPurchase.getItemName().equals(itemName)) {
                   cartItems.remove(itemToPurchase);
                   return;
               }
               // Control reaching here, signifies that item was not present in cart
               System.out.println("Item not found in cart. Nothing removed.");
           }
       }
   }
   /* Modifies an item's description, price and quantity if the item is present in cart */
   public void modifyItem(ItemToPurchase itemToPurchaseToPurchase) {
       boolean itemFound = false;
       if (cartItems != null) {
           for (ItemToPurchase item : cartItems) {
               if (item.getItemName().equals(itemToPurchaseToPurchase.getItemName())) {
                   itemFound = true;
                   // Checking if itemToPurchaseToPurchase has default value for description
                   if (!itemToPurchaseToPurchase.getDescription().equals("none")) {
                       item.setDescription(itemToPurchaseToPurchase.getDescription());
                   }
                   // Checking if itemToPurchaseToPurchase has default value for quantity
                   if (itemToPurchaseToPurchase.getItemQuantity() != 0) {
                       item.setItemQuantity(itemToPurchaseToPurchase.getItemQuantity());
                   } // Checking if itemToPurchaseToPurchase has default value for price
                   if (itemToPurchaseToPurchase.getItemPrice() != 0) {
                       item.setItemPrice(itemToPurchaseToPurchase.getItemPrice());
                   }
               }
           }
           if (itemFound != true) {
               System.out.println("Item not found in cart. Nothing modified");
           }
       }
   }
   /* Returns the quantity of all items in cart */
   public int getNumItemsInCart() {
       int totalQuantity = 0;
       if (cartItems != null) {
           for (ItemToPurchase itemToPurchase : cartItems) {
               totalQuantity += itemToPurchase.getItemQuantity();
           }
       }
       return totalQuantity;
   }
   /* Determines and returns the total cost of items in cart */
   public int getCostOfCart() {
       int totalCostOfCart = 0;
       if (cartItems != null) {
           for (ItemToPurchase itemToPurchase : cartItems) {
               totalCostOfCart += (itemToPurchase.getItemQuantity() * itemToPurchase.getItemPrice());
           }
       }
       return totalCostOfCart;
   }
 /* Prints total of objects in cart */
   public void printTotal() {
       if (cartItems == null || cartItems.size() == 0) {
           System.out.println("SHOPPING CART IS EMPTY.");
           return;
       }
       System.out.println(customerName + "\'s" + " Shopping Cart - " + currentDate);
       System.out.println("Number of Items: " + getNumItemsInCart());
 
       for (ItemToPurchase itemToPurchase : cartItems) {
           itemToPurchase.printItemCost();
       }
       System.out.println("Total: $" + getCostOfCart());
   }
   /* Prints each item's description */
   public void printDescriptions() {
       if (cartItems == null || cartItems.size() == 0) {
           System.out.println("SHOPPING CART IS EMPTY.");
           return;
       }
       System.out.println(customerName + "\'s" + " Shopping Cart - " + currentDate);
       System.out.println("Item Descriptions");
       for (ItemToPurchase itemToPurchase : cartItems) {
           itemToPurchase.printItemDescription();
       }
   }
   /* Accessor method for customer name */
   public String getCustomerName() {
       return customerName;
   }
   /* Accessor method for current date */
   public String getDate() {
       return currentDate;
   }
}