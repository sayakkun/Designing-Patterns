#include<bits/stdc++.h>
using namespace std;
/*Abstract Base Product Class*/
class Computer
{
	//because, unlike interface an abstract class can have data members which can be reused
	private:
		string ram;
		string hdd;
		string cpu;
	public:
		Computer(string,string,string);
		virtual string get_RAM()=0;
                virtual string get_HDD()=0;
                virtual string get_CPU()=0;
		virtual string to_string();
};
		/*you must make these functions access specifier public*/
Computer::Computer(string ram,string hdd,string cpu)
{	
	this->ram=ram;
        this->hdd=hdd;
        this->cpu=cpu;
}
string Computer::get_RAM()
{
	//you can always provide a defintion to pure virtual function
	//however, this definition will not be inherited
	return this->ram;
}
string Computer::get_HDD()
{
	return this->hdd;
}
string Computer::get_CPU()
{
	return this->cpu;
}	
string Computer::to_string()
{
	return "RAM: "+this->get_RAM()+", HDD: "+this->get_HDD()+", CPU: "+this->get_CPU();
};
/*concrete Product Class*/
/*Derived class of Computer*/
class PC: public Computer
{
	public:
		PC(string ram,string hdd,string cpu):Computer(ram,hdd,cpu)
		{
			//initializer list
		}
		string get_RAM()
		{
			return Computer::get_RAM();
		}
		string get_HDD()
		{
			return Computer::get_HDD();
		}
		string get_CPU()
		{
			return Computer::get_CPU();
		}
};
/*concrete Product Class*/
/*Derived class of Computer*/
class Server: public Computer
{
        public:
                Server(string ram,string hdd,string cpu):Computer(ram,hdd,cpu)
                {
                }
		 string get_RAM()
                {
                        return Computer::get_RAM();
                }
                string get_HDD()
                {
                        return Computer::get_HDD();
                }
                string get_CPU()
                {
                        return Computer::get_CPU();
                }

};
/*abstract factory*/
class ComputerAbstractFactory
{
	//creates different type of Computer
	protected:
		string ram;
		string hdd;
		string cpu;
	
	public:
		ComputerAbstractFactory(string,string,string);
		virtual Computer* create_computer()=0;
};
ComputerAbstractFactory::ComputerAbstractFactory(string ram,string hdd,string cpu)
{
	this->ram=ram;
	this->hdd=hdd;
	this->cpu=cpu;
};
class PCFactory: public ComputerAbstractFactory
{
	public:
		PCFactory(string,string,string);
		Computer* create_computer();
};
PCFactory::PCFactory(string ram,string hdd,string cpu):ComputerAbstractFactory(ram,hdd,cpu)
{
}
//must be overriden
////otherwise, it will be an abstract class too
Computer* PCFactory::create_computer()
{
	return new PC(ram,hdd,cpu);
}
class ServerFactory: public ComputerAbstractFactory
{
        public:
		ServerFactory(string,string,string);
		Computer* create_computer();
};
ServerFactory::ServerFactory(string ram,string hdd,string cpu):ComputerAbstractFactory(ram,hdd,cpu)
{
}
//must be overriden
//otherwise, it will be an abstract class too
Computer* ServerFactory::create_computer()
{
	return new Server(ram,hdd,cpu);	
}
class ComputerFactory
{
	public:
		static Computer* get_computer(ComputerAbstractFactory *);
};
Computer* ComputerFactory::get_computer(ComputerAbstractFactory *factory)
{
	return factory->create_computer();
}
int main()
{
	
	Computer *pc=ComputerFactory::get_computer(new PCFactory("2 GB","500 GB","2.4 GHz"));
	cout<<pc->to_string()<<endl;
	return 0;	
}
