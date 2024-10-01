/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package activity2;

/**
 *3.Demonstrate creating multiple product processing orders.s and processing orders.
 * @author lylajanevillanueva
 */
public class Test {
    public static void main(String[] args){
        //declare a product name, price, and quantity
        Product product1 = new Product("Donut", 10, 5); 
        Product product2 = new Product("Chocolate", 50, 3);
        Product product3 = new Product("Coffee", 20, 10);
        
        //print the total product in the system
        System.out.println("Products Available: " + Product.getTotalProduct() + "\n");
        
        //process order and print the inventory to check accuracy
        //precess order product and quantity
        Order order1 = new Order(product1, 2);
        order1.processOrder();
        product1.Inventory();
        
        Order order2 = new Order(product2, 10);
        order2.processOrder();
        product2.Inventory();
        
        Order order3 = new Order(product3, 7);
        order3.processOrder();
        product3.Inventory();
        
        Order order4 = new Order(product1, 3);
        order4.processOrder();
        product1.Inventory();
        
        
        //print the total sales of all products
        System.out.println("Total Revenue: $" + Order.getTotalSales()  + "\n");
        
    }
}
