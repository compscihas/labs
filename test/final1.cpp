struct Coord3D {
    int x = 0, y = 0, z = 0;
};
 
class DynamicCoord3D {
    Coord3D* data;
 
 public:
    DynamicCoord3D(Coord3D c) : data(new Coord3D(c)) {}
 
    // value access by dereference
    const Coord3D & operator*() const { return *data; }
    Coord3D& operator*() { return *data; }
 
    // value assignment – This is NOT the copy assignment
    DynamicCoord3D& operator=(const Coord3D& c) {
        *data = c;
        return *this;
    }
    ~DynamicCoord3D(){
        delete data;
    }
    DynamicCoord3D(const DynamicCoord3D& other){
        data = new Coord3D(*other.data);
    }
    DynamicCoord3D& operator=(const DynamicCoord3D& other){
        if(this != &other){
            delete data;
            data = new Coord3D(*other.data);
        }
        return *this;
    }
 
    // TODO(student): declare and define the rule of three methods

};