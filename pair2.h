template<typename X,typename Y,typename Z>
class pair2 {
    X a;
    Y b;
    Z c;
public:
    void setX(X A){
        this->a=A;
    }
    void setY(Y B){
        this->b=B;
    }
    void setZ(Z C){
        this->c=C;
    }
    X getX(){
      return a;
    }
    Y getY(){
        return b;
    }
    Z getZ(){
        return c;
    }
};

