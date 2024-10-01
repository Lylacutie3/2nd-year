/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package activity2;

/**
 * Activity 2
 * 1.Product Class
 * @author lylajanevillanueva
 */
public class Product{
    
    private String productName; //its in final means it cant be change
    private double price;
    private int stock;
    static int totalProducts;
    private double sale;
       
    public Product(String pN, double p, int s){//constructor for product info
       this.productName = pN;
       this.price = p;
       this.stock = s;
       totalProducts += 1;
    }
    
    public boolean sellProduct(Order orders){//create a variable big as Order
        if(stock >= orders.getQuantity()){ 
            sale += price * orders.getQuantity(); //add to product sale
            return true;//its return true if it have enough order
        }else{
            System.out.println("Product is OUT OF STOCK");
            return false; //false when it cant accomodate orders
        }
    }

    public static int getTotalProduct(){
        return totalProducts;
    } 

    public double getPrice() {
        return price;
    } //get function is creted so the instance data can be acces in other class

    public int getStock() {
        return stock;
    }

    public void setStock(int stock) {
        this.stock = stock;
    }

    public String getProductName() {
        return productName;
    }
     
    //display the product's invetory sales of product
    public void Inventory(){  
        System.out.println("- - - - - - - INVENTORY - - - - - - -");
        if (stock == 0){
        System.out.println(productName + "\tOut of Stock");
        }else{
    System.out.println(productName + "\t\t" + stock);
        }
        System.out.println("Product Sales: $" + sale  + "\n");
    }
    
}
