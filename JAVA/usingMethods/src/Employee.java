/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 * Activity 1: Using Methods
 * @author lylajanevillanueva
 */

public class Employee {
    //instance variable (this is use to object personalized)
    String name;
    int salary;
    String performanceRating;
    //static variable
    static double totalBonus = 0.0;
    
    //constructor
    public Employee(String nm, int sal, String pR){
        this.name = nm;
        this.salary = sal;
        this.performanceRating = pR;
    }
    //instance method to calculate bonus
    public double calculateBonus(){
        double bonus;
        //conditional statement for giving bonuses based on the performance
        bonus = switch (performanceRating) {
            case "high" -> salary * .10;
            case "good" -> salary * .05;
            default -> salary * .0;
        }; //use case here cause its shorter
        totalBonus += bonus; //keep track total bonus
        return bonus;
    }
    //static method
    public static double getTotalBonuses(){
        return totalBonus; //return total bonus
    }

    public static void main(String[] args){
        // initialized the object (make sure correct pR typings)
        Employee obj1 = new Employee("Lyla", 1000, "high"); 
        Employee obj2 = new Employee("Exe", 8000, "good");
        Employee obj3 = new Employee("Lance", 12000, "good");
        Employee obj4 = new Employee("Jer", 2000, "poor");
        
        //print names and calculate the bonus 
        System.out.println(obj1.name + " Bonus:" + obj1.calculateBonus());
        System.out.println(obj2.name + " Bonus:" + obj2.calculateBonus());
        System.out.println(obj3.name + " Bonus:" + obj3.calculateBonus());
        System.out.println(obj4.name + " Bonus:" + obj4.calculateBonus());
        
        //print of TotalBonus
        System.out.println("TotalBonus; " +Employee.getTotalBonuses());
        }
    }
    
