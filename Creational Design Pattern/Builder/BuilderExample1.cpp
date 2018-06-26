#include<bits/stdc++.h>
using namespace std;
/*Abstract product class*/
class HousePlan
{
	/*that's an abstract class*/
	public:
		virtual void set_basement(string)=0;
		virtual void set_structure(string)=0;
		virtual void set_roof(string)=0;
		virtual void set_interior(string)=0;
		//virtual void set_exterior(string)=0;
};
/*Base product class*/
class House:public HousePlan
{
	private:
		string basement;
		string structure;
		string roof;
		string interior;
	public:
		/*this were pure virtual functions in the Abstract product class
 * 		So, this functions must be overridden. Otherwise, House will also become an abstract class*/
		void set_basement(string );
		void set_structure(string );
		void set_roof(string );
		void set_interior(string );
		void display();
};
void House::set_basement(string basement)
{
	this->basement=basement;
}	
void House::set_structure(string structure)
{
	this->structure=structure;
}
void House::set_roof(string roof)
{
	this->roof=roof;
}
void House::set_interior(string interior)
{
	this->interior=interior;
}
void House::display()
{
	cout<<"The basement is set to: "<<basement<<endl;
	cout<<"The structure is set to: "<<structure<<endl;
	cout<<"The roof is set to: "<<roof<<endl;
	cout<<"The interior is set  to: "<<interior<<endl;
}
/*Abstract Builder class*/
class HouseBuilder
{
	public:
		virtual void build_basement()=0;
		virtual void build_structure()=0;
		virtual void build_roof()=0;
		virtual void build_interior()=0;
		virtual House* get_house()=0;
};
/*Builder class*/
class TipiBuilder: public HouseBuilder
{
	/*Now, you will see the difference*/
	/*In AbstractFactory design pattern, the concreteFactory classes contain the same data members
 *  	as Product. Because, user passes the product specification.
 *  	Here, User chooses a Builder class for providing functiality
 *  	That Builder class will serve a representation (a fixed one) of the product
 *  	So, here, In Builder design pattern, we will rather have a pointer to the house class
 *  	Again, another difference, since, there is only one product here, and it is the builder's
 *  	responsibility to provide a different representation of that class, we will have a pointer to the base product class
 *  	in fact, in java, the base product class only implements interface to provide combined set of functionality
 *  	here, in c++, there is no concept of interface. But, we can have multiple inheritance
 *  	though, it would not be theoritically same. Because, interface supports has a relationship while it is implemented 
 *  	by a class. While, with abstract class it is a is a relationship
 */
	private:
		House *house;
	public:
		TipiBuilder();
		void build_basement();
		void build_structure();
		void build_roof();
		void build_interior(); 	
		House* get_house();
};
TipiBuilder::TipiBuilder()
{
	this->house=new House;
}
void TipiBuilder::build_basement()
{
	house->set_basement("Wooden Poles");
}
void TipiBuilder::build_structure()
{
	house->set_structure("Wood and ice");
}
void TipiBuilder::build_roof()
{
	house->set_roof("Fire wood");
}
void TipiBuilder::build_interior()
{
	house->set_interior("Wood, caribou and seal skins");
}
House* TipiBuilder::get_house()
{
	return this->house;
}
class IglooBuilder: public HouseBuilder
{
	 private:
                House *house;
        public:
                IglooBuilder();
                void build_basement();
                void build_structure();
                void build_roof();
                void build_interior();
                House* get_house();
};
IglooBuilder::IglooBuilder() 
{
        this->house = new House();
}
void IglooBuilder::build_basement() 
{
        house->set_basement("Ice Bars");
}
void IglooBuilder::build_structure() 
{
        house->set_structure("Ice Blocks");
}
void IglooBuilder::build_interior() 
{
        house->set_interior("Ice Carvings");
}
void IglooBuilder::build_roof() 
{
        house->set_roof("Ice Dome");
}
House* IglooBuilder::get_house() 
{
        return this->house;
}
/*Director class*/
class CivilEngineer 
{
 	private:
		 HouseBuilder *houseBuilder;
    		//configures the director class with the desired Builder Object
	public:
		CivilEngineer(HouseBuilder *);
		House* get_house();
		void construct_house();
};
CivilEngineer::CivilEngineer(HouseBuilder *houseBuilder)
{
	this->houseBuilder=houseBuilder;
}
House* CivilEngineer::get_house()
{
	houseBuilder->get_house();
}
void CivilEngineer::construct_house()
{
	/*Now, see, the order in which director chooses to build a product step by step, is director specific. Client
 * 	Only cares about Product. And, again, it is director specific. Not builder specific. Builder provides the necessary abstraction
 * 	between the actual director class and how that class builds a product. Nothing else*/
	houseBuilder->build_basement();
	houseBuilder->build_structure();
	houseBuilder->build_roof();
	houseBuilder->build_interior();
};
int main()
{
	HouseBuilder *iglooBuilder=new IglooBuilder();
	CivilEngineer engineer(iglooBuilder);
	//passed the pointer as a ddescription that how client wants his house to be built
	engineer.construct_house();
	House *house=engineer.get_house();
	//since, it will return a pointer. We could try to improvise and return a reference
	//for now, let it be pointer
	house->display();
	return 0;
}
