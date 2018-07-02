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
/*Another concrete builder*/
public class IglooHouseBuilder implements HouseBuilder
{
    private final House house; 
    public IglooHouseBuilder() 
    {
        this.house = new House();
    }
    @Override
    public void buildBasement() 
    {
        house.setBasement("Ice Bars");
    }
    @Override
    public void buildStructure() 
    {
        house.setStructure("Ice Blocks");
    }
    @Override
    public void buildInterior() 
    {
        house.setInterior("Ice Carvings");
    }
    @Override
    public void bulidRoof() 
    {
        house.setRoof("Ice Dome");
    }
    @Override
    public House getHouse() 
    {
        return this.house;
    }
}