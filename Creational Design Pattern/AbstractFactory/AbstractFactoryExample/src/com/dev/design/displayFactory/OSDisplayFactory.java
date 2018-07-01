/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.dev.design.displayFactory;

import com.dev.design.abstractFactory.WidgetDisplayFactory;
import com.dev.design.model.Widget;
/**
 *
 * @author admin
 */
public class OSDisplayFactory 
{
    private final WidgetDisplayFactory displayFactory;
    public OSDisplayFactory(WidgetDisplayFactory displayFactory)
    {
        this.displayFactory=displayFactory;
    }
    public void display()
    {
        Widget widgetArr[]={displayFactory.createMenu(),displayFactory.createButton()};
        widgetArr[0].draw();
        widgetArr[1].draw();
    }
}
