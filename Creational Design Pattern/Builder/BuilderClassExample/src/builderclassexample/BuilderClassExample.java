/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package builderclassexample;

import com.dev.design.Director.CivilEngineer;
import com.dev.design.abstractBuilder.HouseBuilder;
import com.dev.design.finalBuilders.*;
import com.dev.design.finalProduct.House;
/**
 *
 * @author admin
 */
public class BuilderClassExample 
{
    public static void main(String args[])
    {
        HouseBuilder iglooBuilder = new IglooHouseBuilder();
        CivilEngineer engineer = new CivilEngineer(iglooBuilder);
        engineer.constructHouse();
        House house = engineer.getHouse();
        house.getDescriptionOfHouse();
    } 
}
