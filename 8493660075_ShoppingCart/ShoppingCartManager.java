import java.util.*;
import java.util.ArrayList;
import java.util.Scanner;

public class ShoppingCartManager {
    public static final Scanner KEYBOARD = new Scanner(System.in);

    public static void main(String[] args) {
        String customerName, currentDate;

        System.out.print("Enter Customer's Name:");
        customerName = KEYBOARD.nextLine().toString().trim();
        System.out.println();
        System.out.print("Enter Today's Date:");
        currentDate = KEYBOARD.nextLine().toString().trim();
        System.out.println();
        ShoppingCart cart = new ShoppingCart(customerName, currentDate);
        System.out.println("Customer Name:" + cart.getCustomerName());
        System.out.println("Today's Date:" + cart.getDate());
        printMenu(cart);

    }

    /*
     * Prints the menu, and builds the shopping cart * object passed in as parameter
     */
    private static void printMenu(ShoppingCart cart) {

        char choice = 'z';
        System.out.println("MENU:");
        System.out.println("a - Add Item To Cart");
        System.out.println("d - Remove Item from Cart");
        System.out.println("c - Change Item Quantity");
        System.out.println("i - Output Items' Description");
        System.out.println("o - Output Shopping Cart");
        System.out.println("q - Quit");
        System.out.print("Enter an option:");
        choice = KEYBOARD.nextLine().trim().charAt(0);
        while (choice != 'q') {
            if (choice != 'a' && choice != 'd' && choice != 'c' && choice != 'i' && choice != 'o') {
                // An invalid choice is made
                // Prompt for choice again
                System.out.print("Enter an option:");
                choice = KEYBOARD.nextLine().trim().charAt(0);
                continue;
            } else {
                switch (choice) {
                case 'o': {
                    System.out.println("OUTPUT SHOPPING CART");
                    cart.printTotal();
                    break;
                }
                case 'i': {
                    System.out.println("OUTPUT ITEMS' DESCRIPTIONS");
                    cart.printDescriptions();
                    break;
                }
                case 'a': {
                    String name, desc;
                    int price, qty;
                    System.out.println("ADD ITEM TO CART");
                    System.out.println("Enter Item name:");
                    name = KEYBOARD.nextLine().trim().toString();
                    System.out.println("Enter Item description:");
                    desc = KEYBOARD.nextLine().trim().toString();
                    System.out.println("Enter Item price:");
                    price = KEYBOARD.nextInt();
                    KEYBOARD.nextLine();
                    System.out.println("Enter Item quantity:");
                    qty = KEYBOARD.nextInt();
                    KEYBOARD.nextLine();
                    ItemToPurchase itemToPurchase = new ItemToPurchase(name, desc, qty, price);
                    cart.addItem(itemToPurchase);
                    break;
                }
                case 'd': {
                    String itemToRemove;
                    System.out.println("REMOVE ITEM FROM CART");
                    System.out.println("Enter name of item to remove:");
                    itemToRemove = KEYBOARD.nextLine().trim().toString();
                    cart.removeItem(itemToRemove);
                    break;
                }
                case 'c': {
                    String itemName;
                    int itemQty;
                    System.out.println("CHANGE ITEM QUANTITY");
                    System.out.println("Enter item name:");
                    itemName = KEYBOARD.nextLine().trim().toString();
                    System.out.println("Enter the new quantity:");
                    itemQty = KEYBOARD.nextInt();
                    KEYBOARD.nextLine();
                    ItemToPurchase item = new ItemToPurchase(itemName, "none", itemQty, 0);
                    cart.modifyItem(item);
                    break;
                }
                }
                System.out.print("Enter an option:");
                choice = KEYBOARD.nextLine().trim().charAt(0);
            }
        }
    }
}