/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package activity2;

/**
 * 2.Order Class
 * @author lylajanevillanueva
 */
public class Order {
    
    private int orderld;
    private Product product;
    private int quantity;
    static int orders = 1;
    static double totalSales;
    
    //constructor for orders
    public Order(Product nM, int q){
        this.product = nM;
        this.quantity =  q;
        orderld = orders;
    }
    
    //a receipt when order is process succesfully
    public void receipt(){
        System.out.println("======== Order Number: " + "ORD" + orderld + " ========");
        System.out.println("Successfully process the Order ");
        System.out.println(product.getProductName() + "\t\t" + quantity);
        System.out.println("$" + product.getPrice() + "\t\t" + "$" + quantity * product.getPrice() + "\n");
        
    }
    
    public void processOrder(){
        int stock = 0;
        if(product.sellProduct(this)){//this indicate the Orders current working 
            orders += 1;
            receipt();
            stock = product.getStock() - quantity;
            product.setStock(stock);
            totalSales += quantity * product.getPrice();
        }else{
            System.out.println("Insufficient Stock for this Order\n");
        }
    }

    public int getQuantity() {
        return quantity;
    }

    public static double getTotalSales() {
        return totalSales;
    }
    
    
}
