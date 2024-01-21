#include <iostream>
 
class Auto; // объявление класса Auto, чтобы Person видел этот класс
 
class Person
{
public:
    Person(std::string p_name)
    {
        name = p_name;
    }
    friend void drive(const Auto&);
    void setPrice(Auto&, unsigned);
 
private:
    std::string name;
};
 
class Auto
{
    // объявление дружественного класса
    friend class Person;
public:
    Auto(std::string a_name, unsigned a_price) 
    { 
        name = a_name; 
        price = a_price;
    }
    void print()
    {
        std::cout << name << " : " << price << std::endl;
    }
    friend void drive(const Auto&);
  
private:
    std::string name;   // название автомобиля
    unsigned price;  // цена автомобиля
};
  
void Person::drive(const Auto& car) 
{ 
    std::cout << name << " drives " << car.name << std::endl;
}
void Person::setPrice(Auto& car, unsigned price)
{
    car.price = price;
}
  
int main()
{
    Auto tesla{"Tesla", 5000};
    Person tom{"Tom"};
    tom.drive(tesla);
    tom.setPrice(tesla, 8000);
    tesla.print();  
}