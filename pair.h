//If we require pair type of double or character type we
//need to code same code & replace int to char or double so we introduce template.
template<typename T>
//So templates helps in using same class in different form of data types.
//for two template refer pair1.h.
class Pair {
    T x;
    T y;
public:
    void setX(T X){
        this->x=X;
    }
    T getX(){
        return x;
    }
    void setY(T Y){
        this->y=Y;
    }
    T getY(){
        return y;
    }
};

