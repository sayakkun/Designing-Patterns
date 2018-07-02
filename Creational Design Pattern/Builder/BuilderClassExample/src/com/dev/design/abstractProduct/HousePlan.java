/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.dev.design.abstractProduct;

/**
 *
 * @author admin
 */
/*Now, HousePlan is an interface which will be implemented by Concrete Product Class*/
/*We could have directly a ConcreteProduct Class, still why do we choose interface
Because, one of the good designing praactice is Code For/Program to an interface, 
not an implementation
*/
/*Why interface, instead of Abstract Class
First, HousePlan and House does not have a "is a" relationship
Second, Java does not support multiple inheritance, so, if there's no error conceptually
in having interface, we should have interface (like in this case), because, we could
extends multiple inheritance
*/
public interface HousePlan 
{
    void setBasement(String basement); 
    void setStructure(String structure);
    void setRoof(String roof);
    void setInterior(String interior);
    public void getDescriptionOfHouse();
}

