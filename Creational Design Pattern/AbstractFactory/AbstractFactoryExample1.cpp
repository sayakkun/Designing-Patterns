#include<bits/stdc++.h>
using namespace std;
/*Abstract Base Product Class*/
class Computer
{
	public:
		/*you must make these functions access specifier public*/
		virtual string get_RAM()=0;
		virtual string get_HDD()=0;
		virtual string get_CPU()=0;
		/*Now, even if a class contains atleast one pure virtual function*/
		/*make this virtual too*/
		/*So, that, if a defintion exists in the derived concrete class, 
 * 		that function will be called under certain cases */
		virtual string to_string()
		{
			return "RAM: "+this->get_RAM()+", HDD: "+this->get_HDD()+", CPU: "+this->get_CPU();
		}
};
/*concrete Product Class*/
/*Derived class of Computer*/
class PC: public Computer
{
	private:
		string ram;
		string hdd;
		string cpu;
	public:
		PC(string ram,string hdd,string cpu)
		{
			this->ram=ram;
			this->hdd=hdd;
			this->cpu=cpu;
		}
		string get_RAM()
		{
			return this->ram;
		}
		string get_HDD()
		{
			return this->hdd;
		}
		string get_CPU()
		{
			return this->cpu;
		}
};
/*concrete Product Class*/
/*Derived class of Computer*/
class Server: public Computer
{
	private:
                string ram;
                string hdd;
                string cpu;
        public:
                Server(string ram,string hdd,string cpu)
                {
                        this->ram=ram;
                        this->hdd=hdd;
                        this->cpu=cpu;
                }
                string get_RAM()
                {
                        return this->ram;
                }
                string get_HDD()
                {
                        return this->hdd;
                }
                string get_CPU()
                {
                        return this->cpu;
                }
};
/*abstract factory*/
class ComputerAbstractFactory
{
	//creates different type of Computer
	public:
		 virtual Computer* create_computer()=0; 
};
class PCFactory: public ComputerAbstractFactory
{
	private: 
		string ram;
		string hdd;
		string cpu;
	public:
		PCFactory(string ram,string hdd,string cpu)
		{
			this->ram=ram;
			this->hdd=hdd;
			this->cpu=cpu;
		}
		//must be overriden
		//otherwise, it will be an abstract class too
		Computer* create_computer()
		{
			return new PC(ram,hdd,cpu);
		}
		
};
class ServerFactory: public ComputerAbstractFactory
{
        private:
                string ram;
                string hdd;
                string cpu;
        public:
                ServerFactory(string ram,string hdd,string cpu)
                {
                        this->ram=ram;
                        this->hdd=hdd;
                        this->cpu=cpu;
                }
                //must be overriden
                //otherwise, it will be an abstract class too
		Computer* create_computer()
		{
			return new Server(ram,hdd,cpu);
		}
};
class ComputerFactory
{
	public:
		static Computer* get_computer(ComputerAbstractFactory *factory)
		{
			return factory->create_computer();
		}
};
int main()
{
	
	Computer *pc=ComputerFactory::get_computer(new PCFactory("2 GB","500 GB","2.4 GHz"));
	cout<<pc->to_string()<<endl;
	return 0;	
}
