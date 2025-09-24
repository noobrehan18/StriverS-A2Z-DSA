class student{
    public:
    int age;
    const int rollNumber;
    int &x; // reference must be initialized while declaration using constructor

    student(int r,int age ) : rollNumber(r), age(age ),x(this-> age){ // order of initialization is same as order of declaration

     }

    student(int r) : rollNumber(r) { // member initialization list
    }
    student(int r,int a ) : rollNumber(r), age(a) { // MUtltiple member initialization list   
        
     student(int r,int age ) : rollNumber(r), age(age ){ // order of initialization is same as order of declaration

     }
        
        //rollNumber = r;  // we can initialize constant variable using constructor
    }
};