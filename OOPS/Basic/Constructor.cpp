// class student {
//     int id;
//     int age;

// };

class student {
    private:
    int id;
        
    public:
    int age;

    public: 
     // destructor
    ~student(){
        cout<<"Destructor called"<<endl;
    }

    public:
    // default constructor
    student() { // constructor name is same as class name
        cout<<"Constructor called"<<endl;

    }

    student(int a) { // parameterized constructor
        cout<<"Constructor with parameter called"<<endl;
        age = a;
    }

    student(int a, int i) { // parameterized constructor with two parameters
        cout<<"Constructor with two parameters called"<<endl;
        age = a;
        id = i;
    }
    

    void display() {
        
        cout<<"Age: "<<age<<endl;
    }
    int getId() { 
        return id;
    }

    void setId(int i) { 
        id = i;
    
};