#include<iostream>
#include<cmath>

using namespace std;

class shape {
    public :
    virtual void whoAmI() const = 0;
    virtual ~shape() = default;
};

class twoDimensionalShape : public shape {
    public :
    virtual float area() const = 0;
    virtual float perimeter() const = 0;
    void whoAmI() const override {
        cout << "I am a two-dimensional shape." << endl;
    }
};

class threeDimensionalShape : public shape {
    public :
    virtual float volume() const = 0;
    virtual float surfaceArea() const = 0;
    void whoAmI() const override {
        cout << "I am a three-dimensional shape." << endl;
        }
};

class square : public twoDimensionalShape {
    private :
    float side;
    public :
    square(float side) : side(side) {}

    float area() const override {
        return side * side;
    }

    float perimeter() const override {
        return 4 * side;
    }

    void whoAmI() const override {
        cout << "I am a square. ";
        twoDimensionalShape::whoAmI();
    }
};

class circle : public twoDimensionalShape {
    private :
    float radius;
    public :
    circle(float radius) : radius(radius) {}
    float area() const override {
        return 3.14159 * radius * radius;    
    }
    float perimeter() const override {
        return 2 * 3.14159 * radius;
    }
    void whoAmI() const override {
        cout << "I am a circle. ";
        twoDimensionalShape::whoAmI();
    }
};

class rectangle : public twoDimensionalShape {
    private :
    float length;
    float width;
    public :
    rectangle(float length, float width) : length(length), width(width) {}
    float area() const override {
        return length * width;
    }
    float perimeter() const override {
        return 2 * (length + width);
    }
    void whoAmI() const override {
        cout << "I am a rectangle. ";
        twoDimensionalShape::whoAmI();
    }
};

class triangle : public twoDimensionalShape {
    private :
    float a,b,c;
    public :
    triangle(float x, float y, float z) : a(x), b(y),c(z) {}
    float area() const override {
        float s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s -c));
    }
    float perimeter() const override {
        return a + b + c;
    }
    void whoAmI() const override {
        cout << "I am a triangle. ";
        twoDimensionalShape::whoAmI();
    }
};

class cude : public threeDimensionalShape {
    private :
    float side;
    public :
    cude(float s) : side(s) {}
    float surfaceArea() const override {
        return 6 * pow (side , 2);
    }
    float volume() const override {
        return pow (side , 3);
    }
    void whoAmI() const override {
        cout << "I am a cube. ";
        threeDimensionalShape::whoAmI();
    }
};

class sphere : public threeDimensionalShape {
    private :
    float radius;
    public :
    sphere(float r) : radius(r) {}
    float surfaceArea() const override {
        return 4 * 3.14 * pow(radius, 2);
    }
    float volume() const override {
        return 4/3 * 3.14 * pow(radius, 3);
    }
    void whoAmI() const override {
        cout << "I am a sphere. ";
        threeDimensionalShape::whoAmI();
    }
};

class cylinder : public threeDimensionalShape {
    private :
    float radius;
    float height;
    public :
    cylinder(float r, float h) : radius(r), height(h) {}
    float surfaceArea() const override {
        return 2 * 3.14 * radius * (radius + height);
    }
    float volume() const override {
        return 3.14 * pow(radius, 2) * height;
    }
    void whoAmI() const override {
        cout << "I am a cylinder. ";
        threeDimensionalShape::whoAmI();
    }
};

class cone : public threeDimensionalShape {
    private :
    float radius;
    float height;
    public :
    cone(float r, float h) : radius(r), height(h) {}
    float surfaceArea() const override {
        return 3.14 * radius * (radius + sqrt(pow(radius, 2) + pow(height , 2)));
    }
    float volume() const override {
        return 1/3 * 3.14 * pow(radius, 2) * height;
    }
    void whoAmI() const override {
        cout << "I am a cone. ";
        threeDimensionalShape::whoAmI();
    }
};

int main()
{
    square sq(4.0);
    circle cr(5.0);
    rectangle re(4.0,6.0);
    triangle tr(3.0,4.0,5.0);

    cude c(3.0);
    sphere s(4.0);
    cylinder cy(5.0,6.0);
    cone co(4.0,5.0);

     cout << "2D Shapes:" << endl;
    sq.whoAmI();
    cout << "Area: " << sq.area() << ", Perimeter: " << sq.perimeter() << endl;

    cr.whoAmI();
    cout << "Area: " << cr.area() << ", Perimeter: " << cr.perimeter() << endl;

    re.whoAmI();
    cout << "Area: " << re.area() << ", Perimeter: " << re.perimeter() << endl;

    tr.whoAmI();
    cout << "Area: " << tr.area() << ", Perimeter: " << tr.perimeter() << endl;

    cout << "\n3D Shapes:" << endl;
    c.whoAmI();
    cout << "Surface Area: " << c.surfaceArea() << ", Volume: " << c.volume() << endl;

    s.whoAmI();
    cout << "Surface Area: " << s.surfaceArea() << ", Volume: " << s.volume() << endl;

    cy.whoAmI();
    cout << "Surface Area: " << cy.surfaceArea() << ", Volume: " << cy.volume() << endl;

    co.whoAmI();
    cout << "Surface Area: " << co.surfaceArea() << ", Volume: " << co.volume() << endl;


    
    
    return 0;
}