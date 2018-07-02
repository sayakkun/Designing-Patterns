/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.dev.design.abstractBuilder;
import com.dev.design.finalProduct.House;

/**
 *
 * @author admin
 */
/*abstruact Builder*/
/*Now, again, we have interface. For this design, we actually could have abstract class, too
However, interface provides an advantage. That if concrete builder class likes to 
add more feature like having a pool outside house or having a garden, they could implement
both interface
Like, houseBuilder and GardenBuilder
Suppose, you have a concrete Builder class named VillaBuilder. Now, Villa contains
garden and pools. So, it would be helpful in that case
*/
public interface HouseBuilder
{
    /*All methods are public abstract*/
    public void buildBasement();
    public void buildStructure();
    public void bulidRoof();
    public void buildInterior();
    public House getHouse();
    
}
