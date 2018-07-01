/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.dev.design.abstractfactoryExample;
import com.dev.design.factory.*;
import com.dev.design.abstractFactory.WidgetDisplayFactory;
import com.dev.design.displayFactory.OSDisplayFactory;
/**
 *
 * @author admin
 */
public class AbstractFactoryExample 
{
    public static void main(String[] args) 
    {
        // TODO code application logic here
        //Now, let's hardcodde it
        //can we have compile time decision in java
        WidgetDisplayFactory neededDisplayFactory=null;
        if(Configuration.NEEDEDDISPLAY.compareTo("Windows")==0)
        {
            /*This will do conditional compilation
            Because, static variables are resolved in compile time
            Reading from here:
            http://www.javapractices.com/topic/TopicAction.do?Id=64
            However, I need to learn more
            */
            neededDisplayFactory=new WindowsDisplayFactory();
        }
        else if(Configuration.NEEDEDDISPLAY.compareTo("Linux")==0)
        {
            neededDisplayFactory=new LinuxDisplayFactory();
            
        }
        OSDisplayFactory dispFactory=new OSDisplayFactory(neededDisplayFactory);
        dispFactory.display();
    }
}
