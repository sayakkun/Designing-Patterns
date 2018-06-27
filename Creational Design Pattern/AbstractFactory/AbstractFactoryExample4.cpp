#include<bits/stdc++.h>
using namespace std;
class Widget
{
	public:
        	virtual void draw() = 0;
        	//a pure virtual function making it abstract class	
};
/**
 * Concrete product family 1.
 */
class LinuxButton : public Widget
{
	public:
        	void draw() { cout << "LinuxButton\n"; }
};
class LinuxMenu : public Widget 
{
    	public:
        	void draw() { cout << "LinuxMenu\n"; }
};
/*Now, there's the difference. Last example does not show that AbstractFactory can creeate different Product families using composition. Factory ddesign pattern does not do that*/
/*And, this approach is also considered one of the biggest difference between Factory and Abstract Factory*./
/**
 * Concrete product family 2.
 */
class WindowsButton : public Widget 
{
    public:
        void draw() { cout << "WindowsButton\n"; }
};
class WindowsMenu : public Widget 
{
    public:
        void draw() { cout << "WindowsMenu\n"; }
};
/**
 * Abstract factory defines methods to create all
 * related products.
 */
 /*Now, we will no longer be creating WindowsButton, WindowsMenu directly in case of windowsWidget set*/
class WidgetFactory 
{
    public:
        virtual Widget *create_button() = 0;
        virtual Widget *create_menu() = 0;
};
/**
 * Each concrete factory corresponds to one product
 * family. It creates all possible products of
 * one kind.
 */
class LinuxFactory : public WidgetFactory 
{
    public:
        Widget *create_button() 
        {
            return new LinuxButton;
        }
        Widget *create_menu() 
        {
            return new LinuxMenu;
        }
};

/**
 * Concrete factory creates concrete products, but
 * returns them as abstract.
 */
class WindowsFactory : public WidgetFactory 
{
    public:
        Widget *create_button()
        {
            return new WindowsButton;
        }
        Widget *create_menu() 
        {
            return new WindowsMenu;
        }
};
/**
 * Client receives a factory object from its creator.
 *
 * All clients work with factories through abstract
 * interface. They don't know concrete classes of
 * factories. Because of this, you can interchange
 * concrete factories without breaking clients.
 *
 * Clients don't know the concrete classes of created
 * products either, since abstract factory methods
 * returns abstract products.
 */
class Client 
{
	private:
        	WidgetFactory *factory;
    	public:
        	Client(WidgetFactory *f) 
        	{
            		factory = f;
        	}
        	void display_window() 
       	 	{
            		Widget *w[] = {factory->create_button(),factory->create_menu()};
            		//factory is the base class pointer.
            		w[0]->draw();
            		w[1]->draw();
        	}
	//this two different widget, button and menu (achieved thoguh the use of inheritence and composition) will combinedly generate the display_window()
	//that is truely abstract factory example
};
int main()
{
	WidgetFactory *factory;
	//conditional compilation is being used
    	#ifdef LINUX
        	factory = new LinuxFactory;
    	#else // WINDOWS
        	factory = new WindowsFactory;
    	#endif
    	//note that, factory will be always instantiated.
    	//because, conditional compilation is used So, compiled code does not haave any flaws
    	Client *c = new Client(factory);
	c->display_window();
	return 0;
}
/*Note, wwhy do we choose conditional compilation here. There will always be requirement of one particular window type for displaying. So, it is better, that we dont compile the code with the other window type code. Because, conditional compilation provides that optimization feature*/
