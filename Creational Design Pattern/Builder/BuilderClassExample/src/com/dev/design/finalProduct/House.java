/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.dev.design.finalProduct;

import com.dev.design.abstractProduct.HousePlan;

/**
 *
 * @author admin
 */
/*
Now, there will be only one concrete Product
*/
public class House implements HousePlan
{
    private String basement;
    private String structure;
    private String roof;
    private String interior;
    @Override
    public void setBasement(String basement) 
    {
        this.basement = basement;
    }
 
    @Override
    public void setStructure(String structure) 
    {
        this.structure = structure;
    }
 
    @Override
    public void setRoof(String roof) 
    {
        this.roof = roof;
    }
    @Override
    public void setInterior(String interior) 
    {
        this.interior = interior;
    }
    @Override
    public void getDescriptionOfHouse()
    {
        System.out.println("Basement choice: "+basement);
        System.out.println("Structure choice: "+structure);
        System.out.println("Roof choice: "+roof);
        System.out.println("Interior choice: "+interior);
    }
}

