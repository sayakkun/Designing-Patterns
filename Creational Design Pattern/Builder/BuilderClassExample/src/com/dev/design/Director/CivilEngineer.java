package com.dev.design.Director;

import com.dev.design.abstractBuilder.HouseBuilder;
import com.dev.design.finalProduct.House;

/*Director class*/
/*
 The client creates the Director object and configures it with the desired
Builder object.
*/
/*See, that Client Class configures the Director Object CivilEngineer with the 
Desired Builder HouseBuilder object*/ 
public class CivilEngineer 
{
    private final HouseBuilder houseBuilder;
    //configures the director class with the desired Builder Object
    public CivilEngineer(HouseBuilder houseBuilder)
    {
        this.houseBuilder = houseBuilder;
    }
 	//return the final product
    public House getHouse()
    {
        return this.houseBuilder.getHouse();
    }
    //Now, from client class, it must be called before obtaining the  final product here
    public void constructHouse()
    {
        this.houseBuilder.buildBasement();
        this.houseBuilder.buildStructure();
        this.houseBuilder.bulidRoof();
        this.houseBuilder.buildInterior();
    }
}
   
