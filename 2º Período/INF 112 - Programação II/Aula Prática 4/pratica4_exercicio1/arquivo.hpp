class Rectangle {

private:
    float _length;
    float _width;

public:
    Rectangle();
    float getLength();
    float getWidth();
    void setLenght(float addLenght);
    void setWidth(float addWidth);
    float calcPerimeter();
    float calcArea();

};