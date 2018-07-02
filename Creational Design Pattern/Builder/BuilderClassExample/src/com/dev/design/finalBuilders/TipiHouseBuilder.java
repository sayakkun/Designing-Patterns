/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.dev.design.finalBuilders;

import com.dev.design.abstractBuilder.HouseBuilder;
import com.dev.design.finalProduct.House;

/**
 *
 * @author admin
 */
/*Another Concrete Builder*/
public class TipiHouseBuilder implements HouseBuilder
{
    private final House house;
    public TipiHouseBuilder() 
    {
        this.house = new House();
    }
 
    @Override
    public void buildBasement() 
    {
        house.setBasement("Wooden Poles");
    }
 
    @Override
    public void buildStructure() 
    {
        house.setStructure("Wood and Ice");
    }
 
    @Override
    public void buildInterior() 
    {
        house.setInterior("Fire Wood");
    }
 
    @Override
    public void bulidRoof() 
    {
        house.setRoof("Wood, caribou and seal skins");
    }
 
    @Override
    public House getHouse() 
    {
        return this.house;
    }
 
}
