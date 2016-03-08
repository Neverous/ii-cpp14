#include<iostream>

#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "surface.h"
#include <vector>

std::ostream &operator<<(std::ostream &stream, const std::vector<Surface> &data);
void print_statistics(const std::vector<Surface> &data);

int main(void)
{
    {
        Surface circle = Circle(0.0, 0.0, 20.0);
        std::cout << circle << "\n";

        circle = circle;
    }

    {
        Surface rectangle = Rectangle(  0.0, 0.0,
                                        1.0, 1.0);

        std::cout << rectangle << "\n";

        rectangle = rectangle;
    }

    {
        Surface triangle = Triangle(0.0, 0.0,
                                    1.0, 1.0,
                                    0.0, 1.0);
        std::cout << triangle << "\n";
    }

    {
        std::vector<Surface> table;
        table.push_back(Circle{0.0, 0.0, 20.0});
        table.push_back(Rectangle{0.0, 0.0, 1.0, 1.0});
        table.push_back(Triangle{0.0, 0.0, 1.0, 1.0, 0.0, 1.0});

        std::cout << table;
        print_statistics(table);
    }

    {
        Surface test = Circle{0.0, 0.0, 20.0};
        std::cout << test << "\n";
        test = Triangle{0.0, 0.0, 1.0, 1.0, 0.0, 1.0};
        std::cout << test << "\n";
        test = Rectangle{0.0, 0.0, 1.0, 1.0};
        std::cout << test << "\n";

        Surface temp = Circle{0.0, 0.0, 1.0};
        std::cout << temp << "\n";
        std::cout << test << "\n";

        test = temp;
        std::cout << temp << "\n";
        std::cout << test << "\n";

        Rectangle rect{0.0, 0.0, 2.0, 2.0};
        std::cout << rect << "\n";
        std::cout << test << "\n";

        test = rect;
        std::cout << rect << "\n";
        std::cout << test << "\n";

        test = rect;
        std::cout << rect << "\n";
        std::cout << test << "\n";
    }

    {
        std::vector<Surface> table;
        for(size_t t = 0; t < 16; ++ t)
        {
            switch(rand() % 3)
            {
                case 0:
                    table.push_back(Circle{(double) rand(), (double) rand(), (double) rand()});
                    break;

                case 1:
                    table.push_back(Rectangle{(double) rand(), (double) rand(), (double) rand(), (double) rand()});
                    break;

                case 2:
                    table.push_back(Triangle{(double) rand(), (double) rand(), (double) rand()});
                    break;
            }
        }

        std::cout << table << "\n";
        print_statistics(table);
    }

    return 0;
}

inline
std::ostream &operator<<(std::ostream &stream, const std::vector<Surface> &data)
{
    for(size_t d = 0; d < data.size(); ++ d)
        stream << d + 1 << "-th element=" << data[d] << "\n";

    return stream;
}

inline
void print_statistics(const std::vector<Surface> &data)
{
    double total_area = 0.0;
    double total_circumference = 0.0;

    for(const auto &surface: data)
    {
        std::cout << "adding info about " << surface << "\n";
        total_area += surface->area();
        total_circumference += surface->circumference();
    }

    std::cout << "total area is " << total_area << "\n";
    std::cout << "total circumference is " << total_circumference << "\n";
}
