#include <iostream> 
#include <vector>

//Starting point of every c++ program
int main() {
    //declaring our variables
    int age;
    float decimalNumber; //Can store decimal numbers like 3.5
    std::string name;
    std::vector<int> ages;

    std::cout<<"please enter your age: \n";
    //Taking in age and printing out age 
    
    std::cin>>age;
    std::cout<< "Your age is: " << age;
    //Printing blank space/line 
    std::cout<<"\n";

    std::cout<<"please enter your name: \n";
    //Taking in name and printing out name

    std::cin>>name;
    std::cout<<"your name is: "<< name << "\n";
    //printing in a blank space
    ages.push_back(age); //push_back = add
    ages.push_back(16);
    ages.push_back(12);
    ages.push_back(9); 
    //Our first conditional statement IF / ELSE / ELSE IF
    //Always start with an IF and end with an ELSE 
    //As many ELSE IF in between
    if(age >= 18) {
        std::cout<<"You are allowed to legally drink";
    } else if(age >= 16) {
        std::cout<< "You are between 16 and 18";
    } else {
        std::cout<<"You are not allowed to drink";
    } 
    for (int i = 0; i < ages.size(); i++)
    {
        std::cout<< "i has the value: " << i << "\n";
        //std::cout<<ages.at(i) << ",";
    }
    
}  

//NOTES
/*
>> take in cin
<< put out cout
*/