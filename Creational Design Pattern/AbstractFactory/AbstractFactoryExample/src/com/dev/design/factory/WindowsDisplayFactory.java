/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.dev.design.factory;

import com.dev.design.model.*;
import com.dev.design.abstractFactory.WidgetDisplayFactory;

/**
 *
 * @author admin
 */
public class WindowsDisplayFactory implements WidgetDisplayFactory
{

    @Override
    public Widget createButton() 
    {
        return new WindowsButton();
    }
    @Override
    public Widget createMenu() 
    {
        return new WindowsMenu();
    }
}
