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
    void display() {
        
        cout<<"Age: "<<age<<endl;
    }
    int getId() { // getter function
        return id;
    }

    void setId(int i) { // setter function
        id = i;

};