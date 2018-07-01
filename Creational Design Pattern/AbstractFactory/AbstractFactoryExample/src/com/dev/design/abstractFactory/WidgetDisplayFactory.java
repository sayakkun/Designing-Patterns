/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.dev.design.abstractFactory;
import com.dev.design.model.Widget;
/**
 *
 * @author admin
 */
/*Now, note that, only Widget Interface is exposed*/
public interface WidgetDisplayFactory 
{
    /*All methods are by default public abstract*/
    Widget createButton();
    Widget createMenu();
}
