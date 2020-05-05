template<typename T,typename V>
//Using this 2 typename in template we can have two data types
//Eg if we require x as int y as double we can have these type of templates.
//Now if we three typename we can create triplet template as pair2.h
class pair1 {
    T x;
    V y;
public:
    void setX(T X){
        this->x=X;
    }
    void setY(V Y){
        this->y=Y;
    }
    T getX(){
        return x;
    }
    V getY(){
        return y;
    }
};

